#include "PolygonNode.h"
#include "Shader.h"

NS_GTY_BEGIN

PolygonNode * PolygonNode::create(V2F_C3F * vertice, int num)
{
	PolygonNode* node = new PolygonNode();
	if (node->init(vertice, num))
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
	_num(0)
{
	_shader = new Shader(nullptr, nullptr);
}

void PolygonNode::draw()
{
	glBindVertexArray(_vao);
	_shader->use();
	glDrawArrays(GL_TRIANGLES, 0, _num);
}

bool PolygonNode::init(V2F_C3F * vertice, int num)
{
	_num = num;
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &_vao);

	glBindVertexArray(_vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, sizeof(V2F_C3F) * num, vertice, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(V2F_C3F), nullptr);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(V2F_C3F), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return true;
}


NS_GTY_END