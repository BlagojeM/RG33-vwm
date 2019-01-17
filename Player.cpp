#include "Player.hpp"

Player::Player() : Transformable(this) {
	Position();
}

void Player::Draw(float alpha){
		glTranslatef(0, 0, 0.13);
		if(alpha)
			glTranslatef(0, 0, -1);
		glColor3f(0.5, 0, 0);
		glutSolidCube(0.1);
		glScalef(1, 3, 1);
		glTranslatef(0, -0.08, 0);
		glutSolidCube(0.1);
		glTranslatef(0, 0.14, 0);
		glScalef(0.03, 0.017, 0.03);
		glColor3f(0, 1, 0);
		glRotatef(90, 0, 1, 0);
		glutSolidTetrahedron();
		glTranslatef(0, -0.9, 0);
		glRotatef(180, 1, 0, 0);
		glutSolidTetrahedron();

}
