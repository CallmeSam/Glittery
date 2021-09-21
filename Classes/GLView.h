#ifndef  __GL_VIEW_H__
#define  __GL_VIEW_H__

#include <string>
#include "Macros.h"
#include <glad/glad.h>
#include "GLFW/glfw3.h"

NS_GTY_BEGIN

class Camera;
class GLView
{
public:
	static GLView* create(const std::string& name, const int& width, const int& height);

	GLView();
	
	void swapBuffer();

	bool init(const std::string& name, const int& width, const int& height);

	bool windowShouldClose();

	GLFWwindow* getWindow() { return _window; }

	Camera* getCamera() { return _camera; }

	bool isFirstMouse;
	float lastX;
	float lastY;
	double deltaTime;

private:
	GLFWwindow* _window;
	Camera*  _camera;
};

class GLFWEventHandler
{
public:
	static void setGLView(GLView* view);

	//callback
	static void onFrameBufferSize(GLFWwindow* window, int width, int height);

	static void onGLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

	static void onMouseCallback(GLFWwindow* window, double xpos, double ypos);

	static void onScrollCallback(GLFWwindow* window, double xoffset, double yoffset);

private:
	static GLView* _view;
};


NS_GTY_END


#endif // ! __GL_VIEW_H__
