#ifndef PEROSN_HPP
#define PERSON_HPP

#include <GL/glut.h>
#include <vector>
#include <glm/vec3.hpp>

class Person{
    public:
        Person(std::vector<glm::vec3> bodyPoints);
	void Draw();
    private:
	std::vector<glm::vec3> body;
};

#endif
