#include "LevelOne.h"
#include <GL/glut.h>

#include <math.h>

LevelOne::LevelOne() {
	glBegin(GL_LINES);
	glVertex3f(-1, 0, 0);
	glVertex3f(1, 0, 0);

	glVertex3f(0, -1, 0);
	glVertex3f(0, 1, 0);

	glVertex3f(0, 0, -1);
	glVertex3f(0, 0, 1);
	glEnd();

	glBegin(GL_QUADS);
	// top

	glColor3f(1.0f, 0.0f, 0.0f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);

	// left

	glColor3f(0.8f, 0.8f, 0.8f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);

	// right

	glColor3f(0.8f, 0.8f, 0.8f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// bottom

	glColor3f(0.2f, 0.2f, 0.2f);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-10.0f, -1.0f, 10.0f);
	glVertex3f(10.0f, -1.0f, 10.0f);
	glVertex3f(10.0f, -1.0f, -10.0f);
	glVertex3f(-10.0f, -1.0f, -10.0f);

	// front-left

	glColor3f(0.5f, 0.5f, 0.5f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-10.0f, 2.0f, 1.0f);
	glVertex3f(-10.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, 2.0f, 1.0f);

	// front-right

	glColor3f(0.5f, 0.5f, 0.5f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(10.0f, 2.0f, 1.0f);
	glVertex3f(10.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, 2.0f, 1.0f);

	// front-top

	glColor3f(0.5f, 0.5f, 0.5f);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 2.0f, 1.0f);
	glVertex3f(1.0f, 2.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	// left button

	glColor3f(0.9f, 0.9f, 0.9f);
	glNormal3f(0.0f, 0.0f, 0.1f);
	glVertex3f(-1.5f, 0.1f, 1.1f);
	glVertex3f(-1.5f, -0.1f, 1.1f);
	glVertex3f(-1.7f, -0.1f, 1.1f);
	glVertex3f(-1.7f, 0.1f, 1.1f);

	// right button

	glColor3f(0.9f, 0.9f, 0.9f);
	glNormal3f(0.0f, 0.0f, 0.1f);
	glVertex3f(1.5f, 0.1f, 1.1f);
	glVertex3f(1.5f, -0.1f, 1.1f);
	glVertex3f(1.7f, -0.1f, 1.1f);
	glVertex3f(1.7f, 0.1f, 1.1f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0f, 0.0f, 0.0f);
	int num_segments = 1000;
	float r = 0.07f;
	float cx = 1.6f;
	float cy = 0.0f;
	int ii;
	for (ii = 0; ii < num_segments; ii++) {
		float theta = 2.0f * 3.1415926f * float(ii) /
			      float(num_segments);  // get the current angle

		float x = r * cosf(theta);  // calculate the x component
		float y = r * sinf(theta);  // calculate the y component

		glVertex3f(x + cx, y + cy, 1.2f);  // output vertex
	}
	glEnd();
}
