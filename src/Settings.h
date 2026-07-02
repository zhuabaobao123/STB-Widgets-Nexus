#pragma once

#include <SimpleIni.h>
#include <iostream>
#include <fstream>




struct Settings {
private:
  Settings() = default;



  public:
  static inline bool isAtcive = false;
  
	   static inline bool VisibleResistKey{ true };
	  static inline bool VisibleGoldKey{ true };
	   static inline bool VisibleWeightKey{ true };
	  static inline bool VisibleEquipKey{ true };
	   static inline bool VisiblePlayTimeKey{ true };
	  static inline bool VisibleGameTimeKey{ true };
	   static inline bool VisibleLvlKey{ true };

	  static inline float UpdateGameTime{ 100 };
	  static inline float UpdatePlayTime{ 100 };
	  static inline float UpdateEquip{ 100 };
	  static inline float UpdateWeight{ 100 };
	  static inline float UpdateGold{ 100 };
	  static inline int offsetAmmo{ 0xbf };
	  static inline int offsetShout{ 0x4c };
	  static inline int HideKey{ 87 };
	  static inline bool enable = false;
	 static inline bool hidden = true;

	 static inline float SildersScale{ 1 };

	   float scalexResist_{ 100 };
	   float scaleyResist_{ 100 };
	   float scaleResist_{ 100 };
	   static inline float AlphaResist_{ 100 };
	   int PresetResist_{ 2 };
	   int ColorResist_{ 2 };
	   static inline bool VisibleResist_{ true };
	   static inline bool CombatResist_{ false };
	   static inline bool ChangeResist_{ false };
	   static inline float ChangeResistDelay{ 1 };
	   static inline float ChangeResistDelayBase{ 3 };

	   float scalexGold_{ 100 };
	   float scaleGold_{ 100 };
	   float scaleyGold_{ 100 };
	   static inline float AlphaGold_{ 100 };
	   static inline bool VisibleGold_{ true };
	   static inline bool CombatGold_{ false };
	   static inline bool ChangeGold_{ false };
	   static inline float ChangeGoldDelay{ 1 };
	   static inline float ChangeGoldDelayBase{ 3 };

	   float scalexWeight_{ 100 };
	   float scaleWeight_{ 100 };
	   float scaleyWeight_{ 100 };
	   static inline float AlphaWeight_{ 100 };
	   static inline bool VisibleWeight_{ true };
	   static inline bool CombatWeight_{ false };
	   static inline bool ChangeWeight_{ false };
	   static inline float ChangeWeightDelay{ 1 };
	   static inline float ChangeWeightDelayBase{ 3 };

	    float scalexLvl_{ 100 };
	   float scaleLvl_{ 100 };
		float scaleyLvl_{ 100 };
	   static inline float AlphaLvl_{ 100 };
	   static inline bool VisibleLvl_{ true };
	   static inline bool CombatLvl_{ false };
	   static inline bool ChangeLvl_{ false };
	   static inline float ChangeLvlDelay{ 1 };
	   static inline float LvlCheck[]{ 0, 0 };
	   static inline float ChangeLvlDelayBase{ 3 };

	   float scalexShout_{ 100 };
	   float scaleShout_{ 100 };
	   float scaleyShout_{ 100 };
	   float AlphaShout_{ 100 };
	   static inline bool VisibleShout_{ true };


	   	float scalexPlayTime_{ 100 };
	   float scalePlayTime_{ 100 };
	   float scaleyPlayTime_{ 100 };
	   int PresetPlayTime_{ 1 };
	   float AlphaPlayTime_{ 100 };
	   static inline bool VisiblePlayTime_{ true };

	   	   	float scalexGameTime_{ 100 };
	   float scaleGameTime_{ 100 };
	   float scaleyGameTime_{ 100 };
	   int PresetGameTime_{ 1 };
	   float AlphaGameTime_{ 100 };
	   static inline bool VisibleGameTime_{ true };


	  float scalexEquip_{ 100 };
	  float scaleEquip_{ 100 };
	  float scaleyEquip_{ 100 };
	  static inline float AlphaEquip_{ 100 };
	  int PresetEquip_{ 1 };
	  static inline bool VisibleEquip_{ true };
	  static inline bool CombatEquip_{ false };
	  static inline bool ChangeEquip_{ false };
	  static inline float ChangeEquipDelay{ 1 };
	  static inline float ChangeEquipDelayBase{ 3 };

