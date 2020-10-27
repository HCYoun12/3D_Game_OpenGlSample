#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <vector>

class RenderableObject;
class IUpdater;
class ICleanUp;
class GLFWwindow;

class IRenderer
{
public:


public:
	virtual void render() = 0;
};


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
	void Movement();

	void render();
	void addObject(RenderableObject* render_obj);

	void update(IUpdater* src_obj);

	virtual void shutDown() override;

	GLFWwindow* window;

private:
	glm::vec3 set_position;
	
	float moveX = 0.0f;
	float moveY = 0.0f;
	//std::vector<IRenderer*>* _renderingObjArr;

	RenderableObject* src_obj;

};


#endif // ! __RENDERER_H__