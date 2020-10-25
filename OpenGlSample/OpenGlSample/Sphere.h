#pragma once

#include "Object.h"

class Sphere : public RenderableObject
{
public:
	virtual void shutDown() override;
};