#include "Player.hpp"

Player::Player() : Transformable(this) {
	Position();
}

void Player::Draw(){

	glPushMatrix();
		glBegin(GL_QUADS);
		
		
		glEnd();
	glPopMatrix();
}
