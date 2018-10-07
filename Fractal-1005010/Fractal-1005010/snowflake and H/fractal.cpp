/*	Fractal Generator
	Snowflakes & HFractal
	created by Sabbir Ahmad
	#1005010, CSE, BUET
						*/
# include "iGraphics.h"


#define SIZE 50000
#define LOOP 1000
#define SCREEN_X 800
#define SCREEN_Y 500

void iTriangle(struct triangle);    //function to draw triangle
void iFilledTriangle(struct triangle);	//function to draw filled triangle

void drawInterface();
void mainWindow();

//Snowflakes functions
void findPoint_SnowflakesFractal(struct triangle cur, double length);
void returnStructureValue(double pt_x1,double pt_y1,double pt_x2,double pt_y2,double pt_x3,double pt_y3,double length);
void generate_SnowflakesFractal();
void drawSnowlakesFractal();

//HFractal functions
void findPoint_HFractal(struct point P,double hLength);
void generate_HFractal();
void drawHFractal();


struct point{
	double x;
	double y;
};

struct triangle{
	struct point pt1;
	struct point pt2;
	struct point pt3;
};

//HFRACTAL struct
struct hfractalStructure{
	struct point pt1;
	struct point pt2;
	struct point pt3;
	struct point pt4;
	struct point pt5;
	struct point pt6;
};

int mouseX,mouseY;
double R=195,G=35,B=35;
int showFractalMode=0;  //flag to show snowflakes=1 or Hfractal=2 mainWindow=0
int aboutMode=0;		//flag to show ABOUT when aboutMode=1 
int helpMode=0;			//flag to show help when heloMode=1

//snowflakes variables
struct triangle t[3*SIZE];
struct triangle iT;

int countArray[]={0,4,43,256,1552,10000,80000,100000,3*SIZE};
int listNumber=1;
int COUNT_SNOW=0;
int countLevel_SNOW;
int snowflakesFractalMode=0;		//two different modes of snowflakes

char countChar[30]="0";

double firstLength=100;
double centerSnowX=500;
double centerSnowY=250;
//snowflakes variables end



//Hfractal variables
struct point hfractal[3*SIZE];
struct hfractalStructure hfstruct[3*SIZE];

int countHfractal[]={0,1,5,21,85,341,1365,5461,21845};
int hfstructArrayCounter; 
int hfractalArrayCounter;
int COUNT_HF=0;
int countLevel_HF;

char countCharHF[30]="0";

double initialHLength=300;
double centerHfractalX=490;
double centerHfractalY=250;
//Hfractal variables end


void iTriangle(struct triangle tFunc)
{
	double xx[3], yy[3];

	xx[0]=tFunc.pt1.x;
	yy[0]=tFunc.pt1.y;
	xx[1]=tFunc.pt2.x;
	yy[1]=tFunc.pt2.y;
	xx[2]=tFunc.pt3.x;
	yy[2]=tFunc.pt3.y;

	iPolygon(xx, yy, 3);

}

void iFilledTriangle(struct triangle tFunc)
{
	double xx[3], yy[3];

	xx[0]=tFunc.pt1.x;
	yy[0]=tFunc.pt1.y;
	xx[1]=tFunc.pt2.x;
	yy[1]=tFunc.pt2.y;
	xx[2]=tFunc.pt3.x;
	yy[2]=tFunc.pt3.y;

	iFilledPolygon(xx, yy, 3);

}


void mainWindow()
{
	iSetColor(255,255,255);
	iFilledRectangle(5,5,790,490);

	if(aboutMode==0)
	{
		iShowBMP(140,280,"fractalgenerator.bmp");
		
		if(mouseX>220 && mouseX<384 && mouseY>150 && mouseY<278)
			iShowBMP(220,150,"snowflakes2.bmp");
		else
			iShowBMP(220,150,"snowflakes.bmp");
		if(mouseX>420 && mouseX<584 && mouseY>150 && mouseY<278)
			iShowBMP(420,150,"hfractal2.bmp");
		else
			iShowBMP(420,150,"hfractal.bmp");

		iShowBMP(270,50,"helptext.bmp");
		iShowBMP(370,50,"about.bmp");
		iShowBMP(470,50,"mainexit.bmp");

		if(mouseX>260 && mouseX<360 && mouseY>40 && mouseY<92)
		{
			iSetColor(0,0,0);
			iText(mouseX,mouseY,"Press F1 for help");
		}
	}
	else
	{
		iShowBMP(208,160,"abouttext.bmp");

		iShowBMP(580,20,"aboutback.bmp");

		iShowBMP(680,20,"mainexit.bmp");

		if(helpMode==1)
		{
			iShowBMP(30,50,"help.bmp");
		}
	}

	
}

