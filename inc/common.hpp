#pragma once

#include <windows.h>
#include <thread>
#include <map>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

#include <xorstr.hpp>
#include <lazy_importer.hpp>

#define _t(text) xorstr_(text)
#define _f(func) LI_FN(func)

#include "../lib/imgui/imgui.h"
#include "../lib/imgui/imgui_internal.h"
#include "../lib/imgui/imgui_impl_win32.h"
#include "../lib/imgui/imgui_impl_opengl3.h"

#define FMT_HEADER_ONLY
#include <fmt/format.h>
#include <fmt/chrono.h>

#include <MinHook.h>
#include <discord_rpc.h>

#define create_name(pre, post) pre##post
#define create_pad_name(n) create_name(pad, n)
#define pad(n) uint8_t create_pad_name(__LINE__)[n]

#include "utilities/singleton.hpp"
#include "utilities/console.hpp"
#include "utilities/import_table.hpp"
#include "utilities/base_features.hpp"
#include "utilities/utilities.hpp"
#include "utilities/game_sdk.hpp"
#include "utilities/font.hpp"
#include "config.hpp"
#include "hacks.hpp"
#include "discord.hpp"
#include "ui.hpp"
#include "hooks.hpp"
#include "entry.hpp"