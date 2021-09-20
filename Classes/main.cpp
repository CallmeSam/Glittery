#include "GLView.h"
#include "PolygonNode.h"
#include "VerticeData.h"
#include "Sprite2D.h"
USING_NS_GTY

int main()
{
	GLView* view = GLView::create("Glittery", 800, 600);
	if (view)
	{
		//PolygonNode* node = PolygonNode::create(rectWhiteII, 4, rectIndices, 6);
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		Sprite2D* sprite2d = Sprite2D::create("../Resource/btn.png");

		while (!view->windowShouldClose())
		{
			glfwPollEvents();
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			//node->draw();
			sprite2d->draw();

			view->swapBuffer();
		}
	}
		
	glfwTerminate();
	return 0;
}