void drawInterface()
{
	iSetColor(255,255,255);
	iFilledRectangle(5,5,170,490);

	if(showFractalMode==1)
	{
		iShowBMP(5,362,"snowflakes.bmp");

		iShowBMP(10,330,"modetext.bmp");
		if(mouseX>70 && mouseX<150 && mouseY>330 && mouseY<362)
			iShowBMP(70,330,"mode.bmp");
		else
			iShowBMP(70,330,"change.bmp");
	}
	else if(showFractalMode==2)
	{
		iShowBMP(8,362,"hfractal.bmp");
	}

	iShowBMP(10,298,"centertext.bmp");
	iShowBMP(30,200,"arrow.bmp");

	iShowBMP(10,165,"leveltext.bmp");
	iShowBMP(10,130,"level.bmp");

	iShowBMP(80,165,"sizetext.bmp");
	iShowBMP(80,130,"size.bmp");

	iShowBMP(10,42,"rgbtext.bmp");
	iShowBMP(80,74,"r.bmp");
	iShowBMP(80,42,"g.bmp");
	iShowBMP(80,10,"b.bmp");

	iShowBMP(662,5,"back.bmp");
	iShowBMP(731,5,"exit.bmp");

}

void drawSnowlakesFractal()
{
	for(int i=0;i<COUNT_SNOW;i++)
	{

			iT.pt1.x=t[i].pt1.x;
			iT.pt1.y=t[i].pt1.y;
			iT.pt2.x=t[i].pt2.x;
			iT.pt2.y=t[i].pt2.y;
			iT.pt3.x=t[i].pt3.x;
			iT.pt3.y=t[i].pt3.y;

			if(snowflakesFractalMode==0)
			{
				iSetColor(R,G,B);
				iFilledTriangle(iT);
			}

			else
			{
				iSetColor(R,G,B);
				iTriangle(iT);
			}
	}

	iSetColor(255,255,255);
	iText(700,450,"Level: ");
	iText(760,450,countChar);

}

void drawHFractal()
{
	for(int i=0;i<COUNT_HF;i++)
	{
		double x1,x2,x3,x4,x5,x6;
		double y1,y2,y3,y4,y5,y6;
		
		x1=hfstruct[i].pt1.x;
		y1=hfstruct[i].pt1.y;
		x2=hfstruct[i].pt2.x;
		y2=hfstruct[i].pt2.y;
		x3=hfstruct[i].pt3.x;
		y3=hfstruct[i].pt3.y;
		x4=hfstruct[i].pt4.x;
		y4=hfstruct[i].pt4.y;
		x5=hfstruct[i].pt5.x;
		y5=hfstruct[i].pt5.y;
		x6=hfstruct[i].pt6.x;
		y6=hfstruct[i].pt6.y;

		iSetColor(R,G,B);

		iLine(x1,y1,x2,y2);
		iLine(x3,y3,x4,y4);
		iLine(x5,y5,x6,y6);
	}

	iSetColor(255,255,255);
	iText(700,450,"Level: ");
	iText(760,450,countCharHF);
}


/* 
	function iDraw() is called again and again by the system.
*/

