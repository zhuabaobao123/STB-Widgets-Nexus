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
		if (Checkbox(_T("Enable widget"), &Data.VisibleResist_))
					changed = true;
		if (Data.VisibleResist_) {
					if (SliderFloat(_T("Position by X"), &Data.scalexResist_, -300 * Data.SildersScale, 700 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Position by Y"), &Data.scaleyResist_, -200 * Data.SildersScale, 500 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Size"), &Data.scaleResist_, 0, 100))
					changed = true;
					if (SliderFloat(_T("Opacity"), &Data.AlphaResist_, 0, 100))
					changed = true;
					if (RadioButton(_T("First style"), &Data.ColorResist_, 1))
					changed = true;
					SameLine();
					if (RadioButton(_T("Second style"), &Data.ColorResist_, 2))
					changed = true;
					if (RadioButton(_T("Horizontal position"), &Data.PresetResist_, 1))
					changed = true;
					SameLine();
					if (RadioButton(_T("Vertical position"), &Data.PresetResist_, 2))
					changed = true;
					if (Checkbox(_T("Combat mode"), &Data.CombatResist_))
					changed = true;
					if (Checkbox(_T("Change mode"), &Data.ChangeResist_))
					changed = true;
					SameLine();
					SetNextItemWidth(50);
					if (InputFloat(_T("Change mode delay"), &Data.ChangeResistDelayBase))
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
		if (Checkbox(_T("Enable widget"), &Data.VisibleLvl_))
					changed = true;
		if (Data.VisibleLvl_) {
					if (SliderFloat(_T("Position by X"), &Data.scalexLvl_, -300 * Data.SildersScale,
							700 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Position by Y"), &Data.scaleyLvl_, -200 * Data.SildersScale,
							500 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Size"), &Data.scaleLvl_, 0, 100))
					changed = true;
					if (SliderFloat(_T("Opacity"), &Data.AlphaLvl_, 0, 100))
					changed = true;
					if (Checkbox(_T("Hide numbers"), &Data.HideLvlNumbers_))
					changed = true;
					if (Checkbox(_T("Combat mode"), &Data.CombatLvl_))
					changed = true;
					if (Checkbox(_T("Change mode"), &Data.ChangeLvl_))
					changed = true;
					SameLine();
					SetNextItemWidth(50);
					if (InputFloat(_T("Change mode delay"), &Data.ChangeLvlDelayBase))
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
		if (Checkbox(_T("Enable widget"), &Data.VisibleEquip_))
					changed = true;
		if (Data.VisibleEquip_) {
					if (SliderFloat(_T("Position by X"), &Data.scalexEquip_, -100 * Data.SildersScale, 1380 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Position by Y"), &Data.scaleyEquip_, -100 * Data.SildersScale, 820 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Size"), &Data.scaleEquip_, 0, 100))
					changed = true;
					if (SliderFloat(_T("Opacity"), &Data.AlphaEquip_, 0, 100))
					changed = true;
					if (RadioButton(_T("First style"), &Data.PresetEquip_, 1))
					changed = true;
					SameLine();
					if (RadioButton(_T("Second style"), &Data.PresetEquip_, 2))
					changed = true;
					SameLine();
					if (RadioButton(_T("Third style"), &Data.PresetEquip_, 3))
					changed = true;
					if (Checkbox(_T("Combat mode"), &Data.CombatEquip_))
					changed = true;
					if (Checkbox(_T("Change mode"), &Data.ChangeEquip_))
					changed = true;
					SameLine();
					SetNextItemWidth(50);
					if (InputFloat(_T("Change mode delay"), &Data.ChangeEquipDelayBase))
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
		if (Checkbox(_T("Enable widget"), &Data.VisibleShout_))
					changed = true;
		if (Data.VisibleShout_) {
					if (SliderFloat(_T("Position by X"), &Data.scalexShout_, -100 * Data.SildersScale,
							1380 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Position by Y"), &Data.scaleyShout_, -100 * Data.SildersScale,
							820 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Size"), &Data.scaleShout_, 0, 100))
					changed = true;
					if (SliderFloat(_T("Opacity"), &Data.AlphaShout_, 0, 100))
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
		if (Checkbox(_T("Enable widget"), &Data.VisibleGold_))
					changed = true;
		if (Data.VisibleGold_) {
					if (SliderFloat(_T("Position by X"), &Data.scalexGold_, -300 * Data.SildersScale,
							700 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Position by Y"), &Data.scaleyGold_, -200 * Data.SildersScale,
							500 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Size"), &Data.scaleGold_, 0, 100))
					changed = true;
					if (SliderFloat(_T("Opacity"), &Data.AlphaGold_, 0, 100))
					changed = true;
					if (Checkbox(_T("Combat mode"), &Data.CombatGold_))
					changed = true;
					if (Checkbox(_T("Change mode"), &Data.ChangeGold_))
					changed = true;
					SameLine();
					SetNextItemWidth(50);
					if (InputFloat(_T("Change mode delay"), &Data.ChangeGoldDelayBase))
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
		if (Checkbox(_T("Enable widget"), &Data.VisibleWeight_))
					changed = true;
		if (Data.VisibleWeight_) {
					if (SliderFloat(_T("Position by X"), &Data.scalexWeight_, -300 * Data.SildersScale,
							700 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Position by Y"), &Data.scaleyWeight_, -200 * Data.SildersScale,
							500 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Size"), &Data.scaleWeight_, 0, 100))
					changed = true;
					if (SliderFloat(_T("Opacity"), &Data.AlphaWeight_, 0, 100))
					changed = true;
					if (Checkbox(_T("Combat mode"), &Data.CombatWeight_))
					changed = true;
					if (Checkbox(_T("Change mode"), &Data.ChangeWeight_))
					changed = true;
					SameLine();
					SetNextItemWidth(50);
					if (InputFloat(_T("Change mode delay"), &Data.ChangeWeightDelayBase))
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
		if (Checkbox(_T("Enable widget"), &Data.VisibleGameTime_))
					changed = true;
		if (Data.VisibleGameTime_) {
					if (SliderFloat(_T("Position by X"), &Data.scalexGameTime_, -300 * Data.SildersScale,
							700 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Position by Y"), &Data.scaleyGameTime_, -200 * Data.SildersScale,
							500 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Size"), &Data.scaleGameTime_, 0, 100))
					changed = true;
					if (SliderFloat(_T("Opacity"), &Data.AlphaGameTime_, 0, 100))
					changed = true;
					if (RadioButton(_T("First style"), &Data.PresetGameTime_, 1))
					changed = true;
					SameLine();
					if (RadioButton(_T("Second style"), &Data.PresetGameTime_, 2))
					changed = true;
					SameLine();
					if (RadioButton(_T("Third style"), &Data.PresetGameTime_, 3))
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
		if (Checkbox(_T("Enable widget"), &Data.VisiblePlayTime_))
					changed = true;
		if (Data.VisiblePlayTime_) {
					if (SliderFloat(_T("Position by X"), &Data.scalexPlayTime_, -300 * Data.SildersScale,
							700 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Position by Y"), &Data.scaleyPlayTime_, -200 * Data.SildersScale,
							500 * Data.SildersScale))
					changed = true;
					if (SliderFloat(_T("Size"), &Data.scalePlayTime_, 0, 100))
					changed = true;
					if (SliderFloat(_T("Opacity"), &Data.AlphaPlayTime_, 0, 100))
					changed = true;
					if (RadioButton(_T("First style"), &Data.PresetPlayTime_, 1))
					changed = true;
					SameLine();
					if (RadioButton(_T("Second style"), &Data.PresetPlayTime_, 2))
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
		if (InputFloat(_T("Scale sliders for Pos Y and X"), &Data.SildersScale))
					Data.LoadToIni();
		static int clicked = 0;
		if (Button(_T("Restore default settings")))
		clicked++;
		if (clicked & 1) {
		Data.load(true);
		Data.LoadToIni();
		clicked--;
		CheckInI();
		}
		static int clicked2 = 0;
		if (Button(_T("Save settings")))
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

		SKSEMenuFramework::SetSection(_T("STB Widgets"));

		SKSEMenuFramework::AddSectionItem(_T("General"), ShowImgui);
		SKSEMenuFramework::AddSectionItem(_T("Resistances"), ShowResistances);
		SKSEMenuFramework::AddSectionItem(_T("Level"), ShowLevel);
		SKSEMenuFramework::AddSectionItem(_T("Equipment"), ShowEquipment);
		SKSEMenuFramework::AddSectionItem(_T("Shout"), ShowShout);
		SKSEMenuFramework::AddSectionItem(_T("Gold"), ShowGold);
		SKSEMenuFramework::AddSectionItem(_T("Weight"), ShowWeight);
		SKSEMenuFramework::AddSectionItem(_T("Game Time"), ShowGameTime);
		SKSEMenuFramework::AddSectionItem(_T("Play Time"), ShowPlayTime);
	}
}
