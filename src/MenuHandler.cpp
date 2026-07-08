#include "MenuHandler.h"
#include "WidgetLvlWidget.h"
#include "WidgetGold.h"
#include "WidgetShout.h"
#include "WidgetWeight.h"
#include "Settings.h"
#include "WidgetEquip.h"
#include "WidgetResist.h"
#include "WidgetPlayTime.h"
#include "WidgetGameTime.h"
#include "WidgetManager.h"  // CheckInI
using namespace RE;
auto MenuHandler::get_singleton() noexcept -> MenuHandler* {
  static MenuHandler instance;
  return std::addressof(instance);
}

auto MenuHandler::register_() -> void {
  if (const auto ui = UI::GetSingleton()) {
    ui->AddEventSink(get_singleton());
  }
}
// No caching here on purpose. The per-frame PlayerUpdate hook (Hooks.cpp) calls
// check2(true) every frame during normal play, which re-asserts SetVisible(true) on
// every widget. That is what makes the widgets self-heal: if any transition leaves a
// widget with SetVisible(false), the very next normal-play frame turns it back on.
// A "skip if unchanged" cache would defeat that and let a stale hidden state stick -
// which is exactly how the widgets could vanish for good.
void check2(bool a_visible)
{
  ResistWidget::toggle_visibility(a_visible);
  WidgetGold::toggle_visibility(a_visible);
  WidgetWeight::toggle_visibility(a_visible);
  WidgetLvl::toggle_visibility(a_visible);
  WidgetShout::toggle_visibility(a_visible);
  WidgetGameTime::toggle_visibility(a_visible);
  WidgetPlayTime::toggle_visibility(a_visible);
  WidgetEquip::toggle_visibility(a_visible);
}

// Set true whenever a loading screen occurs (coc, new game, F9, fast travel, cell
// change). The player Update hook then re-applies CheckInI() once the widget movies
// have finished their async LoadMovieEx, and clears it. Starts true so the very first
// entry into the world configures the widgets.
static bool g_hudNeedsConfig = true;

// (Re)send kShow to every always-open overlay. This is what actually reveals the
// widgets after the world loads (kPostLoadGame does the same). There is no kHide
// anywhere in the flow, so this cannot reintroduce the old close/reopen churn bug.
static void ShowAllWidgets()
{
  ResistWidget::show();
  WidgetGold::show();
  WidgetWeight::show();
  WidgetLvl::show();
  WidgetShout::show();
  WidgetPlayTime::show();
  WidgetGameTime::show();
  WidgetEquip::show();
}

void RequestHudReconfig()
{
  g_hudNeedsConfig = true;
  logger::info("RequestHudReconfig");
}

void ConfigureHudIfNeeded()
{
  if (!g_hudNeedsConfig) {
    return;
  }
  const auto ui = RE::UI::GetSingleton();
  if (!ui) {
    return;
  }
  // Wait until the movies are actually loaded, otherwise show()/CheckInI would run
  // against a null uiMovie and we'd clear the request too early (the coc/new-game race).
  const auto equip = ui->GetMenu(WidgetEquip::MENU_NAME);
  if (!equip || !equip->uiMovie) {
    static int waitLog = 0;
    if ((waitLog++ % 120) == 0) {
      logger::info("ConfigureHudIfNeeded waiting: equipMenu={} movie={}", static_cast<bool>(equip),
        equip ? static_cast<bool>(equip->uiMovie) : false);
    }
    return;
  }

  ShowAllWidgets();
  CheckInI();
  check2(true);
  g_hudNeedsConfig = false;
  logger::info("ConfigureHudIfNeeded: movies ready -> show + CheckInI done");
}

// NOTE: the STB widgets are kAlwaysOpen overlay menus and must NEVER be closed with
// kHide/kShow during menu transitions. If a kShow is skipped, delayed, or blocked by
// a stale IsMenuOpen() state, the overlay menu stays closed and GetMenu() returns
// null forever, so both the per-frame restore in Hooks.cpp AND the hide/show hotkey
// (which Invoke widget.setVisible) silently become no-ops - the widgets are gone
// until the game is restarted. Everything below flips the movie's visual visibility
// with SetVisible via check2() only; the menu object always stays alive.