void iDraw()
{
	iClear();

	if(showFractalMode==0)
	{
		mainWindow();
	}
	else if(showFractalMode==1)
	{
		drawInterface();
		drawSnowlakesFractal();
	}
	else if(showFractalMode==2)
	{
		drawInterface();
		drawHFractal();
	}
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
	mouseX=mx;
	mouseY=my;
}
/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{

	//printf("X=%d\n",mx);
	//printf("Y=%d\n",my);
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//change showFractalMode
		if(mx>220 && mx<384 && my>150 && my<278 && showFractalMode==0 && aboutMode==0)
		{
			showFractalMode=1;
		}
		if(mx>420 && mx<584 && my>150 && my<278 && showFractalMode==0 && aboutMode==0)
		{
			showFractalMode=2;
		}

		if(mx>370 && mx<450 && my>50 && my<82 && showFractalMode==0 && aboutMode==0)
		{
			aboutMode=1;
		}
		
		if(mx>580 && mx<660 && my>20 && my<52 && showFractalMode==0 && aboutMode==1)
		{
			aboutMode=0;
			helpMode=0;
		}
		if(mx>270 && mx<350 && my>50 && my<82 && showFractalMode==0)
		{
			helpMode=1;
			aboutMode=1;
		}
		if(mx>70 && mx<150 && my>330 && my<362)
		{
			if(showFractalMode==1)
			{
				if(snowflakesFractalMode==0)
					snowflakesFractalMode=1;
				else
					snowflakesFractalMode=0;
			}
		}

		if(mx>470 && mx<550 && my>50 && my<82 && showFractalMode==0 && aboutMode==0)
		{
			exit(0);
		}
		if(mx>680 && mx<760 && my>20 && my<52 && showFractalMode==0 && aboutMode==1)
		{
			exit(0);
		}
		if(mx>662 && mx<726 && my>5 && my<37 && showFractalMode!=0)
		{
			showFractalMode=0;
		}
		if(mx>731 && mx<795 && my>5 && my<37 && showFractalMode!=0)
		{
			exit(0);
		}

		//fractal center change start
		if(mx>30 && mx<60 && my>234 && my<262)
		{
			if(showFractalMode==1)
			{
				centerSnowX-=10;
				listNumber=1;
				generate_SnowflakesFractal();	
			}
			else if(showFractalMode==2)
			{
				centerHfractalX-=10;
				hfstructArrayCounter=0; 
				hfractalArrayCounter=0;
				generate_HFractal();
			}
		}
		if(mx>96 && mx<126 && my>234 && my<262)
		{
			if(showFractalMode==1)
			{
				centerSnowX+=10;
				listNumber=1;
				generate_SnowflakesFractal();	
			}
			else if(showFractalMode==2)
			{
				centerHfractalX+=10;
				hfstructArrayCounter=0; 
				hfractalArrayCounter=0;
				generate_HFractal();
			}
		}
		if(mx>64 && mx<92 && my>266 && my<296)
		{
			if(showFractalMode==1)
			{
				centerSnowY+=10;
				listNumber=1;
				generate_SnowflakesFractal();
			}	
			else if(showFractalMode==2)
			{
				centerHfractalY+=10;
				hfstructArrayCounter=0; 
				hfractalArrayCounter=0;
				generate_HFractal();
			}
		}
		if(mx>64 && mx<92 && my>200 && my<230)
		{
			if(showFractalMode==1)
			{
				centerSnowY-=10;
				listNumber=1;
				generate_SnowflakesFractal();
			}	
			else if(showFractalMode==2)
			{
				centerHfractalY-=10;
				hfstructArrayCounter=0; 
				hfractalArrayCounter=0;
				generate_HFractal();
			}
		}
		//fractal center change end

		//fractal level change start
		if(mx>15 && mx<40 && my>135 && my<168)
		{
			if(showFractalMode==1)
			{
				if(countLevel_SNOW<8)
				{
					countLevel_SNOW++;
					firstLength+=30;
					listNumber=1;
					generate_SnowflakesFractal();

				}
				COUNT_SNOW=countArray[countLevel_SNOW];
				itoa(countLevel_SNOW,countChar,10);
				//printf("count   %d\n",COUNT);
			}
			else if(showFractalMode==2)
			{
				//COUNT++;
				if(countLevel_HF<8)
				{
					countLevel_HF++;
					if(initialHLength>30)
						initialHLength-=30;
					hfstructArrayCounter=0; 
					hfractalArrayCounter=0;
					generate_HFractal();
				}
				COUNT_HF=countHfractal[countLevel_HF];
				itoa(countLevel_HF,countCharHF,10);
			}
		}

		if(mx>45 && mx<70 && my>135 && my<168)
		{
			if(showFractalMode==1)
			{
				if(countLevel_SNOW>0)
				{
					countLevel_SNOW--;
					if(firstLength>30)
						firstLength-=30;
					listNumber=1;
					generate_SnowflakesFractal();

				}
				COUNT_SNOW=countArray[countLevel_SNOW];
				itoa(countLevel_SNOW,countChar,10);
			}
			else if(showFractalMode==2)
			{
				//COUNT--;
				if(countLevel_HF>0)
				{
					countLevel_HF--;
					initialHLength+=30;
					hfstructArrayCounter=0; 
					hfractalArrayCounter=0;
					generate_HFractal();
				}
				COUNT_HF=countHfractal[countLevel_HF];
				itoa(countLevel_HF,countCharHF,10);
			}
		}
		//fractal level change end

		//fractal size change start
		if(mx>85 && mx<110 && my>135 && my<168)
		{
			if(showFractalMode==1)
			{
				firstLength+=30;
				listNumber=1;
				generate_SnowflakesFractal();	
			}
			else if(showFractalMode==2)
			{
				initialHLength+=30;
				hfstructArrayCounter=0; 
				hfractalArrayCounter=0;
				generate_HFractal();
			}
		}
		if(mx>115 && mx<140 && my>135 && my<168)
		{
			if(showFractalMode==1 && firstLength>30)
			{
				firstLength-=30;
				listNumber=1;
				generate_SnowflakesFractal();	
			}
			else if(showFractalMode==2 && initialHLength>30)
			{
				initialHLength-=30;
				hfstructArrayCounter=0; 
				hfractalArrayCounter=0;
				generate_HFractal();
			}	
		}
		//fractal size change end

		//fractal color change start
		if(mx>100 && mx<118 && my>80 && my<100)
		{
			if(R<236)
				R+=20;
		}
		if(mx>122 && mx<142 && my>80 && my<100)
		{
			if(R>19)
				R-=20;
		}

		if(mx>100 && mx<118 && my>48 && my<67)
		{
			if(G<236)
				G+=20;
		}
		if(mx>122 && mx<142 && my>48 && my<67)
		{
			if(G>19)
				G-=20;
		}

		if(mx>100 && mx<118 && my>17 && my<35)
		{
			if(B<236)
				B+=20;
		}
		if(mx>122 && mx<142 && my>17 && my<35)
		{
			if(B>19)
				B-=20;
		}
		//fractal color change end


	}

	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/

