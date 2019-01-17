// g++ -o program m sa imenom texture_nameain.cpp Room.cpp Wall.cpp -lgnut -lGL -lGLU -lm
//	./program

#include <stdio.h>
#include <iostream>
#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "image.h"
#include "objloader.h"

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
#define TIMER_INTERVAL2 10
#define TIMER_ID1 0
#define TIMER_ID2 0

int width_a = 0;
int height_a = 0;
int mouse_x = 0;
int mouse_x1 = 0;
int delta_x = 0;
float jump_ongoing = 0.0f;
int w_d = 1;
int s_d = 1;
int a_d = 1;
int d_d = 1;
int q_d = 1;
int e_d = 1;
int m_l = 1;
int m_r = 1;
float colition_corection = 0;

char view_mode = 0; // 0 for first person view, 1 for third person view
float alpha = 1;
int alpha1 = 0;
int follow = 1;
GLuint texture_name;
glm::mat4 screen;


Image * img = nullptr;
Image * img1 = nullptr;
Image * img2 = nullptr;
Image * img3 = nullptr;
Image * img4 = nullptr;
Image * img5 = nullptr;


std::vector<glm::vec3>  out_vertices;
std::vector<glm::vec2>  out_uvs;
std::vector<glm::vec3>  out_normals;


static Camera *activeCamera = nullptr;
static Player *activePlayer = nullptr;


static void on_display(void);
static void on_reshape(int width, int height);
static void on_keyboard(unsigned char key, int x, int y);
static void keyUp (unsigned char key, int x, int y);
static void on_mouse(int x, int y);
static void on_timer2(int);
static void on_timer3(int);
static void on_timer4(int);
static void on_timer5(int);
static void on_timer6(int);
static void on_timer7(int);
static void colition_timer(int);
static void jump_timer(int);

static void mouse_l_timer(int);
static Player create_player();
static Room create_room_1();

void make_texture();
void unbind_texture();




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
	//glutPassiveMotionFunc(on_mouse);
	glutTimerFunc(TIMER_INTERVAL2, colition_timer, TIMER_ID2);
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	


	Player player = Player();
	Camera cam = Camera(&player);
	activePlayer = &player;
	activeCamera = &cam;
	screen = activePlayer->getModelMatrix();

	img = image_init(200, 200);
	img1 = image_init(200, 200);
	img2 = image_init(200, 200);
	img3 = image_init(200, 200);
	img4 = image_init(200, 200);
	img5 = image_init(200, 200);	
	/* Ucitas sliku */
	image_read(img, "pictures/texture.bmp");
	image_read(img1, "pictures/texture1.bmp");
	image_read(img2, "pictures/texture2.bmp");
	image_read(img3, "pictures/texture3.bmp");
	image_read(img4, "pictures/texture4.bmp");
	image_read(img5, "pictures/texture5.bmp");

	/* Generises ime teksture */
	glGenTextures(1, &texture_name);

	/* Ucitas objekat (iscrtavanje u on display) */
	const char * path = "cube.obj";
	loadOBJ(path, out_vertices, out_uvs, out_normals);

	/* Boiler plate (dodeljivanje teksturi sa imenom texture_name sliku) */
	make_texture();

	glutMainLoop();

	return 0;
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
static void mouse_l_timer(int){
		glutTimerFunc(TIMER_INTERVAL2, mouse_l_timer, TIMER_ID2);
	glutPostRedisplay();
}

static void mouse_r_timer(int){
	activePlayer->rotate(-0.001, glm::vec3(0, 1, 0));
	if(m_r)
		glutTimerFunc(TIMER_INTERVAL2, mouse_r_timer, TIMER_ID2);
	glutPostRedisplay();
}

static void jump_timer(int){
	if(jump_ongoing > 0.5)
		activePlayer->translate(glm::vec3(0, 0.05, 0));
	else
		activePlayer->translate(glm::vec3(0, -0.05, 0));

	jump_ongoing -= 0.03f;
	if(jump_ongoing > 0)
		glutTimerFunc(TIMER_INTERVAL2, jump_timer, TIMER_ID2);
}

