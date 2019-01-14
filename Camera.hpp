#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

#include "Position.hpp"

enum class CamMode {
    firstPersonView,
    thirdPersonView
};
 
class Camera {
    private:
        glm::mat4 viewMatrix = glm::mat4(1);
    public: 
        Position *attachedTo = nullptr;
        Camera() = default;
        Camera(Position *attachTo);
        
        void attachTo(Position *attachTo);
        void setCamPos(CamMode);
        const glm::mat4 getView();
};

#endif
