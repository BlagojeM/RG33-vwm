#ifndef ROOM_HPP
#define ROOM_HPP

#include <vector>
#include <glm/vec3.hpp>
#include "Wall.hpp"
//#include "Floor.hpp"
//#include "Ceiling.hpp"


class Room{
    private:
        std::vector<Wall> listOfWalls;
    
    public:
	static std::vector<Room*> listOfRooms;

        Room(std::vector<glm::vec3> vec);
        void Draw();
};

#endif
