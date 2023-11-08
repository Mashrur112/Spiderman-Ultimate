
#include<iostream>
#include <fstream>
#include < algorithm>
#include<string.h>
#include <cstdlib>

using namespace std;

# include "iGraphics.h"
int mposx,  mposy,i=0,speed=10,r=0,jy=50,j=0,mh=240,dj=0,f1=0,fc=0,f2=0,s_life=200,p_f=0;
int pos[100];
int slice=70,width=1350/slice;
#define scw 1350;
#define sch 510;
#define sspd 14;
#define gspd 14;

int h=1,u=0,cond_e=0,sh=0,w=0,m1=1,b2=0,sc=0,over=0,play=1,rec1=0,obs=0,at=0,e_g_max=1150,e_g=e_g_max,e_s=0,ab1=((rand()%10)+(rand()%10)+1330),ac1=rand(),ac2=rand(),ac3=rand(),ac4=rand(),ac5=rand(),ab2=((rand()%10)+(rand()%10)+1330),ab3=((rand()%10)+(rand()%10)+1330),ab4=((rand()%10)+(rand()%10)+1330),ab5=((rand()%10)+(rand()%10)+1330);

bool run=true,jump=false,down=false,jump1=false,d_jump=false,djjump=false,djdown=false,fight=false,dash=false,kick=false;
int run1=0,jump_c=0,in=0,d=6,w3=0,shg,e_i=0,idx=0,dg=0,s_d=0;

double obj_x,e_max=250,e_life=e_max,s_max=1400,f_c=0,e_dead=1,in1=0,b3=false,music=0,rec_g=109,e_con=0,rec_e=109;


