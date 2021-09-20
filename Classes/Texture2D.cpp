#include "Texture2D.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#include <iostream>

NS_GTY_BEGIN

Texture2D * Texture2D::create(const std::string & path)
{
	Texture2D* pRet = new Texture2D();
	if (pRet->init(path))
	{
		return pRet;
	}
	else
	{
		GTY_SAFE_DELETE(pRet);
		return nullptr;
	}
}

Texture2D::Texture2D()
	:_texture(0)
{
	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, _texture);
}

void Texture2D::use()
{
	glBindTexture(GL_TEXTURE_2D, _texture);
}

Vec2 Texture2D::getSize()
{
	return _size;
}

bool Texture2D::init(const std::string & path)
{
	int width, height;
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &_channel, 0);
	if (!data)
	{
		std::cout << "Failed to load texture:" << path << std::endl;
		return false;
	}
	
	_size.x = width;
	_size.y = height;

	glBindTexture(GL_TEXTURE_2D, _texture);
	GLuint format = 0;
	if (_channel == 4)
	{
		format = GL_RGBA;
	}
	else if(_channel == 3)
	{
		format = GL_RGB;
	}
	else
	{
		format = GL_RED;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	return true;
}


NS_GTY_END