// Is any HUD-blocking menu (other than a_except) still open? DialogueMenu counts:
// while the player is in dialogue the widgets stay hidden.
static bool AnyBlockingMenuOpen(RE::UI* ui, const RE::BSFixedString& a_except)
{
  const auto stillOpen = [&](std::string_view a_menu) {
    return !(a_except == a_menu) && ui->IsMenuOpen(a_menu);
  };
  return stillOpen(RE::InventoryMenu::MENU_NAME) || stillOpen(RE::CraftingMenu::MENU_NAME) ||
         stillOpen(RE::BarterMenu::MENU_NAME) || stillOpen(RE::TweenMenu::MENU_NAME) ||
         stillOpen(RE::GiftMenu::MENU_NAME) || stillOpen(RE::ContainerMenu::MENU_NAME) ||
         stillOpen(RE::MagicMenu::MENU_NAME) || stillOpen(RE::JournalMenu::MENU_NAME) ||
         stillOpen(RE::LockpickingMenu::MENU_NAME) || stillOpen(RE::RaceSexMenu::MENU_NAME) ||
         stillOpen(RE::MapMenu::MENU_NAME) || stillOpen(RE::DialogueMenu::MENU_NAME);
}

static bool IsBlockingMenu(const RE::BSFixedString& a_name)
{
  return a_name == RE::InventoryMenu::MENU_NAME || a_name == RE::CraftingMenu::MENU_NAME ||
         a_name == RE::BarterMenu::MENU_NAME || a_name == RE::TweenMenu::MENU_NAME ||
         a_name == RE::GiftMenu::MENU_NAME || a_name == RE::ContainerMenu::MENU_NAME ||
         a_name == RE::MagicMenu::MENU_NAME || a_name == RE::JournalMenu::MENU_NAME ||
         a_name == RE::LockpickingMenu::MENU_NAME || a_name == RE::RaceSexMenu::MENU_NAME ||
         a_name == RE::MapMenu::MENU_NAME;
}

// Restore widget visibility on the NEXT UI frame. Inside a MenuOpenCloseEvent the
// closing menu (and other transient menus) can still report IsMenuOpen()==true, so
// deciding to restore right here would be based on a stale state and get skipped -
// which is the JournalMenu / TweenMenu->Map case in the bug report. One frame later
// the state is settled.
static void QueueHudRestore()
{
  const auto task = SKSE::GetTaskInterface();
  if (!task) {
    return;
  }
  task->AddTask([]() {
    auto ui = RE::UI::GetSingleton();
    if (!ui) {
      return;
    }
    if (!AnyBlockingMenuOpen(ui, RE::BSFixedString{})) {
      check2(true);
      CheckInI();
    }
  });
}

auto MenuHandler::ProcessEvent(const MenuOpenCloseEvent* event, BSTEventSource<MenuOpenCloseEvent>*) -> BSEventNotifyControl
{
  if (!event) {
    return BSEventNotifyControl::kContinue;
  }
  auto ui = RE::UI::GetSingleton();
  if (!ui) {
    return BSEventNotifyControl::kContinue;
  }

  const auto& name = event->menuName;

  // Loading screens / F9 quickload. CheckInI() must run UNCONDITIONALLY here: it is
  // what pushes each widget's position/scale/alpha/internal visibility into the movie
  // once it has finished loading. Gating it behind "no blocking menu" (as QueueHudRestore
  // does) means that if a Fader/Cursor is briefly up at that instant - which is exactly
  // the case on the first load from the main menu - the widgets never get configured and
  // stay internally invisible until a save/load cycle happens to win the timing race.
  if (name == LoadingMenu::MENU_NAME) {
    CheckInI();
    RequestHudReconfig();  // movies may still be loading; Update re-applies once ready
    if (event->opening) {
      check2(false);
    } else {
      ShowAllWidgets();  // kShow now (like the original / kPostLoadGame); coc relies on this
      check2(true);
      QueueHudRestore();  // one-frame-later safety net once the fade has cleared
    }
    return BSEventNotifyControl::kContinue;
  }

  // Full-screen / HUD-blocking menus (including Map, so opening Map from the Tween
  // menu no longer leaves the widgets stranded): hide the overlays while open,
  // restore on the next frame once the last blocking menu has closed.
  if (IsBlockingMenu(name)) {
    if (name == JournalMenu::MENU_NAME) {
      Settings::get_singleton().load(false);
    }
    if (event->opening) {
      check2(false);
    } else {
      QueueHudRestore();
    }
    return BSEventNotifyControl::kContinue;
  }

  // Transient overlays and dialogue: visual toggle only, never close the menus.
  // (kHide/kShow here used to break follower command / "favor" mode.)
  if (name == CursorMenu::MENU_NAME || name == MessageBoxMenu::MENU_NAME ||
      name == FaderMenu::MENU_NAME || name == DialogueMenu::MENU_NAME) {
    if (event->opening) {
      check2(false);
    } else {
      QueueHudRestore();
    }
  }

  return BSEventNotifyControl::kContinue;
}
