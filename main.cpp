#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

#include "Collision.h"
#include "Light.h"
#include "Shoot.h"
#include "windows.h"
using namespace std;

#define WIDTH 600
#define HEIGHT 1000

#define boundaryL 0
#define boundaryR 600
#define boundaryT (460*sqrt(3)+20)
#define boundaryB (100*sqrt(3)-20)

#define radius 30
#define PI 3.141492
#define RadianConstant (180/PI)
Light light(600, 1000, 300, GL_LIGHT0);

vector<SolidSphere*> spheres;

CollisionHandling colHandler;
Shoot shoot;

float angle = PI/2 ;
vector<int> arr;


void init() {
	srand((unsigned int)time(0));
	light.setAmbient(0.5, 0.5, 0.5, 1.0);
	light.setDiffuse(0.7, 0.7, 0.7, 1.0);
	light.setSpecular(1.0, 1.0, 1.0, 1.0);

	// 화살표랑 넥스트 공 채우기
	spheres.push_back(new SolidSphere());
	spheres.push_back(new SolidSphere());
	spheres.push_back(new SolidSphere());
	spheres[0]->setCenter(2200, 200, 0);
	spheres[1]->setCenter(300, 200, 0);
	arr.push_back(0);
}

// 같은공 드랍 함수

void  dropsame(SolidSphere& sph)
{
	CollisionDetection samecollision;
	for (int i = 0; i < spheres.size() - 3; i++) {
		
		if (samecollision(sph, *spheres[i]) && sph.getColor() == spheres[i]->getColor() && arr.back() != i) {
			arr.push_back(i);

			dropsame(*spheres[i]);
		}
		else {}
			
		
	}

}



void idle() {
	//공끼리 충돌 
	for (int i = 0; i < spheres.size() - 3; i++)
		colHandler(*spheres[i], *spheres[spheres.size() - 3]);
	//천장 충돌 

	colHandler(*spheres[spheres.size() - 3]);

	//좌우 충돌
	if (spheres[spheres.size() - 3]->getCenter()[0] + spheres[spheres.size() - 3]->getRadius() >= boundaryR ||
		spheres[spheres.size() - 3]->getCenter()[0] - spheres[spheres.size() - 3]->getRadius() <= boundaryL)
		spheres[spheres.size() - 3]->setVelocity(-spheres[spheres.size() - 3]->getVelocity()[0], spheres[spheres.size() - 3]->getVelocity()[1], spheres[spheres.size() - 3]->getVelocity()[2]);

	
	
	
	// 같은공 드랍
	dropsame(*spheres[spheres.size() - 3]);

	for (int i = 0; i < arr.size() - 1; i++)
		spheres[arr[i]]->setVelocity(0, -20, -10);


	for (int i = 0; i < spheres.size() - 1; i++)
		spheres[i]->move();



	// 주위가 빈 공 드랍

	
	
	glutPostRedisplay();
	// 게임오버
	

}

void renderScene() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(boundaryL, boundaryR, 0, HEIGHT, -300.0, 300.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	light.draw();

	//for (auto sph : spheres)
	//	sph.draw();
	for (int i = 0; i < spheres.size(); ++i) {
		spheres[i]->draw();
	}
	shoot.drawStick(angle*RadianConstant);

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);

	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case ('w'):
		if (spheres[spheres.size() - 3]->getVelocity()[1] == 0) {
			shoot(*spheres[spheres.size() - 2], angle);
			spheres.push_back(new SolidSphere());
			spheres[spheres.size() - 2]->setCenter(300, 200, 0);
		}
		break;
	case ('a'):
		angle = angle + 0.05;
		cout << angle << endl;
		break;
	case ('d'):
		angle = angle - 0.05;
		cout << angle << endl;
		break;
	default:
		break;
	}
	glutPostRedisplay();
	
}


int main(int argc, char** argv) {
	
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(650, 0);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Final Project_Puzzle bubble");
	init();

	// register callbacks
	glutDisplayFunc(renderScene);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}