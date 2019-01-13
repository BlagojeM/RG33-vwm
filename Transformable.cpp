#include "Transformable.hpp"

Transformable::Transformable(Position *pos){
    this->pos = pos;
}

void Transformable::translate(glm::vec3 translate){
    this->pos->setModelMatrix(glm::translate(this->pos->getModelMatrix(), translate));
}


void Transformable::rotate(float angle, glm::vec3 aroundVec){
    this->pos->setModelMatrix(glm::rotate(this->pos->getModelMatrix(), angle, aroundVec));
}