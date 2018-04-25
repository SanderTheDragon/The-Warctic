#ifndef SCENE_HPP_
#define SCENE_HPP_

class Engine;

class Scene
{
public:
	Scene(Engine* engine);

	bool init();

private:
	Engine* engine;
};

#endif
