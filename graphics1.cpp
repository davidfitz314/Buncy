// OpenGL/GLUT starter kit for Windows 7 and Visual Studio 2010
// Created spring, 2011
//
// This is a starting point for OpenGl applications.
// Add code to the "display" function below, or otherwise
// modify this file to get your desired results.
//
// For the first assignment, add this file to an empty Windows Console project
//		and then compile and run it as is.
// NOTE: You should also have glut.h,
// glut32.dll, and glut32.lib in the directory of your project.
// OR, see GlutDirectories.txt for a better place to put them.
#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <cstring>
#include "glut.h"
#include "Circle.h"



// Global Variables (Only what you need!)
double screen_x = 700;
double screen_y = 500;

//double gDX = .17;
//double gDY = .13;
const double WIDTH = 50;
const double HEIGHT = 50;
std::vector<circle*> cirVec;
const double FRICTION = .9999;
const double GRAVITY = .0001;
// 
// Functions that draw basic primitives
//
/*void DrawCircle(double x1, double y1, double radius)
{
	glBegin(GL_POLYGON);
	for(int i=0; i<32; i++)
	{
		double theta = (double)i/32.0 * 2.0 * 3.1415926;
		double x = x1 + radius * cos(theta);
		double y = y1 + radius * sin(theta);
		glVertex2d(x, y);
	}
	glEnd();
}*/

void DrawRectangle(double x1, double y1, double x2, double y2)
{
	glBegin(GL_QUADS);
	glVertex2d(x1,y1);
	glVertex2d(x2,y1);
	glVertex2d(x2,y2);
	glVertex2d(x1,y2);
	glEnd();
}

void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glVertex2d(x3,y3);
	glEnd();
}

// Outputs a string of text at the specified location.
void DrawText(double x, double y, char *string)
{
	void *font = GLUT_BITMAP_9_BY_15;

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
	
	int len, i;
	glRasterPos2d(x, y);
	len = (int) strlen(string);
	for (i = 0; i < len; i++) 
	{
		glutBitmapCharacter(font, string[i]);
	}

    glDisable(GL_BLEND);
}


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	
	// Draw Rectangle
	//glColor3d(0,0,1);
	//DrawRectangle(gX, gY, gX+WIDTH, gY+HEIGHT);
	//test = new circle(gX, gY, WIDTH);
	for (unsigned int i = 0; i < cirVec.size(); i++)
	{
		//colors
		double r = cirVec[i]->getRed();
		double g = cirVec[i]->getGreen();
		double b = cirVec[i]->getBlue();
		glColor3d(r,g,b);
		// Wall bouncing
		double tempX = cirVec[i]->getX();
		double tempY = cirVec[i]->getY();
		double tempR = cirVec[i]->getRadius();
		double gDX = (cirVec[i]->getSpeedX())*FRICTION;
		double gDY = (cirVec[i]->getSpeedY()-GRAVITY)*FRICTION;
		if (tempX + tempR + gDX >= screen_x)
		{
			gDX = -gDX;
		}
		if (tempX - tempR + gDX < 0)
		{
			gDX = -gDX;
		}
		if (tempY + tempR + gDY >= screen_y)
		{
			gDY = -gDY;
		}
		if (tempY - tempR + gDY < 0)
		{
			gDY = -gDY;
		}
		// Increment Rectangle Position
		tempX += gDX;
		tempY += gDY;
		cirVec[i] = new circle(tempX, tempY, tempR);
		cirVec[i]->setSpeeds(gDX, gDY);
		cirVec[i]->setColors(r,g,b);
		cirVec[i]->draw();
	}
	//test->draw();
	glutSwapBuffers();
	glutPostRedisplay(); // Force an animation
}


// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
	switch (c) 
	{
		case 27: // escape character means to quit the program
			exit(0);
			break;
		case 'b':
			// do something when 'b' character is hit.
			break;
		default:
			return; // if we don't care, return without glutPostRedisplay()
	}

	glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
	// Reset our global variables to the new width and height.
	screen_x = w;
	screen_y = h;

	// Set the pixel resolution of the final picture (Screen coordinates).
	glViewport(0, 0, w, h);

	// Set the projection mode to 2D orthographic, and set the world coordinates:
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glMatrixMode(GL_MODELVIEW);

}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
	}
	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
	{
	}
	if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) 
	{
	}
	if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) 
	{
	}
	glutPostRedisplay();
}

// Your initialization code goes here.
void InitializeMyStuff()
{
	//test = new circle(gX, gY, WIDTH);
	for (unsigned int i = 0; i < 20; i++)
	{
		double randx = (std::rand() % 600) + 50;
		double randy = (std::rand() % 400) + 50;
		double randr = (std::rand() % 50) + 1;
		double randsx = (double(std::rand() % 25)+.001) / 100;
		//std::cout <<"x speed is "<< randsx << std::endl;
		double randsy = (double(std::rand() % 25)+.001) / 100;
		double randc1 = double(std::rand() % 100) / 100;
		double randc2 = double(std::rand() % 100) / 100;
		double randc3 = double(std::rand() % 100) / 100;
		
		circle * temp = new circle(randx, randy, randr); 
		temp->setSpeeds(randsx, randsy);
		temp->setColors(randc1,randc2,randc3);
		cirVec.push_back(temp);
	}
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screen_x, screen_y);
	glutInitWindowPosition(50, 50);

	int fullscreen = 0;
	if (fullscreen) 
	{
		glutGameModeString("800x600:32");
		glutEnterGameMode();
	} 
	else 
	{
		glutCreateWindow("This appears in the title bar");
	}

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	glColor3d(0,0,0); // forground color
	glClearColor(1, 1, 1, 0); // background color
	InitializeMyStuff();

	glutMainLoop();

	return 0;
}