void iKeyboard(unsigned char key)
{
	//back button set
	if(key == 'b' && showFractalMode==0 && aboutMode==1)
	{
		aboutMode=0;
		helpMode=0;
	}
	if(key == 'b' && showFractalMode!=0)
	{
		showFractalMode=0;
	}
	if(key == 'm')
	{
		if(showFractalMode==1)
		{
			if(snowflakesFractalMode==0)
				snowflakesFractalMode=1;
			else
				snowflakesFractalMode=0;
		}
	}

	//fractal size change start
	if(key == '.')	//size up
	{
		if(showFractalMode==1)
		{
			firstLength+=30;
			listNumber=1;
			generate_SnowflakesFractal();	
		}
		else if(showFractalMode==2)
		{
			initialHLength+=30;
			hfstructArrayCounter=0; 
			hfractalArrayCounter=0;
			generate_HFractal();
		}
	}
	if(key == ',')	//size down
	{
		if(showFractalMode==1 && firstLength>30)
		{
			firstLength-=30;
			listNumber=1;
			generate_SnowflakesFractal();	
		}
		else if(showFractalMode==2 && initialHLength>30)
		{
			initialHLength-=30;
			hfstructArrayCounter=0; 
			hfractalArrayCounter=0;
			generate_HFractal();
		}	
	}
	//fractal size change end
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE_UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/

void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}

	if(key == GLUT_KEY_F1)
	{
		helpMode=1;
		aboutMode=1;
	}
	//fractal level change start
	if(key == GLUT_KEY_PAGE_UP)
	{
		if(showFractalMode==1)
		{
			if(countLevel_SNOW<8)
			{
				countLevel_SNOW++;
				firstLength+=30;
				listNumber=1;
				generate_SnowflakesFractal();

			}
			COUNT_SNOW=countArray[countLevel_SNOW];
			itoa(countLevel_SNOW,countChar,10);
			//printf("count   %d\n",COUNT);
		}
		else if(showFractalMode==2)
		{
			//COUNT++;
			if(countLevel_HF<8)
			{
				countLevel_HF++;
				if(initialHLength>30)
					initialHLength-=30;
				hfstructArrayCounter=0; 
				hfractalArrayCounter=0;
				generate_HFractal();
			}
			COUNT_HF=countHfractal[countLevel_HF];
			itoa(countLevel_HF,countCharHF,10);
		}
	}

	if(key == GLUT_KEY_PAGE_DOWN)
	{
		if(showFractalMode==1)
		{
			if(countLevel_SNOW>0)
			{
				countLevel_SNOW--;
				if(firstLength>30)
					firstLength-=30;
				listNumber=1;
				generate_SnowflakesFractal();

			}
			COUNT_SNOW=countArray[countLevel_SNOW];
			itoa(countLevel_SNOW,countChar,10);
		}
		else if(showFractalMode==2)
		{
			//COUNT--;
			if(countLevel_HF>0)
			{
				countLevel_HF--;
				initialHLength+=30;
				hfstructArrayCounter=0; 
				hfractalArrayCounter=0;
				generate_HFractal();
			}
			COUNT_HF=countHfractal[countLevel_HF];
			itoa(countLevel_HF,countCharHF,10);
		}
	}
	//fractal level change end

	//fractal center change start
	if(key == GLUT_KEY_LEFT)
	{
		if(showFractalMode==1)
		{
			centerSnowX-=10;
			listNumber=1;
			generate_SnowflakesFractal();	
		}
		else if(showFractalMode==2)
		{
			centerHfractalX-=10;
			hfstructArrayCounter=0; 
			hfractalArrayCounter=0;
			generate_HFractal();
		}
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(showFractalMode==1)
		{
			centerSnowX+=10;
			listNumber=1;
			generate_SnowflakesFractal();	
		}
		else if(showFractalMode==2)
		{
			centerHfractalX+=10;
			hfstructArrayCounter=0; 
			hfractalArrayCounter=0;
			generate_HFractal();
		}
	}
	if(key == GLUT_KEY_UP)
	{
		if(showFractalMode==1)
		{
			centerSnowY+=10;
			listNumber=1;
			generate_SnowflakesFractal();
		}	
		else if(showFractalMode==2)
		{
			centerHfractalY+=10;
			hfstructArrayCounter=0; 
			hfractalArrayCounter=0;
			generate_HFractal();
		}
	}
	if(key == GLUT_KEY_DOWN)
	{
		if(showFractalMode==1)
		{
			centerSnowY-=10;
			listNumber=1;
			generate_SnowflakesFractal();
		}	
		else if(showFractalMode==2)
		{
			centerHfractalY-=10;
			hfstructArrayCounter=0; 
			hfractalArrayCounter=0;
			generate_HFractal();
		}
	}
	//fractal center change end
}


