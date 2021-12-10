#include <common.hpp>

std::map<std::string_view, std::vector<casanova::base_features::feature_def_t>> casanova::base_features::table = {
  { "Bypass",
    {
      {
        false, "Icons", "Unlocks all icons",
        {
          { 0xC50A8, "GeometryDash.exe", "B0 01 90 90 90", "E8 7A CD 19 00" },
          { 0xC54BA, "GeometryDash.exe", "B0 01 90 90 90", "E8 68 C9 19 00" }
        },
        { }
      },
      {
        false, "Text Length", "Allows for unlimited text length in text inputs",
        {
          { 0x21ACB, "GeometryDash.exe", "EB 04", "7C 04" }
        },
        { }
      },
      {
        false, "Character Filter", "Lets you input any character in text inputs",
        {
          { 0x21A99, "GeometryDash.exe", "90 90", "75 04" }
        },
        { }
      },
      {
        false, "Slider Limit", "Lets sliders be dragged beyond the visible limit",
        {
          { 0x2E5CA, "GeometryDash.exe", "EB", "76" },
          { 0x2E5F8, "GeometryDash.exe", "EB", "76" },
          { 0x8F196, "GeometryDash.exe", "83", "87" },
          { 0x8F1A2, "GeometryDash.exe", "90 90 90 90 90 90", "0F 87 6A 01 00 00" }
        },
        {
          { true, "GeometryDash.exe", 0x8F181, 0x322DD0 },
          { false, "GeometryDash.exe", 0x8F181, 0x2E6260 }
        }
      },
      {
        false, "Main Levels", "Unlocks main demon levels",
        {
          { 0x188CE1, "GeometryDash.exe", "E9 8A 00 00 00 90", "0F 8E 89 00 00 00" }
        },
        { }
      },
      {
        false, "Guard Vault", "Unlocks the guard's vault",
        {
          { 0x1DE1DA, "GeometryDash.exe", "90 90", "7C 4A" }
        },
        { }
      },
      {
        false, "Keymaster Vault", "Unlocks the keymaster's vault",
        {
          { 0x4F268, "GeometryDash.exe", "90 90", "74 4A" }
        },
        { }
      },
      {
        false, "Keymaster Basement", "Unlocks the keymaster's basement",
        {
          { 0x221759, "GeometryDash.exe", "90 90", "74 4A" }
        },
        { }
      },
      {
        false, "Basement Key Bypass", "Lets you unlock the locks in the basement",
        {
          { 0x226E19, "GeometryDash.exe", "E9 59 01 00 00 90", "0F 85 58 01 00 00" },
          { 0x226FB8, "GeometryDash.exe", "E9 59 01 00 00 90", "0F 85 58 01 00 00" },
          { 0x227157, "GeometryDash.exe", "E9 30 02 00 00 90", "0F 85 2F 02 00 00" },
        },
        { }
      },
      {
        false, "Challenge Bypass", "Unlocks 'The Challenge' level",
        {
          { 0x2214E0, "GeometryDash.exe", "90 90 90 90 90 90", "0F 84 87 00 00 00" }
        },
        { }
      },
      {
        false, "Treasure Room", "Unlocks the treasure room",
        {
          { 0x4F631, "GeometryDash.exe", "90 90", "74 4A" }
        },
        { }
      },
      {
        false, "Potbor Shop", "Unlocks Potbor's shop in the treasure room",
        {
          { 0x15706B, "GeometryDash.exe", "90 90 90 90 90 90", "0F 8C B4 01 00 00" }
        },
        { }
      },
      {
        false, "Scratch Shop", "Unlocks Scratch's shop in the treasure room",
        {
          { 0x1562D3, "GeometryDash.exe", "90 90 90 90 90 90", "0F 8C AF 01 00 00" }
        },
        { }
      },
      {
        false, "Shop Items", "Allows all shop items to be bought for 0 mana orbs",
        {
          { 0x14B339, "GeometryDash.exe", "90 31 F6 89 B3 10 01 00 00 89 B3 14 01 00 00 E8 03 6B FA FF 8B C8 E8 2C 82 FA FF 90", "2B B3 10 01 00 00 2B B3 14 01 00 00 E8 06 6B FA FF 8B C8 E8 2F 82 FA FF 3B F0 7F 25" }
        },
        { }
      },
      {
        false, "Gatekeeper Vault", "Unlocks the Gatekeeper's vault",
        {
          { 0x188836, "GeometryDash.exe", "90 90", "74 61" },
          { 0x18857F, "GeometryDash.exe", "90 90 90 90 90 90", "0F 84 FC 00 00 00" }
        },
        { }
      },
      {
        false, "Backup Stars Limit", "Lets you backup data with less than 10 stars",
        {
          { 0x3928E, "GeometryDash.exe", "EB 3E", "7D 3E" }
        },
        { }
      },
      {
        false, "Demon Gauntlet", "Bypasses demon gauntlet lock",
        {
          { 0x10664F, "GeometryDash.exe", "E9 E0 01 00 00 90", "0F 85 DF 01 00 00"}
        },
        { }
      }
    }
  },
  { "Creator",
    {

    }
  },
  { "Player",
    {

    }
  },
  { "Universal",
    {

    }
  }
};