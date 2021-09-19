#ifndef __POLYGON_NODE_H__
#define __POLYGON_NODE_H__

#include "Macros.h"
#include "glad/glad.h"

NS_GTY_BEGIN

class Shader;

struct V2F_C3F {
	float point[2];
	float color[3];
};

class PolygonNode
{
public:
	static PolygonNode* create(V2F_C3F* vertice, int num);
	PolygonNode();
	void draw();

private:
	bool init(V2F_C3F* vertice, int num);

	Shader* _shader;
	GLuint _vao;
	int _num;
};


NS_GTY_END




#endif // !__POLYGON_NODE_H__