  [[nodiscard]] static auto get_singleton() noexcept -> Settings& {
    // Function-local static: thread-safe, lazily initialised once.
    static Settings instance;
    return instance;
  }
  static inline const wchar_t* path_to_ini{ L"Data/SKSE/Plugins/STB_Widgets.ini" };

  static inline const wchar_t* section{ L"Main" };
  static inline const wchar_t* sectionbase{ L"Default" };
  static inline const wchar_t* sectionKeys{ L"Keys" };
  static inline const wchar_t* Keys{ L"OpenMenu" };
  static inline const wchar_t* Keys2{ L"HideWidgets" };


   static inline const wchar_t* fSildersScale{ L"fSildersScale" };


	  static inline const wchar_t* PosResistWidgetX{ L"fPosResistWidgetX" };
      static inline const wchar_t* ScaleResistWidget{ L"fScaleResistWidget" };
	  static inline const wchar_t* PosResistWidgetY{ L"fPosResistWidgetY" };
	  static inline const wchar_t* PresetResist{ L"iPresetResistWidget" };
	  static inline const wchar_t* ColorResist{ L"iColorResistWidget" };
	  static inline const wchar_t* AlphaResist{ L"fSetAlphaResist" };
	  static inline const wchar_t* VisibleResist{ L"SetResistVisible" };
	  static inline const wchar_t* CombatResist{ L"CombatModeResist" };
	  static inline const wchar_t* ChangeResist{ L"ChangeModeResist" };
	  static inline const wchar_t* ResistChangeDelay{ L"ResistChangeDelay" };

	  static inline const wchar_t* PosGoldWidgetX{ L"fPosGoldWidgetX" };
	  static inline const wchar_t* ScaleGoldWidget{ L"fScaleGoldWidget" };
	  static inline const wchar_t* PosGoldWidgetY{ L"fPosGoldWidgetY" };
	  static inline const wchar_t* AlphaGold{ L"fSetAlphaGold" };
	  static inline const wchar_t* VisibleGold{ L"SetGoldVisible" };
	  static inline const wchar_t* CombatGold{ L"CombatModeGold" };
	  static inline const wchar_t* ChangeGold{ L"ChangeModeGold" };
	  static inline const wchar_t* GoldChangeDelay{ L"GoldChangeDelay" };

	  static inline const wchar_t* PosWeightWidgetX{ L"fPosWeightWidgetX" };
	  static inline const wchar_t* ScaleWeightWidget{ L"fScaleWeightWidget" };
	  static inline const wchar_t* PosWeightWidgetY{ L"fPosWeightWidgetY" };
	  static inline const wchar_t* AlphaWeight{ L"fSetAlphaWeight" };
	  static inline const wchar_t* VisibleWeight{ L"SetWeightVisible" };
	  static inline const wchar_t* CombatWeight{ L"CombatModeWeight" };
	  static inline const wchar_t* ChangeWeight{ L"ChangeModeWeight" };
	  static inline const wchar_t* WeightChangeDelay{ L"WeightChangeDelay" };

	  static inline const wchar_t* PosLvlWidgetX{ L"fPosLvlWidgetX" };
	  static inline const wchar_t* ScaleLvlWidget{ L"fScaleLvlWidget" };
	  static inline const wchar_t* PosLvlWidgetY{ L"fPosLvlWidgetY" };
	  static inline const wchar_t* AlphaLvl{ L"fSetAlphaLvl" };
	  static inline const wchar_t* VisibleLvl{ L"SetLvlVisible" };
	  static inline const wchar_t* CombatLvl{ L"CombatModeLvl" };
	  static inline const wchar_t* ChangeLvl{ L"ChangeModeLvl" };
	  static inline const wchar_t* LvlChangeDelay{ L"LvlChangeDelay" };

	  static inline const wchar_t* PosShoutWidgetX{ L"fPosShoutWidgetX" };
	  static inline const wchar_t* ScaleShoutWidget{ L"fScaleShoutWidget" };
	  static inline const wchar_t* PosShoutWidgetY{ L"fPosShoutWidgetY" };
	  static inline const wchar_t* AlphaShout{ L"fSetAlphaShout" };
	  static inline const wchar_t* VisibleShout{ L"SetShoutVisible" };


