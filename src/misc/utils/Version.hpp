#ifndef UTILS_VERSION_HPP_
#define UTILS_VERSION_HPP_

namespace Utils
{
    class Version
    {
    public:
        //Print version info functions
        static void PrintWarctic(bool tabbed = true);       //Prints Warctic version
        static void PrintSDL();                             //Prints SDL and SDL_Mixer versions
        static void PrintOgre();                            //Prints Ogre3d version
        static void PrintOpenGL();                          //Prints OpenGL version of current context
    };
};

#endif
