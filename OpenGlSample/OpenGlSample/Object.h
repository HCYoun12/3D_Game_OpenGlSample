#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <vector>

#include "glm/glm.hpp"
#include "include/GL/glew.h"

#include "ICleanUp.h"

class Object : public ICleanUp
{
public:
	glm::vec3 obj_position;

public:
	void setPosition(glm::vec3 in_position);

public:
	virtual ~Object() {}
};

class RenderableObject : public Object
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
	virtual void shutDown() override;

};

class NonRenderableObject : public Object
{
public:
	virtual void shutDown() override {}
};



#endif // !__OBJECT_H__