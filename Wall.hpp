#ifndef WALL_HPP
#define WALL_HPP

#include <GL/glut.h>
#include <vector>
#include <glm/vec3.hpp>

class Wall{
    public:
        Wall(glm::vec3 first, glm::vec3 second);
	void Draw();
    private:
	glm::vec3 firstPoint;
	glm::vec3 secondPoint; 
};

#endif
