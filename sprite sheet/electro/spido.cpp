#include<iostream>
using namespace std;

# include "iGraphics.h"
int mposx,  mposy,i=0,speed=10,r=0,jy=50,j=0,mh=200,dj=0,f1=0,fc=0,f2=0,ki=0;
int pos[100];
int slice=70+27,width=1450/slice;
#define scw 1350;
#define sch 510;
#define sspd 14;
#define gspd 14;


bool run=true,jump=false,down=false,jump1=false,d_jump=false,djjump=false,djdown=false,fight=false,dash=false,kick=false;
int run1=0,jump_c=0,in=0,d=6;
char sp [3][20]= {"char\\s1.bmp","char\\s2.bmp","char\\s3.bmp"};
char rn[][20]= {"char\\r1.bmp","char\\r2.bmp","char\\r3.bmp","char\\r4.bmp","char\\r5.bmp","char\\r6.bmp","char\\r7.bmp","char\\r8.bmp","char\\r9.bmp","char\\r10.bmp","char\\r11.bmp","char\\r12.bmp","char\\r13.bmp","char\\r14.bmp"};
char djmp[][20]= {"char\\j2.bmp","char\\j3.bmp","char\\j4.bmp","char\\j5.bmp","char\\j6.bmp","char\\j10.bmp","char\\j11.bmp","char\\j1.bmp"};
char jmp[][20]= {"char\\j1.bmp"};
char bg[][30]= {"bg\\b01.bmp",	"bg\\b02.bmp",	"bg\\b03.bmp",	"bg\\b04.bmp",	"bg\\b05.bmp",	"bg\\b06.bmp",	"bg\\b07.bmp",	"bg\\b08.bmp",	"bg\\b09.bmp",	"bg\\b10.bmp",	"bg\\b11.bmp",	"bg\\b12.bmp",	"bg\\b13.bmp",	"bg\\b14.bmp",	"bg\\b15.bmp",	"bg\\b16.bmp",	"bg\\b17.bmp",	"bg\\b18.bmp",	"bg\\b19.bmp",	"bg\\b20.bmp",	"bg\\b21.bmp",	"bg\\b22.bmp",	"bg\\b23.bmp",	"bg\\b24.bmp",	"bg\\b25.bmp",	"bg\\b26.bmp",	"bg\\b27.bmp",	"bg\\b28.bmp",	"bg\\b29.bmp",	"bg\\b30.bmp",	"bg\\b31.bmp",	"bg\\b32.bmp",	"bg\\b33.bmp",	"bg\\b34.bmp",	"bg\\b35.bmp",	"bg\\b36.bmp",	"bg\\b37.bmp",	"bg\\b38.bmp",	"bg\\b39.bmp",	"bg\\b40.bmp",	"bg\\b41.bmp",	"bg\\b42.bmp",	"bg\\b43.bmp",	"bg\\b44.bmp",	"bg\\b45.bmp",	"bg\\b46.bmp",	"bg\\b47.bmp",	"bg\\b48.bmp",	"bg\\b49.bmp",	"bg\\b50.bmp",	"bg\\b51.bmp",	"bg\\b52.bmp",	"bg\\b53.bmp",	"bg\\b54.bmp",	"bg\\b55.bmp",	"bg\\b56.bmp",	"bg\\b57.bmp",	"bg\\b58.bmp",	"bg\\b59.bmp",	"bg\\b60.bmp",	"bg\\b61.bmp",	"bg\\b62.bmp",	"bg\\b63.bmp",	"bg\\b64.bmp",	"bg\\b65.bmp",	"bg\\b66.bmp",	"bg\\b67.bmp",	"bg\\b68.bmp",	"bg\\b69.bmp",	"bg\\b70.bmp",	"bg\\b01.bmp",	"bg\\b02.bmp",	"bg\\b03.bmp",	"bg\\b04.bmp",	"bg\\b05.bmp",	"bg\\b06.bmp",	"bg\\b07.bmp",	"bg\\b08.bmp",	"bg\\b09.bmp",	"bg\\b10.bmp",	"bg\\b11.bmp",	"bg\\b12.bmp",	"bg\\b13.bmp",	"bg\\b14.bmp",	"bg\\b15.bmp",	"bg\\b16.bmp",	"bg\\b17.bmp",	"bg\\b18.bmp",	"bg\\b19.bmp",	"bg\\b20.bmp",	"bg\\b21.bmp",	"bg\\b22.bmp",	"bg\\b23.bmp",	"bg\\b24.bmp",	"bg\\b25.bmp",	"bg\\b26.bmp",	"bg\\b27.bmp",	"bg\\b28.bmp",	"bg\\b29.bmp",	"bg\\b30.bmp",	"bg\\b31.bmp",	"bg\\b32.bmp",	"bg\\b33.bmp",	"bg\\b34.bmp",	"bg\\b35.bmp",	"bg\\b36.bmp","bg\\b37.bmp",	"bg\\b38.bmp",	"bg\\b39.bmp",	"bg\\b40.bmp",	"bg\\b41.bmp",	"bg\\b42.bmp",	"bg\\b43.bmp",	"bg\\b44.bmp",	"bg\\b45.bmp",	"bg\\b46.bmp",	"bg\\b47.bmp",	"bg\\b48.bmp",	"bg\\b49.bmp",	"bg\\b50.bmp",	"bg\\b51.bmp",	"bg\\b52.bmp",	"bg\\b53.bmp",	"bg\\b54.bmp",	"bg\\b55.bmp",	"bg\\b56.bmp",	"bg\\b57.bmp",	"bg\\b58.bmp",	"bg\\b59.bmp",	"bg\\b60.bmp",	"bg\\b61.bmp",	"bg\\b62.bmp",	"bg\\b63.bmp",	"bg\\b64.bmp",	"bg\\b65.bmp",	"bg\\b66.bmp",	"bg\\b67.bmp",	"bg\\b68.bmp",	"bg\\b69.bmp",	"bg\\b70.bmp"};
char f[][20]= {"char\\f1.bmp","char\\f2.bmp","char\\f3.bmp","char\\f4.bmp","char\\f5.bmp","char\\f6.bmp","char\\f7.bmp","char\\f8.bmp"};
char k[][20]={"char\\k1.bmp"};


