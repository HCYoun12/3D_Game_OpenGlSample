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
	
	void Movement();

	void addObject(IRenderer* render_obj)
	{
		_renderingObjArr.push_back(render_obj);
	}

	void render();
	

	void update(IUpdater* src_obj);

	virtual void shutDown() override;

	

private:
	GLFWwindow* window;
	
	float moveX = 0.0f;
	float moveY = 0.0f;

	std::vector<IRenderer*> _renderingObjArr;

	

};


#endif // ! __RENDERER_H__