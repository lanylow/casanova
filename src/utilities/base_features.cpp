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
      {
        false, "NoClip", "Makes the player invincible",
        {
          { 0x20A23C, "GeometryDash.exe", "90 90 90 90 90 90 90 E9 72 06 00 00", "6A 14 8B CB FF 15 00 00 00 00 8B CB" }
        },
        {
          { false, "GeometryDash.exe", 0x20A242, 0x28241C }
        }
      },
      {
        false, "NoClip (Experimental)", "Makes the player invincible",
        {
          { 0x20A23C, "GeometryDash.exe", "E9 79 06 00 00", "6A 14 8B CB FF" },
          { 0x1E9F6B, "GeometryDash.exe", "E9 13 02 00 00 90", "0F 84 12 02 00 00" },
          { 0x1EA195, "GeometryDash.exe", "E9 22 01 00 00 90", "0F 8B 21 01 00 00" },
        },
        { }
      },
      {
        false, "No Spikes", "Ignores spike object",
        {
          { 0x205347, "GeometryDash.exe", "75", "74" }
        },
        { }
      },
      {
        false, "No Hitbox", "Disables all object hitboxes. Special objects are disabled",
        {
          { 0x20456D, "GeometryDash.exe", "B8 07 00 00 00 90", "8B 83 00 03 00 00" }
        },
        { }
      },
      {
        false, "No Solids", "Disables most solid hitboxes. Special objects still work",
        {
          { 0x20456D, "GeometryDash.exe", "B8 14 00 00 00 90", "8B 83 00 03 00 00" }
        },
        { }
      },
      {
        false, "Force Block Type", "Treats all objects as if they were blocks",
        {
          { 0x20456D, "GeometryDash.exe", "31 C0 83 7B 34 00 BA 07 00 00 00 0F 44 C2 90", "8B 83 00 03 00 00 83 F8 07 0F 84 7F 0A 00 00" }
        },
        { }
      },
      {
        false, "Everything Hurts", "Owie",
        {
          { 0x20456D, "GeometryDash.exe", "B8 02 00 00 00 90", "8B 83 00 03 00 00" }
        },
        { }
      },
      {
        false, "Freeze Player", "Freezes player movement",
        {
          { 0x203519, "GeometryDash.exe", "90 90 90", "50 FF D6" },
          { 0x203544, "GeometryDash.exe", "90", "50" },
          { 0x20354B, "GeometryDash.exe", "90 90", "FF D6" }
        },
        { }
      },
      {
        false, "Jump Hack", "Allows for jumping in mid-air",
        {
          { 0x1E9141, "GeometryDash.exe", "01", "00" },
          { 0x1E9498, "GeometryDash.exe", "01", "00" }
        }, 
        { }
      },
      {
        false, "Hide Attempts", "Hides the attempt count in-game",
        {
          { 0x2D83B8, "GeometryDash.exe", "00", "41" }
        },
        { }
      },
      {
        false, "Practice Music Hack", "Plays the level's song in-sync with your position, instead of the standard practice song",
        {
          { 0x20C925, "GeometryDash.exe", "90 90 90 90 90 90", "0F 85 F7 00 00 00" },
          { 0x20D143, "GeometryDash.exe", "90 90", "75 41" },
          { 0x20A563, "GeometryDash.exe", "90 90", "75 3E" },
          { 0x20A595, "GeometryDash.exe", "90 90", "75 0C" },
        },
        { }
      },
      {
        false, "Ignore ESC", "Stops the ESC key from exiting a level",
        {
          { 0x1E660C, "GeometryDash.exe", "EB 0B", "6A 00" }
        },
        { }
      },
      {
        false, "Suicide", "Kills the player",
        {
          { 0x203DA2, "GeometryDash.exe", "E9 57 02 00 00 90", "0F 86 56 02 00 00" },
          { 0x20401A, "GeometryDash.exe", "E9 27 02 00 00 90", "0F 87 26 02 00 00" }
        },
        { }
      },
      {
        false, "Accurate Percentage", "Allows for decimals in the level percentage",
        {
          { 0x2080FE, "GeometryDash.exe", "F3 0F 10 00 F3 0F 5E 87 B4 03 00 00 BA 00 00 00 00 F3 0F 59 02 0F 2F 02 76 04 F3 0F 10 02 8B 87 C0 03 00 00 8B B0 04 01 00 00 F3 0F 5A C0 83 EC 08 F2 0F 11 04 24 68 B0 81 63 00", "33 C9 F3 0F 10 00 F3 0F 5E 87 B4 03 00 00 F3 0F 59 05 00 00 00 00 F3 0F 2C C0 85 C0 0F 4F C8 B8 64 00 00 00 3B C8 0F 4F C8 8B 87 C0 03 00 00 51 68 30 32 64 00 8B B0 04 01 00 00" },
          { 0x20813F, "GeometryDash.exe", "83 C4 0C", "83 C4 08" },
          { 0x2881B0, "GeometryDash.exe", "25 2E 32 66 25 25 00", "25 2E 32 66 00" }
        },
        {
          { true, "GeometryDash.exe", 0x20810B, 0x2E65C0 },
          { true, "GeometryDash.exe", 0x208135, 0x2881B0 },
          { false, "GeometryDash.exe", 0x208110, 0x2E65C0 },
          { false, "GeometryDash.exe", 0x20812F, 0x293230 },
        }
      },
      {
        false, "Instant Complete", "Teleports the player to the end of a level",
        {
          { 0x20350D, "GeometryDash.exe", "C7 81 7C 06 00 00 20 BC BE 4C 90 90 90 90 90", "8B 35 00 00 00 00 81 C1 7C 06 00 00 50 FF D6" }
        },
        {
          { false, "GeometryDash.exe", 0x20350F, 0x2823E0 }
        }
      },
      {
        false, "Percentage Only", "Hides the progress bar and shows only the percentage at top",
        {
          { 0x1FCF35, "GeometryDash.exe", "90 90 90 90 90 90 90 90", "F3 0F 58 05 00 00 00 00" },
          { 0x1FCE92, "GeometryDash.exe", "F3 0F 58", "F3 0F 5C" },
          { 0x1FCF68, "GeometryDash.exe", "00 00 00 3F", "00 00 00 00" }
        },
        {
          { false, "GeometryDash.exe", 0x1FCF39, 0x2E65D8 }
        }
      },
      {
        false, "Hide Pause Button", "Hides the pause button when the in-game cursor is enabled",
        {
          { 0x25F4AC, "GeometryDash.exe", "90 90", "75 10" }
        },
        { }
      },
      {
        false, "Mini Cube Icon", "Forces use of the mini cube icon",
        {
          { 0x1E6DF4, "GeometryDash.exe", "31 FF 90", "0F 4F FA" },
          { 0x1F7E51, "GeometryDash.exe", "31 C9 90 90", "0F 4C 4D 08" }
        },
        { }
      },
      {
        false, "Same Dual Colour", "Gives both icons the same colour combo, not an inverted one in dual mode",
        {
          { 0x1FC1C3, "GeometryDash.exe", "8B 81 48 02 00 00 2B 81 4C 02 00 00", "8B 81 3C 02 00 00 2B 81 40 02 00 00" },
          { 0x1FC142, "GeometryDash.exe", "8B 88 3C 02 00 00 2B 88 40 02 00 00", "8B 88 48 02 00 00 2B 88 4C 02 00 00" }
        },
        { }
      },
      {
        false, "Replay Last Checkpoint", "Lets you replay your last practice pode checkpoint after completing a level",
        { },
        {
          { true, "GeometryDash.exe", 0x96BB8, 0x20BF00 },
          { false, "GeometryDash.exe", 0x96BB8, 0x20BDF0 },
        }
      },
      {
        false, "No New Best Popup", "Disable the new best popup",
        {
          { 0x1FE548, "GeometryDash.exe", "EB 42", "75 47" },
          { 0x1FE97E, "GeometryDash.exe", "00 00 00 00", "CD CC 8C 3F" }
        },
        { }
      },
      {
        false, "Practice User-Coins", "Allows for user-coins to be picked up in practice mode",
        {
          { 0x204F10, "GeometryDash.exe", "90 90 90 90 90 90 90 90 90 90 90 90 90", "80 BE 95 04 00 00 00 0F 85 DE 00 00 00" }
        },
        { }
      },
      {
        false, "Coins Show Uncollected", "Forces coins & user-coins show as uncollected",
        {
          { 0xE6706, "GeometryDash.exe", "8B C2 90", "0F 44 C2" },
          { 0xE720F, "GeometryDash.exe", "8B D9 90", "0F 44 D9" }
        },
        { }
      },
      {
        false, "Corrective Music Sync", "Syncs music properly after unpausing",
        {
          { 0x208808, "GeometryDash.exe", "EB 08", "75 08" }
        },
        { }
      },
      {
        false, "No Spider Dash", "Disables spider dash trail when teleporting",
        {
          { 0x1EDCE3, "GeometryDash.exe", "E9 90 01 00 00 90", "0F 84 8F 01 00 00" }
        },
        { }
      },
      {
        false, "Ball Rotation Bug", "Brings back the ball rotation bug when entering a portal mid ball animation",
        {
          { 0x1E9E40, "GeometryDash.exe", "90 90 90 90 90 90 90 90", "6A 01 FF 15 00 00 00" }
        },
        {
          { false, "GeometryDash.exe", 0x1E9E44, 0x28241C }
        }
      },
      {
        false, "Block Level Exit", "Blocks the exit level button & shortcut",
        {
          { 0x1E644C, "GeometryDash.exe", "90 90 90 90 90", "E8 BF 73 02 00" }
        }
      }
    }
  },
  { "Rendering",
    {
      {
        false, "No Portal Lightning", "Disables portal lightning from size-changing portals",
        {
          { 0x1F9971, "GeometryDash.exe", "EB 2C 90", "83 EC 08" }
        },
        { }
      },
      {
        false, "Solid Wave Trail", "No blending on the wave trail, like the black & white trail",
        {
          { 0x1E8162, "GeometryDash.exe", "90 90", "75 18" },
          { 0x1E816B, "GeometryDash.exe", "90 90", "75 0F" }
        },
        { }
      },
      {
        false, "No Death Effect", "No visual effects on death",
        {
          { 0x1EFBA4, "GeometryDash.exe", "90 90 90 90 90", "E8 37 00 00 00" }
        },
        { }
      },
      {
        false, "No Force Glow", "Doesn't force a white glow when using black secondary colour",
        {
          { 0x1F7953, "GeometryDash.exe", "EB", "75" },
          { 0x1F796C, "GeometryDash.exe", "EB", "75" }
        },
        { }
      },
      {
        false, "Practice Pulse", "Pulses orbs & wave in practice mode",
        {
          { 0x3DB26, "GeometryDash.exe", "90 90", "75 0C" },
          { 0x205536, "GeometryDash.exe", "90 90", "75 08" },
          { 0x20553E, "GeometryDash.exe", "EB 1F", "74 13" }
        },
        { }
      },
      {
        false, "No Respawn Flash", "Disables the respawn flash & circle effect",
        {
          { 0x1EF36D, "GeometryDash.exe", "E9 A8 00 00 00 90", "0F 85 A7 00 00 00" }
        },
        { }
      },
      {
        false, "No Wave Trail", "Disables the hard wave trail, standard trail remains",
        {
          { 0x1F90C6, "GeometryDash.exe", "EB 42", "74 42" }
        },
        { }
      },
      {
        false, "Trail Bug Fix", "Fixes trail cutting on high refresh rates",
        {
          { 0xAE9BD, "libcocos2d.dll", "BB FF 00 00 00 90", "F3 0F 2C C1 2B D8" }
        },
        { }
      },
      {
        false, "No Glow", "Disables objects glow",
        {
          { 0xCFF35, "GeometryDash.exe", "90 90", "74 0D" },
          { 0xF02A4, "GeometryDash.exe", "E9 C0 00 00 00 90", "0F 84 BF 00 00 00" },
          { 0xF0434, "GeometryDash.exe", "E9 C0 00 00 00 90", "0F 84 BF 00 00 00" }
        },
        { }
      },
      {
        false, "No Wave Pulse", "Disables wave pulsing",
        {
          { 0x1E8688, "GeometryDash.exe", "F3 0F 10 05 00 00 00 00", "F3 0F 10 83 94 06 00 00" }
        },
        {
          { true, "GeometryDash.exe", 0x1E868C, 0x2E6260 }
        }
      },
      {
        false, "No Particles", "Disables the particle system (mostly)",
        {
          { 0xB76C5, "libcocos2d.dll", "31 F6", "8B F0" },
          { 0xB8ED6, "libcocos2d.dll", "00", "01" }
        },
        { }
      },
      {
        false, "No Pulse", "Disables pulsing on objects",
        {
          { 0x2060D9, "GeometryDash.exe", "EB 4A", "74 4A" }
        },
        { }
      },
      {
        false, "No Mirror", "Disables mirror portals",
        {
          { 0x204D08, "GeometryDash.exe", "E9 DF 01 00 00", "8B 03 8B CB FF" }
        },
        { }
      },
      {
        false, "Trail Always On", "Sets the trail to either always on or always off",
        {
          { 0xAEDCC, "libcocos2d.dll", "90 90 90 90 90 90", "0F 84 68 02 00 00" }
        },
        { }
      },
      {
        false, "Trail Always Off", "Sets the trail to either always on or always off",
        {
          { 0xAEDCC, "libcocos2d.dll", "E9 69 02 00 00 90", "0F 84 68 02 00 00" }
        },
        { }
      },
      {
        false, "Inversed Trail", "Inverses the trail state",
        {
          { 0xAEDCC, "libcocos2d.dll", "0F 85 68 02 00 00", "0F 84 68 02 00 00" }
        },
        { }
      }
    }
  },
  { "Universal",
    {
      {
        false, "AntiCheat Bypass", "Disables common anticheats",
        {
          { 0x202AAA, "GeometryDash.exe", "EB 2E", "74 2E" },
          { 0x15FC2E, "GeometryDash.exe", "EB", "74" },
          { 0x1FD335, "GeometryDash.exe", "EB", "74" },
          { 0x1FD557, "GeometryDash.exe", "EB 0C", "74 0C" },
          { 0x1FD742, "GeometryDash.exe", "C7 87 E0 02 00 00 01 00 00 00 C7 87 E4 02 00 00 00 00 00 00 90 90 90 90 90 90", "80 BF DD 02 00 00 00 0F 85 0A FE FF FF 80 BF 34 05 00 00 00 0F 84 FD FD FF FF" },
          { 0x1FD756, "GeometryDash.exe", "90 90 90 90 90 90", "0F 84 FD FD FF FF" },
          { 0x1FD79A, "GeometryDash.exe", "90 90 90 90 90 90", "0F 84 B9 FD FF FF" },
          { 0x1FD7AF, "GeometryDash.exe", "90 90 90 90 90 90", "0F 85 A4 FD FF FF" },
          { 0x20D3B3, "GeometryDash.exe", "90 90 90 90 90", "E8 58 04 00 00" },
          { 0x1FF7A2, "GeometryDash.exe", "90 90", "74 6E" },
          { 0x18B2B4, "GeometryDash.exe", "B0 01", "88 D8" },
          { 0x20C4E6, "GeometryDash.exe", "E9 D7 00 00 00 90", "0F 85 D6 00 00 00" }
        },
          { }
      },
      {
        false, "Force Visibility", "Sets all nodes to be visible",
        {
          { 0x60753, "libcocos2d.dll", "B0 01 90", "8A 45 08" },
          { 0x60C5A, "libcocos2d.dll", "90 90 90 90 90 90", "0F 84 CB 00 00 00" }
        },
        { }
      },
      {
        false, "No Rotation", "Locks all rotation at 0 degrees",
        {
          { 0x60554, "libcocos2d.dll", "90 90 90 90 90 90 90 90 90 90", "F3 0F 11 49 24 F3 0F 11 49 20" }
        },
        { }
      },
      {
        false, "Free Window Resize", "Removes limits in place for window resizing",
        {
          { 0x11388B, "libcocos2d.dll", "90 90 90 90 90", "E8 B0 F3 FF FF" },
          { 0x11339D, "libcocos2d.dll", "B9 FF FF FF 7F 90 90", "E8 EE F6 FF FF 8B C8" },
          { 0x1133C0, "libcocos2d.dll", "48", "50" },
          { 0x1133C6, "libcocos2d.dll", "48", "50" },
          { 0x112536, "libcocos2d.dll", "EB 11 90", "50 6A 00" }
        },
        { }
      },
      {
        false, "No Transition", "Shorterns scene transition time to 0s, doesn't work with the transition customiser",
        {
          { 0xA5424, "libcocos2d.dll", "90 90 90 90 90", "F3 0F 10 45 08" }
        },
        { }
      },
      {
        false, "Safe Mode", "Disables progress, completion & verification of levels",
        {
          { 0x20A3D1, "GeometryDash.exe", "E9 7B 01 00 00 90", "0F 85 7A 01 00 00" },
          { 0x1FF80B, "GeometryDash.exe", "90 90 90 90 90 90 90", "7D 0C E9 C2 FB FF FF" }
        }
      },
      {
        false, "Transparent BG", "Removes the blue filter from menu's backgrounds",
        {
          { 0x15A174, "GeometryDash.exe", "FF", "00" },
          { 0x15A175, "GeometryDash.exe", "FF", "66" },
          { 0x15A16F, "GeometryDash.exe", "FF", "FF" },
          { 0x15A16D, "GeometryDash.exe", "90 B1", "80 C9" },
          { 0x15891D, "GeometryDash.exe", "FF", "00" },
          { 0x15891E, "GeometryDash.exe", "FF", "66" },
          { 0x158917, "GeometryDash.exe", "FF", "FF" },
          { 0x158915, "GeometryDash.exe", "90 B1", "80 C9" },
          { 0x6F7FB, "GeometryDash.exe", "FF", "00" },
          { 0x6F7FC, "GeometryDash.exe", "FF", "66" },
          { 0x6F7F6, "GeometryDash.exe", "FF", "FF" },
          { 0x6F7F4, "GeometryDash.exe", "90 B1", "80 C9" },
          { 0x1979AD, "GeometryDash.exe", "FF", "00" },
          { 0x1979AE, "GeometryDash.exe", "FF", "66" },
          { 0x1979A7, "GeometryDash.exe", "FF", "FF" },
          { 0x1979A5, "GeometryDash.exe", "90 B1", "80 C9" },
          { 0x17DBC1, "GeometryDash.exe", "FF", "00" },
          { 0x17DBC2, "GeometryDash.exe", "FF", "66" },
          { 0x17DBBB, "GeometryDash.exe", "FF", "FF" },
          { 0x17DBB9, "GeometryDash.exe", "90 B1", "80 C9" },
          { 0x176032, "GeometryDash.exe", "FF", "00" },
          { 0x176033, "GeometryDash.exe", "FF", "66" },
          { 0x176036, "GeometryDash.exe", "FF", "FF" },
          { 0x176034, "GeometryDash.exe", "90 B1", "80 C9" },
          { 0x4DF7E, "GeometryDash.exe", "FF", "00" },
          { 0x4DF7F, "GeometryDash.exe", "FF", "66" },
          { 0x4DF78, "GeometryDash.exe", "FF", "FF" },
          { 0x4DF76, "GeometryDash.exe", "90 B1", "80 C9" }
        },
        { }
      },
      {
        false, "Transparent Lists", "Makes the menu lists transparent",
        {
          { 0x15C02C, "GeometryDash.exe", "00 00 00 40", "BF 72 3E FF" },
          { 0x5C70A, "GeometryDash.exe", "60", "FF" },
          { 0x5C6D9, "GeometryDash.exe", "20 20", "A1 58" },
          { 0x5C6DC, "GeometryDash.exe", "20", "2C" },
          { 0x5C6CF, "GeometryDash.exe", "40 40", "C2 72" },
          { 0x5C6D2, "GeometryDash.exe", "40", "3E" }
        }
      },
      {
        false, "Fast Alt-Tab", "Disables savefile saving on minimize",
        {
          { 0x3D02E, "GeometryDash.exe", "90 90 90 90 90 90 90", "8B 03 8B CB FF 50 18" }
        },
        { }
      },
      {
        false, "Allow Low Volume", "Removed snapping to 0.00 setting volume to 0.03",
        {
          { 0x1E5D7F, "GeometryDash.exe", "EB 08", "76 08" },
          { 0x1DDEC1, "GeometryDash.exe", "EB 08", "76 08" }
        }
      }
    }
  }
};