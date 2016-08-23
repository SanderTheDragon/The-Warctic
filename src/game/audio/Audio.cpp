#include "game/audio/Audio.hpp"

#include <cmath>

#include "Config.hpp"
#include "misc/Error.hpp"
#include "misc/Logger.hpp"

Audio::Audio()
{
    
}
    
uint Audio::Initialize()
{
    int error = ERR_OK;
    
    device = alcOpenDevice(NULL);
    if (!device)
    {
#ifdef DEBUG
        Log(LOG_DEBUG_ERROR) << alGetError() << NEWLINE;
#endif
        
        Log(LOG_ERROR) << GetErrorString(ERR_AUDIO_DEVICE_NULL) << NEWLINE;
        return ERR_AUDIO_INITIALIZE;
    }
    
    Log(LOG_INFO) << "Audio device: " << alcGetString(NULL, ALC_DEFAULT_DEVICE_SPECIFIER) << NEWLINE;
    
    context = alcCreateContext(device, NULL);
    if (!alcMakeContextCurrent(context))
    {
#ifdef DEBUG
        Log(LOG_DEBUG_ERROR) << alGetError() << NEWLINE;
#endif
        
        Log(LOG_ERROR) << GetErrorString(ERR_AUDIO_CONTEXT) << NEWLINE;
        return ERR_AUDIO_INITIALIZE;
    }
    
    return ERR_OK;
}

void Audio::Sine(float freq, int time, uint rate)
{
#ifdef DEBUG
    Log(LOG_DEBUG) << "Playing sine wave at " << freq << " for " << time << " seconds at rate " << rate << NEWLINE;
#endif
    
    ALuint buffer;
    alGenBuffers(1, &buffer);

    uint bufferSize = time * rate;

    short* samples = new short[bufferSize];
    
    for(int i = 0; i < bufferSize; i++)
    {
        samples[i] = 32760 * sin((2.f * float(M_PI) * freq) / rate * i);
    }

    alBufferData(buffer, AL_FORMAT_MONO16, samples, bufferSize, rate);

    ALuint source = 0;
    alGenSources(1, &source);
    alSourcei(source, AL_BUFFER, buffer);
    alSourcePlay(source);
}
    
Audio::~Audio()
{
    context = alcGetCurrentContext();
    device = alcGetContextsDevice(context);
    
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);
}
