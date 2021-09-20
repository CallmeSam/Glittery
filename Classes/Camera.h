#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "Macros.h"
#include "glm/glm.hpp"

NS_GTY_BEGIN

class Camera
{
public:
	static Camera* create();
	Camera();

private:
	glm::vec3 _worldUp;
	glm::vec3 _pos;
	glm::vec3 _front;
	glm::vec3 _right;
	glm::vec3 _up;
};



NS_GTY_END





#endif // !__CAMERA_H__
