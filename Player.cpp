#include "Player.hpp"

Player::Player() : Transformable(this) {
	Position();
}

void Player::Draw(float alpha){
		glColor3f(0.5, 0, 0);
		glTranslatef(0, 0, 0.13);
		if(alpha)
			glTranslatef(0, 0, -1);
		glutSolidCube(0.1);
		glScalef(1, 3, 1);
		glTranslatef(0, -0.08, 0);
		glutSolidCube(0.1);
}