static void colition_timer(int){
	glm::mat4 tmpMatrix = glm::mat4(activePlayer->getModelMatrix());

	if(tmpMatrix[3][0] > 1.95-colition_corection)//7.
		tmpMatrix[3][0] = 1.95-colition_corection;
	if(tmpMatrix[3][0] < -1.95+colition_corection)//5.
		tmpMatrix[3][0] = -1.95+colition_corection;
	if(tmpMatrix[3][2] > 149.95-colition_corection)//3.
		tmpMatrix[3][2] = 149.95-colition_corection;
	if(tmpMatrix[3][2] < -149.95+colition_corection)//3.
		tmpMatrix[3][2] = -149.95+colition_corection;
	
	if(jump_ongoing <= 0){
		if(tmpMatrix[3][1] != 0)
			tmpMatrix[3][1] = 0;
	}

	activePlayer->setModelMatrix(tmpMatrix);

	glutPostRedisplay();
	glutTimerFunc(TIMER_INTERVAL2, colition_timer, TIMER_ID2);

}

static void on_display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Podesava se tacka pogleda. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glLoadMatrixf(glm::value_ptr(activeCamera->getView()));
	//gluLookAt(0, 0, 0, 0, 0, 1, 0,1,0);
	if(view_mode == 1){
		activePlayer->translate(glm::vec3(0, 0, 1));
		view_mode++;
	}

	//red cube for testing
// 	glColor3f(1, 0, 0);
// 	glPushMatrix();
// 		glTranslatef(0, 0, 2);
// 		glutSolidCube(0.5);
// 	glPopMatrix();
	
	
// 	//green cube for testing
// 	glColor3f(0, 1, 0);
// 	glPushMatrix();
// 		glTranslatef(0, 0, -2);
// 		glutSolidCube(0.5);
// 	glPopMatrix();


// 	//blue cube for testing
// 	glColor3f(0, 0, 1);
// 	glPushMatrix();
// 		glTranslatef(2, 0, 0);
// 		glutSolidCube(0.5);
// 	glPopMatrix();

// //black cube for testing
// 	glColor3f(0, 0, 0);
// 	glPushMatrix();
// 		glTranslatef(-2, 0, 0);
// 		glutSolidCube(0.5);
// 	glPopMatrix();
	

	Room room_1(create_room_1());
	glPushMatrix();
		room_1.Draw();
	glPopMatrix();
	
	
	 /* Ukljucuju se teksture. */
 	//glEnable(GL_LIGHTING);
	glPushMatrix();
	/* Ukljuvcis teksturu sa imenom texture_name */

		if(follow)
			glMultMatrixf(glm::value_ptr(activePlayer->getModelMatrix()));
		else
			glMultMatrixf(glm::value_ptr(screen));

		glRotatef(-20, 0, 1, 0);
		glRotatef(13, 1, 0, 0);
		if(alpha)
			glRotatef(180, 0, 1, 0);
		glTranslatef(0, 0, -2);
		glRotatef(90, 0, 1, 0);


		glScalef(0.05*0.45, 1*0.45, 1.6*0.45);
		glBindTexture(GL_TEXTURE_2D, texture_name);

		int numOfVertices = out_vertices.size();
		int numOfNormals = out_normals.size();
		int numOfTextureCoordinates = out_uvs.size(); 

		glBegin(GL_TRIANGLES);

			for (int i=0; i<numOfVertices; i++) {

				if (i < numOfNormals) {
					glNormal3f(out_normals[i].x, out_normals[i].y, out_normals[i].z);
				}

				if (i < numOfTextureCoordinates) {
					glTexCoord2f(out_uvs[i].s, out_uvs[i].t);
				}

				glVertex3f(out_vertices[i].x, out_vertices[i].y, out_vertices[i].z);
			}
		glEnd();
		/* Iskljucis teksture */
		glBindTexture(GL_TEXTURE_2D, 0);
		glPopMatrix();
		glPushMatrix();
			glMultMatrixf(glm::value_ptr(activePlayer->getModelMatrix()));
			activePlayer->Draw(view_mode);
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
	glutPostRedisplay();
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
		case 'k':
			e_d = 1;
			glutTimerFunc(TIMER_INTERVAL2, on_timer6, TIMER_ID2);
			break;
		case 'j':
			q_d = 1;
			glutTimerFunc(TIMER_INTERVAL2, on_timer7, TIMER_ID2);
			break;
		case 't':
			if(alpha)
				alpha = 0;
			else{
				follow = 1;
				alpha = 1;
			}
			break;
		case 'f':
			if(follow && !alpha){
				screen = activePlayer->getModelMatrix();
				follow = 0;
			}
			else
				follow = 1;
			break;
		case 'n':
			if(alpha1 == 5)
				alpha1 = 0;
			else
				alpha1 = alpha1 + 1;
			std::cout << alpha1;
			make_texture();
			break;
		case 'v':
			if(view_mode){
				view_mode = 0;
				colition_corection = 0;
				activePlayer->translate(glm::vec3(0, 0, -1));
			}
			else{
				view_mode = 1;
				colition_corection = 1;
			}
			break;
		case 32:
			if(jump_ongoing <= 0){
				jump_ongoing = 1;
				glutTimerFunc(TIMER_INTERVAL2, jump_timer, TIMER_ID2);
			}
			break;
	}

	glutPostRedisplay();
}
static void keyUp (unsigned char key, int x, int y)
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
		case 'k':
			e_d = 0;
			break;
		case 'j':
			q_d = 0;
			break;
	}
}


