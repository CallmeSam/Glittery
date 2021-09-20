#include "Sprite2D.h"
#include "Shader.h"
#include "Texture2D.h"

NS_GTY_BEGIN

Sprite2D * Sprite2D::create(const std::string & path)
{
	Sprite2D* sprite = new Sprite2D();
	if (sprite->init(path))
	{
		return sprite;
	}
	GTY_SAFE_DELETE(sprite);
	return nullptr;
}

Sprite2D::Sprite2D()
	:_shader(nullptr),
	_texture(nullptr)
{
	_shader = new Shader("../Shader/Sprite_V2F_C3F_T2F.vs", "../Shader/Sprite_V2F_C3F_T2F.fs");
}

void Sprite2D::draw()
{
	glBindVertexArray(_vao);
	_texture->use();
	_shader->use();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}

bool Sprite2D::init(const std::string & path)
{
	_texture = Texture2D::create(path);
	if (!_texture)
		return false;

	GLuint vbo, ebo;
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &_vao);

	glBindVertexArray(_vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(V2F_C3F_T2F) * 4, rectWhiteIII, GL_STATIC_DRAW);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * 6, rectIndices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(V2F_C3F_T2F), nullptr);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(V2F_C3F_T2F), (void*)(2 * sizeof(float)));
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(V2F_C3F_T2F), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	return true;
}


NS_GTY_END