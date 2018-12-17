#include "Room.hpp"



Room::Room(std::vector<glm::vec3> vec){
	//	vec is a sequence of coordinates in 3d
	//	it represents all points of corners of a room
	//	the first and the last point of the sequence are the same
	//
	//	number of walls in a room

	int n = static_cast<int>(vec.size()); 

	//	creates a wall and saves it

	for(int i = 0; i < n; i++)
		listOfWalls.push_back(Wall(vec[i], vec[i+1]));		
}


void Room::Draw(){
	int n = static_cast<int>(listOfWalls.size());

	for(int i = 0; i < n; i++)
		Room::listOfWalls[i].Draw();
	
	//TODO	Draw() for ceiling and floor
}