char sp [3][20]= {"char\\s1.bmp","char\\s2.bmp","char\\s3.bmp"};
char rn[][20]= {"char\\r1.bmp","char\\r2.bmp","char\\r3.bmp","char\\r4.bmp","char\\r5.bmp","char\\r6.bmp","char\\r7.bmp","char\\r8.bmp","char\\r9.bmp","char\\r10.bmp","char\\r11.bmp","char\\r12.bmp","char\\r13.bmp","char\\r14.bmp"};
char djmp[][20]= {"char\\j2.bmp","char\\j3.bmp","char\\j4.bmp","char\\j5.bmp","char\\j6.bmp","char\\j10.bmp","char\\j11.bmp","char\\j1.bmp"};
char jmp[][20]= {"char\\j1.bmp"};
char bg[][30]= {"bg\\b01.bmp",	"bg\\b02.bmp",	"bg\\b03.bmp",	"bg\\b04.bmp",	"bg\\b05.bmp",	"bg\\b06.bmp",	"bg\\b07.bmp",	"bg\\b08.bmp",	"bg\\b09.bmp",	"bg\\b10.bmp",	"bg\\b11.bmp",	"bg\\b12.bmp",	"bg\\b13.bmp",	"bg\\b14.bmp",	"bg\\b15.bmp",	"bg\\b16.bmp",	"bg\\b17.bmp",	"bg\\b18.bmp",	"bg\\b19.bmp",	"bg\\b20.bmp",	"bg\\b21.bmp",	"bg\\b22.bmp",	"bg\\b23.bmp",	"bg\\b24.bmp",	"bg\\b25.bmp",	"bg\\b26.bmp",	"bg\\b27.bmp",	"bg\\b28.bmp",	"bg\\b29.bmp",	"bg\\b30.bmp",	"bg\\b31.bmp",	"bg\\b32.bmp",	"bg\\b33.bmp",	"bg\\b34.bmp",	"bg\\b35.bmp",	"bg\\b36.bmp",	"bg\\b37.bmp",	"bg\\b38.bmp",	"bg\\b39.bmp",	"bg\\b40.bmp",	"bg\\b41.bmp",	"bg\\b42.bmp",	"bg\\b43.bmp",	"bg\\b44.bmp",	"bg\\b45.bmp",	"bg\\b46.bmp",	"bg\\b47.bmp",	"bg\\b48.bmp",	"bg\\b49.bmp",	"bg\\b50.bmp",	"bg\\b51.bmp",	"bg\\b52.bmp",	"bg\\b53.bmp",	"bg\\b54.bmp",	"bg\\b55.bmp",	"bg\\b56.bmp",	"bg\\b57.bmp",	"bg\\b58.bmp",	"bg\\b59.bmp",	"bg\\b60.bmp",	"bg\\b61.bmp",	"bg\\b62.bmp",	"bg\\b63.bmp",	"bg\\b64.bmp",	"bg\\b65.bmp",	"bg\\b66.bmp",	"bg\\b67.bmp",	"bg\\b68.bmp",	"bg\\b69.bmp",	"bg\\b70.bmp",	"bg\\b01.bmp",	"bg\\b02.bmp",	"bg\\b03.bmp",	"bg\\b04.bmp",	"bg\\b05.bmp",	"bg\\b06.bmp",	"bg\\b07.bmp",	"bg\\b08.bmp",	"bg\\b09.bmp",	"bg\\b10.bmp",	"bg\\b11.bmp",	"bg\\b12.bmp",	"bg\\b13.bmp",	"bg\\b14.bmp",	"bg\\b15.bmp",	"bg\\b16.bmp",	"bg\\b17.bmp",	"bg\\b18.bmp",	"bg\\b19.bmp",	"bg\\b20.bmp",	"bg\\b21.bmp",	"bg\\b22.bmp",	"bg\\b23.bmp",	"bg\\b24.bmp",	"bg\\b25.bmp",	"bg\\b26.bmp",	"bg\\b27.bmp",	"bg\\b28.bmp",	"bg\\b29.bmp",	"bg\\b30.bmp",	"bg\\b31.bmp",	"bg\\b32.bmp",	"bg\\b33.bmp",	"bg\\b34.bmp",	"bg\\b35.bmp",	"bg\\b36.bmp","bg\\b37.bmp",	"bg\\b38.bmp",	"bg\\b39.bmp",	"bg\\b40.bmp",	"bg\\b41.bmp",	"bg\\b42.bmp",	"bg\\b43.bmp",	"bg\\b44.bmp",	"bg\\b45.bmp",	"bg\\b46.bmp",	"bg\\b47.bmp",	"bg\\b48.bmp",	"bg\\b49.bmp",	"bg\\b50.bmp",	"bg\\b51.bmp",	"bg\\b52.bmp",	"bg\\b53.bmp",	"bg\\b54.bmp",	"bg\\b55.bmp",	"bg\\b56.bmp",	"bg\\b57.bmp",	"bg\\b58.bmp",	"bg\\b59.bmp",	"bg\\b60.bmp",	"bg\\b61.bmp",	"bg\\b62.bmp",	"bg\\b63.bmp",	"bg\\b64.bmp",	"bg\\b65.bmp",	"bg\\b66.bmp",	"bg\\b67.bmp",	"bg\\b68.bmp",	"bg\\b69.bmp",	"bg\\b70.bmp"};
char f[][20]= {"char\\f1.bmp","char\\f2.bmp","char\\f3.bmp","char\\f4.bmp","char\\f5.bmp","char\\f6.bmp","char\\f7.bmp","char\\f8.bmp"};
char k[][20]= {"char\\k1.bmp"};
char m[][20]= {"menu\\m1.bmp","menu\\b1.bmp","menu\\b2.bmp","menu\\b3.bmp","menu\\b4.bmp","menu\\b5.bmp"};
char web[][20]={"web\\w1.bmp","web\\w2.bmp","web\\sh.bmp" };
char e_id[][20]={	"electro\\b02.bmp",	"electro\\b03.bmp",	"electro\\b04.bmp",	"electro\\b05.bmp",	"electro\\b06.bmp",	"electro\\b07.bmp",	"electro\\b08.bmp",	"electro\\b09.bmp",	"electro\\b10.bmp",	"electro\\b11.bmp",	"electro\\b12.bmp",	"electro\\b13.bmp",	"electro\\b14.bmp",	"electro\\b15.bmp"};
char user[][20]={"name\\n2.bmp"};
char ob[][20]={"obs\\b01.bmp","obs\\b02.bmp","obs\\b03.bmp","obs\\b04.bmp","obs\\b05.bmp","obs\\b06.bmp"};
char e_a[][20]={"electro\\a1.bmp","electro\\a2.bmp","electro\\a3.bmp","electro\\a4.bmp","electro\\a5.bmp","electro\\a6.bmp","electro\\a11.bmp","electro\\a12.bmp","electro\\a13.bmp","electro\\a14.bmp","electro\\a15.bmp","electro\\a10.bmp","electro\\a9.bmp","electro\\a8.bmp","electro\\a16.bmp",};
char dmg[][20]={"dmg\\b01.bmp","dmg\\b02.bmp","dmg\\b03.bmp","dmg\\b04.bmp","dmg\\b05.bmp","dmg\\b06.bmp","dmg\\b07.bmp",} ;
char s_dd[][20]={"dd\\d1.bmp","dd\\d2.bmp","dd\\d3.bmp","dd\\d4.bmp","dd\\d5.bmp","dd\\d6.bmp","dd\\d7.bmp"};
char health[][20]={"health\\b01.bmp","health\\b02.bmp"};
char n[10];
 char s[1000];
 FILE *rec;


