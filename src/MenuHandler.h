#pragma once
void check2(bool opening);

// Marks that the widgets need their settings (position/scale/alpha/visibility)
// re-pushed once their movies have finished loading. Called on loading screens.
void RequestHudReconfig();

// Called every frame from the player Update hook. Once the widget movies are
// actually loaded, runs CheckInI() exactly once to configure them, then clears the
// request. This is what makes the widgets appear after `coc`/new game, where the
// movies are still loading when the loading screen closes.
void ConfigureHudIfNeeded();
struct MenuHandler final : public RE::BSTEventSink<RE::MenuOpenCloseEvent>
{
public:
  [[nodiscard]] static auto get_singleton() noexcept -> MenuHandler*;
  static auto               register_() -> void;

  auto ProcessEvent(const RE::MenuOpenCloseEvent*               event,
                    RE::BSTEventSource<RE::MenuOpenCloseEvent>* event_source)
      -> RE::BSEventNotifyControl override;
};
