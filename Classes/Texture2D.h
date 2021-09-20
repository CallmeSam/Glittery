#ifndef __TEXTURE_2D_H__
#define __TEXTURE_2D_H__

#include "Macros.h"
#include <string>
#include "glad/glad.h"
#include "math/Vec2.h"

NS_GTY_BEGIN

class Texture2D
{
public:
	static Texture2D* create(const std::string& path);
	Texture2D();

	void use();

	Vec2 getSize();
private:
	bool init(const std::string& path);
	GLuint _texture;
	Vec2 _size;
	int _channel;
};



NS_GTY_END



#endif // !__TEXTURE_2D_H__