	  	  	  static inline const wchar_t* PosPlayTimeWidgetX{ L"fPosPlayTimeWidgetX" };
	  static inline const wchar_t* ScalePlayTimeWidget{ L"fScalePlayTimeWidget" };
	  static inline const wchar_t* PosPlayTimeWidgetY{ L"fPosPlayTimeWidgetY" };
	  static inline const wchar_t* AlphaPlayTime{ L"fSetAlphaPlayTime" };
	  static inline const wchar_t* PresetPlayTime{ L"iPresetPlayTimeWidget" };
	  static inline const wchar_t* VisiblePlayTime{ L"SetPlayTimeVisible" };

	  	  	  	  static inline const wchar_t* PosGameTimeWidgetX{ L"fPosGameTimeWidgetX" };
	  static inline const wchar_t* ScaleGameTimeWidget{ L"fScaleGameTimeWidget" };
	  static inline const wchar_t* PosGameTimeWidgetY{ L"fPosGameTimeWidgetY" };
	  static inline const wchar_t* AlphaGameTime{ L"fSetAlphaGameTime" };
	  static inline const wchar_t* PresetGameTime{ L"iPresetGameTimeWidget" };
	  static inline const wchar_t* VisibleGameTime{ L"SetGameTimeVisible" };

	  	  static inline const wchar_t* PosEquipWidgetX{ L"fPosEquipWidgetX" };
	  static inline const wchar_t* ScaleEquipWidget{ L"fScaleEquipWidget" };
		  static inline const wchar_t* PosEquipWidgetY{ L"fPosEquipWidgetY" };
	  static inline const wchar_t* AlphaEquip{ L"fSetAlphaEquip" };
		  static inline const wchar_t* PresetEquip{ L"iSetPresetEquip" };
	  static inline const wchar_t* VisibleEquip{ L"SetEquipVisible" };
		  static inline const wchar_t* CombatEquip{ L"CombatModeEquip" };
	  static inline const wchar_t* ChangeEquip{ L"ChangeModeEquip" };
		  static inline const wchar_t* EquipChangeDelay{ L"EquipChangeDelay" };

