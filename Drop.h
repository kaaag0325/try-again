#pragma once
#include "SolidSphere.h"
#include "Collision.h"
class Drop {
public:
	void operator()(SolidSphere& sph1);

};