/*	function that takes triangle type structure introduced before. if y cordinates of 2 points are same,
	then calls another function to find other points to make triangle*/

void findPoint_SnowflakesFractal(struct triangle current, double length)
{
	if(fabs(current.pt1.y-current.pt2.y)<0.00000000001)
	{
		returnStructureValue(current.pt1.x,current.pt1.y,current.pt2.x,current.pt2.y,current.pt3.x,current.pt3.y,length);
	}
	else if(fabs(current.pt2.y-current.pt3.y)<0.00000000001)
	{
		returnStructureValue(current.pt2.x,current.pt2.y,current.pt3.x,current.pt3.y,current.pt1.x,current.pt1.y,length);
	}
	else if(fabs(current.pt3.y-current.pt1.y)<0.00000000001)
	{
		returnStructureValue(current.pt3.x,current.pt3.y,current.pt1.x,current.pt1.y,current.pt2.x,current.pt2.y,length);
	}
}



/*	this function calculates cordinates of needed points and stores them in the triangle structure
	type array t */


void returnStructureValue(double pt_x1,double pt_y1,double pt_x2,double pt_y2,double pt_x3,double pt_y3,double length)
{
    double x1,y1,x2,y2,x3,y3;
    double midx,midy;

    midx=(pt_x1+pt_x2)/2.0;
    midy=(pt_y1+pt_y2)/2.0;

    if(pt_y3>pt_y1)
    {
        x1=midx;
        y1=midy-.5*sqrt(3)*(length/3.0);

        x2=midx-length/6.0;
        y2=midy;

        x3=midx+length/6.0;
        y3=midy;

        t[listNumber].pt1.x=x1;
        t[listNumber].pt1.y=y1;
        t[listNumber].pt2.x=x2;
        t[listNumber].pt2.y=y2;
        t[listNumber].pt3.x=x3;
        t[listNumber].pt3.y=y3;

        listNumber++;

        x1=midx+length/2.0;
        y1=midy+length/(sqrt(3));

        x2=midx+length/6.0;
        y2=midy+length/(sqrt(3));

        x3=midx+length/3.0;
        y3=midy+.5*sqrt(3)*length/3.0;

        t[listNumber].pt1.x=x1;
        t[listNumber].pt1.y=y1;
        t[listNumber].pt2.x=x2;
        t[listNumber].pt2.y=y2;
        t[listNumber].pt3.x=x3;
        t[listNumber].pt3.y=y3;

        listNumber++;

        x1=midx-length/2.0;
        y1=midy+length/(sqrt(3));

        x2=midx-length/6.0;
        y2=midy+length/(sqrt(3));

        x3=midx-length/3.0;
        y3=midy+.5*sqrt(3)*length/3.0;

        t[listNumber].pt1.x=x1;
        t[listNumber].pt1.y=y1;
        t[listNumber].pt2.x=x2;
        t[listNumber].pt2.y=y2;
        t[listNumber].pt3.x=x3;
        t[listNumber].pt3.y=y3;

        listNumber++;

    }

    else
    {
        x1=midx;
        y1=midy+.5*sqrt(3)*(length/3.0);

        x2=midx-length/6.0;
        y2=midy;

        x3=midx+length/6.0;
        y3=midy;

        t[listNumber].pt1.x=x1;
        t[listNumber].pt1.y=y1;
        t[listNumber].pt2.x=x2;
        t[listNumber].pt2.y=y2;
        t[listNumber].pt3.x=x3;
        t[listNumber].pt3.y=y3;

        listNumber++;

        x1=midx+length/2.0;
        y1=midy-length/(sqrt(3));

        x2=midx+length/6.0;
        y2=midy-length/(sqrt(3));

        x3=midx+length/3.0;
        y3=midy-.5*sqrt(3)*length/3.0;

        t[listNumber].pt1.x=x1;
        t[listNumber].pt1.y=y1;
        t[listNumber].pt2.x=x2;
        t[listNumber].pt2.y=y2;
        t[listNumber].pt3.x=x3;
        t[listNumber].pt3.y=y3;

        listNumber++;

        x1=midx-length/2.0;
        y1=midy-length/(sqrt(3));

        x2=midx-length/6.0;
        y2=midy-length/(sqrt(3));

        x3=midx-length/3.0;
        y3=midy-.5*sqrt(3)*length/3.0;

        t[listNumber].pt1.x=x1;
        t[listNumber].pt1.y=y1;
        t[listNumber].pt2.x=x2;
        t[listNumber].pt2.y=y2;
        t[listNumber].pt3.x=x3;
        t[listNumber].pt3.y=y3;

        listNumber++;
    }

    x1=pt_x1;
    y1=pt_y1;
    x2=(pt_x2+2*pt_x1)/3.0;
    y2=(pt_y2+2*pt_y1)/3.0;
    x3=(pt_x3+2*pt_x1)/3.0;
    y3=(pt_y3+2*pt_y1)/3.0;

    t[listNumber].pt1.x=x1;
    t[listNumber].pt1.y=y1;
    t[listNumber].pt2.x=x2;
    t[listNumber].pt2.y=y2;
    t[listNumber].pt3.x=x3;
    t[listNumber].pt3.y=y3;

    listNumber++;

    x1=pt_x2;
    y1=pt_y2;
    x2=(pt_x1+2*pt_x2)/3.0;
    y2=(pt_y1+2*pt_y2)/3.0;
    x3=(pt_x3+2*pt_x2)/3.0;
    y3=(pt_y3+2*pt_y2)/3.0;

    t[listNumber].pt1.x=x1;
    t[listNumber].pt1.y=y1;
    t[listNumber].pt2.x=x2;
    t[listNumber].pt2.y=y2;
    t[listNumber].pt3.x=x3;
    t[listNumber].pt3.y=y3;

    listNumber++;

    x1=pt_x3;
    y1=pt_y3;
    x2=(pt_x2+2*pt_x3)/3.0;
    y2=(pt_y2+2*pt_y3)/3.0;
    x3=(pt_x1+2*pt_x3)/3.0;
    y3=(pt_y1+2*pt_y3)/3.0;

    t[listNumber].pt1.x=x1;
    t[listNumber].pt1.y=y1;
    t[listNumber].pt2.x=x2;
    t[listNumber].pt2.y=y2;
    t[listNumber].pt3.x=x3;
    t[listNumber].pt3.y=y3;

    listNumber++;
}



