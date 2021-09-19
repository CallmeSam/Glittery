#include "GLView.h"
USING_NS_GTY

int main()
{
	GLView* view = GLView::create("Glittery", 800, 600);
	if (view)
	{
		while (!view->windowShouldClose())
		{
			glfwPollEvents();
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			view->swapBuffer();
		}
	}
		
	glfwTerminate();
	return 0;
}