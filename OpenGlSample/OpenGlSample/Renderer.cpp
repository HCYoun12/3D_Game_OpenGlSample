#include <stdio.h>

#include "Object.h"
#include "Renderer.h"
#include "ICleanUp.h"
#include "IUpdater.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h" 
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

void Renderer::init()
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(1024, 768, "Custom Engine Sample", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Set the mouse at the center of the screen
	glfwPollEvents();
	glfwSetCursorPos(window, 1024 / 2, 768 / 2);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

}



void Renderer::update(IUpdater* src_obj)
{
	src_obj->update();
}

void Renderer::Movement()
{
	render_obj->getMovement(moveX, moveY);

	if (glfwGetKey(window, GLFW_KEY_RIGHT))
	{
		moveX = moveX + 0.001f;
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT))
	{
		moveX = moveX - 0.001f;
	}

	if (glfwGetKey(window, GLFW_KEY_UP))
	{
		moveY = moveY + 0.001f;
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN))
	{
		moveY = moveY - 0.001f;
	}

	
}



void Renderer::render()
{
	for (std::vector<IRenderer*>::iterator iter = _renderingObjArr.begin(); 
		iter != _renderingObjArr.end(); 
		++iter)
	{
		(*iter)->render();
		

	}
	

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	
		
}

void Renderer::shutDown()
{
	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}
