#pragma once

namespace Input
{
	using EventResult = RE::BSEventNotifyControl;

	// Listens for the configurable "hide widgets" hotkey and toggles every
	// widget on/off at once.
	class InputEventHandler : public RE::BSTEventSink<RE::InputEvent*>
	{
	public:
		EventResult ProcessEvent(RE::InputEvent* const* a_event,
			RE::BSTEventSource<RE::InputEvent*>* a_eventSource) override;

		static void Register()
		{
			auto deviceManager = RE::BSInputDeviceManager::GetSingleton();
			deviceManager->AddEventSink(InputEventHandler::GetSingleton());
		}

		static std::uint32_t GetKey(RE::BSFixedString a_event);

	private:
		static InputEventHandler* GetSingleton()
		{
			static InputEventHandler singleton;
			return std::addressof(singleton);
		}

		InputEventHandler()                                    = default;
		InputEventHandler(const InputEventHandler&)            = delete;
		InputEventHandler(InputEventHandler&&)                 = delete;
		~InputEventHandler() override                          = default;
		InputEventHandler& operator=(const InputEventHandler&) = delete;
		InputEventHandler& operator=(InputEventHandler&&)      = delete;

		static std::uint32_t GetGamepadIndex(RE::BSWin32GamepadDevice::Key a_key);

		enum : std::uint32_t
		{
			kInvalid        = static_cast<std::uint32_t>(-1),
			kKeyboardOffset = 0,
			kMouseOffset    = 256,
			kGamepadOffset  = 266
		};
	};
}
