#include "Room.hpp"



Room::Room(std::vector<glm::vec3> vec){
	//	vec is a sequence of coordinates in 3d
	//	it represents all points of corners of a room
	//	the first and the last point of the sequence are the same
	//
	//	number of walls in a room

	unsigned n = (vec.size()); 

	//	creates a wall and saves it

	for(int i = 0; i < n-1; i++){
		listOfWalls.push_back(Wall(vec[i], vec[i+1]));
		listOfPoints.push_back(vec[i]);
	}
}
 

void Room::Draw(){
	 int n = static_cast<int>(listOfWalls.size());

	// glBegin(GL_QUADS);
	// 	for(int i = 0; i < n; i++)
	// 		Room::listOfWalls[i].Draw();
	// glEnd();

	 n = static_cast<int>(listOfPoints.size());




	// this works for floors and cellings that are convex,
	// but all of my rooms wiill be like that, and if they dont all of my rooms will 
	// have the same floor celling texture so i wont worry about overlaping

	// //floor
	//glEnable(GL_BLEND);
	//glBegin(GL_TRIANGLE_FAN);
	//	glColor4f(0.1f, 0.1f, 0.1f, 0.2f);
	//	for(int i = 0; i < n; i++)
	//		glVertex3f(listOfPoints[i].x, listOfPoints[i].y, listOfPoints[i].z);
	//	glVertex3f(listOfPoints[0].x, listOfPoints[0].y, listOfPoints[0].z);
	glEnd();

	glEnable(GL_LINE_SMOOTH | GL_LIGHTING);	
	//floor2 infinity hole
	glPushMatrix();
	glRotatef(90, 2, 0, 0);
	glLineWidth(2.5);
	glColor3f(1.0, 1.0, 1.0);
	 glBegin(GL_LINE_LOOP);
	 	for(float j = 0; j < 300; j = j+0.3){
	 		glColor3f(0.1f, 0.1f, 0.1f);
	 		for(int i = 0; i < n; i++)
	 			glVertex3f(listOfPoints[i].x, listOfPoints[i].y - j + 150, listOfPoints[i].z);
	 		glVertex3f(listOfPoints[0].x, listOfPoints[0].y-j + 150, listOfPoints[0].z);
		}
	 glEnd();
	glPopMatrix();
	
	//glTranslatef(0, 10, 0);
	glColor3f(0.7, 0.7, 0.9);
	 //glBegin(GL_QUADS);
	 	for(float i = 0; i < 300; i++){
			 glPushMatrix();
			 glTranslatef(0, -1, 2*i - 100);
			 glScalef(1, 0.005, 1);
			 
			 glTranslatef(0, 0, 0);
			 glutSolidCube(1.85);
			 
			 glTranslatef(-2, 0, 0);
			 glutSolidCube(1.85);

			 glTranslatef(4, 0, 0);
			 glutSolidCube(1.85);
			 glPopMatrix();
		 }


	 //glEnd();

	//celling
	// glBegin(GL_TRIANGLE_FAN);
	// 	glColor3f(0.3f, 0.3f, 0.3f);
	// 	for(int i = 0; i < n; i++)
	// 		glVertex3f(listOfPoints[i].x, listOfPoints[i].y + 3.0f, listOfPoints[i].z);
	// 	glVertex3f(listOfPoints[0].x, listOfPoints[0].y + 3.0f, listOfPoints[0].z);
	// glEnd();

}

