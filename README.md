# STB Widgets - Localization

Multi-language localization fork of **STB Widgets**: a set of customizable SKSE
HUD widgets for Skyrim Special Edition / Anniversary Edition (equipment,
level/XP, gold, weight, resistances, shout meter, game time, play time).

Built as an SKSE plugin against **CommonLibSSE-NG**. This fork adds a runtime
I18n layer (interface strings are loaded from `STB_Widgets.json` next to the
DLL) and ports the code to CommonLibSSE-NG v9 for Skyrim 1.7.104 support.

Supported languages: English, Русский, 日本語, 한국어, Français, Deutsch,
Español, 简体中文.

## Requirements

- **Visual Studio 2022** (or newer) with the *Desktop development with C++* workload.
- **CMake** >= 3.21 (bundled with recent Visual Studio).
- **vcpkg** — set the `VCPKG_ROOT` environment variable to your vcpkg checkout.
- **Git** (required — CommonLibSSE-NG is pulled in as a submodule).

vcpkg dependencies (installed automatically from `vcpkg.json`): `directxtk`,
`glm`, `rapidcsv`, `rapidjson`, `simpleini`, `spdlog`.

## Cloning

CommonLibSSE-NG is a git submodule, so clone recursively:

```sh
git clone --recursive https://github.com/zhuabaobao123/STB-Widgets-Nexus.git
cd STB-Widgets-Nexus
```

If you already cloned without `--recursive`:

```sh
git submodule update --init --recursive --remote CommonLibSSE
```

## Building

```sh
cmake -B build -S . -A x64 ^
  -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%/scripts/buildsystems/vcpkg.cmake ^
  -DVCPKG_TARGET_TRIPLET=x64-windows-static ^
  -DCOPY_BUILD=OFF
cmake --build build --config Release --parallel
```

## Installing

Copy `STB_Widgets.dll` into `Data/SKSE/Plugins/`, together with the widget `.swf`
assets under `Data/interface/`.

The interface language is read at runtime from `Data/SKSE/Plugins/STB_Widgets.json`
(UTF-8, flat `{"English string": "translated string"}` table). Deleting that file
reverts the interface to English; swapping it switches languages without
recompiling.

## License

This fork is distributed under the **GNU General Public License version 3 or
later (GPL-3.0-or-later)**, because it is built with
[CommonLibSSE-NG](https://github.com/alandtse/CommonLibSSE-NG), which is
GPL-3.0 licensed (with linking exceptions, see its `EXCEPTIONS.md`).

Copyright (C) 2026 STB team (original mod) and zhuabaobao123 (localization and
CommonLibSSE-NG v9 port).

- The full, unmodified GPL-3.0 license text is included in the downloadable
  archive as `LICENSE.txt`.
- Corresponding source code: <https://github.com/zhuabaobao123/STB-Widgets-Nexus>
- Original STB Widgets mod (MIT) by STB team:
  <https://www.nexusmods.com/skyrimspecialedition/mods/136148>

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.
