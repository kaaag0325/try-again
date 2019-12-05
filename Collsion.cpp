#include "Collision.h"
// ���浹����
bool CollisionDetection::operator()(const SolidSphere& sph1, const SolidSphere& sph2) {
	Vector3 dist_vec = sph1.getCenter() - sph2.getCenter();
	float distance = sqrt(dotProduct(dist_vec, dist_vec));

	if (sph1.getRadius() + sph2.getRadius()+1 >= distance)
		return true;
	return false;
}


// õ���浹����
bool CollisionDetection::operator()(const SolidSphere& sph1) {
	if (sph1.getCenter()[1] >= 460*sqrt(3))
		return true;
	return false;
}

//������ �浹
void CollisionHandling::operator()(SolidSphere& sph1, SolidSphere& sph2) {
	CollisionDetection colDetector;
	float xd = 0;
	int yd = 0;
	if (colDetector(sph1, sph2) ) {
		yd = round(sph2.getCenter()[1] / (20 * sqrt(3)));
		if (yd % 2 == 1) {
			xd = round((sph2.getCenter()[0] - 20) / 40);
			sph2.setCenter(xd * 40 + 20, yd * (20 * sqrt(3)), sph2.getCenter()[2]);
		}
		else {
			xd = round(sph2.getCenter()[0] / 40);
			sph2.setCenter(xd * 40, yd * (20 * sqrt(3)), sph2.getCenter()[2]);
		}
		sph1.setVelocity(0, 0, 0);
		sph2.setVelocity(0, 0, 0);
	}
}


//õ�� �浹
void CollisionHandling::operator()(SolidSphere& sph1) {
	CollisionDetection colDetector;
	int xy[2];
	float xd = 0;
	int yd = 0;
	if (colDetector(sph1)) {
		xd = round((sph1.getCenter()[0] - 20) / 40);
		yd = round(sph1.getCenter()[1] / (20 * sqrt(3)));
		if (yd % 2 == 1) {
			sph1.setCenter(xd * 40 + 20, yd * (20 * sqrt(3)), sph1.getCenter()[2]);;
		}
		else {
			sph1.setCenter(xd * 40, yd * (20 * sqrt(3)), sph1.getCenter()[2]);
		}
		sph1.setVelocity(0, 0, 0);
	}
}