#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <iostream>

#define ERR_OK                          0x000000    //Function ended without errors
#define ERR_UNKNOWN                     0x000001    //Should never be returned
#define ERR_OGRE_EXCEPTION              0x000002    //Prefix for Ogre exceptions

#define ERR_ENGINE_UNKNOWN              0x000100    //Should never be returned
#define ERR_ENGINE_INIT                 0x000101    //Engine failed to initialize: cause undefined
#define ERR_ENGINE_SDL_INIT             0x000102    //Engine failed to initialize: cause SDL_Init
#define ERR_ENGINE_SDL_MIXER_INIT       0x000104    //Engine failed to initialize: cause Mix_OpenAudio
#define ERR_ENGINE_GRAPHICS_INIT        0x000108    //Engine failed to initialize: cause graphics->Initialize
#define ERR_ENGINE_EVENT_INIT           0x000110    //Engine failed to initialize: cause event->Initialize

#define ERR_GRAPHICS_UNKNOWN            0x000200    //Should never be returned
#define ERR_GRAPHICS_INIT               0x000201    //Graphics engine failed to initialize: cause undefined
#define ERR_GRAPHICS_WINDOW_INIT        0x000202    //Graphics engine failed to initialize: cause window->Initialize
#define ERR_GRAPHICS_RENDERER_CREATE    0x000204    //Graphics engine failed to initialize: cause SDL_CreateRenderer

#define ERR_WINDOW_UNKNOWN              0x000400    //Should never be returned
#define ERR_WINDOW_INIT                 0x000401    //Window failed to initialize: cause undefined
#define ERR_WINDOW_SDL_CREATE           0x000402    //Window failed to initialize: cause SDL_CreateWindow
#define ERR_WINDOW_OGRE_INIT            0x000404    //Window failed to initialize: cause root->initialise
#define ERR_WINDOW_OGL_CREATE           0x000408    //Window failed to initialize: cause SDL_GL_CreateContext

extern const char* GetErrorMessage(uint err);

#endif