	  	  void LoadToBaseIni()
	  {
	const auto read_settings = [this](CSimpleIni& ini, const wchar_t* path) -> void {
		ini.LoadFile(path);

		ini.SetDoubleValue(sectionbase, PosResistWidgetX, scalexResist_);
		ini.SetDoubleValue(sectionbase, PosResistWidgetY, scaleyResist_);
		ini.SetDoubleValue(sectionbase, ScaleResistWidget, scaleResist_);
		ini.SetLongValue(sectionbase, PresetResist, PresetResist_);
		ini.SetLongValue(sectionbase, ColorResist, ColorResist_);
		ini.SetDoubleValue(sectionbase, AlphaResist, AlphaResist_);
		ini.SetBoolValue(sectionbase, VisibleResist, VisibleResist_);
		ini.SetBoolValue(sectionbase, CombatResist, CombatResist_);
		ini.SetBoolValue(sectionbase, ChangeResist, ChangeResist_);
		ini.SetDoubleValue(sectionbase, ResistChangeDelay, ChangeResistDelayBase);

		ini.SetDoubleValue(sectionbase, PosGoldWidgetX, scalexGold_);
		ini.SetDoubleValue(sectionbase, PosGoldWidgetY, scaleyGold_);
		ini.SetDoubleValue(sectionbase, ScaleGoldWidget, scaleGold_);
		ini.SetDoubleValue(sectionbase, AlphaGold, AlphaGold_);
		ini.SetBoolValue(sectionbase, VisibleGold, VisibleGold_);
		ini.SetBoolValue(sectionbase, CombatGold, CombatGold_);
		ini.SetBoolValue(sectionbase, ChangeGold, ChangeGold_);
		ini.SetDoubleValue(sectionbase, GoldChangeDelay, ChangeGoldDelayBase);

		ini.SetDoubleValue(sectionbase, PosWeightWidgetX, scalexWeight_);
		ini.SetDoubleValue(sectionbase, PosWeightWidgetY, scaleyWeight_);
		ini.SetDoubleValue(sectionbase, ScaleWeightWidget, scaleWeight_);
		ini.SetDoubleValue(sectionbase, AlphaWeight, AlphaWeight_);
		ini.SetBoolValue(sectionbase, VisibleWeight, VisibleWeight_);
		ini.SetBoolValue(sectionbase, CombatWeight, CombatWeight_);
		ini.SetBoolValue(sectionbase, ChangeWeight, ChangeWeight_);
		ini.SetDoubleValue(sectionbase, WeightChangeDelay, ChangeWeightDelayBase);

		ini.SetDoubleValue(sectionbase, PosLvlWidgetX, scalexLvl_);
		ini.SetDoubleValue(sectionbase, PosLvlWidgetY, scaleyLvl_);
		ini.SetDoubleValue(sectionbase, ScaleLvlWidget, scaleLvl_);
		ini.SetDoubleValue(sectionbase, AlphaLvl, AlphaLvl_);
		ini.SetBoolValue(sectionbase, VisibleLvl, VisibleLvl_);
		ini.SetBoolValue(sectionbase, CombatLvl, CombatLvl_);
		ini.SetBoolValue(sectionbase, ChangeLvl, ChangeLvl_);
		ini.SetDoubleValue(sectionbase, LvlChangeDelay, ChangeLvlDelayBase);

		ini.SetDoubleValue(sectionbase, PosShoutWidgetX, scalexShout_);
		ini.SetDoubleValue(sectionbase, PosShoutWidgetY, scaleyShout_);
		ini.SetDoubleValue(sectionbase, ScaleShoutWidget, scaleShout_);
		ini.SetDoubleValue(sectionbase, AlphaShout, AlphaShout_);
		ini.SetBoolValue(sectionbase, VisibleShout, VisibleShout_);

		ini.SetDoubleValue(sectionbase, PosPlayTimeWidgetX, scalexPlayTime_);
		ini.SetDoubleValue(sectionbase, PosPlayTimeWidgetY, scaleyPlayTime_);
		ini.SetDoubleValue(sectionbase, ScalePlayTimeWidget, scalePlayTime_);
		ini.SetLongValue(sectionbase, PresetPlayTime, PresetPlayTime_);
		ini.SetDoubleValue(sectionbase, AlphaPlayTime, AlphaPlayTime_);
		ini.SetBoolValue(sectionbase, VisiblePlayTime, VisiblePlayTime_);

		ini.SetDoubleValue(sectionbase, PosGameTimeWidgetX, scalexGameTime_);
		ini.SetDoubleValue(sectionbase, PosGameTimeWidgetY, scaleyGameTime_);
		ini.SetDoubleValue(sectionbase, ScaleGameTimeWidget, scaleGameTime_);
		ini.SetLongValue(sectionbase, PresetGameTime, PresetGameTime_);
		ini.SetDoubleValue(sectionbase, AlphaGameTime, AlphaGameTime_);
		ini.SetBoolValue(sectionbase, VisibleGameTime, VisibleGameTime_);

		ini.SetDoubleValue(sectionbase, PosEquipWidgetX, scalexEquip_);
		ini.SetDoubleValue(sectionbase, PosEquipWidgetY, scaleyEquip_);
		ini.SetDoubleValue(sectionbase, ScaleEquipWidget, scaleEquip_);
		ini.SetDoubleValue(sectionbase, AlphaEquip, AlphaEquip_);
		ini.SetLongValue(sectionbase, PresetEquip, PresetEquip_);
		ini.SetBoolValue(sectionbase, VisibleEquip, VisibleEquip_);
		ini.SetBoolValue(sectionbase, CombatEquip, CombatEquip_);
		ini.SetBoolValue(sectionbase, ChangeEquip, ChangeEquip_);
		ini.SetDoubleValue(sectionbase, EquipChangeDelay, ChangeEquipDelayBase);



		ini.SetDoubleValue(sectionbase, fSildersScale, SildersScale);
	};

	CSimpleIni ini;

	read_settings(ini, path_to_ini);

	ini.SaveFile(path_to_ini);
	  }
	  void LoadToIni()
	  {
		  const auto read_settings = [this](CSimpleIni& ini, const wchar_t* path)
			  -> void {
			  ini.LoadFile(path);


		ini.SetDoubleValue(section, PosResistWidgetX, scalexResist_);
		ini.SetDoubleValue(section, PosResistWidgetY, scaleyResist_);
		ini.SetDoubleValue(section, ScaleResistWidget, scaleResist_);
		ini.SetLongValue(section, PresetResist, PresetResist_);
		ini.SetLongValue(section, ColorResist, ColorResist_);
		ini.SetDoubleValue(section, AlphaResist, AlphaResist_);
		ini.SetBoolValue(section, VisibleResist, VisibleResist_);
		ini.SetBoolValue(section, CombatResist, CombatResist_);
		ini.SetBoolValue(section, ChangeResist, ChangeResist_);
		ini.SetDoubleValue(section, ResistChangeDelay, ChangeResistDelayBase);

		ini.SetDoubleValue(section, PosGoldWidgetX, scalexGold_);
		ini.SetDoubleValue(section, PosGoldWidgetY, scaleyGold_);
		ini.SetDoubleValue(section, ScaleGoldWidget, scaleGold_);
		ini.SetDoubleValue(section, AlphaGold, AlphaGold_);
		ini.SetBoolValue(section, VisibleGold, VisibleGold_);
		ini.SetBoolValue(section, CombatGold, CombatGold_);
		ini.SetBoolValue(section, ChangeGold, ChangeGold_);
		ini.SetDoubleValue(section, GoldChangeDelay, ChangeGoldDelayBase);

		ini.SetDoubleValue(section, PosWeightWidgetX, scalexWeight_);
		ini.SetDoubleValue(section, PosWeightWidgetY, scaleyWeight_);
		ini.SetDoubleValue(section, ScaleWeightWidget, scaleWeight_);
		ini.SetDoubleValue(section, AlphaWeight, AlphaWeight_);
		ini.SetBoolValue(section, VisibleWeight, VisibleWeight_);
		ini.SetBoolValue(section, CombatWeight, CombatWeight_);
		ini.SetBoolValue(section, ChangeWeight, ChangeWeight_);
		ini.SetDoubleValue(section, WeightChangeDelay, ChangeWeightDelayBase);

		ini.SetDoubleValue(section, PosLvlWidgetX, scalexLvl_);
		ini.SetDoubleValue(section, PosLvlWidgetY, scaleyLvl_);
		ini.SetDoubleValue(section, ScaleLvlWidget, scaleLvl_);
		ini.SetDoubleValue(section, AlphaLvl, AlphaLvl_);
		ini.SetBoolValue(section, VisibleLvl, VisibleLvl_);
		ini.SetBoolValue(section, CombatLvl, CombatLvl_);
		ini.SetBoolValue(section, ChangeLvl, ChangeLvl_);
		ini.SetDoubleValue(section, LvlChangeDelay, ChangeLvlDelayBase);

		ini.SetDoubleValue(section, PosShoutWidgetX, scalexShout_);
		ini.SetDoubleValue(section, PosShoutWidgetY, scaleyShout_);
		ini.SetDoubleValue(section, ScaleShoutWidget, scaleShout_);
		ini.SetDoubleValue(section, AlphaShout, AlphaShout_);
		ini.SetBoolValue(section, VisibleShout, VisibleShout_);


				ini.SetDoubleValue(section, PosPlayTimeWidgetX, scalexPlayTime_);
		ini.SetDoubleValue(section, PosPlayTimeWidgetY, scaleyPlayTime_);
		ini.SetDoubleValue(section, ScalePlayTimeWidget, scalePlayTime_);
		ini.SetLongValue(section, PresetPlayTime, PresetPlayTime_);
		ini.SetDoubleValue(section, AlphaPlayTime, AlphaPlayTime_);
		ini.SetBoolValue(section, VisiblePlayTime, VisiblePlayTime_);

						ini.SetDoubleValue(section, PosGameTimeWidgetX, scalexGameTime_);
		ini.SetDoubleValue(section, PosGameTimeWidgetY, scaleyGameTime_);
		ini.SetDoubleValue(section, ScaleGameTimeWidget, scaleGameTime_);
		ini.SetLongValue(section, PresetGameTime, PresetGameTime_);
		ini.SetDoubleValue(section, AlphaGameTime, AlphaGameTime_);
		ini.SetBoolValue(section, VisibleGameTime, VisibleGameTime_);




		ini.SetDoubleValue(section, PosEquipWidgetX, scalexEquip_);
		ini.SetDoubleValue(section, PosEquipWidgetY, scaleyEquip_);
		ini.SetDoubleValue(section, ScaleEquipWidget, scaleEquip_);
		ini.SetDoubleValue(section, AlphaEquip, AlphaEquip_);
		ini.SetLongValue(section, PresetEquip, PresetEquip_);
		ini.SetBoolValue(section, VisibleEquip, VisibleEquip_);
		ini.SetBoolValue(section, CombatEquip, CombatEquip_);
		ini.SetBoolValue(section, ChangeEquip, ChangeEquip_);
		ini.SetDoubleValue(section, EquipChangeDelay, ChangeEquipDelayBase);

		ini.SetDoubleValue(section, fSildersScale, SildersScale);

	};

	CSimpleIni ini;

	read_settings(ini, path_to_ini);

	ini.SaveFile(path_to_ini);

	 }

