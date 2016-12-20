#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <iostream>

#define ERR_OK                          0x000000    //Function ended without errors
#define ERR_UNKNOWN                     0x000001    //Should never ever be returned

#define ERR_ENGINE_UNKNOWN              0x000100    //Should never be returned
#define ERR_ENGINE_INIT                 0x000101    //Engine failed to initialize: cause undefined
#define ERR_ENGINE_SDL_INIT             0x000102    //Engine failed to initialize: cause SDL_Init
#define ERR_ENGINE_SDL_MIXER_INIT       0x000104    //Engine failed to initialize: cause Mix_OpenAudio
#define ERR_ENGINE_GRAPHICS_INIT        0x000108    //Engine failed to initialize: cause graphics->Initialize
#define ERR_ENGINE_EVENT_INIT           0x00010F    //Engine failed to initialize: cause event->Initialize
#define ERR_ENGINE_SDL_TTF_INIT         0x000120    //Engine failed to initialize: cause Ttf_Init
#define ERR_ENGINE_IO_CONFIG_READ       0x000140    //Engine failed to initialize: cause configFile->Read

#define ERR_GRAPHICS_UNKNOWN            0x000200    //Should never be returned
#define ERR_GRAPHICS_INIT               0x000201    //Graphics engine failed to initialize: cause undefined
#define ERR_GRAPHICS_WINDOW_INIT        0x000202    //Graphics engine failed to initialize: cause window->Initialize
#define ERR_GRAPHICS_RENDERER_CREATE    0x000204    //Graphics engine failed to initialize: cause SDL_CreateRenderer

#define ERR_WINDOW_UNKNOWN              0x000400    //Should never be returned
#define ERR_WINDOW_INIT                 0x000401    //Window failed to initialize: cause undefined
#define ERR_WINDOW_SDL_CREATE           0x000402    //Window failed to initialize: cause SDL_CreateWindow

#define ERR_IO_UNKNOWN                  0x000800    //Should never be returned
#define ERR_IO_CONFIG_KEYNOTFOUND       0x000801    //Config could not find key: cause GetConfig
#define ERR_IO_CONFIG_OPEN              0x000802    //Config file failed to open

extern std::string GetErrorMessage(uint err);

#endif
