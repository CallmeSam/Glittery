#ifndef __SPRITE_2D_H__
#define __SPRITE_2D_H__
#include "Macros.h"
#include <string>
#include "glad/glad.h"
#include "VerticeData.h"
#include "math/Vec2.h"

NS_GTY_BEGIN
class Shader;
class Texture2D;

class Sprite2D
{
public:
	static Sprite2D* create(const std::string& path);
	Sprite2D();

	void draw();
private:
	bool init(const std::string& path);

	Texture2D* _texture;
	Shader* _shader;
	GLuint _vao;
	Vec2 _size;
};


NS_GTY_END






#endif // !__SPRITE_2D_H__