//on_mouse currently does absolutly nothing good

static void on_mouse(int x, int y){
		//m_r = 1;
		//mouse_x = mouse_x - 20;
		
		float sensitivity = 0.005;
		delta_x = x - width_a/2;
		activePlayer->rotate(-delta_x*sensitivity,glm::vec3( 0, 1, 0 ));
		glutWarpPointer(width_a/2, height_a/2);
		glutPostRedisplay();
		//float delta_y = y - width_a/2;

	//	glutTimerFunc(TIMER_INTERVAL2, mouse_r_timer, TIMER_ID2);
		//m_r = 0;
       // if(x < width_a/2){
       // 	m_l = 1;
       // 	//glutTimerFunc(TIMER_INTERVAL2, mouse_l_timer, TIMER_ID2);
       // 	mouse_x = mouse_x + 20;
       // }
       // else
       // 	m_l = 0;

	
}



static Room create_room_1(){
	glm::vec3 a = glm::vec3(-3.0f*2, -1.0f, 2.0f*2);
	glm::vec3 b = glm::vec3(-3.0f*2, -1.0f, -2.0f*2);
	glm::vec3 c = glm::vec3(4.0f*2, -1.0f, -2.0f*2);
	glm::vec3 d = glm::vec3(4.0f*2, -1.0f, 2.0f*2);
	


	std::vector<glm::vec3> zidovi;
	
	zidovi.push_back(a);
	zidovi.push_back(b);
	zidovi.push_back(c);
	zidovi.push_back(d);
	zidovi.push_back(a);
	

	Room sampleRoom(zidovi);

	return sampleRoom;
}



//	i'm not sure how textures work yet, but i did make it work 
//	in time with bunch of copying from this and last year practise,
//	internet, man pages and modifying it till it did what i needed it to do

//	image.cpp/h cube.obj and objloader.h are purley copyed from somewhere

void make_texture() 
{

  /* Ukljucuje se testiranje z-koordinate piksela. */
    glEnable(GL_DEPTH_TEST);

    /* Ukljucuju se teksture. */
    glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);
    glBindTexture(GL_TEXTURE_2D, texture_name);
    //glTexParameteri(GL_TEXTURE_2D,
    //                GL_TEXTURE_WRAP_S, GL_CLAMP);
    //glTexParameteri(GL_TEXTURE_2D,
    //                GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	if(alpha1 == 0){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
					img->width, img->height, 0,
					GL_RGB, GL_UNSIGNED_BYTE, img->pixels);
	}
	if(alpha1 == 1){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 img1->width, img1->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, img1->pixels);
	}
	if(alpha1 == 2){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 img2->width, img2->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, img2->pixels);
	}
	if(alpha1 == 3){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 img3->width, img3->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, img3->pixels);
	}
	if(alpha1 == 4){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 img4->width, img4->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, img4->pixels);
	}
	if(alpha1 == 5){
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 img5->width, img5->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, img5->pixels);
	}
glBindTexture(GL_TEXTURE_2D, 0);


}

void unbind_texture()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
