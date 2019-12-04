#include "Vector3.h"

Vector3::Vector3() {
	setXYZ(0, 0, 0);
}

void Vector3::setXYZ(float x, float y, float z) {
	xyz[0] = x;
	xyz[1] = y;
	xyz[2] = z;
}

const float* Vector3::getXYZ() const {
	return xyz;
}

Vector3& Vector3::operator=(const Vector3& vec3) {
	setXYZ(vec3.xyz[0], vec3.xyz[1], vec3.xyz[2]);

	return (*this);
}

float& Vector3::operator[](const int i) {
	return xyz[i];
}

float Vector3::operator[](const int i) const {
	return xyz[i];
}

Vector3 operator+(const Vector3& v1, const Vector3& v2) {
	Vector3 tmp;
	for (int i = 0; i < 3; i++)
		tmp[i] = v1[i] + v2[i];

	return tmp;
}

Vector3 operator-(const Vector3& v1, const Vector3& v2) {
	Vector3 tmp;
	for (int i = 0; i < 3; i++)
		tmp[i] = v1[i] - v2[i];

	return tmp;
}

Vector3 operator-(const Vector3& v) {
	Vector3 tmp;
	tmp.setXYZ(-v.getXYZ()[0], -v.getXYZ()[1], -v.getXYZ()[2]);

	return tmp;
}

Vector3 operator*(const float s, const Vector3& vec3) {
	Vector3 tmp;
	tmp.setXYZ(s * vec3.getXYZ()[0], s * vec3.getXYZ()[1], s * vec3.getXYZ()[2]);

	return tmp;
}

float dotProduct(const Vector3& v1, const Vector3& v2) {
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}