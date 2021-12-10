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
      {
        false, "Copy Hack", "Lets you copy any level, without a password",
        {
          { 0x179B8E, "GeometryDash.exe", "90 90", "75 0E" },
          { 0x176F5C, "GeometryDash.exe", "8B CA 90", "0F 44 CA" },
          { 0x176FE5, "GeometryDash.exe", "B0 01 90", "0F 95 C0" }
        },
        { }
      },
      {
        false, "No (C) Mark", "Removes the (C) mark when uploading copied levels",
        {
          { 0xA6B8B, "GeometryDash.exe", "2B 87 CC 02 00 00", "2B 87 D0 02 00 00" },
          { 0x70E87, "GeometryDash.exe", "EB 26", "74 26" }
        },
        { }
      },
      {
        false, "Level Edit", "Lets you edit any level through the pause menu",
        {
          { 0x1E4A32, "GeometryDash.exe", "90 90", "75 6C" }
        },
        { }
      },
      {
        false, "Object Bypass", "Uncaps the object limit",
        {
          { 0x73169, "GeometryDash.exe", "FF FF FF 7F", "80 38 01 00" },
          { 0x856A4, "GeometryDash.exe", "FF FF FF 7F", "80 38 01 00" },
          { 0x87B17, "GeometryDash.exe", "FF FF FF 7F", "80 38 01 00" },
          { 0x87BC7, "GeometryDash.exe", "FF FF FF 7F", "80 38 01 00" },
          { 0x87D95, "GeometryDash.exe", "FF FF FF 7F", "80 38 01 00" },
          { 0x880F4, "GeometryDash.exe", "FF FF FF 7F", "80 38 01 00" },
          { 0x160B06, "GeometryDash.exe", "FF FF FF 7F", "80 38 01 00" },
        },
        { }
      },
      {
        false, "Custom Object Bypass", "Removes the object limit for custom objects & lets you save over 50",
        {
          { 0x7A100, "GeometryDash.exe", "EB", "72" },
          { 0x7A022, "GeometryDash.exe", "EB", "76" },
          { 0x7A203, "GeometryDash.exe", "90 90", "77 3A" },
        },
        { }
      },
      {
        false, "Zoom Bypass", "Lets you zoom fully in & out. (NOTE: Can crash with an edited grid size)",
        {
          { 0x87801, "GeometryDash.exe", "90 90 90", "0F 2F C8" },
          { 0x87806, "GeometryDash.exe", "90 90 90", "0F 28 C8" }
        },
        {
          { true, "GeometryDash.exe", 0x8786D, 0x2E6200 },
          { false, "GeometryDash.exe", 0x8786D, 0x2E6218 }
        }
      },
      {
        false, "Toolbox Button Bypass", "Allows for more objects in the editor toolbox",
        {
          { 0x13A548, "GeometryDash.exe", "83 F9 01", "83 F9 06" },
          { 0x13A559, "GeometryDash.exe", "B8 01 00 00 00", "B8 06 00 00 00" },
          { 0x13A54D, "GeometryDash.exe", "83 F9 7F", "83 F9 0C" },
          { 0x13A552, "GeometryDash.exe", "B9 7F 00 00 00", "B9 0C 00 00 00" },
          { 0x13A5D8, "GeometryDash.exe", "83 F9 01", "83 F9 02" },
          { 0x13A5E9, "GeometryDash.exe", "B8 01 00 00 00", "B8 02 00 00 00" },
          { 0x13A5DD, "GeometryDash.exe", "83 F9 7F", "83 F9 03" },
          { 0x13A5E2, "GeometryDash.exe", "B9 7F 00 00 00", "B9 03 00 00 00" },
        },
        { }
      },
      {
        false, "Verify Hack", "Lets you upload unverified levels",
        {
          { 0x71D48, "GeometryDash.exe", "EB", "74" }
        },
        { }
      },
      {
        false, "Default Song Bypass", "Lets you use hidden default songs in the editor",
        {
          { 0x174407, "GeometryDash.exe", "90 90", "74 2F" },
          { 0x174411, "GeometryDash.exe", "90 90 90", "0F 4F C6" },
          { 0x174456, "GeometryDash.exe", "90 90", "74 2F" },
          { 0x174460, "GeometryDash.exe", "90 90 90", "0F 4F C6" },
        },
        { }
      },
      {
        false, "Editor Extension", "Increases the editor length by a factor of 128",
        {
          { 0x2E67A4, "GeometryDash.exe", "00 60 EA 4B", "00 60 6A 48" },
          { 0x8FA4D, "GeometryDash.exe", "0F 60 EA 4B", "80 67 6A 48" },
        },
        { }
      },
      {
        false, "Place Over", "Lets you place the same object over itself in the editor",
        {
          { 0x160EE1, "GeometryDash.exe", "8B C1 90", "0F 48 C1" },
          { 0x160EF2, "GeometryDash.exe", "E9 23 02 00 00 90", "0F 8F 22 02 00 00" },
        },
        { }
      },
      {
        false, "Testmode Bypass", "Hides 'Testmode' text when playing with a startpos",
        {
          { 0x1FD270, "GeometryDash.exe", "E9 B7 00 00 00 90", "0F 84 B6 00 00 00" }
        },
        { }
      },
      {
        false, "Rotation Hack", "Allows you to rotate any object. Only works locally",
        {
          { 0x85CBC, "GeometryDash.exe", "B8 01 00 00 00 90", "8B 80 00 03 00 00" },
          { 0x8BDDD, "GeometryDash.exe", "B8 01 00 00 00 90", "8B 80 00 03 00 00" },
          { 0x8BE16, "GeometryDash.exe", "B8 01 00 00 00 90", "8B 80 00 03 00 00" },
          { 0xECA3D, "GeometryDash.exe", "B8 01 00 00 00 90", "8B 87 00 03 00 00" },
          { 0xEE5A9, "GeometryDash.exe", "B8 01 00 00 00 90", "8B 86 00 03 00 00" },
          { 0x20181E, "GeometryDash.exe", "B8 01 00 00 00 90", "8B 83 00 03 00 00" }
        },
        { }
      },
      {
        false, "Free Scroll", "Allows you to scroll out the editor",
        {
          { 0x8FAAC, "GeometryDash.exe", "EB", "77" },
          { 0x8FA95, "GeometryDash.exe", "EB", "77" },
          { 0x8FAC5, "GeometryDash.exe", "EB", "77" },
          { 0x8FADC, "GeometryDash.exe", "EB", "77" }
        },
        { }
      },
      {
        false, "Hide UI", "Hides the editor UI while building",
        {
          { 0x8720A, "GeometryDash.exe", "B3 00 90", "0F 44 D9" }
        },
        { }
      },
      {
        false, "Z Order Bypass", "Removes the -100 to 100 Z order range limit",
        {
          { 0x22DEDE, "GeometryDash.exe", "90 90 90", "0F 4C C1" },
          { 0x22DEE8, "GeometryDash.exe", "90 90 90", "0F 4F C1" }
        },
        { }
      },
      {
        false, "Absolute Scaling", "Locks block position for just scaling",
        {
          { 0x8F2F9, "GeometryDash.exe", "90 90 90 90 90 90", "56 E8 B1 EA FF FF" }
        },
        { }
      },
      {
        false, "Absolute Position", "Locks block position for scaling, rotation, moving, etc",
        {
          { 0x8DDE4, "GeometryDash.exe", "90 8B CE 90 90 90", "51 8B CE FF 50 5C" }
        },
        { }
      },
      {
        false, "Group ID Bypass", "Allows you to use Group IDs up to 1100 (except on the pulse trigger)",
        {
          { 0x1628F7, "GeometryDash.exe", "81 FE 4D 04 00 00", "81 FE E8 03 00 00" },
          { 0x22D66E, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x132A60, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x131E31, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x230FA0, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x23CE90, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x23B790, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x247AA0, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x149820, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x14918E, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x124C10, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x1244C1, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x124CB0, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x12451E, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x232B60, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x135FE0, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x1358B1, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x2357E0, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x236EE0, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x2385E0, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x23E500, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x41940, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x235860, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" },
          { 0x2358E0, "GeometryDash.exe", "B9 4C 04 00 00", "B9 E7 03 00 00" }
        },
        { }
      },
      {
        false, "Scale Snap Bypass", "Removed snapping to 1.00 when moving the scale slider between 0.97 and 1.03",
        {
          { 0x948C5, "GeometryDash.exe", "EB", "76" }
        },
        { }
      },
      {
        false, "ColourID Bypass", "Bypasses the 999 ColourID limit",
        {
          { 0x472FA, "GeometryDash.exe", "90 90 90", "0F 4F C1" },
          { 0x473EB, "GeometryDash.exe", "EB", "7C"},
          { 0x4754B, "GeometryDash.exe", "8B D0 90", "0F 4C D0" },
          { 0x4759B, "GeometryDash.exe", "EB", "7C" },
          { 0x470DB, "GeometryDash.exe", "90 90 90", "0F 4F C1"},
          { 0x470A0, "GeometryDash.exe", "EB", "7C"},
          { 0x1628FD, "GeometryDash.exe", "EB", "7C"},
        },
        { }
      },
      {
        false, "Playtest Zoom Bypass", "Allows further zoom during playtesting",
        {
          { 0x1697A9, "GeometryDash.exe", "90 90", "77 03" }
        },
        { }
      },
      {
        false, "Smooth Editor Trail", "Makes the playtest line in the editor smoother by updating it every frame instead of at 30fps",
        {
          { 0x16AB0D, "GeometryDash.exe", "90 90 90 90 90 90", "0F 82 85 00 00 00" }
        },
        { }
      }
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