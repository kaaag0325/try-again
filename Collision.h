#pragma once
#include "SolidSphere.h"

class CollisionDetection
{
public:
	bool operator()(const SolidSphere& sph1, const SolidSphere& sph2);
	bool operator()(const SolidSphere& sph1);
};
class CollisionHandling
{
public:
	void operator()(SolidSphere& sph1, SolidSphere& sph2);
	void operator()(SolidSphere& sph1);
};


