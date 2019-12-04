#include "SolidSphere.h"


SolidSphere::SolidSphere() {
	properties.setXYZ(20, 15, 15);
	setCenter(150, 200, 0);
	setVelocity(0, 0, 0);
	int RanColor = rand() % 4 + 1;
	setColor(static_cast<Color> (RanColor));
	setMTL();
}
SolidSphere::SolidSphere(float r, int sl, int st) {
	properties.setXYZ(r, sl, st);
	int RanColor = rand() % 4 + 1;
	setColor(static_cast<Color> (RanColor));
	setMTL();
}



Vector3 SolidSphere::getProperties() const {
	return properties;
}


void SolidSphere::draw() const {
	glPushMatrix();

	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_EMISSION, mtl.getEmission());
	glMaterialfv(GL_FRONT, GL_AMBIENT, mtl.getAmbient());
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mtl.getDiffuse());
	glMaterialfv(GL_FRONT, GL_SPECULAR, mtl.getSpecular());
	glMaterialfv(GL_FRONT, GL_SHININESS, mtl.getShininess());

	glTranslatef(center[0], center[1], center[2]);
	glutSolidSphere(properties[0], properties[1], properties[2]);
	glPopMatrix();
}
void SolidSphere::setCenter(float x, float y, float z) {
	center[0] = x;
	center[1] = y;
	center[2] = z;
}

void SolidSphere::setCenter(const Vector3& c) {
	center = c;
}

Vector3 SolidSphere::getCenter() const {
	return center;
}

void SolidSphere::setVelocity(float x, float y, float z) {
	velocity[0] = x;
	velocity[1] = y;
	velocity[2] = z;
}

void SolidSphere::setVelocity(const Vector3& v) {
	velocity = v;
}

Vector3 SolidSphere::getVelocity() const {
	return velocity;
}

void SolidSphere::move() {
	center = center + velocity;
}

void SolidSphere::setMTL() {
	switch (b_color)
	{
	case RED:
		mtl.setAmbient(1, 0, 0, 1);
		break;
	case GREEN:
		mtl.setAmbient(0, 1, 0, 1);
		break;
	case BLUE:
		mtl.setAmbient(0, 0, 1, 1);
		break;
	case Yellow:
		mtl.setAmbient(1, 1, 0, 1);
		break;
	default:
		break;
	}
	mtl.setEmission(0.1, 0.1, 0.1, 1);
	mtl.setDiffuse(0.5, 0.5, 0.5, 1);
	mtl.setSpecular(1.0, 1.0, 1.0, 1);
	mtl.setShininess(10);
}

void  SolidSphere::setColor(Color c) {
	b_color = c;
};
Color SolidSphere::getColor() {
	return b_color;
};
float SolidSphere::getRadius() const {
	return properties[0];
}