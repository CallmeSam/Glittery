#ifndef __POLYGON_NODE_H__
#define __POLYGON_NODE_H__

#include "Macros.h"
#include "glad/glad.h"
#include "VerticeData.h"

NS_GTY_BEGIN

class Shader;

class PolygonNode
{
public:
	static PolygonNode* create(V2F_C3F* vertice, int num, unsigned int* indicesData = nullptr, int indicesNum = 0);
	PolygonNode();
	void draw();

private:
	bool init(V2F_C3F* vertice, int num, unsigned int* indicesData, int indicesNum);

	Shader* _shader;
	GLuint _vao;
	int _num;
	int _indicesNum;
};


NS_GTY_END




#endif // !__POLYGON_NODE_H__
