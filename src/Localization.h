#pragma once

namespace Localization
{
	void Load();
	[[nodiscard]] const char* Translate(const char* a_key);  // missing key -> return key itself
}
