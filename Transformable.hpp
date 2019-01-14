#ifndef TRANSFORMABLE_HPP
#define TRANSFORMABLE_HPP


#include <vector>
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include "Position.hpp"

class Transformable{
    public:
        Transformable(Position *pos);
        void translate(glm::vec3 translate);
        void rotate(float angle, glm::vec3 aroundVec);
        Position *pos = nullptr;
};

#endif
