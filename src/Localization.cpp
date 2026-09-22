#include "Localization.h"
#include "PCH.h"

#include <Windows.h>
#include <filesystem>
#include <fstream>
#include <map>
#include <mutex>
#include <string>

#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

namespace Localization
{
	namespace
	{
		// std::map: node-based, c_str() pointers stay valid after insert.
		std::map<std::string, std::string> s_table;
		std::mutex s_mutex;
		bool s_loaded = false;
	}

	void Load()
	{
		std::lock_guard lock(s_mutex);
		if (s_loaded) {
			return;
		}
		s_loaded = true;

		wchar_t buf[MAX_PATH]{};
		const auto mod = GetModuleHandleW(L"STB_Widgets.dll");
		if (!mod || !GetModuleFileNameW(mod, buf, MAX_PATH)) {
			logger::warn("Localization: cannot locate module path, English UI");
			return;
		}
		std::filesystem::path p(buf);
		p.replace_extension(L".json");  // STB_Widgets.json next to the DLL

		std::ifstream in(p, std::ios::binary);
		if (!in) {
			logger::info("Localization: {} not found, English UI", p.filename().string());
			return;
		}
		std::string text((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
		if (text.size() >= 3 && static_cast<unsigned char>(text[0]) == 0xEF &&
			static_cast<unsigned char>(text[1]) == 0xBB && static_cast<unsigned char>(text[2]) == 0xBF) {
			text.erase(0, 3);  // strip UTF-8 BOM
		}

		rapidjson::Document doc;
		doc.Parse(text.c_str());
		if (doc.HasParseError()) {
			logger::warn("Localization: {} parse error (offset {}): {}, English UI", p.filename().string(),
				doc.GetErrorOffset(), rapidjson::GetParseError_En(doc.GetParseError()));
			return;
		}
		if (!doc.IsObject()) {
			logger::warn("Localization: {} root is not an object, English UI", p.filename().string());
			return;
		}
		for (auto it = doc.MemberBegin(); it != doc.MemberEnd(); ++it) {
			if (it->name.IsString() && it->value.IsString()) {
				s_table.emplace(it->name.GetString(), it->value.GetString());
			}
		}
		logger::info("Localization: loaded {} entries from {}", s_table.size(), p.filename().string());
	}

	const char* Translate(const char* a_key)
	{
		if (!a_key) {
			return "";
		}
		std::lock_guard lock(s_mutex);
		const auto it = s_table.find(a_key);
		return it != s_table.end() ? it->second.c_str() : a_key;
	}
}
