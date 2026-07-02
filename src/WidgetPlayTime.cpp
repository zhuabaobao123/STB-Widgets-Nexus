#include "WidgetPlayTime.h"
#include "Settings.h"


WidgetPlayTime::WidgetPlayTime()
{
  const auto scale_form_manager = RE::BSScaleformManager::GetSingleton();

  logger::info("Construct menu");

  inputContext  = Context::kNone;
  depthPriority = 0;

  menuFlags.set(RE::UI_MENU_FLAGS::kAlwaysOpen);
  menuFlags.set(RE::UI_MENU_FLAGS::kRequiresUpdate);
  menuFlags.set(RE::UI_MENU_FLAGS::kAllowSaving);

  if (uiMovie) {
    uiMovie->SetMouseCursorCount(0);
  }

  scale_form_manager->LoadMovieEx(this, MENU_PATH, [](RE::GFxMovieDef* def) -> void {
    def->SetState(RE::GFxState::StateType::kLog, RE::make_gptr<WidgetLogger>().get());
  });
}

auto WidgetPlayTime::register_() -> void
{
  if (const auto ui = RE::UI::GetSingleton()) {
    ui->Register(MENU_NAME, creator);
    logger::info("Register menu");
    show();
  }
}

auto WidgetPlayTime::show() -> void
{
  if (const auto message_queue = RE::UIMessageQueue::GetSingleton()) {
	if (auto ui = RE::UI::GetSingleton();  !ui->GetMenu(RE::TweenMenu::MENU_NAME) &&
										  !ui->GetMenu(RE::BarterMenu::MENU_NAME) && !ui->GetMenu(RE::ContainerMenu::MENU_NAME) &&
										  !ui->GetMenu(RE::MapMenu::MENU_NAME) &&
										  !ui->GetMenu(RE::InventoryMenu::MENU_NAME) && !ui->GetMenu(RE::GiftMenu::MENU_NAME)) {
		logger::debug("Show menu");
		message_queue->AddMessage(MENU_NAME, RE::UI_MESSAGE_TYPE::kShow, nullptr);
	}
  }
}

auto WidgetPlayTime::hide() -> void
{
  if (const auto message_queue = RE::UIMessageQueue::GetSingleton()) {
    logger::debug("Hide menu");
    message_queue->AddMessage(MENU_NAME, RE::UI_MESSAGE_TYPE::kHide, nullptr);
  }
}
float GetRealTime()
{
  using func_t = decltype(GetRealTime);
  REL::Relocation<func_t> func{ REL::ID(56455) };
  return func();
}

auto WidgetPlayTime::update() -> void
{

  const auto ui = RE::UI::GetSingleton();
  if (!ui || ui->GameIsPaused()) {
    return;
  }

  const auto widgettime = ui->GetMenu(MENU_NAME);
  if (!widgettime || !widgettime->uiMovie) {
    return;
  }

  const auto player = RE::PlayerCharacter::GetSingleton();
  if (!player) {
    return;
  }
  std::string result = std::to_string(player->GetInfoRuntimeData().totalPlayingTime / 1000000.0 / 3.6);
  //RE::ConsoleLog::GetSingleton()->Print(std::to_string(player->totalPlayingTime).c_str());
  const RE::GFxValue time{ result };
  widgettime->uiMovie->Invoke("widget.Update", nullptr, &time, 1);
}

void WidgetPlayTime::AdvanceMovie(const float interval, const uint32_t current_time)
{
  logger::debug("AdvanceMovie");
  if (Settings::VisiblePlayTime_ && Settings::VisibleEquipKey && Settings::UpdatePlayTime >= 1) {
	update();
	Settings::UpdatePlayTime = 0;
  }
  IMenu::AdvanceMovie(interval, current_time);
}

auto WidgetPlayTime::toggle_visibility(const bool mode) -> void
{
  const auto ui = RE::UI::GetSingleton();
  if (!ui) {
    return;
  }

  const auto overlay_menu = ui->GetMenu(MENU_NAME);
  if (!overlay_menu || !overlay_menu->uiMovie) {
    return;
  }

  overlay_menu->uiMovie->SetVisible(mode);
}
