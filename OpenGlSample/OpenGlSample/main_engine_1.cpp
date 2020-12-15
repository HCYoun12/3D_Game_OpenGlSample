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
	

	RenderableObject* cube = new RenderableObject();
	file_mgr->loadObj(
		cube,
		"cube.obj",
		"uvtemplate.DDS",
		"vs.shader",
		"fs.shader"
	);

	cube->setCameraPosition(glm::vec3(4.0f, 4.0f, 3.0f));
	renderer->addObject(cube);


	Sphere* sphere = new Sphere();

	NonRenderableObject* non = new NonRenderableObject();

	

	while (true)
	{
		renderer->update(non);
		
		renderer->render();

		renderer->Movement();
	}

	cube->shutDown();
	sphere->shutDown();
	renderer->shutDown();
	

	delete cube;
	delete non;
	delete sphere;

	return 0;

}