/*
	function iDraw() is called again and again by the system.
*/

 	void record()
{
	rec=fopen("data.txt","a");
	//for(int idx1=0;idx1<=idx;idx1++)
		fputs(n,rec);
		fprintf(rec," ",1,rec);
		fputs(s,rec);
	fprintf(rec,"\n",1,rec);
		idx=0;
		fclose(rec);
		over=1;

		char x[100];
		char y[100];
		
		int z[100];
		string l[100];
		int v[100];
		int idx[100];
		int ix=0;
		int k=0;
		rec=fopen("data.txt","r");

		while(fscanf(rec,"%s %s",x,y)!=EOF)
		{
				l[k]=x;
				//cout << l[0] << endl;
		      z[k]=atoi(y);	
			  v[k]=atoi(y);
			  k++;
		}

		k--;
		fclose(rec);
		int a;
		//sort(z,z+k);
		for (int p = 0;p<=k; ++p){
   for (int o = p + 1; o <= k; ++o){
      if (z[p] < z[o]){
         a = z[p];
         z[p] = z[o];
         z[o] = a;
      }
   }
}
		rec=fopen("data.txt","w");
		
			
		for(int o=0;o<=k;o++)
		{
			for(int p=0;p<=k;p++)
			{
				if(z[o]==v[p])
				{
					
					idx[ix]=p;
					ix++;
					break;
				}
			}
		}
		ix--;
		
		char u[4];
		for(int p=0;p<=ix;p++)
		{
			
			sprintf(s,"%d",z[p]);
			//fprintf(rec,"%s %s",l[idx[p]],s);
			/*int o=0;
			while(o<=3)
			{

				u[o]=l[idx[p]][o];
				o++;
			}*/
			cout << l[idx[p]]<<endl;
			//ofstream out("data.txt");
			//out << l[idx[p]] << endl;
			
			
			
			//fputs(u,rec);
			fprintf(rec,"%s",l[idx[p]].c_str());
			fprintf(rec," ",1);
			fputs(s,rec);
			fprintf(rec,"\n",1);
			
		}
		fclose(rec);
		
		
}
	


