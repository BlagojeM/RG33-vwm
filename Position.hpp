#ifndef POSITION_HPP
#define POSITION_HPP

#include <glm/matrix.hpp>



class Position{
    protected:
	    glm::mat4 modelMatrix = glm::mat4(1.0f);
    public:
        const glm::mat4 &getModelMatrix();
        void setModelMatrix(glm::mat4 newMatrix);
        //nothing for now
};

#endif
