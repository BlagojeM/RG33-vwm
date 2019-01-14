#include "Camera.hpp"

Camera::Camera(Position *attachTo){
    this->attachTo(attachTo);
}

void Camera::attachTo(Position *attachTo){
    this->attachedTo = attachTo;
}
 
void Camera::setCamPos(CamMode){
    viewMatrix = glm::lookAt(glm::vec3(0, 0, 0), glm::vec3(0, 0, 1), glm::vec3(0, 1, 0));
}
const glm::mat4 Camera::getView(){
    return glm::mat4(glm::inverse(this->viewMatrix*this->attachedTo->getModelMatrix()));
}
