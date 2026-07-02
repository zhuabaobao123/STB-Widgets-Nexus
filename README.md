# STB Widgets

A set of customizable SKSE HUD widgets for Skyrim Special Edition / Anniversary
Edition (equipment, level/XP, gold, weight, resistances, shout meter, game time,
play time). Built as an SKSE plugin against **CommonLibSSE-NG**.

## Requirements

- **Visual Studio 2022** (or newer) with the *Desktop development with C++* workload.
- **CMake** ≥ 3.21 (bundled with recent Visual Studio).
- **vcpkg** — set the `VCPKG_ROOT` environment variable to your vcpkg checkout.
- **Git** (required — CommonLibSSE-NG is pulled in as a submodule).

vcpkg dependencies (installed automatically from `vcpkg.json`): `glm`, `rapidcsv`,
`simpleini`, `spdlog`.

## Cloning

CommonLibSSE-NG is a git submodule, so clone recursively:

```sh
git clone --recursive https://github.com/STB-Team/STB-Widgets-Nexus.git
cd STB-Widgets-Nexus
```

If you already cloned without `--recursive`:

```sh
git submodule update --init --recursive
```

## Building

```sh
cmake -B build -S . -A x64 ^
  -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%/scripts/buildsystems/vcpkg.cmake ^
  -DVCPKG_TARGET_TRIPLET=x64-windows-static ^
  -DCOPY_BUILD=OFF
cmake --build build --config Release --parallel
```

`gen.bat` runs the configure + build for you (needs `VCPKG_ROOT` set).

- Pass a specific generator with `-G "Visual Studio 17 2022"` (or `18 2026`, etc.)
  if CMake doesn't pick your toolchain automatically.
- Output: `build/Release/STB_Widgets.dll`.

### `COPY_BUILD`

`COPY_BUILD` defaults to `ON`, which copies the built DLL into a Skyrim/MO2 deploy
folder after each build. Unless you set that path up in `CMakeLists.txt`, build with
`-DCOPY_BUILD=OFF`.

## Installing

Copy `STB_Widgets.dll` into `Data/SKSE/Plugins/`, together with the widget `.swf`
assets (shipped with the mod release) under `Data/interface/`.

## License

See [LICENSE](LICENSE).
