#include "Scene.hpp"

#include "Engine.hpp"

Scene::Scene(Engine* engine) :
	engine(engine)
{

}

bool Scene::init()
{
	engine->getRoot()->createSceneManager(Ogre::SCENE_DYNAMIC, 4, Ogre::INSTANCING_CULLING_THREADED);

	return true;
}
