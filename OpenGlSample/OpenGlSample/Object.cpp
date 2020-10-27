#include "Object.h"

#include "include/GL/glew.h"
#include "include/GLFW/glfw3.h"

class GLFWwindow;

void RenderableObject::shutDown()
{
	// Cleanup VBO and shader
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);
}

void RenderableObject::update()
{

}

void RenderableObject::render()
{

}

void NonRenderableObject::update()
{
	
}