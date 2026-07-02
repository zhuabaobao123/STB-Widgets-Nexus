#include "WidgetWeight.h"
#include "Settings.h"

using namespace RE;

WidgetWeight::WidgetWeight()
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

auto WidgetWeight::register_() -> void
{
  if (const auto ui = RE::UI::GetSingleton()) {
    ui->Register(MENU_NAME, creator);
    logger::info("Register menu");
    show();
  }
}

auto WidgetWeight::show() -> void
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

auto WidgetWeight::hide() -> void
{
  if (const auto message_queue = RE::UIMessageQueue::GetSingleton()) {
    logger::debug("Hide menu");
    message_queue->AddMessage(MENU_NAME, RE::UI_MESSAGE_TYPE::kHide, nullptr);
  }
}

int GetNormValue(float a) {
  double num = a;
  int result;

  if (num - static_cast<int>(num) >= 0.5) {
	result = static_cast<int>(num) + 1;
  } else {
	result = static_cast<int>(num);
  }
  return result;
}

auto WidgetWeight::update() -> void
{

  const auto ui = RE::UI::GetSingleton();
  if (!ui || ui->GameIsPaused()) {
    return;
  }

  const auto widgetweight = ui->GetMenu(MENU_NAME);
  if (!widgetweight || !widgetweight->uiMovie) {
    return;
  }

  const auto player = RE::PlayerCharacter::GetSingleton();
  if (!player) {
    return;
  }

  std::string result =
	  std::to_string(GetNormValue(player->AsActorValueOwner()->GetActorValue(RE::ActorValue::kInventoryWeight))) + "/" +
	  std::to_string(GetNormValue(player->AsActorValueOwner()->GetActorValue(RE::ActorValue::kCarryWeight)));

  const RE::GFxValue weight{ static_cast<RE::BSFixedString>(result) };
  widgetweight->uiMovie->Invoke("widget.Update", nullptr, &weight, 1);
}

void WidgetWeight::AdvanceMovie(const float interval, const uint32_t current_time)
{
  logger::debug("AdvanceMovie");
  if (Settings::VisibleWeight_ && Settings::VisibleEquipKey)
  update();
  IMenu::AdvanceMovie(interval, current_time);
}

auto WidgetWeight::toggle_visibility(const bool mode) -> void
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
