#include "GLView.h"
#include <iostream>

NS_GTY_BEGIN
void onFrameBufferSize(GLFWwindow* window, int width, int height);
void onGLFWKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
//void processInput(GLFWwindow* window);

GLView * GLView::create(const std::string & name, const int & width, const int & height)
{
	GLView* pRet = new GLView();
	if (pRet->init(name, width, height))
	{
		return pRet;
	}
	else
	{
		GTY_SAFE_DELETE(pRet);
		return nullptr;
	}
}

GLView::GLView()
	:_window(nullptr)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void GLView::swapBuffer()
{
	if (_window)
	{
		glfwSwapBuffers(_window);
	}
}

bool GLView::init(const std::string & name, const int & width, const int & height)
{
	_window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
	if (!_window)
	{
		std::cout << "FAILED TO CREATE GLFW WINDOW" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, onFrameBufferSize);
	glfwSetKeyCallback(_window, onGLFWKeyCallback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "FAILED TO INITIALIZE GLAD" << std::endl;
		return false;
	}

	return true;
}

bool GLView::windowShouldClose()
{
	if (_window)
	{
		return glfwWindowShouldClose(_window);
	}

	return true;
}

void onFrameBufferSize(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void onGLFWKeyCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE)
		{
			glfwSetWindowShouldClose(window, true);
		}
	}
}

//void processInput(GLFWwindow * window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, true);
//	}
//}
NS_GTY_END

