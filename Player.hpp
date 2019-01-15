#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <glm/gtc/type_ptr.hpp>
#include <GL/glut.h>
#include <vector>
#include <glm/vec3.hpp>

#include "Position.hpp"
#include "Transformable.hpp"

class Player: public Position, public Transformable{
    public:
        Player();
	    void Draw(float alpha);
    private:
};

#endif
