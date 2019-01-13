// g++ -o program main.cpp Room.cpp Wall.cpp -lglut -lGL -lGLU -lm
//	./program

#include <iostream>
#include <GL/glut.h>

#include <glm/glm.hpp>
#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <math.h>
//#include "LevelOne.h"
#include "Room.hpp"
#include "Wall.hpp"
#include "Player.hpp"
#include "Camera.hpp"
#include "Position.hpp"

#define TIMER_INTERVAL1 10
#define TIMER_INTERVAL2 5
#define TIMER_ID1 0
#define TIMER_ID2 0


float lx=0.0f,lz=-1.0f;
float angle=0.0f;
float angle1=0.0f;
float xx=0.0f,zz=0.0f;
float yy = 0.0f, yy_par = 0.0f;

float mouse_x = 0.0f;
float mouse_y = 0.0f;
int width_a = 0;
int height_a = 0;

float person_x = 0.0f;
float person_y = 0.0f;

float jump_ongoing = 1.0f;
int w_d = 1;
int s_d = 1;
int a_d = 1;
int d_d = 1;
int q_d = 1;
int e_d = 1;




glm::vec3 p_pos = glm::vec3(0.0f, 1.35f, 0.0f);
float angle_1 = 0.5f;
float angle_2 = 0.0f;
char view_mode = 0; // 0 for first person view, 1 for third person view
glm::vec3 eye_point, ref_point, up_vec;




static void on_display(void);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key, int x, int y);
static void on_mouse(int x, int y);
static void on_timer1(int);
static void on_timer2(int);
static void on_timer3(int);
static void on_timer4(int);
static void on_timer5(int);
static Player create_player();
static Room create_room_1();
void keyUp (unsigned char key, int x, int y);

static Camera *activeCamera = nullptr;
static Player *activePlayer = nullptr;

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

	glutInitWindowSize(300, 150);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	glutFullScreen();


	glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

	glutKeyboardUpFunc(keyUp);
	glutKeyboardFunc(on_keyboard);
	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);
	glutPassiveMotionFunc(on_mouse);
	glutTimerFunc(TIMER_INTERVAL1, on_timer1, TIMER_ID1);//???da li ovde???

	glClearColor(0.75, 0.75, 0.75, 0);
	glEnable(GL_DEPTH_TEST);


	Player player = Player();
	Camera cam = Camera(&player);
	activePlayer = &player;
	activeCamera = &cam;

	glutMainLoop();
	return 0;
}

static void on_timer1(int){
	
	glutWarpPointer(width_a/2, height_a/2);

	glutTimerFunc(TIMER_INTERVAL1, on_timer1, TIMER_ID1);
	glutPostRedisplay();
}
static void on_timer2(int){
	activePlayer->translate(glm::vec3(0, 0, -0.05));
	if(w_d)
		glutTimerFunc(TIMER_INTERVAL2, on_timer2, TIMER_ID2);
	glutPostRedisplay();
	
}
static void on_timer3(int){
	activePlayer->translate(glm::vec3(0, 0, 0.05));
	if(s_d)
		glutTimerFunc(TIMER_INTERVAL2, on_timer3, TIMER_ID2);
	glutPostRedisplay();
	
}
static void on_timer4(int){
	activePlayer->translate(glm::vec3(0.05, 0, 0));
	if(d_d)
		glutTimerFunc(TIMER_INTERVAL2, on_timer4, TIMER_ID2);
	glutPostRedisplay();
	
}
static void on_timer5(int){
	activePlayer->translate(glm::vec3(-0.05, 0, 0));
	if(a_d)
		glutTimerFunc(TIMER_INTERVAL2, on_timer5, TIMER_ID2);
	glutPostRedisplay();
	
}

