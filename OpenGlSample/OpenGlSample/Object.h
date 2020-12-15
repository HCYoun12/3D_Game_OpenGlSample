#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <vector>

#include "glm/glm.hpp"
#include "include/GL/glew.h"

#include "ICleanUp.h"
#include "IUpdater.h"
#include "Renderer.h"

class Object : public ICleanUp, public IUpdater
{

public:
	virtual ~Object() {}
};

class RenderableObject : public Object, public IRenderer
{
public:
	GLuint VertexArrayID;
	GLuint programID;
	GLuint MatrixID;
	GLuint ViewMatrixID;
	GLuint ModelMatrixID;
	GLuint Texture;
	GLuint TextureID;

	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	GLuint vertexbuffer;
	GLuint uvbuffer;
	GLuint normalbuffer;
	GLuint LightID;

public:
	void setCameraPosition(glm::vec3 in_position);
	void getMovement(float x, float y);

	virtual void update() override;
	virtual void render() override;
	virtual void shutDown() override;


private:
	glm::vec3 set_position;
	float ObjmoveX = 0.0f;
	float ObjmoveY = 0.0f;
};

class NonRenderableObject : public Object
{
public:
	virtual void shutDown() override {}
	virtual void update() override;


};



#endif // !__OBJECT_H__