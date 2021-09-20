#include "PolygonNode.h"
#include "Shader.h"

NS_GTY_BEGIN

PolygonNode * PolygonNode::create(V2F_C3F * vertice, int num, unsigned int* indicesData, int indicesNum)
{
	PolygonNode* node = new PolygonNode();
	if (node->init(vertice, num, indicesData, indicesNum))
	{
		return node;
	}
	else
	{
		GTY_SAFE_DELETE(node);
		return nullptr;
	}
}

PolygonNode::PolygonNode()
	:_shader(nullptr),
	_num(0),
	_indicesNum(0)
{
	_shader = new Shader("../Shader/PolygonNode_V2F_C3F.vs", "../Shader/PolygonNode_V2F_C3F.fs");
}

void PolygonNode::draw()
{
	glBindVertexArray(_vao);
	_shader->use();
	if (_indicesNum > 0)
	{
		glDrawElements(GL_TRIANGLES, _indicesNum, GL_UNSIGNED_INT, nullptr);
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, _num);
	}
}

bool PolygonNode::init(V2F_C3F * vertice, int num, unsigned int* indicesData, int indicesNum)
{
	_num = num;
	GLuint vbo, ebo;
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &_vao);

	glBindVertexArray(_vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(V2F_C3F) * num, vertice, GL_STATIC_DRAW);
	
	if (indicesData)
	{
		_indicesNum = indicesNum;
		glGenBuffers(1, &ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * indicesNum, indicesData, GL_STATIC_DRAW);
	}

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(V2F_C3F), nullptr);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(V2F_C3F), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return true;
}


NS_GTY_END