static void on_timer6(int){
	activePlayer->rotate(-0.05, glm::vec3(0, 1, 0));
	if(e_d)
		glutTimerFunc(TIMER_INTERVAL2, on_timer6, TIMER_ID2);
	glutPostRedisplay();
	
}
static void on_timer7(int){
	activePlayer->rotate(0.05, glm::vec3(0, 1, 0));
	if(q_d)
		glutTimerFunc(TIMER_INTERVAL2, on_timer7, TIMER_ID2);
	glutPostRedisplay();
	
}
static void on_display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Podesava se tacka pogleda. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glLoadMatrixf(glm::value_ptr(activeCamera->getView()));
	//gluLookAt(0, 0, 0, 0, 0, 1, 0,1,0);
	

	//red cube for testing
	glColor3f(1, 0, 0);
	glPushMatrix();
		glTranslatef(0, 0, 2);
		glutSolidCube(0.5);
	glPopMatrix();
	
	
	//green cube for testing
	glColor3f(0, 1, 0);
	glPushMatrix();
		glTranslatef(0, 0, -2);
		glutSolidCube(0.5);
	glPopMatrix();


	//blue cube for testing
	glColor3f(0, 0, 1);
	glPushMatrix();
		glTranslatef(2, 0, 0);
		glutSolidCube(0.5);
	glPopMatrix();


	//black cube for testing
	glColor3f(0, 0, 0);
	glPushMatrix();
		glTranslatef(-2, 0, 0);
		glutSolidCube(0.5);
	glPopMatrix();
	

	Room room_1(create_room_1());
	glPushMatrix();
		room_1.Draw();
	glPopMatrix();

	glutSwapBuffers();
}

static void on_reshape(int width, int height)
{
	width_a = width;
	height_a = height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (float) width/height,0.01, 1000);
}

static void on_keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 27:
			/* Zavrsava se program. */
			exit(0);
			break;
		case 'w':
			w_d = 1;
			glutTimerFunc(TIMER_INTERVAL2, on_timer2, TIMER_ID2);
			break;
		case 's':
			s_d = 1;
			glutTimerFunc(TIMER_INTERVAL2, on_timer3, TIMER_ID2);
			break;
		case 'a':
			a_d = 1;
			glutTimerFunc(TIMER_INTERVAL2, on_timer5, TIMER_ID2);
			break;
		case 'd':
			d_d = 1;
			glutTimerFunc(TIMER_INTERVAL2, on_timer4, TIMER_ID2);
			break;
		case 'e':
			e_d = 1;
			glutTimerFunc(TIMER_INTERVAL2, on_timer6, TIMER_ID2);
			break;
		case 'q':
			q_d = 1;
			glutTimerFunc(TIMER_INTERVAL2, on_timer7, TIMER_ID2);
			break;
	}

	glutPostRedisplay();
}
void keyUp (unsigned char key, int x, int y)
{
    switch (key) {
		case 27:
			/* Zavrsava se program. */
			exit(0);
			break;
		case 'w':
			w_d = 0;
			break;
		case 's':
			s_d = 0;
			break;
		case 'a':
			a_d = 0;
			break;
		case 'd':
			d_d = 0;
			break;
		case 'e':
			e_d = 0;
			break;
		case 'q':
			q_d = 0;
			break;
	}
}

static void on_mouse(int x, int y){
	if(x > width_a/2)
		angle_1 += x*0.00005f;
	if(x < width_a/2)
		angle_1 -= x*0.00005f;
	if(y > height_a/2)
		//yy_par -= 0.01f;
		angle_2 -= y*0.00005f;
	if(y < height_a/2)
		//yy_par += 0.01f;
		angle_2 += y*0.000005f;
}











static Room create_room_1(){
	glm::vec3 a = glm::vec3(0.0f, -1.0f, 0.0f);
	glm::vec3 b = glm::vec3(5.0f, -1.0f, 0.0f);
	glm::vec3 c = glm::vec3(5.0f, -1.0f, 5.0f);
	glm::vec3 d = glm::vec3(10.0f, -1.0f, 2.5f);
	glm::vec3 e = glm::vec3(15.0f, -1.0f, 5.0f);
	glm::vec3 f = glm::vec3(15.0f, -1.0f, 0.0f);
	glm::vec3 g = glm::vec3(20.0f, -1.0f, 0.0f);
	glm::vec3 h = glm::vec3(15.0f, -1.0f, 15.0f);
	glm::vec3 i = glm::vec3(10.0f, -1.0f, 10.0f);
	glm::vec3 j = glm::vec3(5.0f, -1.0f, 15.0f);


	std::vector<glm::vec3> zidovi;
	
	zidovi.push_back(a);
	zidovi.push_back(b);
	zidovi.push_back(c);
	zidovi.push_back(d);
	zidovi.push_back(e);
	zidovi.push_back(f);
	zidovi.push_back(g);
	zidovi.push_back(h);
	zidovi.push_back(i);
	zidovi.push_back(j);
	zidovi.push_back(a);
	

	Room sampleRoom(zidovi);

	return sampleRoom;
}