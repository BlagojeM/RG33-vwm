#include "Player.hpp"

Player::Player() : Transformable(this) {
	Position();
}

void Player::Draw(float alpha){
		glRotatef(-20, 0, 1, 0);
		glRotatef(13, 1, 0, 0);
		glTranslatef(0, 0, -2);
		// if(alpha)
		// 	glColor4f(1, 0, 1, 1);
		// else
			glColor4f(1, 0, 1, 0);
		glutSolidCube(0.7);
}
