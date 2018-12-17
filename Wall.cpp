#include "Wall.hpp"

Wall::Wall(glm::vec3 first, glm::vec3 second){
	firstPoint = first;
	secondPoint = second;
}

void Wall::Draw(){
	glBegin(GL_QUADS);
		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex3f(firstPoint.x, firstPoint.y, firstPoint.z);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(firstPoint.x, 2.0f, firstPoint.z);
		glColor3f(0.7f, 0.7f, 0.7f);
		glVertex3f(secondPoint.x, 2.0f, secondPoint.z);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(secondPoint.x, secondPoint.y, secondPoint.z);
	glEnd();
}
