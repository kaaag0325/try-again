#pragma once

#include "SolidSphere.h"
class Shoot {
public:
	void operator()(SolidSphere& sph1, float& angle);
	void drawStick(float a);
};