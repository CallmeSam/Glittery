#include "GLView.h"
#include "Camera.h"
#include <iostream>

NS_GTY_BEGIN
//void processInput(GLFWwindow* window);

GLView* GLFWEventHandler::_view = nullptr;;

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
	:_window(nullptr),
	isFirstMouse(true),
	lastX(0),
	lastY(0)
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

	_camera = Camera::create(glm::vec3(0.f, 0.f, 3.f));
	lastX = width / 2.f;
	lastY = height / 2.f;

	GLFWEventHandler::setGLView(this);
	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, GLFWEventHandler::onFrameBufferSize);
	glfwSetKeyCallback(_window, GLFWEventHandler::onGLFWKeyCallback);
	glfwSetCursorPosCallback(_window, GLFWEventHandler::onMouseCallback);
	glfwSetScrollCallback(_window, GLFWEventHandler::onScrollCallback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

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

//void processInput(GLFWwindow * window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//	{
//		glfwSetWindowShouldClose(window, true);
//	}
//}


//EventHandler
void GLFWEventHandler::setGLView(GLView * view)
{
	_view = view;
}

void GLFWEventHandler::onFrameBufferSize(GLFWwindow * window, int width, int height)
{
	if (_view)
	{
		glViewport(0, 0, width, height);
	}
}

void GLFWEventHandler::onGLFWKeyCallback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	if (_view)
	{
		if (action == GLFW_PRESS)
		{
			if (key == GLFW_KEY_ESCAPE)
			{
				glfwSetWindowShouldClose(window, true);
			}

			Camera* camera = _view->getCamera();
			double deltaTime = _view->deltaTime;
			if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
				camera->onKeyPress(CAMERA_MOVEMENT::FORWARD, deltaTime);
			if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
				camera->onKeyPress(CAMERA_MOVEMENT::BACKWARD, deltaTime);
			if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
				camera->onKeyPress(CAMERA_MOVEMENT::LEFT, deltaTime);
			if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
				camera->onKeyPress(CAMERA_MOVEMENT::RIGHT, deltaTime);
		}
	}
}

void GLFWEventHandler::onMouseCallback(GLFWwindow * window, double xpos, double ypos)
{
	if (_view)
	{
		Camera* camera = _view->getCamera();
		if (_view->isFirstMouse)
		{
			_view->lastX = xpos;
			_view->lastY = ypos;
			_view->isFirstMouse = false;
		}

		float xoffset = xpos - _view->lastX;
		float yoffset = _view->lastY - ypos; // reversed since y-coordinates go from bottom to top

		_view->lastX = xpos;
		_view->lastY = ypos;

		camera->onMouseMovement(xoffset, yoffset);
	}
}

void GLFWEventHandler::onScrollCallback(GLFWwindow * window, double xoffset, double yoffset)
{
	if (_view)
	{
		Camera* camera = _view->getCamera();
		camera->onMouseScroll(yoffset);
	}
}

NS_GTY_END

