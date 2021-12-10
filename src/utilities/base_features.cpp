#include <common.hpp>

std::map<std::string_view, std::vector<casanova::base_features::feature_def_t>> casanova::base_features::table = {
  { "Bypass",
    {
      {
        false,
        "Icons",
        "Unlocks all icons",
        {
          { 0xC50A8, "GeometryDash.exe", "B0 01 90 90 90", "E8 7A CD 19 00" },
          { 0xC54BA, "GeometryDash.exe", "B0 01 90 90 90", "E8 68 C9 19 00" }
        },
        { }
      },
      {
        false,
        "Text Length",
        "Allows for unlimited text length in text inputs",
        {
          { 0x21ACB, "GeometryDash.exe", "EB 04", "7C 04" }
        },
        { }
      },
      {
        false,
        "Character Filter",
        "Lets you input any character in text inputs",
        {
          { 0x21A99, "GeometryDash.exe", "90 90", "75 04" }
        },
        { }
      },
      {
        false,
        "Slider Limit",
        "Lets sliders be dragged beyond the visible limit",
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