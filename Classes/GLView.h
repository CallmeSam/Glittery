#ifndef  __GL_VIEW_H__
#define  __GL_VIEW_H__

#include <string>
#include "Macros.h"
#include <glad/glad.h>
#include "GLFW/glfw3.h"

NS_GTY_BEGIN

class GLView
{
public:
	static GLView* create(const std::string& name, const int& width, const int& height);
	
	GLView();
	
	void swapBuffer();

	bool init(const std::string& name, const int& width, const int& height);

	bool windowShouldClose();

	GLFWwindow* getWindow() { return _window; }



private:
	GLFWwindow* _window;
};


NS_GTY_END


#endif // ! __GL_VIEW_H__