void findPoint_HFractal(struct point P,double hLength)
{
	double x1,y1,x2,y2,x3,y3,x4,y4;

	x1=P.x-hLength/2;
	y1=P.y+hLength/2;

	x2=P.x-hLength/2;
	y2=P.y-hLength/2;

	x3=P.x+hLength/2;
	y3=P.y+hLength/2;

	x4=P.x+hLength/2;
	y4=P.y-hLength/2;

	hfractal[hfractalArrayCounter].x = x1;
	hfractal[hfractalArrayCounter].y = y1;
	hfractalArrayCounter++;

	hfractal[hfractalArrayCounter].x = x2;
	hfractal[hfractalArrayCounter].y = y2;
	hfractalArrayCounter++;

	hfractal[hfractalArrayCounter].x = x3;
	hfractal[hfractalArrayCounter].y = y3;
	hfractalArrayCounter++;

	hfractal[hfractalArrayCounter].x = x4;
	hfractal[hfractalArrayCounter].y = y4;
	hfractalArrayCounter++;

	hfstruct[hfstructArrayCounter].pt1.x = P.x-hLength/2;
	hfstruct[hfstructArrayCounter].pt1.y = P.y;
	hfstruct[hfstructArrayCounter].pt2.x = P.x+hLength/2;
	hfstruct[hfstructArrayCounter].pt2.y = P.y;
	hfstruct[hfstructArrayCounter].pt3.x = x1;
	hfstruct[hfstructArrayCounter].pt3.y = y1;
	hfstruct[hfstructArrayCounter].pt4.x = x2;
	hfstruct[hfstructArrayCounter].pt4.y = y2;
	hfstruct[hfstructArrayCounter].pt5.x = x3;
	hfstruct[hfstructArrayCounter].pt5.y = y3;
	hfstruct[hfstructArrayCounter].pt6.x = x4;
	hfstruct[hfstructArrayCounter].pt6.y = y4;
	hfstructArrayCounter++;


}

