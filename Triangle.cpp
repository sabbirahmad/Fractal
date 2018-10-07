# include "iGraphics.h"

/* 
	function iDraw() is called again and again by the system.
*/

int Tx1=150,Ty1=400;
int Tx2=450,Ty2=400;
int Tx3=300,Ty3=100;

int level=0;
char levelStr[5]="0";

//int length=300;
double checkLength=1025;
void recursiveTriangle(double x1,double y1, double x2, double y2, double x3, double y3,double check)
{
	if(check<checkLength)
		return;

	iLine(x1,y1,x2,y2);
	iLine(x2,y2,x3,y3);
	iLine(x3,y3,x1,y1);

	//recursiveTriangle((x1+x2)/2,(y1+y2)/2,(x2+x3)/2,(y2+y3)/2,(x3+x1)/2,(y3+y1)/2,check/2);
	recursiveTriangle(x1,y1,(x1+x2)/2,(y1+y2)/2,(x3+x1)/2,(y3+y1)/2,check/2);
	recursiveTriangle((x1+x2)/2,(y1+y2)/2,x2,y2,(x2+x3)/2,(y2+y3)/2,check/2);
	recursiveTriangle((x2+x3)/2,(y2+y3)/2,(x3+x1)/2,(y3+y1)/2,x3,y3,check/2);

}





void iDraw()
{
	//place your drawing codes here	

	iClear();

	iText(10,580,"Level: ");
	iText(65,580,levelStr);
	iText(300,580,"Press UP ARROW to level up");
	iText(300,560,"Press DOWN ARROW to level down");

	recursiveTriangle(Tx1,Ty1,Tx2,Ty2,Tx3,Ty3,1024);
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
		checkLength/=2;
		level++;
		itoa(level,levelStr,10);
	}

	if(key == GLUT_KEY_DOWN)
	{
		checkLength*=2;
		level--;
		itoa(level,levelStr,10);
	}

	//place your codes for other keys here
}

int main()
{
	//place your own initialization codes here. 
	iInitialize(600, 600, "demooo");
	return 0;
}	