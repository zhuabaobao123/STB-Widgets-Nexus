#include "Serialization.h"
#include "WidgetEquip.h"

using namespace RE;

void SaveCallback(SKSE::SerializationInterface* a_intfc)
{
	bool ok;
	auto hp = WidgetEquip::LastUseHP ? WidgetEquip::LastUseHP->formID : 0u;
	auto st = WidgetEquip::LastUseST ? WidgetEquip::LastUseST->formID : 0u;
	auto mp = WidgetEquip::LastUseMP ? WidgetEquip::LastUseMP->formID : 0u;

	ok = a_intfc->WriteRecord('DAT1', 314, &hp, sizeof(hp));
	assert(ok);
	ok = a_intfc->WriteRecord('DAT2', 314, &st, sizeof(st));
	assert(ok);
	ok = a_intfc->WriteRecord('DAT3', 314, &mp, sizeof(mp));
	assert(ok);
}

void LoadCallback(SKSE::SerializationInterface* a_intfc)
{
	bool ok;
	FormID ID;
	uint32_t type;
	uint32_t version;
	uint32_t length;
	while (a_intfc->GetNextRecordInfo(type, version, length)) {
		assert(version == 314);
		switch (type) {
		case 'DAT1':
				ok = a_intfc->ReadRecordData(ID);
				if (ok) {
					FormID newID;
					if (a_intfc->ResolveFormID(ID, newID)) {
						WidgetEquip::LastUseHP = TESForm::LookupByID<AlchemyItem>(newID);
					} else {
						WidgetEquip::LastUseHP = nullptr;
					}
				}
				break;
		case 'DAT2':
				ok = a_intfc->ReadRecordData(ID);
				if (ok) {
					FormID newID;
					if (a_intfc->ResolveFormID(ID, newID)) {
						WidgetEquip::LastUseST = TESForm::LookupByID<AlchemyItem>(newID);
					} else {
						WidgetEquip::LastUseST = nullptr;
					}
				}
				break;
		case 'DAT3':
				ok = a_intfc->ReadRecordData(ID);
				if (ok) {
					FormID newID;
					if (a_intfc->ResolveFormID(ID, newID)) {
						WidgetEquip::LastUseMP = TESForm::LookupByID<AlchemyItem>(newID);
					} else {
						WidgetEquip::LastUseMP = nullptr;
					}
				}
				break;
		default:
				assert(false);
				break;
		}
	}

}

void RevertCallback(SKSE::SerializationInterface*)
{
	WidgetEquip::LastUseHP = nullptr;
	WidgetEquip::LastUseST = nullptr;
	WidgetEquip::LastUseMP = nullptr;
}

void SetupSerialization()
{
	auto serialization = SKSE::GetSerializationInterface();
	serialization->SetUniqueID(0xfb37673);
	serialization->SetSaveCallback(SaveCallback);
	serialization->SetLoadCallback(LoadCallback);
	serialization->SetRevertCallback(RevertCallback);
}
