#define _CRT_SECURE_NO_WARNINGS

#pragma comment(lib, "OpenGL32.lib")
#pragma comment(lib, "lib-vc2017/glew32.lib")
#pragma comment(lib, "lib-vc2017/glfw3.lib")

#include "Object.h"
#include "FileManager.h"
#include "Renderer.h"

#include "Sphere.h"

int main()
{
	FileManager* file_mgr = FileManager::instance();

	Renderer* renderer = Renderer::instance();
	renderer->init();
	renderer->setCameraPosition(glm::vec3(4.0f, 4.0f, 3.0f));

	RenderableObject* cube = new RenderableObject();
	cube->setPosition(glm::vec3(3.0f, 0.0f, 0.0f));
	renderer->addObject(cube);


	Sphere* sphere = new Sphere();

	NonRenderableObject* non = new NonRenderableObject();


	file_mgr->loadObj(
		cube,
		"cube.obj",
		"uvtemplate.DDS",
		"vs.shader",
		"fs.shader"
	);

	while (true)
	{
		renderer->update(non);
		renderer->render();
	}

	cube->shutDown();
	sphere->shutDown();
	renderer->shutDown();
	

	delete cube;
	delete non;
	delete sphere;

	return 0;

}