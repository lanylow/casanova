#include <common.hpp>

std::map<std::string_view, std::map<std::string_view, uintptr_t>> casanova::import_table::table = {
  { "libcocos2d", 
    {
      { "CCEGLView::swapBuffers", casanova::utilities::get_function(_t("libcocos2d.dll"), _t("?swapBuffers@CCEGLView@cocos2d@@UAEXXZ")) },
      { "CCEGLView::pollEvents", casanova::utilities::get_function(_t("libcocos2d.dll"), _t("?pollEvents@CCEGLView@cocos2d@@QAEXXZ")) },
      { "CCEGLView::toggleFullScreen", casanova::utilities::get_function(_t("libcocos2d.dll"), _t("?toggleFullScreen@CCEGLView@cocos2d@@QAEX_N@Z")) },
      { "CCEGLView::getWindow", casanova::utilities::get_function(_t("libcocos2d.dll"), _t("?getWindow@CCEGLView@cocos2d@@QBEPAUGLFWwindow@@XZ")) }
    }
  }
};