#include "Position.hpp"


const glm::mat4 &Position::getModelMatrix(){
    return this->modelMatrix;
}
void Position::setModelMatrix(glm::mat4 newMatrix){
    this->modelMatrix = newMatrix;
}