/*
	function iDraw() is called again and again by the system.
*/



void iDraw()
{
    //place your drawing codes here

    iClear();

    for(int m=0; m<slice; m++)
    {

        iShowBMP(pos[m],0,bg[m]);//1315


    }




    if(in==0)
    {
        int n=0;

        for(int m=0; m<slice; m++)
        {
            iShowBMP(n,0,bg[m]);
            n+=width;
        }
        iShowBMP2(0,50,sp[i],16777215);

    }
	if(kick)
	{
		iShowBMP2(speed,jy,k[0],16777215);
		ki++;
		
	}
	if(in!=0 && dash)
	{

		iShowBMP2(speed,50,f[d],16777215);
		
	}
    
    if(fight && in!=0 && f2==1)
   {

        if(f1>=0)

            iShowBMP2(speed,50,f[f1],16777215);

		


    }
	if(fight && in!=0 && f2==2)
	{
		
			iShowBMP2(speed,50,f[f1],16777215);
	}
    if(jump && in!=0)
    {



        run=true;


        if(d_jump)
        {
            jump1=false;
            down=false;
            iShowBMP2(speed,jy,djmp[dj],16777215);
        }
        else
		{
			if(!kick)

            iShowBMP2(speed,jy,jmp[j],16777215);
		}

    }
    if(!run)
    {


        iShowBMP2(speed,50,rn[r],16777215);
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
/*iPassiveMouseMove is called to detect and use
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
    //place your code here

    mposx = mx;
    mposy = my;
    if(mx== 2) {}       /*Something to do with mx*/
    else if(my== 2) {}  /*Something to do with my*/

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
    if(key == '0')
    {
        if(jump_c>0)
        {
            jump1=false;
            down=false;
            d_jump=true;
            djjump=true;
        }
    }
    if(key=='f' && !jump)
    {

        fight=true;
        run=true;
        if(f2>2)
			f2=0;
		else
		f2++;
		
		

    }
	
	if(key == 'd' && !jump)
	{
		run=true;
		dash=true;

	}
	if(key == 'f' && jump && !d_jump)
	{
		run=true;
		kick=true;
		down=false;
		jump1=false;
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

    if(key == GLUT_KEY_RIGHT)
    {
        run=false;
        speed+=20;
        if(speed>=1240)
            speed=1240;
        in++;

    }
    if(key == GLUT_KEY_LEFT)
    {
        run=false;
        speed-=20;
        if(speed<=0)
            speed=0;
    }
    if(key==GLUT_KEY_UP && in!=0 && !fight)
    {

        jump_c++;
        jump=true;
        jump1=true;
        run=false;


    }


    //place your codes for other keys here
}
void Run()
{
    if(in==0)
    {

        i++;
        if(i>2)
            i=0;
    }




}
void change1()
{
    if(!run)
    {
        r++;
        if(r>13)
            r=2;
    }
}
void Jump()
{


    if(jump1)
    {
        jy+=15;



        if(jy>=mh)
        {

            down=true;
            jump1=false;
        }

    }
    if(down)
    {
        if(GLUT_KEY_UP)
        {
            jump1=false;

        }
        jy-=20;
        if(jy<=100)
        {
            jy=50;
            jump=false;
            down=false;
            jump_c=0;

            run=false;
        }
    }

}
void doubleJump()
{

    if(djjump)
    {
        jy+=12;


        if(jy>=mh+100)
        {

            djdown=true;
            djjump=false;
        }


    }
    if(djdown)
    {
        if(GLUT_KEY_UP )
        {
            djjump=false;

        }

        jy-=15;
        dj++;
        if(dj>8)
            dj=7;
        if(jy<=100)
        {
            jy=100;
            jump=false;
            djdown=false;
            d_jump=false;
            jump_c=0;
            dj=0;
            run=false;

        }
    }

}
void doubleJumpMotion()
{
    if(djjump)
    {
        dj++;
        if(dj>8)
            dj=7;
    }
}
void bgPos()
{
    int m;
    for(m=0; m<slice; m++)
    {
        pos[m]-=width;
        if(pos[m]<0)
            pos[m]=(slice*width)-width;
    }

}
void position()
{
    int m,n;
    for(m=0,n=0; m<slice; m++)
    {
        pos[m]=n;
        n+=width;
    }


}
void fight1()
{
    if(fight && f2==1)
    {
        if(fc==0)
        {
            fc++;
            f1=0;
        }
        else
            ++f1;
    }
    if(f1>1 && f2==1 )
    {

        
        fight=false;
        fc=0;
		f1=2;
        if(in!=0)
            run=false;
    }
	

}
void fight2()
{
	if(fight && f2==2)
	{
		if(fc==0)
		{
			f1=2;
			fc++;
		}
		else
			f1++;
	}
	if(f1>5 && f2==2)
	{
		fight=false;
		fc=0;
		f2=0;
		f1=0;
		//if(in != 0)
			run=false;
	}
}
void fdash()
{
	if(dash)
	{
	   d++;
	   if(d==7)
		   speed=speed+100;
	}
	
	if(d>7 && dash)
	{
		dash=false;
		run=false;
		d=6;
	}
}
void fkick()
{
	if(kick)
	{

		
		
			kick=false;
			down=true;
			ki=0;

		
		
		run=false;
		


	}
}







//
int main()
{
    //place your own initialization codes here.
    position();
	iSetTimer(300,fkick);
    iSetTimer(100,fight1);
	 iSetTimer(300,fdash);
	iSetTimer(80,fight2);
    iSetTimer(0,bgPos);
    iSetTimer(90,doubleJumpMotion);
    iSetTimer(10,doubleJump);
    iSetTimer(10,Jump);

    iSetTimer(62,change1);

    iSetTimer(400,Run);


    iInitialize(1350, 510, "Spiderman");




    return 0;
}
