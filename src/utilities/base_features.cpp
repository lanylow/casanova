#include <common.hpp>

std::map<std::string_view, std::vector<casanova::base_features::feature_def_t>> casanova::base_features::table = {
  { "Bypass",
    {
      {
        false,
        "Icons",
        "Unlocks all icons",
        {
          {
            0xC50A8,
            "GeometryDash.exe",
            "B0 01 90 90 90",
            "E8 7A CD 19 00"
          },
          {
            0xC54BA,
            "GeometryDash.exe",
            "B0 01 90 90 90",
            "E8 68 C9 19 00"
          }
        },
        { }
      },
      {
        false,
        "Text Length",
        "Allows for unlimited text length in text inputs",
        {
          {
            0x21ACB,
            "GeometryDash.exe",
            "EB 04",
            "7C 04"
          }
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