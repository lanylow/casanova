#include <common.hpp>

std::map<std::string_view, std::map<std::string_view, uintptr_t>> casanova::import_table::table = {
  { "libcocos2d", 
    {
      { "CCEGLView::swapBuffers", casanova::utilities::get_function(_t("libcocos2d.dll"), _t("?swapBuffers@CCEGLView@cocos2d@@UAEXXZ")) },
      { "CCEGLView::pollEvents", casanova::utilities::get_function(_t("libcocos2d.dll"), _t("?pollEvents@CCEGLView@cocos2d@@QAEXXZ")) },
      { "CCEGLView::toggleFullScreen", casanova::utilities::get_function(_t("libcocos2d.dll"), _t("?toggleFullScreen@CCEGLView@cocos2d@@QAEX_N@Z")) },
      { "CCEGLView::getWindow", casanova::utilities::get_function(_t("libcocos2d.dll"), _t("?getWindow@CCEGLView@cocos2d@@QBEPAUGLFWwindow@@XZ")) },
      { "CCDirector::sharedDirector", casanova::utilities::get_function(_t("libcocos2d.dll"), _t("?sharedDirector@CCDirector@cocos2d@@SAPAV12@XZ")) },
      { "CCDirector::getScheduler", casanova::utilities::get_function(_t("libcocos2d.dll"), _t("?getScheduler@CCDirector@cocos2d@@UAEPAVCCScheduler@2@XZ")) },
      { "CCScheduler::setTimeScale", casanova::utilities::get_function(_t("libcocos2d.dll"), _t("?setTimeScale@CCScheduler@cocos2d@@QAEXM@Z")) }
    }
  },
  { "fmod",
    {
      { "ChannelControl::setPitch", casanova::utilities::get_function(_t("fmod.dll"), _t("?setPitch@ChannelControl@FMOD@@QAG?AW4FMOD_RESULT@@M@Z")) },
      { "ChannelControl::setVolume", casanova::utilities::get_function(_t("fmod.dll"), _t("?setVolume@ChannelControl@FMOD@@QAG?AW4FMOD_RESULT@@M@Z")) }
    }
  },
  { "kernel32",
    {
      { "GetTickCount", casanova::utilities::get_function(_t("kernel32.dll"), _t("GetTickCount")) },
      { "GetTickCount64", casanova::utilities::get_function(_t("kernel32.dll"), _t("GetTickCount64")) },
      { "QueryPerformanceCounter", casanova::utilities::get_function(_t("kernel32.dll"), _t("QueryPerformanceCounter")) }
    }
  }
};