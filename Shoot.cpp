#include "Shoot.h"

void Shoot::operator()(SolidSphere& sph1,float& angle) {
	sph1.setCenter(300, 200, 0);
	sph1.setVelocity(10*cosf(angle), 10*sinf(angle), 0);
};

void Shoot::drawStick(float a) {
	glPushMatrix();

	glShadeModel(GL_SMOOTH);

	glTranslatef(300, 200, -100);
	glRotatef(90, 1, 0, 0);
	glRotatef(a, 0, 1, 0);
	static GLfloat mat_ambdif[] = { 1.0, 1.0 , 1.0 , 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambdif);
	glutSolidTeapot(50);
	glPopMatrix();
};