void iDraw()
{
    //place your drawing codes here
	
	
    iClear();
	
	
	if(over)
	{
		
		
		iShowBMP(0,0,s_dd[6]);

		iShowBMP2(speed,80,s_dd[s_d],16777215);
		iShowBMP2(35,400,health[0],16777215);
		iText(390,250,"GAME OVER",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(1080,400,"Press 'P' to save Score",GLUT_BITMAP_TIMES_ROMAN_24);
		
		iShowBMP2(700,70,ob[5],16777215);
		if(s_d>=6)
		
		over=0;
		play=0;
		
		
		

	}
	else if(play){
		
			

    if(m1)
    {
		
		
        iShowBMP(0,0,m[0]);
        iShowBMP2(150,300,m[1],0);

        iShowBMP2(97,150,m[2],0);
		iShowBMP2(97,40,m[4],0);
    }
    else if(b2)
    {
        iShowBMP(0,0,m[3]);
		
		rec=fopen("data.txt","r");
		char t[100],r[100];
		int h_y=450;
		while(fscanf(rec,"%s %s",t,r)!=EOF)
		{
			iSetColor(255,255,255);
			iText(50,h_y,t,GLUT_BITMAP_TIMES_ROMAN_24);
			iText(200,h_y,r,GLUT_BITMAP_TIMES_ROMAN_24);
			h_y-=50;
			
		}
		fclose(rec);
		
		
				
    }
	else if(b3)
	{
		iShowBMP(0,0,m[5]);
	}
	else if(u)
	{
		
		iShowBMP(0,0,user[0]);
		iSetColor(255,255,255);
		iFilledRectangle(425,253,505,37);
		iSetColor(0,0,255);
		
		iText(550,262,n,GLUT_BITMAP_TIMES_ROMAN_24);
		
		
		
			
		
	
		
	}
		

   else
    {
        for(int m=0; m<slice; m++)
        {

            iShowBMP(pos[m],0,bg[m]);//1315


        }


		iShowBMP2(35,400,health[0],16777215);
		iSetColor(77,222,18);
		if(rec_g<=0)
		{
			rec_g=0;
			iFilledRectangle(83,421,rec_g,14);
		}
		iFilledRectangle(83,421,rec_g,14);
		
		if(e_con )
		{
			iSetColor(77,222,18);

			iShowBMP2(1100,400,health[0],16777215);
			iFilledRectangle(1150,419,(rec_e),14);
			if(e_life<=0)
			{
				iShowBMP2(1309,400,health[0],16777215);
				rec_e=109;
				e_con=0;
			}

		}
			

        if(in==0)
        {
            int n=0;

            for(int m=0; m<slice; m++)
            {
                iShowBMP(n,0,bg[m]);
                n+=width;
            }
            iShowBMP2(0,80,sp[i],16777215);
			
			iShowBMP2(35,400,health[0],16777215);
			iSetColor(77,222,18);
			iFilledRectangle(83,421,109,14);
			

        }
		


		if(!u && !m1 && in)
		{
			iSetColor(255,255,255);
			iText(580,431,"SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);
			iText(672,431,s,GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
        if(kick)
        {
            iShowBMP2(speed,jy,k[0],16777215);
            //ki++;

        }
		if(w)
		{
			
			iShowBMP2(speed,80,web[w3],16777215);
			run=true;
			shg=speed;
			

		}
		if(sh )
		{
			
			iShowBMP2(shg+130,160,web[2],16777215);
		}
		if( cond_e && e_dead)
		{
			iShowBMP2(1200,80,e_id[e_i],16777215);
			e_con=1;
			e_life=e_max;
		  //cout << e_i;
		}
		if(!cond_e && e_life){
			
			if(shg>=890 && shg<=1120)
			{
				e_life-=20;
				rec_e-=9;
				s_max=1090;
				if(e_life<=0)
				{
					e_life=0;
					e_dead=1;
					
					in1=0;
				}
				//cout << e_life;
				//iShowBMP2(1130,160,web[2],16777215);
				
			}
			if(p_f && speed>=1130 && speed <= 1250 )
			{
				e_life-=30;
				rec_e-=15;
				if(e_life<=0)
				{
					e_life=0;
					e_dead=1;
					
					in1=0;
				}
				p_f=false;
				//cout<<e_life;
			}

		}
		
		if(sc>=2)
		{
			
			    
				iShowBMP2(ab1,70,ob[ac1%5],16777215);
				
				iShowBMP2(ab2,70,ob[ac2%5],16777215);
				

				
				if((speed-20)<=ab1 && (speed+20)>=ab1 && jy<=100)
				{
					
					if(dg<=6)
						run=true;
						iShowBMP2(speed,80,dmg[dg],16777215);
					s_life-=10;
					rec_g-=6;
					if(s_life<=0)
						over=1;
					//cout <<s_life<<endl;
				}
				if((speed-10)<=ab2 && (speed+10)>=ab2 && jy<=100)
				{
					
					if(dg<=6)
						run=true;
						iShowBMP2(speed,80,dmg[dg],16777215);
					s_life-=10;
					rec_g-=6;
					if(s_life<=0)
						over=1;
					//cout <<s_life<<endl;
				}
				if(jy<=140 && (e_g<=speed+50 && e_g>= speed-50) && e_life)
		{
			if(dg<=6)
						run=true;
						iShowBMP2(speed,80,dmg[dg],16777215);
			s_life-=20;
			rec_g-=11;
			if(s_life<=0)
				over=1;
		}
		}
		
		if(!cond_e && e_life && in1 )
		{
			iShowBMP2(1200,80,e_a[at],16777215);
		}
		if(e_s && e_life)
		{
			iShowBMP2(e_g,140,e_a[14],16777215);
		}
		
        if(in!=0 && dash)
        {

            iShowBMP2(speed,80,f[d],16777215);
			run=true;

        }

        if(fight && in!=0 && f2==1)
        {
			run=true;
            if(f1>=0)

                iShowBMP2(speed,80,f[f1],16777215);
			




        }
        if(fight && in!=0 && f2==2)
        {
			run=true;
            iShowBMP2(speed,80,f[f1],16777215);
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



            iShowBMP2(speed,80,rn[r],16777215);
		}
		}
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
		
        if(mx>=155 && mx <=391 && my >= 305 && my <= 406 && !b2 && !b3)
        {
			
			
            m1=false;
            b2=false;
            in =0;
            u=true;
            speed=10;
			h=false;
        }
        else if(mx >=124 && mx <= 430 && my >=183 && my <= 259 && h && !b3)
        {

            b2=true;
            m1=false;
			rec1=true;
			
        }
		else if(mx>=145 && mx<=398 && my>=82 && my<=154 && h  )
		{
			b3=true;
			m1=false;
			rec1=true;
			b2=false;
		}
		//cout<<mx<<" "<<my<<" ";
		if(u && mx >=471 && mx <= 648 && my>=184 && my <= 219 && idx>0)
		{
			//record();
			u=false;
			PlaySound("bgm\\bgm2.wav",NULL,SND_LOOP| SND_ASYNC);
			
		}
		cout << mx <<" "<< my<<" ";
		


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
	if(key=='w' && in && !jump && !sh)
	{
		w=true;
			run=true;
	}
    if(key=='f' && !jump)
    {

        fight=true;
        run=true;
        if(f2>2)
            f2=0;
        else
            f2++;
		if(sc>=5 && e_life)
			p_f=true;




    }

    if(key == 'd' && !jump && in)
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
    if(key == 'q' )
	{
        m1=true;
		u=false;
		h=true;
		b2=false;
		b3=false;
		
	}
	
	if(u && key!=' ' && key!='\r')
	{
		b2=false;
		 n [idx]=key;
		 if(key=='\b')
		 {
			 if(idx==0)
			 {
				 idx=0;
			 }
			 else
			 {
				 idx--;
			 }
		 }
		 else
		idx++;
	}
	if(u && key=='\r' && idx>0)
	{
		
		u=false;
		PlaySound("bgm\\bgm2.wav",NULL,SND_LOOP| SND_ASYNC);
	}
	if(key=='p' && !u )
	{
		record();
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

    if(key == GLUT_KEY_RIGHT && !over)
    {
        run=false;
        speed+=20;
        if(speed>=1240)
            speed=1240;
        in++;

    }
    if(key == GLUT_KEY_LEFT && !over)
    {
        
        speed-=20;
        if(speed<=0)
            speed=0;

    }
    if(key==GLUT_KEY_UP && in!=0 && !fight && !over)
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
        jy+=30;



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
        jy-=33;
        if(jy<=100)
        {
            jy=80;
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
        jy+=30;


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

        jy-=33;
        dj++;
        if(dj>8)
            dj=7;
        if(jy<=80)
        {
            jy=80;
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
void webs()
{
	if(w)
	w3++;
	
	if(w3>=2)
	{
		w3=0;
		w=false;
		run=false;
		sh=true;
	}
	 
	
}
void shoot()
{
	if (sh){

	shg+=150;
	
	}
	if(shg>s_max)
	{
		sh=false;
		shg=speed;
	}
}
void e_idl()
{
	if(cond_e)
	e_i++;
	if(e_i>=14)
	{
		
		cond_e=false;
		e_dead=0;
		e_i=0;
		in1=1;
	}
	
}
void obstackle()
{
	if(sc>=2)
	ab1-=19;
	ab2-=19;
	
	if(ab1<-10)
	{
		//srand(time(0));
		int x2=rand();
		int x3=rand();
		ab1=(x3%100)+(x2%1000)+1332;
		
		ac1=rand();
		
	}
	if(ab2<-10)
	{
		
		int y2=rand();
		int y3=rand();
		int y4=rand();
		ab2=(y4%100)+(y3%100)+(y2%100)+1332;
	
		ac2=rand();
	}
	
}
void e_attack()
{
	if(!cond_e && in1 )
		at++;
	if(at>=7)
		e_s=true;
	if(at>=13)
	{
		
		at=0;
	}
}
void e_shoot()
{
	if(e_s)
	e_g-=75;
	if(e_g<=0 )
	{
		e_g=e_g_max;
		e_s=false;
	}
}
void score()
{
	if(!u && !m1 && in)
	{
		sc++;
		if((sc%30)==0 && e_dead )
		{
			
			cond_e=true;
		}
		sprintf(s,"%d",sc);
	}
}
void s_dead()
{
	if(over)
		s_d++;
	if(s_d>=6)
		s_d=5;
}
void damage()
{
	
		
	
	dg++;
	
	if(dg>=6 && sc>=2)
	{
		dg=0;
		run=false;
	}
}
void obstackle1()
{
	ab1=(rand()%10)+1332;
		ac1=rand();
	
}

 void sound()
{
	if(music)
	{
	
	music=0;
	}
}
void fkick()
{
    if(kick)
    {



        kick=false;	
        down=true;
        



        run=false;



    }
}







//
int main()
{
    //place your own initialization codes here.
	
    position();
	PlaySound("bgm\\bgm.wav",NULL,SND_LOOP| SND_ASYNC);
	
    iSetTimer(10,sound);
	iSetTimer(100,shoot); 
	iSetTimer(90,e_shoot);
    iSetTimer(300,fkick);
	iSetTimer(0,obstackle);
	iSetTimer(150,webs);
    iSetTimer(100,fight1);
	iSetTimer(0,damage);
    iSetTimer(300,fdash);
	iSetTimer(300,s_dead);
    iSetTimer(50,fight2);
    iSetTimer(0,bgPos);
    iSetTimer(80,e_idl);

	iSetTimer(100,e_attack);
	
    iSetTimer(0,doubleJump);
	iSetTimer(90,doubleJumpMotion);
	
	//iSetTimer(1000,obstackle1);
    iSetTimer(0,Jump);

    iSetTimer(62,change1);
	
    iSetTimer(400,Run);
	iSetTimer(1000,score);


    iInitialize(1330, 510, "Spiderman");
	




    return 0;
}