void generate_SnowflakesFractal()
{
	struct triangle first;

	first.pt1.x=centerSnowX-firstLength/2.0;
	first.pt1.y=centerSnowY-firstLength/(2*sqrt(3.0));
	first.pt2.x=centerSnowX+firstLength/2.0;
	first.pt2.y=centerSnowY-firstLength/(2*sqrt(3.0));
	first.pt3.x=centerSnowX;
	first.pt3.y=centerSnowY+firstLength/(sqrt(3.0));

	t[0]=first;

	double newLength=firstLength;

	int varLength=0;
	int numlist=1;
	for(int i=0;i<25*LOOP;i++)
	{
		findPoint_SnowflakesFractal(t[i],newLength);
		if(numlist>=pow(6,varLength))
		{
			numlist=0;
			varLength++;
			newLength=newLength/3;
		}
		numlist++;
	}


}

void generate_HFractal()
{
	hfractal[0].x = centerHfractalX;
	hfractal[0].y = centerHfractalY;

	hfractalArrayCounter++;

	double newHLength=initialHLength;

	int varLength=0;
	int numlist=1;
	for(int i=0;i<25*LOOP;i++)
	{
		findPoint_HFractal(hfractal[i],newHLength);
		if(numlist>=pow(4,varLength))
		{
			numlist=0;
			varLength++;
			newHLength=newHLength/2;
		}
		numlist++;
	}
}

int main()
{
	//generate_SnowflakesFractal();
	//generate_HFractal();

	iInitialize(SCREEN_X, SCREEN_Y, "SNOWFLAKES FRACTAL");
	return 0;
}	