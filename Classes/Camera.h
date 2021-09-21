#ifndef __CAMERA_H__
#define __CAMERA_H__
#include "Macros.h"
#include "glm/glm.hpp"

NS_GTY_BEGIN
enum class CAMERA_MOVEMENT {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};


class Camera
{
public:
	static Camera* create(const glm::vec3& pos, const glm::vec3& lookPos = glm::vec3(0.f, 0.f, 0.f), const glm::vec3& up = glm::vec3(0.f, 1.f, 0.f));
	Camera();

	bool init(const glm::vec3& pos, const glm::vec3& lookPos, const glm::vec3& up);

	glm::mat4 getLookUpMatrix();

	void onKeyPress(CAMERA_MOVEMENT movement, float deltaTime);

	void onMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

	void onMouseScroll(float yoffset);

	float getFov() { return _fov; }

	float getMovementSpeed() { return _movementSpeed; }

	float getMouseSensitivity() { return _mouseSensitivity; }

	float getZoom() { return _zoom; }

private:
	void updateTransform();

	glm::vec3 _worldUp;
	glm::vec3 _pos;
	glm::vec3 _front;
	glm::vec3 _right;
	glm::vec3 _up;
	float _pitch;
	float _yaw;
	float _fov;
	float _movementSpeed;
	float _mouseSensitivity;
	float _zoom;
};



NS_GTY_END





#endif // !__CAMERA_H__
