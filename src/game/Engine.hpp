#ifndef ENGINE_HPP_
#define ENGINE_HPP_

class Engine
{
private:
    bool running;
    
public:
    Engine();
    
    bool IsRunning() { return running; }
    
    void Loop();
    
    virtual ~Engine();
};

#endif
