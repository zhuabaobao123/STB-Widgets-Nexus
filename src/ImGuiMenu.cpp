#include "ImGuiMenu.h"
#include "Settings.h"
#include "WidgetManager.h"  // CheckInI

#include "SKSEMenuFramework.h"
#include <string>

namespace SKSE_Menu
{
	using namespace ImGuiMCP;

	void __stdcall ShowResistances()
	{
		auto& Data = Settings::get_singleton();
		bool changed = false;
		if (Checkbox("Enable widget", &Data.VisibleResist_))
					changed = true;
		if (Data.VisibleResist_) {
					if (SliderFloat("Position by X", &Data.scalexResist_, -300 * Data.SildersScale, 700 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Position by Y", &Data.scaleyResist_, -200 * Data.SildersScale, 500 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Size", &Data.scaleResist_, 0, 100))
					changed = true;
					if (SliderFloat("Opacity", &Data.AlphaResist_, 0, 100))
					changed = true;
					if (RadioButton("First style", &Data.ColorResist_, 1))
					changed = true;
					SameLine();
					if (RadioButton("Second style", &Data.ColorResist_, 2))
					changed = true;
					if (RadioButton("Horizontal position", &Data.PresetResist_, 1))
					changed = true;
					SameLine();
					if (RadioButton("Vertical position", &Data.PresetResist_, 2))
					changed = true;
					if (Checkbox("Combat mode", &Data.CombatResist_))
					changed = true;
					if (Checkbox("Change mode", &Data.ChangeResist_))
					changed = true;
					SameLine();
					SetNextItemWidth(50);
					if (InputFloat("Change mode delay", &Data.ChangeResistDelayBase))
					changed = true;
		}
		if (changed) {
					CheckInI();
					Data.LoadToIni();
		}
	}
	void __stdcall ShowLevel()
	{
		auto& Data = Settings::get_singleton();
		bool changed = false;
		if (Checkbox("Enable widget", &Data.VisibleLvl_))
					changed = true;
		if (Data.VisibleLvl_) {
					if (SliderFloat("Position by X", &Data.scalexLvl_, -300 * Data.SildersScale,
							700 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Position by Y", &Data.scaleyLvl_, -200 * Data.SildersScale,
							500 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Size", &Data.scaleLvl_, 0, 100))
					changed = true;
					if (SliderFloat("Opacity", &Data.AlphaLvl_, 0, 100))
					changed = true;
					if (Checkbox("Hide numbers", &Data.HideLvlNumbers_))
					changed = true;
					if (Checkbox("Combat mode", &Data.CombatLvl_))
					changed = true;
					if (Checkbox("Change mode", &Data.ChangeLvl_))
					changed = true;
					SameLine();
					SetNextItemWidth(50);
					if (InputFloat("Change mode delay", &Data.ChangeLvlDelayBase))
					changed = true;
		}
		if (changed) {
					CheckInI();
					Data.LoadToIni();
		}
	}
	void __stdcall ShowEquipment()
	{
		auto& Data = Settings::get_singleton();
		bool changed = false;
		if (Checkbox("Enable widget", &Data.VisibleEquip_))
					changed = true;
		if (Data.VisibleEquip_) {
					if (SliderFloat("Position by X", &Data.scalexEquip_, -100 * Data.SildersScale, 1380 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Position by Y", &Data.scaleyEquip_, -100 * Data.SildersScale, 820 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Size", &Data.scaleEquip_, 0, 100))
					changed = true;
					if (SliderFloat("Opacity", &Data.AlphaEquip_, 0, 100))
					changed = true;
					if (RadioButton("First style", &Data.PresetEquip_, 1))
					changed = true;
					SameLine();
					if (RadioButton("Second style", &Data.PresetEquip_, 2))
					changed = true;
					SameLine();
					if (RadioButton("Third style", &Data.PresetEquip_, 3))
					changed = true;
					if (Checkbox("Combat mode", &Data.CombatEquip_))
					changed = true;
					if (Checkbox("Change mode", &Data.ChangeEquip_))
					changed = true;
					SameLine();
					SetNextItemWidth(50);
					if (InputFloat("Change mode delay", &Data.ChangeEquipDelayBase))
					changed = true;
		}
		if (changed) {
					CheckInI();
					Data.LoadToIni();
		}
	}
	void __stdcall ShowShout()
	{
		auto& Data = Settings::get_singleton();
		bool changed = false;
		if (Checkbox("Enable widget", &Data.VisibleShout_))
					changed = true;
		if (Data.VisibleShout_) {
					if (SliderFloat("Position by X", &Data.scalexShout_, -100 * Data.SildersScale,
							1380 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Position by Y", &Data.scaleyShout_, -100 * Data.SildersScale,
							820 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Size", &Data.scaleShout_, 0, 100))
					changed = true;
					if (SliderFloat("Opacity", &Data.AlphaShout_, 0, 100))
					changed = true;
		}
		if (changed) {
					CheckInI();
					Data.LoadToIni();
		}
	}
	void __stdcall ShowGold()
	{
		auto& Data = Settings::get_singleton();
		bool changed = false;
		if (Checkbox("Enable widget", &Data.VisibleGold_))
					changed = true;
		if (Data.VisibleGold_) {
					if (SliderFloat("Position by X", &Data.scalexGold_, -300 * Data.SildersScale,
							700 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Position by Y", &Data.scaleyGold_, -200 * Data.SildersScale,
							500 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Size", &Data.scaleGold_, 0, 100))
					changed = true;
					if (SliderFloat("Opacity", &Data.AlphaGold_, 0, 100))
					changed = true;
					if (Checkbox("Combat mode", &Data.CombatGold_))
					changed = true;
					if (Checkbox("Change mode", &Data.ChangeGold_))
					changed = true;
					SameLine();
					SetNextItemWidth(50);
					if (InputFloat("Change mode delay", &Data.ChangeGoldDelayBase))
					changed = true;
		}
		if (changed) {
					CheckInI();
					Data.LoadToIni();
		}
	}
	void __stdcall ShowWeight()
	{
		auto& Data = Settings::get_singleton();
		bool changed = false;
		if (Checkbox("Enable widget", &Data.VisibleWeight_))
					changed = true;
		if (Data.VisibleWeight_) {
					if (SliderFloat("Position by X", &Data.scalexWeight_, -300 * Data.SildersScale,
							700 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Position by Y", &Data.scaleyWeight_, -200 * Data.SildersScale,
							500 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Size", &Data.scaleWeight_, 0, 100))
					changed = true;
					if (SliderFloat("Opacity", &Data.AlphaWeight_, 0, 100))
					changed = true;
					if (Checkbox("Combat mode", &Data.CombatWeight_))
					changed = true;
					if (Checkbox("Change mode", &Data.ChangeWeight_))
					changed = true;
					SameLine();
					SetNextItemWidth(50);
					if (InputFloat("Change mode delay", &Data.ChangeWeightDelayBase))
					changed = true;
		}
		if (changed) {
					CheckInI();
					Data.LoadToIni();
		}
	}
	void __stdcall ShowGameTime()
	{
		auto& Data = Settings::get_singleton();
		bool changed = false;
		if (Checkbox("Enable widget", &Data.VisibleGameTime_))
					changed = true;
		if (Data.VisibleGameTime_) {
					if (SliderFloat("Position by X", &Data.scalexGameTime_, -300 * Data.SildersScale,
							700 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Position by Y", &Data.scaleyGameTime_, -200 * Data.SildersScale,
							500 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Size", &Data.scaleGameTime_, 0, 100))
					changed = true;
					if (SliderFloat("Opacity", &Data.AlphaGameTime_, 0, 100))
					changed = true;
					if (RadioButton("First style", &Data.PresetGameTime_, 1))
					changed = true;
					SameLine();
					if (RadioButton("Second style", &Data.PresetGameTime_, 2))
					changed = true;
					SameLine();
					if (RadioButton("Third style", &Data.PresetGameTime_, 3))
					changed = true;
		}
		if (changed) {
					CheckInI();
					Data.LoadToIni();
		}
	}
	void __stdcall ShowPlayTime()
	{
		auto& Data = Settings::get_singleton();
		bool changed = false;
		if (Checkbox("Enable widget", &Data.VisiblePlayTime_))
					changed = true;
		if (Data.VisiblePlayTime_) {
					if (SliderFloat("Position by X", &Data.scalexPlayTime_, -300 * Data.SildersScale,
							700 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Position by Y", &Data.scaleyPlayTime_, -200 * Data.SildersScale,
							500 * Data.SildersScale))
					changed = true;
					if (SliderFloat("Size", &Data.scalePlayTime_, 0, 100))
					changed = true;
					if (SliderFloat("Opacity", &Data.AlphaPlayTime_, 0, 100))
					changed = true;
					if (RadioButton("First style", &Data.PresetPlayTime_, 1))
					changed = true;
					SameLine();
					if (RadioButton("Second style", &Data.PresetPlayTime_, 2))
					changed = true;
		}
		if (changed) {
					CheckInI();
					Data.LoadToIni();
		}
	}
	void __stdcall ShowImgui()
	{
		auto& Data = Settings::get_singleton();
		if (InputFloat("Scale sliders for Pos Y and X", &Data.SildersScale))
					Data.LoadToIni();
		static int clicked = 0;
		if (Button("Restore default settings"))
		clicked++;
		if (clicked & 1) {
		Data.load(true);
		Data.LoadToIni();
		clicked--;
		CheckInI();
		}
		static int clicked2 = 0;
		if (Button("Save settings"))
		clicked2++;
		if (clicked2 & 1) {
		Data.LoadToBaseIni();
		clicked2--;
		}
		Separator();
	}
	void register_skse_menu()
	{
		if (!SKSEMenuFramework::IsInstalled()) {
		logger::warn("SKSEMenuFramework not installed");
		return;
		}

		static constexpr auto main_title = "STB Widgets";
		SKSEMenuFramework::SetSection(main_title);

		static constexpr auto settings_title = "General";
		SKSEMenuFramework::AddSectionItem(settings_title, ShowImgui);
		static constexpr auto settings_title2 = "Resistances";
		SKSEMenuFramework::AddSectionItem(settings_title2, ShowResistances);
		static constexpr auto settings_title3 = "Level";
		SKSEMenuFramework::AddSectionItem(settings_title3, ShowLevel);
		static constexpr auto settings_title4 = "Equipment";
		SKSEMenuFramework::AddSectionItem(settings_title4, ShowEquipment);
		static constexpr auto settings_title5 = "Shout";
		SKSEMenuFramework::AddSectionItem(settings_title5, ShowShout);
		static constexpr auto settings_title6 = "Gold";
		SKSEMenuFramework::AddSectionItem(settings_title6, ShowGold);
		static constexpr auto settings_title7 = "Weight";
		SKSEMenuFramework::AddSectionItem(settings_title7, ShowWeight);
		static constexpr auto settings_title8 = "Game Time";
		SKSEMenuFramework::AddSectionItem(settings_title8, ShowGameTime);
		static constexpr auto settings_title9 = "Play Time";
		SKSEMenuFramework::AddSectionItem(settings_title9, ShowPlayTime);
	}
}
