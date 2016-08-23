#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include <iostream>

#include "AL/al.h"
#include "AL/alc.h"

class Audio
{
private:
    ALCdevice* device;
    ALCcontext* context;
    
public:
    Audio();
    
    uint Initialize();
    
    void Sine(float freq, int time, uint rate);
    
    virtual ~Audio();
};

#endif
