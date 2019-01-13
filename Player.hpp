#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <GL/glut.h>
#include <vector>
#include <glm/vec3.hpp>

#include "Position.hpp"
#include "Transformable.hpp"

class Player: public Position, public Transformable{
    public:
        Player();
	    void Draw();
    private:
};

#endif
