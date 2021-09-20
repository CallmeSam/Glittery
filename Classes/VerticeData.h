#ifndef __VERTICE_DATA_H__
#define __VERTICE_DATA_H__
#include "Macros.h"
NS_GTY_BEGIN

struct V2F_C3F {
	float point[2];
	float color[3];
};

struct V2F_C3F_T2F {
	float point[2];
	float color[3];
	float texCoord[2];
};

NS_GTY_END

USING_NS_GTY
static V2F_C3F triangleWhite[3] = {
	{-0.5f, -0.5f, 1.0f, 1.0f, 1.0f},
	{0.5f, -0.5f, 1.0f, 1.0f, 1.0f},
	{0.0f,  0.5f, 1.0f, 1.0f, 1.0f}
};

static V2F_C3F rectWhite[6] = {
	 0.5f,  0.5f, 1.0f, 1.0f, 1.0f,  // top right
	 0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // bottom right
	-0.5f,  0.5f, 1.0f, 1.0f, 1.0f,  // top left 
	// second triangle
	 0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // bottom right
	-0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // bottom left
	-0.5f,  0.5f, 1.0f, 1.0f, 1.0f   // top left
};

static V2F_C3F rectWhiteII[4] = {
	 0.5f,  0.5f, 1.0f, 1.0f, 1.0f,  // top right
	 0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // bottom right
	-0.5f, -0.5f, 1.0f, 1.0f, 1.0f,  // bottom left
	-0.5f,  0.5f, 1.0f, 1.0f, 1.0f   // top left 
};

static V2F_C3F_T2F rectWhiteIII[4] = {
	 0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,  // top right
	 0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.f, // bottom right
	-0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.f, 0.f,  // bottom left
	-0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.f, 1.f,   // top left 
};

static unsigned int rectIndices[] = {  // note that we start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};


#endif // !__VERTICE_DATA_H__