  auto load(bool based) -> void {
	const auto read_Key = [this](const CSimpleIni& ini, const wchar_t* key, int& value) -> void {
		if (ini.GetValue(sectionKeys, key)) {
			value = ini.GetLongValue(sectionKeys, key);
		}
	};
	if (based) {

	  const auto read_double = [this](const CSimpleIni& ini, const wchar_t* key, float& value) -> void {
		  if (ini.GetValue(sectionbase, key)) {
			  value = static_cast<float>(ini.GetDoubleValue(sectionbase, key));
		  }
	  };
	  const auto read_int = [this](const CSimpleIni& ini, const wchar_t* key, int& value) -> void {
		  if (ini.GetValue(sectionbase, key)) {
			  value = ini.GetLongValue(sectionbase, key);
		  }
	  };
	  const auto read_bool = [this](const CSimpleIni& ini, const wchar_t* key, bool& value) -> void {
		  if (ini.GetValue(sectionbase, key)) {
			  value = ini.GetBoolValue(sectionbase, key);
		  }
	  };
	  const auto read_settings = [this, read_int, read_bool, read_double, read_Key](CSimpleIni& ini,
									 const wchar_t* path) -> void {
		  ini.LoadFile(path);


		 // read_Key(ini, Keys, ImguiKey);
		  read_Key(ini, Keys2, HideKey);
		  read_double(ini, PosResistWidgetX, scalexResist_);
		  read_double(ini, PosResistWidgetY, scaleyResist_);
		  read_double(ini, ScaleResistWidget, scaleResist_);
		  read_int(ini, PresetResist, PresetResist_);
		  read_int(ini, ColorResist, ColorResist_);
		  read_double(ini, AlphaResist, AlphaResist_);
		  read_bool(ini, VisibleResist, VisibleResist_);
		  read_bool(ini, CombatResist, CombatResist_);
		  read_bool(ini, ChangeResist, ChangeResist_);
		  read_double(ini, ResistChangeDelay, ChangeResistDelayBase);

		  read_double(ini, PosGoldWidgetX, scalexGold_);
		  read_double(ini, PosGoldWidgetY, scaleyGold_);
		  read_double(ini, ScaleGoldWidget, scaleGold_);
		  read_double(ini, AlphaGold, AlphaGold_);
		  read_bool(ini, VisibleGold, VisibleGold_);
		  read_bool(ini, CombatGold, CombatGold_);
		  read_bool(ini, ChangeGold, ChangeGold_);
		  read_double(ini, GoldChangeDelay, ChangeGoldDelayBase);

		  read_double(ini, PosWeightWidgetX, scalexWeight_);
		  read_double(ini, PosWeightWidgetY, scaleyWeight_);
		  read_double(ini, ScaleWeightWidget, scaleWeight_);
		  read_double(ini, AlphaWeight, AlphaWeight_);
		  read_bool(ini, VisibleWeight, VisibleWeight_);
		  read_bool(ini, CombatWeight, CombatWeight_);
		  read_bool(ini, ChangeWeight, ChangeWeight_);
		  read_double(ini, WeightChangeDelay, ChangeWeightDelayBase);

		  read_double(ini, PosLvlWidgetX, scalexLvl_);
		  read_double(ini, PosLvlWidgetY, scaleyLvl_);
		  read_double(ini, ScaleLvlWidget, scaleLvl_);
		  read_double(ini, AlphaLvl, AlphaLvl_);
		  read_bool(ini, VisibleLvl, VisibleLvl_);
		  read_bool(ini, CombatLvl, CombatLvl_);
		  read_bool(ini, ChangeLvl, ChangeLvl_);
		  read_double(ini, LvlChangeDelay, ChangeLvlDelayBase);

		   read_double(ini, PosShoutWidgetX, scalexShout_);
		  read_double(ini, PosShoutWidgetY, scaleyShout_);
		  read_double(ini, ScaleShoutWidget, scaleShout_);
		  read_double(ini, AlphaShout, AlphaShout_);
		  read_bool(ini, VisibleShout, VisibleShout_);


		  		  		  read_double(ini, PosPlayTimeWidgetX, scalexPlayTime_);
		  read_double(ini, PosPlayTimeWidgetY, scaleyPlayTime_);
		  read_double(ini, ScalePlayTimeWidget, scalePlayTime_);
		  read_int(ini, PresetPlayTime, PresetPlayTime_);
		  read_double(ini, AlphaPlayTime, AlphaPlayTime_);
		  read_bool(ini, VisiblePlayTime, VisiblePlayTime_);

		  read_double(ini, PosGameTimeWidgetX, scalexGameTime_);
		  read_double(ini, PosGameTimeWidgetY, scaleyGameTime_);
		  read_double(ini, ScaleGameTimeWidget, scaleGameTime_);
		  read_int(ini, PresetGameTime, PresetGameTime_);
		  read_double(ini, AlphaGameTime, AlphaGameTime_);
		  read_bool(ini, VisibleGameTime, VisibleGameTime_);

		  


		  read_double(ini, PosEquipWidgetX, scalexEquip_);
		  read_double(ini, PosEquipWidgetY, scaleyEquip_);
		  read_double(ini, ScaleEquipWidget, scaleEquip_);
		  read_int(ini, PresetEquip, PresetEquip_);
		  read_double(ini, AlphaEquip, AlphaEquip_);
		  read_bool(ini, VisibleEquip, VisibleEquip_);
		  read_bool(ini, CombatEquip, CombatEquip_);
		  read_bool(ini, ChangeEquip, ChangeEquip_);
		  read_double(ini, EquipChangeDelay, ChangeEquipDelayBase);

		   read_double(ini, fSildersScale, SildersScale);
	  };
	  CSimpleIni ini;
	  ini.SetUnicode();

	  read_settings(ini, path_to_ini);
	} else {
	  const auto read_double = [this](const CSimpleIni& ini, const wchar_t* key, float& value) -> void {
		  if (ini.GetValue(section, key)) {
			  value = static_cast<float>(ini.GetDoubleValue(section, key));
		  }
	  };
	  const auto read_int = [this](const CSimpleIni& ini, const wchar_t* key, int& value) -> void {
		  if (ini.GetValue(section, key)) {
			  value = ini.GetLongValue(section, key);
		  }
	  };
	  const auto read_bool = [this](const CSimpleIni& ini, const wchar_t* key, bool& value) -> void {
		  if (ini.GetValue(section, key)) {
			  value = ini.GetBoolValue(section, key);
		  }
	  };
	  const auto read_settings = [this, read_int, read_bool, read_double, read_Key](CSimpleIni& ini,
									 const wchar_t* path) -> void {
		  ini.LoadFile(path);

		 // read_Key(ini, Keys, ImguiKey);
		  read_Key(ini, Keys2, HideKey);
		  read_double(ini, PosResistWidgetX, scalexResist_);
		  read_double(ini, PosResistWidgetY, scaleyResist_);
		  read_double(ini, ScaleResistWidget, scaleResist_);
		  read_int(ini, PresetResist, PresetResist_);
		  read_int(ini, ColorResist, ColorResist_);
		  read_double(ini, AlphaResist, AlphaResist_);
		  read_bool(ini, VisibleResist, VisibleResist_);
		  read_bool(ini, CombatResist, CombatResist_);
		  read_bool(ini, ChangeResist, ChangeResist_);
		  read_double(ini, ResistChangeDelay, ChangeResistDelayBase);

		  read_double(ini, PosGoldWidgetX, scalexGold_);
		  read_double(ini, PosGoldWidgetY, scaleyGold_);
		  read_double(ini, ScaleGoldWidget, scaleGold_);
		  read_double(ini, AlphaGold, AlphaGold_);
		  read_bool(ini, VisibleGold, VisibleGold_);
		  read_bool(ini, CombatGold, CombatGold_);
		  read_bool(ini, ChangeGold, ChangeGold_);
		  read_double(ini, GoldChangeDelay, ChangeGoldDelayBase);

		  read_double(ini, PosWeightWidgetX, scalexWeight_);
		  read_double(ini, PosWeightWidgetY, scaleyWeight_);
		  read_double(ini, ScaleWeightWidget, scaleWeight_);
		  read_double(ini, AlphaWeight, AlphaWeight_);
		  read_bool(ini, VisibleWeight, VisibleWeight_);
		  read_bool(ini, CombatWeight, CombatWeight_);
		  read_bool(ini, ChangeWeight, ChangeWeight_);
		  read_double(ini, WeightChangeDelay, ChangeWeightDelayBase);

		  read_double(ini, PosLvlWidgetX, scalexLvl_);
		  read_double(ini, PosLvlWidgetY, scaleyLvl_);
		  read_double(ini, ScaleLvlWidget, scaleLvl_);
		  read_double(ini, AlphaLvl, AlphaLvl_);
		  read_bool(ini, VisibleLvl, VisibleLvl_);
		  read_bool(ini, CombatLvl, CombatLvl_);
		  read_bool(ini, ChangeLvl, ChangeLvl_);
		  read_double(ini, LvlChangeDelay, ChangeLvlDelayBase);

		  read_double(ini, PosShoutWidgetX, scalexShout_);
		  read_double(ini, PosShoutWidgetY, scaleyShout_);
		  read_double(ini, ScaleShoutWidget, scaleShout_);
		  read_double(ini, AlphaShout, AlphaShout_);
		  read_bool(ini, VisibleShout, VisibleShout_);

		  read_double(ini, PosPlayTimeWidgetX, scalexPlayTime_);
		  read_double(ini, PosPlayTimeWidgetY, scaleyPlayTime_);
		  read_double(ini, ScalePlayTimeWidget, scalePlayTime_);
		  read_int(ini, PresetPlayTime, PresetPlayTime_);
		  read_double(ini, AlphaPlayTime, AlphaPlayTime_);
		  read_bool(ini, VisiblePlayTime, VisiblePlayTime_);

		  read_double(ini, PosGameTimeWidgetX, scalexGameTime_);
		  read_double(ini, PosGameTimeWidgetY, scaleyGameTime_);
		  read_double(ini, ScaleGameTimeWidget, scaleGameTime_);
		  read_int(ini, PresetGameTime, PresetGameTime_);
		  read_double(ini, AlphaGameTime, AlphaGameTime_);
		  read_bool(ini, VisibleGameTime, VisibleGameTime_);

		  read_double(ini, PosEquipWidgetX, scalexEquip_);
		  read_double(ini, PosEquipWidgetY, scaleyEquip_);
		  read_double(ini, ScaleEquipWidget, scaleEquip_);
		  read_int(ini, PresetEquip, PresetEquip_);
		  read_double(ini, AlphaEquip, AlphaEquip_);
		  read_bool(ini, VisibleEquip, VisibleEquip_);
		  read_bool(ini, CombatEquip, CombatEquip_);
		  read_bool(ini, ChangeEquip, ChangeEquip_);
		  read_double(ini, EquipChangeDelay, ChangeEquipDelayBase);

		  read_double(ini, fSildersScale, SildersScale);

	  };

	  CSimpleIni ini;

	  ini.SetUnicode();
	  read_settings(ini, path_to_ini);
	}
  }
};
