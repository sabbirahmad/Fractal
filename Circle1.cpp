# include "iGraphics.h"

/* 
	function iDraw() is called again and again by the system.
*/


int centreX=300;
int centreY=200;
int radius=100;
int checkRadius=196;

int up=1,right=2,down=3,left=4;



int level=0;
char levelStr[30]="0";

void recursiveCircle(int cirX,int cirY,int rad,int pos)
{
	if(checkRadius>rad)
		return;

	iCircle(cirX,cirY,rad);

	if(pos!=left)
		recursiveCircle(cirX+rad+rad/2,cirY,rad/2,right);
	if(pos!=right)
		recursiveCircle(cirX-rad-rad/2,cirY,rad/2,left);
	if(pos!=up)
		recursiveCircle(cirX,cirY+rad+rad/2,rad/2,down);
	if(pos!=0)
	{
		if(pos!=down)
			recursiveCircle(cirX,cirY-rad-rad/2,rad/2,up);
	}
}

void iDraw()
{
	iClear();

	iText(10,580,"Level: ");
	iText(65,580,levelStr);
	iText(300,580,"Press UP ARROW to level up");
	iText(300,560,"Press DOWN ARROW to level down");

	recursiveCircle(centreX,centreY,radius,0);
}

/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

void iPassiveMouseMove(int mx, int my)
{
	//place your codes here
}
/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == GLUT_KEY_UP)
	{
		checkRadius/=2;
		level++;
		itoa(level,levelStr,10);
	}

	if(key == GLUT_KEY_DOWN)
	{
		checkRadius*=2;
		level--;
		itoa(level,levelStr,10);
	}

	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here. 
	iInitialize(600, 600, "CIRCLE FRACTAL");
	return 0;
}	