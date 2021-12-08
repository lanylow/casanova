#include <common.hpp>

std::map<std::string_view, std::map<std::string_view, uintptr_t>> casanova::import_table::table = {
  { "libcocos2d", 
    {
      { "CCEGLView::swapBuffers", casanova::utilities::get_function("libcocos2d.dll", "?swapBuffers@CCEGLView@cocos2d@@UAEXXZ") },
      { "CCEGLView::pollEvents", casanova::utilities::get_function("libcocos2d.dll", "?pollEvents@CCEGLView@cocos2d@@QAEXXZ") },
      { "CCEGLView::toggleFullScreen", casanova::utilities::get_function("libcocos2d.dll", "?toggleFullScreen@CCEGLView@cocos2d@@QAEX_N@Z") }
    }
  }
};