#include "Camera.h"
#include "glm/gtc/matrix_transform.hpp"

NS_GTY_BEGIN

enum class CAMERA_MOVEMENT {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

Camera * Camera::create(const glm::vec3& pos, const glm::vec3& lookPos, const glm::vec3& up)
{
	Camera* camera = new Camera();
	if (camera->init(pos, lookPos, up))
	{
		return camera;
	}
	else
	{
		GTY_SAFE_DELETE(camera);
		return nullptr;
	}
}

Camera::Camera()
	:_pitch(0),
	_yaw(-90),
	_fov(45),
	_movementSpeed(2.5f),
	_mouseSensitivity(0.1f)
{
}

bool Camera::init(const glm::vec3 & pos, const glm::vec3 & lookPos, const glm::vec3 & up)
{
	_pos = pos;
	_worldUp = up;

	updateTransform();
	return true;
}

glm::mat4 Camera::getLookUpMatrix()
{
	return glm::lookAt(_pos, _pos + _front, _worldUp);
}

void Camera::onKeyPress(CAMERA_MOVEMENT movement, float deltaTime)
{
	float velocity = _movementSpeed * deltaTime;
	if (movement == CAMERA_MOVEMENT::FORWARD)
		_pos += _front * velocity;
	if (movement == CAMERA_MOVEMENT::BACKWARD)
		_pos -= _front * velocity;
	if (movement == CAMERA_MOVEMENT::LEFT)
		_pos -= _front * velocity;
	if (movement == CAMERA_MOVEMENT::RIGHT)
		_pos += _front * velocity;
}

void Camera::onMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
	xoffset *= _mouseSensitivity;
	yoffset *= _mouseSensitivity;

	_yaw += xoffset;
	_pitch += yoffset;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch)
	{
		if (_pitch > 89.0f)
			_pitch = 89.0f;
		if (_pitch < -89.0f)
			_pitch = -89.0f;
	}

	// update Front, Right and Up Vectors using the updated Euler angles
	updateTransform();
}

void Camera::onMouseScroll(float yoffset)
{
	_zoom -= (float)yoffset;
	if (_zoom < 1.0f)
		_zoom = 1.0f;
	if (_zoom > 45.0f)
		_zoom = 45.0f;
}

void Camera::updateTransform()
{
	_front.x = glm::cos(glm::radians(_pitch)) * glm::cos(glm::radians(_yaw));
	_front.y = glm::sin(glm::radians(_pitch));
	_front.z = glm::cos(glm::radians(_pitch)) * glm::sin(glm::radians(_yaw));
	_front = glm::normalize(_front);

	_right = glm::normalize(glm::cross(_front, _worldUp));
	_up = glm::normalize(glm::cross(_front, _up));
}

NS_GTY_END

