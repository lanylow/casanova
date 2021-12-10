#pragma once

#include <windows.h>
#include <thread>
#include <map>
#include <vector>
#include <algorithm>

#include <xorstr.hpp>
#include <lazy_importer.hpp>

#define _t(text) xorstr_(text)
#define _f(func) LI_FN(func)

#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_win32.h>
#include <imgui_impl_opengl3.h>

#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <fmt/chrono.h>

#include <MinHook.h>

#include "entry.hpp"
#include "utilities/console.hpp"
#include "utilities/import_table.hpp"
#include "utilities/base_features.hpp"
#include "utilities/utilities.hpp"
#include "utilities/game_sdk.hpp"
#include "utilities/font.hpp"
#include "ui.hpp"
#include "hooks.hpp"