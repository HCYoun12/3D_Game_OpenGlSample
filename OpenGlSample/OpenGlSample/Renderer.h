#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "ICleanUp.h"

class Object;
class GLFWwindow;

class Renderer : public ICleanUp
{
public:
	static Renderer* instance()
	{
		static Renderer instance;

		return &instance;
	}

public:
	void init();
	void setCameraPosition(glm::vec3 in_position);
	void render(RenderableObject* in_obj);
	virtual void shutDown() override;

private:
	glm::vec3 set_position;
	GLFWwindow* window;
};


#endif // ! __RENDERER_H__