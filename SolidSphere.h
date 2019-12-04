#pragma once
#include <iostream>
#include <cstdlib>
#include <GL/glut.h>
#include <math.h>

#include "Vector3.h"
#include "Material.h"

enum Color { RED = 1, GREEN = 2, BLUE = 3, Yellow =4 };
class SolidSphere 
{
public:
	SolidSphere();
	SolidSphere(float r, int sl, int st);
	Vector3 getProperties() const;
		
	void setCenter(float x, float y, float z);
	void setCenter(const Vector3& c);
	Vector3 getCenter() const;
	
	
	void setVelocity(float x, float y, float z);
	void setVelocity(const Vector3& v);
	Vector3 getVelocity() const;
	
	float getRadius() const;

	void setMTL();
	
	void move();
	void draw() const;


	void setColor(Color c);
	Color getColor();

private:
	Vector3 properties;
	Vector3 center;
	Vector3 velocity;
	Material mtl;
	Color b_color;
};
