#include "Person.hpp"

Person::Person(std::vector<glm::vec3> bodyPoints){
	unsigned n1 =  bodyPoints.size();

	for(int i = 0; i < n1; i++)
		body.push_back(bodyPoints[i]);
}

void Person::Draw(){
	glBegin(GL_QUADS);
		glColor3f(0.8f, 0.1f, 0.1f);

		glVertex3f(body[0].x, body[0].y, body[0].z);
		glVertex3f(body[1].x, body[1].y, body[1].z);
		glVertex3f(body[1].x, body[1].y + 1.1f, body[1].z);
		glVertex3f(body[0].x, body[0].y + 1.1f, body[0].z);
		
		glVertex3f(body[1].x, body[1].y, body[1].z);
		glVertex3f(body[2].x, body[2].y, body[2].z);
		glVertex3f(body[2].x, body[2].y + 1.1f, body[2].z);
		glVertex3f(body[1].x, body[1].y + 1.1f, body[1].z);
		
		glVertex3f(body[2].x, body[0].y, body[2].z);
		glVertex3f(body[3].x, body[1].y, body[3].z);
		glVertex3f(body[3].x, body[1].y + 1.1f, body[3].z);
		glVertex3f(body[2].x, body[0].y + 1.1f, body[2].z);
		
		glVertex3f(body[3].x, body[3].y, body[3].z);
		glVertex3f(body[0].x, body[0].y, body[0].z);
		glVertex3f(body[0].x, body[0].y + 1.1f, body[0].z);
		glVertex3f(body[3].x, body[3].y + 1.1f, body[3].z);
		


		
		glVertex3f(body[0].x, body[0].y + 1.2f, body[0].z);
		glVertex3f(body[1].x, body[1].y + 1.2f, body[1].z);
		glVertex3f(body[1].x, body[1].y + 1.5f, body[1].z);
		glVertex3f(body[0].x, body[0].y + 1.5f, body[0].z);
		
		glVertex3f(body[1].x, body[1].y + 1.2f, body[1].z);
		glVertex3f(body[2].x, body[2].y + 1.2f, body[2].z);
		glVertex3f(body[2].x, body[2].y + 1.5f, body[2].z);
		glVertex3f(body[1].x, body[1].y + 1.5f, body[1].z);
		
		glVertex3f(body[2].x, body[0].y + 1.2f, body[2].z);
		glVertex3f(body[3].x, body[1].y + 1.2f, body[3].z);
		glVertex3f(body[3].x, body[1].y + 1.5f, body[3].z);
		glVertex3f(body[2].x, body[0].y + 1.5f, body[2].z);
		
		glVertex3f(body[3].x, body[3].y + 1.2f, body[3].z);
		glVertex3f(body[0].x, body[0].y + 1.2f, body[0].z);
		glVertex3f(body[0].x, body[0].y + 1.5f, body[0].z);
		glVertex3f(body[3].x, body[3].y + 1.5f, body[3].z);
		
	glEnd();
}
