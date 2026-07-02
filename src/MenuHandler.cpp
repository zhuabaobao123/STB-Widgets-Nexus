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
static int g_lastVisible = -1;

void check2(bool a_visible)
{
  if (g_lastVisible == static_cast<int>(a_visible)) {
    return;
  }
  g_lastVisible = static_cast<int>(a_visible);

  ResistWidget::toggle_visibility(a_visible);
  WidgetGold::toggle_visibility(a_visible);
  WidgetWeight::toggle_visibility(a_visible);
  WidgetLvl::toggle_visibility(a_visible);
  WidgetShout::toggle_visibility(a_visible);
  WidgetGameTime::toggle_visibility(a_visible);
  WidgetPlayTime::toggle_visibility(a_visible);
  WidgetEquip::toggle_visibility(a_visible);
}

void checkHide()
{
  ResistWidget::hide();
  WidgetGold::hide();
  WidgetWeight::hide();
  WidgetLvl::hide();
  WidgetShout::hide();
  WidgetPlayTime::hide();
  WidgetGameTime::hide();
  WidgetEquip::hide();
  g_lastVisible = -1;  // kHide changed the open/close state; force re-apply next check2
  logger::info("checkHide (kHide) - widget menus CLOSED");
}

void checkShow()
{
  ResistWidget::show();
  WidgetGold::show();
  WidgetWeight::show();
  WidgetLvl::show();
  WidgetShout::show();
  WidgetPlayTime::show();
  WidgetGameTime::show();
  WidgetEquip::show();
  g_lastVisible = -1;  // kShow reopened the movies (now visible); force re-apply next check2
  logger::info("checkShow (kShow) - widget menus REOPENED");
}

auto MenuHandler::ProcessEvent(const MenuOpenCloseEvent* event, BSTEventSource<MenuOpenCloseEvent>*) -> BSEventNotifyControl
{
  if (event) {
	if (auto ui = RE::UI::GetSingleton()) {
		// Is any other HUD-blocking menu (besides the one closing now) still open?
		bool otherMenuOpen = ui->IsMenuOpen(RE::InventoryMenu::MENU_NAME) || ui->IsMenuOpen(RE::CraftingMenu::MENU_NAME) ||
			                 ui->IsMenuOpen(RE::BarterMenu::MENU_NAME) || ui->IsMenuOpen(RE::TweenMenu::MENU_NAME) ||
			                 ui->IsMenuOpen(RE::GiftMenu::MENU_NAME) || ui->IsMenuOpen(RE::ContainerMenu::MENU_NAME) ||
			                 ui->IsMenuOpen(RE::MagicMenu::MENU_NAME) || ui->IsMenuOpen(RE::JournalMenu::MENU_NAME) ||
			                 ui->IsMenuOpen(RE::LockpickingMenu::MENU_NAME) || ui->IsMenuOpen(RE::RaceSexMenu::MENU_NAME) ||
			                 ui->IsMenuOpen(RE::FaderMenu::MENU_NAME);

		bool dialogueOpen = ui->IsMenuOpen(RE::DialogueMenu::MENU_NAME);

		if (event->menuName == RaceSexMenu::MENU_NAME || event->menuName == LockpickingMenu::MENU_NAME ||
			event->menuName == ContainerMenu::MENU_NAME || event->menuName == GiftMenu::MENU_NAME ||
			event->menuName == BarterMenu::MENU_NAME || event->menuName == CraftingMenu::MENU_NAME ||
			event->menuName == TweenMenu::MENU_NAME || event->menuName == MagicMenu::MENU_NAME ||
			event->menuName == InventoryMenu::MENU_NAME) {
			if (event->opening) {
				checkHide();
			} else if (!otherMenuOpen && !dialogueOpen) {
				checkShow();
			} else if (!otherMenuOpen && dialogueOpen) {
				// Re-register the widgets (kShow) but hide them visually right away.
				// When the dialogue closes, check2(true) will reveal them again.
				checkShow();
				check2(false);
			}
		}

		if (event->menuName == JournalMenu::MENU_NAME) {
			Settings::get_singleton().load(false);
			if (event->opening) {
				checkHide();
			} else if (!otherMenuOpen && !dialogueOpen) {
				checkShow();
			} else if (!otherMenuOpen && dialogueOpen) {
				checkShow();
				check2(false);
			}
		}

		if (event->menuName == LoadingMenu::MENU_NAME) {
			CheckInI();
			event->opening ? checkHide() : checkShow();
		}

		if (event->menuName == MapMenu::MENU_NAME || event->menuName == CursorMenu::MENU_NAME ||
			event->menuName == MessageBoxMenu::MENU_NAME || event->menuName == FaderMenu::MENU_NAME) {
			check2(!event->opening);
		}

		// DialogueMenu: only toggle_visibility, never hide/show.
		// Using kHide/kShow here breaks the follower command ("favor") mode.
		if (event->menuName == DialogueMenu::MENU_NAME) {
			check2(!event->opening);
		}
	}
  }
  return BSEventNotifyControl::kContinue;
}
