#include "Room.hpp"



Room::Room(std::vector<glm::vec3> vec){
	//	vec is a sequence of coordinates in 3d
	//	it represents all points of corners of a room
	//	the first and the last point of the sequence are the same
	//
	//	number of walls in a room

	int n = static_cast<int>(vec.size()); 

	//	creates a wall and saves it

	for(int i = 0; i < n; i++){
		listOfWalls.push_back(Wall(vec[i], vec[i+1]));
		listOfPoints.push_back(vec[i]);
	}
}
 

void Room::Draw(){
	int n = static_cast<int>(listOfWalls.size());

	glBegin(GL_QUADS);
		for(int i = 0; i < n; i++)
			Room::listOfWalls[i].Draw();
	glEnd();

	n = static_cast<int>(listOfPoints.size());




	// this works for floors and cellings that are convex,
	// but all of my rooms wiill be like that, and if they dont all of my rooms will 
	// have the same floor celling texture so i wont worry about overlaping
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.1f, 0.1f, 0.1f);
		for(int i = 0; i < n-1; i++)
			glVertex3f(listOfPoints[i].x, listOfPoints[i].y, listOfPoints[i].z);
		glVertex3f(listOfPoints[0].x, listOfPoints[0].y, listOfPoints[0].z);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
		glColor3f(0.3f, 0.3f, 0.3f);
		for(int i = 0; i < n-1; i++)
			glVertex3f(listOfPoints[i].x, listOfPoints[i].y + 2.0f, listOfPoints[i].z);
		glVertex3f(listOfPoints[0].x, listOfPoints[0].y + 2.0f, listOfPoints[0].z);
	glEnd();

}

