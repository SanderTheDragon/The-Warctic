#include "Scene.hpp"

#include "Engine.hpp"

Scene::Scene(Engine* engine) :
	engine(engine)
{

}

bool Scene::init()
{
	engine->getRoot()->createSceneManager(Ogre::ST_GENERIC, 2, Ogre::INSTANCING_CULLING_THREADED);

	return true;
}
