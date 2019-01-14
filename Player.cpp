#include "Player.hpp"

Player::Player() : Transformable(this) {
	Position();
}

void Player::Draw(){
		glColor3f(1, 0, 1);
		glTranslatef(0, 0, -2);
		glutSolidCube(0.2);
}
