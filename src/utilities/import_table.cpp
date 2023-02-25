#include <common.hpp>

std::map<std::string_view, std::map<std::string_view, uintptr_t>> casanova::import_table::table = {
  { "libcocos2d", 
    {
      { "CCEGLView::swapBuffers", casanova::utilities::get_function("libcocos2d.dll", "?swapBuffers@CCEGLView@cocos2d@@UAEXXZ") },
      { "CCEGLView::pollEvents", casanova::utilities::get_function("libcocos2d.dll", "?pollEvents@CCEGLView@cocos2d@@QAEXXZ") },
      { "CCEGLView::toggleFullScreen", casanova::utilities::get_function("libcocos2d.dll", "?toggleFullScreen@CCEGLView@cocos2d@@QAEX_N@Z") },
      { "CCEGLView::getWindow", casanova::utilities::get_function("libcocos2d.dll", "?getWindow@CCEGLView@cocos2d@@QBEPAUGLFWwindow@@XZ") },
      { "CCDirector::sharedDirector", casanova::utilities::get_function("libcocos2d.dll", "?sharedDirector@CCDirector@cocos2d@@SAPAV12@XZ") },
      { "CCDirector::getScheduler", casanova::utilities::get_function("libcocos2d.dll", "?getScheduler@CCDirector@cocos2d@@UAEPAVCCScheduler@2@XZ") },
      { "CCScheduler::setTimeScale", casanova::utilities::get_function("libcocos2d.dll", "?setTimeScale@CCScheduler@cocos2d@@QAEXM@Z") },
      { "CCEGLView::sharedOpenGLView", casanova::utilities::get_function("libcocos2d.dll", "?sharedOpenGLView@CCEGLView@cocos2d@@SAPAV12@XZ") },
      { "CCEGLView::getIsFullscreen", casanova::utilities::get_function("libcocos2d.dll", "?getIsFullscreen@CCEGLView@cocos2d@@QBE_NXZ") },
      { "CCApplication::toggleVerticalSync", casanova::utilities::get_function("libcocos2d.dll", "?toggleVerticalSync@CCApplication@cocos2d@@QAEX_N@Z") },
      { "CCApplication::sharedApplication", casanova::utilities::get_function("libcocos2d.dll", "?sharedApplication@CCApplication@cocos2d@@SAPAV12@XZ") },
      { "CCApplication::getVerticalSyncEnabled", casanova::utilities::get_function("libcocos2d.dll", "?getVerticalSyncEnabled@CCApplication@cocos2d@@QBE_NXZ") },
      { "CCApplication::setAnimationInterval", casanova::utilities::get_function("libcocos2d.dll", "?setAnimationInterval@CCApplication@cocos2d@@UAEXN@Z") }
    }
  },
  { "fmod",
    {
      { "ChannelControl::setPitch", casanova::utilities::get_function("fmod.dll", "?setPitch@ChannelControl@FMOD@@QAG?AW4FMOD_RESULT@@M@Z") },
      { "ChannelControl::setVolume", casanova::utilities::get_function("fmod.dll", "?setVolume@ChannelControl@FMOD@@QAG?AW4FMOD_RESULT@@M@Z") }
    }
  },
  { "kernel32",
    {
      { "GetTickCount", casanova::utilities::get_function("kernel32.dll", "GetTickCount") },
      { "GetTickCount64", casanova::utilities::get_function("kernel32.dll", "GetTickCount64") },
      { "QueryPerformanceCounter", casanova::utilities::get_function("kernel32.dll", "QueryPerformanceCounter") }
    }
  }
};