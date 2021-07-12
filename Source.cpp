#define STB_IMAGE_IMPLEMENTATION
#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <gl/stb_image.h>
#include<GL/texture.h>
#include<GL/GLTexture.h>
#include<GL/Model_3DS.h>
#include<gl/glut.h>
#include<math.h>
#include"ProjectModel.h"
#include<iostream>
#include <fstream>
#include <string>
//for texture
using namespace std;
// angle of rotation for the camera direction
float angle = 0.0;
float fraction = 0.2f;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f, x = 0.0f, z = -5.0f;
// XZ position of the camera
bool move = false;
bool movement =false;
double ttt=0.0;
double cheack= 50.4;
bool finals =false;
bool cimpact2= false;
bool cimpact3= false;
bool cimpact4= false;
bool cimpact5= false;
bool cimpact6= false;
bool cimpact7= false;
bool verse = false;
bool wall_impact = false;
bool wall_Moblique = false;
bool Bmove = false;
bool Bmove2 = false;
bool Cmove = false;
void ball2WallImpactFinal(int);

double pushForce =80.0;

double uk = 0.12;
double mass = 2.0;
double Bmass = 2.0;
double radius = 0.25;

double gravity = 10;
double kk =0.5;
double pp = 1;
double ss = radius *0.01;
double force = 4;

double a=1.0;
double Ba=1.0;
double fraction_f =0.0 ;
double Bfraction_f = 0.0;
double air_resistance = 1.0;
double Bair_resistance = 1.0;

double velocity =pushForce/2;
double aftervelocity =0.0;
double afterBvelocity =0.0;
double acculeration =0.0;
double Bacculeration =0.0;
double e =0.5;
double alpha = 0.0;

double teta = 20;
double ua =velocity;
double un =0.0;
double ut =0.0;

double usa =0.0;
double usn =0.0;
double ust =0.0;
double za =0.0;
double k1=0;
double k2=0;

void changeSize(int w, int h)
{

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, w/h, 0.1f, 1000.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void draw_right_street()
{
	//draw right street
	glBindTexture(GL_TEXTURE_2D, img1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(1.0f, 0.01f, -1.0f);
	glTexCoord2f(50, 0); glVertex3f(100.0f, 0.01f, -1.0f);
	glTexCoord2f(50, 1); glVertex3f(100.0f, 0.01f, 1.0f);
	glTexCoord2f(0, 1); glVertex3f(1.0f, 0.01f, 1.0f);
	glEnd();

}

void draw_forward_streer(){
	//draw main street
	glBindTexture(GL_TEXTURE_2D, img1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(-1.0f, 0.01f, -100.0f);
	glTexCoord2f(100, 0); glVertex3f(-1.0f, 0.01f, 100.0f);
	glTexCoord2f(100, 1); glVertex3f(1.0f, 0.01f, 100.0f);
	glTexCoord2f(0, 1); glVertex3f(1.0f, 0.01f, -100.0f);
	glEnd();
}

void draw_trees()
{

glPushMatrix();

glTranslated(-2,0,-100);
Tree();
for(int i=0;i<10;i++)
{glTranslated(0,0,10);
Tree();
}


glPopMatrix();

glTranslated(2,0,-100);
Tree();
for(int i=0;i<10;i++)
{glTranslated(0,0,10);
Tree();
}

glPopMatrix();
}

void draw_sid_walk()
{
	glBindTexture(GL_TEXTURE_2D, sideWalk);
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3f(-3.0f, 0.009f, -100.0f);
	glTexCoord2f(0,25);glVertex3f(-3.0f, 0.009f, 100.0f);
	glTexCoord2f(25,25);glVertex3f(3.0f, 0.009f, 100.0f);
	glTexCoord2f(25,0);glVertex3f(3.0f, 0.009f, -100.0f);
	glEnd();
}

void draw_right_sid_walk()
{
    glBindTexture(GL_TEXTURE_2D, sideWalk);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(1.0f, 0.008f, -3.0f);
	glTexCoord2f(0, 25); glVertex3f(100.0f, 0.008f, -3.0f);
	glTexCoord2f(25, 25); glVertex3f(100.0f, 0.008f, 3.0f);
	glTexCoord2f(25, 0); glVertex3f(1.0f, 0.008f, 3.0f);
	glEnd();

}

void draw_red_building()
{

	// left wall
glPushMatrix();

glTranslated(15,0,15);
glBindTexture(GL_TEXTURE_2D, rock);
	glBegin(GL_QUADS);
	glTexCoord2f(55, 55); glVertex3f(0, 0.0f, 40.0f);
	glTexCoord2f(55, 0); glVertex3f(0.0f, 3.0f, 40.0f);
	glTexCoord2f(55, 55); glVertex3f(0.0f, 3.0f, 61.0f);
	glTexCoord2f(55, 0); glVertex3f(0.0f, 0.0f, 61.0f);
	glEnd();
	
glPopMatrix();

// forward

glPushMatrix();

glTranslated(15,0,15);
glBindTexture(GL_TEXTURE_2D, rock);
	glBegin(GL_QUADS);
	glTexCoord2f(55, 55); glVertex3f(0, 0.0f, 40.0f);
	glTexCoord2f(55, 0); glVertex3f(0.0f, 3.0f, 40.0f);
	glTexCoord2f(55, 55); glVertex3f(39.0f, 3.0f, 40.0f);
	glTexCoord2f(55, 0); glVertex3f(39.0f, 0.0f, 40.0f);
	glEnd();
	
glPopMatrix();
// backward
glPushMatrix();

glTranslated(15,0,15);
glBindTexture(GL_TEXTURE_2D, rock);
	glBegin(GL_QUADS);
	glTexCoord2f(55, 55); glVertex3f(39, 0.0f, 40.0f);
	glTexCoord2f(55, 0); glVertex3f(39.0f, 3.0f, 40.0f);
	glTexCoord2f(55, 55); glVertex3f(39.0f, 3.0f, 61.0f);
	glTexCoord2f(55, 0); glVertex3f(39.0f, 0.0f, 61.0f);
	glEnd();
	
glPopMatrix();
//right
glPushMatrix();

glTranslated(15,0,15);
glBindTexture(GL_TEXTURE_2D, rock);
	glBegin(GL_QUADS);
	glTexCoord2f(55, 55); glVertex3f(0, 0.0f, 61.0f);
	glTexCoord2f(55, 0); glVertex3f(0.0f, 3.0f, 61.0f);
	glTexCoord2f(55, 55); glVertex3f(39.0f, 3.0f, 61.0f);
	glTexCoord2f(55, 0); glVertex3f(39.0f, 0.0f, 61.0f);
	glEnd();
	
glPopMatrix();
}

void draw_fac_ground(){

glPushMatrix();


glBindTexture(GL_TEXTURE_2D, ground);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0); glVertex3f(100.0f, 0.007f, -14.0f);
	glTexCoord2f(0, 100); glVertex3f(-14.0f, 0.007f, -14.0f);
	glTexCoord2f(100, 100); glVertex3f(-14.0f, 0.007f, 40.0f);
	glTexCoord2f(100, 0); glVertex3f(100.0f, 0.007f, 40.0f);
	glEnd();
	
glPopMatrix();
}

void draw_right_sid_tree()
{

glPushMatrix();
glTranslated(2,0,2);
Tree();
for(int i=0;i<10;i++)
{glTranslated(10,0,0);
Tree();
}


glPopMatrix();

glPushMatrix();
glTranslated(2,0,-2);
Tree();
for(int i=0;i<10;i++)
{glTranslated(10,0,0);
Tree();
}
glPopMatrix();
}

void draw_grass()
{
	glBindTexture(GL_TEXTURE_2D, grass);
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3f(-100.0f, 0.0f, -100.0f);
	glTexCoord2f(0,100);glVertex3f(-100.0f, 0.0f, 100.0f);
	glTexCoord2f(100,100);glVertex3f(100.0f, 0.0f, 100.0f);
	glTexCoord2f(100,0);glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();
}

double finalPower(double power , double friction){
double finalPower= 0.0;
finalPower = power - friction ;
return finalPower;
}

double acculrate(double finalPower , double ballMass){
	double acculrate =0.0;
	acculrate = finalPower / ballMass;
	return acculrate;
}

double speed(double acculrate , double oldSpeed){
	double speed=0;
	speed = acculrate + oldSpeed;
	return speed;

}

double callculate(double power , double friction ,double ballMass ,double oldSpeed)
{	
double f = finalPower(power,friction);
double a = acculrate(f,ballMass);
double s = speed(a,oldSpeed);

if(s>=0)
{
callculate(f,friction,ballMass,s);
}
else 
return 0;

}




void drawfunction(void) {

	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	//gluLookAt(x, 70.0f, z,x + lx, 1.0f, z + lz-Bvel,0.0f, 1.0f, 0.0f);
	if(!wall_oblique)
		gluLookAt(x, 1.0f, z+60-vel,x + lx, 1.0f, z + lz-vel,0.0f, 1.0f, 0.0f);
    if(wall_oblique)
		gluLookAt(x+xn, 1.0f, z+20+zt,x + lx, 1.0f, z + lz-vel,0.0f, 1.0f, 0.0f);
	//BALL
	if(!wall_impact)
	{
	glPushMatrix();
	//glTranslatef(0,0,0-s);
	BALL();
	glPopMatrix();
	}

	glPushMatrix();
	BALL2();
	glPopMatrix();


	glPushMatrix();
	draw_grass();
	glPopMatrix();

	draw_forward_streer();
	
	glPushMatrix();
	draw_sid_walk();

    glPopMatrix();


	glPushMatrix();
	draw_trees();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,-75);
    draw_right_street();
	draw_right_sid_walk();
	draw_right_sid_tree();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,-50);
    draw_right_street();
	draw_right_sid_walk();
	draw_right_sid_tree();
	glPopMatrix();


		glPushMatrix();
	glTranslated(0,0,-15);
    draw_right_street();
	draw_right_sid_walk();
	draw_right_sid_tree();
	draw_fac_ground();
	glPopMatrix();
	if(wall_impact && !finals)
	{
	// draw red
	glPushMatrix();
	glTranslated(-30,0,-85.7);
	draw_red_building();
	glPopMatrix();
	}

	if(wall_oblique)
	{
	// draw red
	glPushMatrix();
	glTranslated(-30,0,-65.7);
	draw_red_building();
	glPopMatrix();
	}

	if(finals)
	{
	glPushMatrix();
	glTranslated(-30,0,-125.7);
	draw_red_building();
	glPopMatrix();
	}
	glutSwapBuffers();
}

// «·ﬂ«„Ì—« 
void processSpecialKeys(int key, int xx, int yy) {
	switch (key) {
	case GLUT_KEY_LEFT:
		angle -= 0.1f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.1f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}


void processNormalKeys(unsigned char key,int x,int y)
{
	if(key=='i' || key=='I')
	{
		
		if(ball.pos.z==ball2.pos.z || ball.pos.z<=ball2.pos.z || ball2.pos.z>=ball.pos.z)
		{s-=1;
		 s+=1;
		 std::cout<<"1123\n";
		}

		else
		{
		s++;
		std::cout<<"112345\n";
		}

		
		std::cout<<"1\n"<<ball.pos.z;
		std::cout<<"2\n"<<ball2.pos.z;
		k+=45;

	}
}





void OWTimer(int)
{
	if(wall_oblique)
	{
	 ut = ua * sin(teta);
	 un = ua *cos(teta);
	 ust=ut;
	 xn = un;
	 zt = ut;
	 std::cout<<"ua = "<<ua << "\n";
	 std::cout<<"ut = "<<ut << "\n";
	 std::cout<<"un = "<<un  << "\n";
	 if(ua + Bacculeration > 0 )
	 {	
	 Bair_resistance =  0.5 *(( kk ) * (ss) *( pp ) * (ua *ua)) ;	 
	 fraction_f = uk * mass *gravity ;
	 std::cout<<"fraction_f = "<<fraction_f <<"\n";
	 Ba = (-fraction_f - Bair_resistance)/mass;
	 Bacculeration = Ba;
     std::cout<<"Bacculeration = "<<Bacculeration <<"\n";
	 if(ua + Bacculeration >= 0 )
	 {
	  ua = (ua + Bacculeration) ;
      std::cout<<"ua = "<<ua<< "\n";
	  k+=45;
	 }
	 else
	 {return;}
	 }
	 else
	 {cimpact5 =true;
	 return;}
	}
	
	glutTimerFunc(1,OWTimer,1);
}

void OWTimer2(int)
{ 
	if(cimpact5)
	{
		ust = ut;
		usn = -e*un;
		usa = sqrt(ust*ust + usn*usn);
		alpha = ust/ua;
		
		if(za < usa)
		{
		za += usa*0.1;
		zt +=za*sin(alpha);
		xn -=za*cos(alpha);
		k-=90;
		std::cout<<"u't = "<<zt << "\n";
		std::cout<<"u'n = "<<xn << "\n";
		std::cout<<"u' = "<<za << "\n";
		std::cout<<"alpha = "<<alpha << "\n";
		}
	}
	glutTimerFunc(1,OWTimer2,1);
}



void moveBall(int)
{ 
	if(!movement)
	{velocity =pushForce/2;
	movement = true;
	}
	if(finals && e==1)
	{
	e=0.9;
	}
	if(velocity>=59.4)
	{
		std::cout<<"veloctiy = "<<velocity << "\n";
		vel+=59.6;
		std::cout<<"distance = "<<vel << "\n";
		cimpact1 =true;
		return;
	}
	else{
		if(velocity + acculeration > 0 && ball2.pos.z > -9.6)
		{
	    air_resistance =  0.5 *(( kk ) * (ss) *( pp ) * (velocity *velocity)) ;	 
	    fraction_f = uk * mass *gravity ;
	    std::cout<<"fraction_f = "<<fraction_f <<"\n";
        a = (-fraction_f - air_resistance)/mass;
	    acculeration = a/10;
	    std::cout<<"air_resistance = "<<air_resistance <<"\n";
	    std::cout<<"acculeration = "<<acculeration <<"\n";
	    //vel = (vel + acculeration)*0.001;
	    std::cout<<"veloctiy = "<<velocity << "\n";
		if(velocity + acculeration > 0 && vel + velocity <= 59.6 )
	    velocity = (velocity + acculeration) ;
		
		if(vel + velocity*0.1 <= 59.6 )
		{vel+=velocity*0.1; k+=90;
		std::cout<<"vel = "<<vel << "\n";
		}
		else
		{
		vel =59.6;
		cimpact1 =true;
		return;
		}
		}
	
	}
	glutTimerFunc(1,moveBall,1);
}	

void impact(int){

	if(cimpact7)
	{
		velocity = afterBvelocity;
		aftervelocity = velocity + (e*(0 + velocity));
		afterBvelocity= velocity - afterBvelocity  ;
		return;
	}

	else{

	if(cimpact1 && !wall_impact){

	if(e!=1 && e!=0)
	{  
		if(mass==Bmass)
		{
	
		afterBvelocity = velocity + (e*(0 + velocity));
		afterBvelocity = afterBvelocity / 2;
		std::cout<<"afterBvelocity = "<<afterBvelocity << "\n";
		aftervelocity = velocity - afterBvelocity  ;
		std::cout<<"aftervelocity = "<<aftervelocity << "\n";
		cimpact2 = true;
		return;
		}
		else
		{
		aftervelocity = (mass*velocity-Bmass*e*velocity)/(Bmass+mass);
		std::cout<<"afterBvelocity = "<<afterBvelocity << "\n";
		afterBvelocity = e*velocity + aftervelocity;
	    std::cout<<"aftervelocity = "<<aftervelocity << "\n";
		cimpact2 = true;
		return;
		}
	} 

	else if(e==1){
			if(mass==Bmass)
		{
		aftervelocity =0;
		std::cout<<"aftervelocity = "<<aftervelocity << "\n";
		afterBvelocity = velocity;
		std::cout<<"afterBvelocity = "<<afterBvelocity << "\n";
		cimpact2 = true;
		return;
			}
			else{
				aftervelocity = (mass*velocity-Bmass*e*velocity)/(Bmass+mass);
		std::cout<<"aftervelocity = "<<aftervelocity << "\n";
		afterBvelocity = e*velocity + aftervelocity;
		std::cout<<"afterBvelocity = "<<afterBvelocity << "\n";
				cimpact2 = true;
				return;
			}
		}

	else if(e==0)
		{
		afterBvelocity = (velocity*mass)/(mass+Bmass);
		std::cout<<"afterBvelocity = "<<afterBvelocity << "\n";
		cimpact3=true;
		return;
		}
	
	}

	if(cimpact1 && wall_impact){
		aftervelocity = -e*velocity;
		std::cout<<"aftervelocity = "<<aftervelocity << "\n";
		cimpact4 =true;
		return;

	}
	}

	glutTimerFunc(1000,impact,1);
}

void ball2ballImpact(int){
	if(cimpact2)
	{
		if(aftervelocity <0 && !verse)
		{
			verse =true;
			aftervelocity = aftervelocity*-1;
		}
     	if(aftervelocity + acculeration > 0 )
		{
	    air_resistance =  0.5 *(( kk ) * (ss) *( pp ) * (aftervelocity *aftervelocity)) ;	 
	    fraction_f = uk * mass *gravity ;
	    std::cout<<"fraction_f = "<<fraction_f <<"\n";
        a = (-fraction_f - air_resistance)/mass;
	    acculeration = a/10;
	    std::cout<<"air_resistance = "<<air_resistance <<"\n";
	    std::cout<<"acculeration = "<<acculeration <<"\n";
	    //vel = (vel + acculeration)*0.001;
	    std::cout<<"afterBvelocity = "<<afterBvelocity << "\n";
		
	    if(aftervelocity + acculeration > 0 )
	    aftervelocity = (aftervelocity + acculeration) ;
		if(!verse)
		{vel += aftervelocity*0.1;
		std::cout<<"vel = "<<vel << "\n";
		k+=90;
		}
		if(verse)
		{vel -= aftervelocity*0.1;
		k-=90;
		}
		}
		if(afterBvelocity + acculeration > 0 )
		{
	    Bair_resistance =  0.5 *(( kk ) * (ss) *( pp ) * (afterBvelocity *afterBvelocity)) ;	 
	    Bfraction_f = uk * Bmass *gravity ;
	    std::cout<<"Bfraction_f = "<<Bfraction_f <<"\n";
        Ba = (-Bfraction_f - Bair_resistance)/mass;
	    Bacculeration = Ba/10;
	    std::cout<<"Bair_resistance = "<<Bair_resistance <<"\n";
	    std::cout<<"Bacculeration = "<<Bacculeration <<"\n";
	    //vel = (vel + acculeration)*0.001;
	    std::cout<<"Baftervelocity = "<<afterBvelocity << "\n";
	    if(afterBvelocity + Bacculeration > 0 )
	    afterBvelocity = (afterBvelocity + Bacculeration);
		Bvel += afterBvelocity*0.1;
		kkk+=90;
		}	
}
 glutTimerFunc(1,ball2ballImpact,1); 
}

void ball2ballImpact2(int){
	if(cimpact3)
	{
		if(afterBvelocity + acculeration > 0 )
		{
	    air_resistance =  0.5 *(( kk ) * (ss) *( pp ) * (afterBvelocity *afterBvelocity)) ;	 
	    fraction_f = uk * mass *gravity ;
	    std::cout<<"fraction_f = "<<fraction_f <<"\n";
        a = (-fraction_f - air_resistance)/mass;
	    acculeration = a/10;
	    std::cout<<"air_resistance = "<<air_resistance <<"\n";
	    std::cout<<"acculeration = "<<acculeration <<"\n";
	    //vel = (vel + acculeration)*0.001;
	    std::cout<<"afterBvelocity = "<<afterBvelocity << "\n";
	    if(afterBvelocity + acculeration > 0 )
			if((!finals)||(finals && Bvel + afterBvelocity*0.1 <= 38 ))
	    {afterBvelocity = (afterBvelocity + acculeration) ;
		vel += afterBvelocity*0.1;
		std::cout<<"vel = "<<vel << "\n";
		Bvel +=afterBvelocity*0.1;
		kkk+=90;
		k+=90;}
		if(finals && Bvel + afterBvelocity*0.1 >= 38 )
		{
			return;
		}
		}

      
	
}
 glutTimerFunc(1,ball2ballImpact2,1); 
}

void ball2WallImpact(int){
	if(cimpact4)
	{
		if(aftervelocity <0 && !verse)
		{
			verse =true;
			aftervelocity = aftervelocity*-1;
		}
		if(aftervelocity + acculeration > 0 )
		{
	    air_resistance =  0.5 *(( kk ) * (ss) *( pp ) * (aftervelocity *aftervelocity)) ;	 
	    fraction_f = uk * mass *gravity ;
	    std::cout<<"fraction_f = "<<fraction_f <<"\n";
        a = (-fraction_f - air_resistance)/mass;
	    acculeration = a/10;
	    std::cout<<"air_resistance = "<<air_resistance <<"\n";
	    std::cout<<"acculeration = "<<acculeration <<"\n";
	    //vel = (vel + acculeration)*0.001;
	    std::cout<<"aftervelocity = "<<aftervelocity << "\n";
	    if(aftervelocity + acculeration > 0 )
	    aftervelocity = (aftervelocity + acculeration) ;
		if(!verse)
		{vel += aftervelocity*0.1;
		std::cout<<"vel = "<<vel << "\n";
		k+=90;
		}
		if(verse)
		{vel -= aftervelocity*0.1;
		k-=90;
		}
		}	
}
 glutTimerFunc(1,ball2WallImpact,1); 
}

void ball2ballImpactFinal(int){
	if(cimpact2)
	{

		if(aftervelocity <0 && !verse)
		{
			verse =true;
			aftervelocity = aftervelocity*-1;
		}


		if(aftervelocity + acculeration > 0 )
		{
	    air_resistance =  0.5 *(( kk ) * (ss) *( pp ) * (aftervelocity *aftervelocity)) ;	 
	    fraction_f = uk * mass *gravity ;
	    std::cout<<"fraction_f = "<<fraction_f <<"\n";
        a = (-fraction_f - air_resistance)/mass;
	    acculeration = a/10;
	    std::cout<<"air_resistance = "<<air_resistance <<"\n";
	    std::cout<<"acculeration = "<<acculeration <<"\n";
	    //vel = (vel + acculeration)*0.001;
	    std::cout<<"afterBvelocity = "<<afterBvelocity << "\n";
		
	    if(aftervelocity + acculeration > 0 )
	    aftervelocity = (aftervelocity + acculeration) ;
		if(!verse)
		{vel += aftervelocity*0.1;
		std::cout<<"vel = "<<vel << "\n";
		k+=90;
		}
		if(verse)
		{vel -= aftervelocity*0.1;
		k-=90;
		}

		}
		if(afterBvelocity + acculeration > 0 && ball.pos.z > -48)
		{
	    Bair_resistance =  0.5 *(( kk ) * (ss) *( pp ) * (afterBvelocity *afterBvelocity)) ;	 
	    Bfraction_f = uk * Bmass *gravity ;
	    std::cout<<"Bfraction_f = "<<Bfraction_f <<"\n";
        Ba = (-Bfraction_f - Bair_resistance)/mass;
	    Bacculeration = Ba/10;
	    std::cout<<"Bair_resistance = "<<Bair_resistance <<"\n";
	    std::cout<<"Bacculeration = "<<Bacculeration <<"\n";
	    //vel = (vel + acculeration)*0.001;
	    std::cout<<"Baftervelocity = "<<afterBvelocity << "\n";
	    if(afterBvelocity + Bacculeration > 0 )
	    afterBvelocity = (afterBvelocity + Bacculeration);
		if(Bvel + afterBvelocity*0.1 <= 48)
		{Bvel += afterBvelocity*0.1;
		kkk+=90;}
		else{
			std::cout<<"wall impact = "<<"\n";
		afterBvelocity = -e*afterBvelocity;
		cimpact6 =  true;
		
		return;
		}
		}
		else{
       std::cout<<"wall impact = "<<"\n";
			afterBvelocity = -e*afterBvelocity;
		cimpact6 =  true;
		return;
		}

      
	
}
 glutTimerFunc(1,ball2ballImpactFinal,1); 
}

void ball2WallImpactFinal(int){
	if(cimpact6)
	{

		if(afterBvelocity <0 && !verse)
		{
			verse =true;
			afterBvelocity = afterBvelocity*-1;
		}


		if(afterBvelocity + acculeration > 0  )
		{
	    air_resistance =  0.5 *(( kk ) * (ss) *( pp ) * (afterBvelocity *afterBvelocity)) ;	 
	    fraction_f = uk * Bmass *gravity ;
	    std::cout<<"Bfraction_f = "<<fraction_f <<"\n";
        a = (-fraction_f - air_resistance)/Bmass;
	    acculeration = a/10;
	    std::cout<<"Bair_resistance = "<<air_resistance <<"\n";
	    std::cout<<"Bacculeration = "<<acculeration <<"\n";
	    //vel = (vel + acculeration)*0.001;
	    std::cout<<"afterBvelocity = "<<afterBvelocity << "\n";
		std::cout<<"Bvel = "<<Bvel << "\n";
	    if(afterBvelocity + acculeration > 0 )
	    afterBvelocity = (afterBvelocity + acculeration) ;
		if(!verse )
		{Bvel += afterBvelocity*0.1;
		std::cout<<"Bvel = "<<Bvel << "\n";
		kkk-=90;
		}
		if(verse && ball.pos.z < ball2.pos.z-1.9)
		{Bvel -= afterBvelocity*0.1;
		kkk-=90;
		}
		else{
			cimpact7 = true;
			glutTimerFunc(1000,impact,1);
			return;
		}
		}	
}
	glutTimerFunc(1,ball2WallImpactFinal,1);
}

void ball2ballImpact2Final(int){
	if(cimpact7)
	{
	    std::cout<<"cimpact7 = " <<"\n";
		if(aftervelocity <0 && !verse)
		{
			verse =true;
			aftervelocity = aftervelocity*-1;
		}

		if(aftervelocity + acculeration > 0 )
		{
	    air_resistance =  0.5 *(( kk ) * (ss) *( pp ) * (aftervelocity *aftervelocity)) ;	 
	    fraction_f = uk * mass *gravity ;
	    std::cout<<"fraction_f = "<<fraction_f <<"\n";
        a = (-fraction_f - air_resistance)/mass;
	    acculeration = a/10;
	    std::cout<<"air_resistance = "<<air_resistance <<"\n";
	    std::cout<<"acculeration = "<<acculeration <<"\n";
	    //vel = (vel + acculeration)*0.001;
	    std::cout<<"afterBvelocity = "<<afterBvelocity << "\n";
		
	    if(aftervelocity + acculeration > 0 )
	    aftervelocity = (aftervelocity + acculeration) ;
		if(!verse)
		{vel += aftervelocity*0.1;
		std::cout<<"vel = "<<vel << "\n";
		k+=90;
		}
		if(verse)
		{vel -= aftervelocity*0.1;
		k-=90;
		}

		}
		if(afterBvelocity + acculeration > 0 && ball.pos.z > -48)
		{
	    Bair_resistance =  0.5 *(( kk ) * (ss) *( pp ) * (afterBvelocity *afterBvelocity)) ;	 
	    Bfraction_f = uk * Bmass *gravity ;
	    std::cout<<"Bfraction_f = "<<Bfraction_f <<"\n";
        Ba = (-Bfraction_f - Bair_resistance)/mass;
	    Bacculeration = Ba/10;
	    std::cout<<"Bair_resistance = "<<Bair_resistance <<"\n";
	    std::cout<<"Bacculeration = "<<Bacculeration <<"\n";
	    //vel = (vel + acculeration)*0.001;
	    std::cout<<"Baftervelocity = "<<afterBvelocity << "\n";
	    if(afterBvelocity + Bacculeration > 0 )
	    afterBvelocity = (afterBvelocity + Bacculeration);
		if(Bvel + afterBvelocity*0.1 <= 48)
		{Bvel += afterBvelocity*0.1;
		kkk+=90;}
		else{
		std::cout<<"ball_impact = "<<"\n";
		afterBvelocity = -e*afterBvelocity;
		cimpact6 =  true;
		return;
		}
		}
		else{
       std::cout<<"ball_impact = "<<"\n";
			afterBvelocity = -e*afterBvelocity;
		cimpact6 =  true;
		return;
		}

      
	
}
 glutTimerFunc(1,ball2ballImpact2Final,1); 
}

int main(int argc, char** argv) {

	// init GLUT and create window
	int yes =0;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(30, 30);
	glutInitWindowSize(700, 700);
	glutCreateWindow("Ball");

	std::ifstream fi1("C:\\Users\\User\\Desktop\\v0\\1.txt");
	fi1>>pushForce;
	std::ifstream fi2("C:\\Users\\User\\Desktop\\v0\\2.txt");
	fi2>>mass;

	std::ifstream fi3("C:\\Users\\User\\Desktop\\v0\\3.txt");
	fi3>>radius;
	std::ifstream fi4("C:\\Users\\User\\Desktop\\v0\\4.txt");
	fi4>>pp;
	std::ifstream fi5("C:\\Users\\User\\Desktop\\v0\\5.txt");
	fi5>>kk;
	std::ifstream fi6("C:\\Users\\User\\Desktop\\v0\\6.txt");
	fi6>>uk;
	std::ifstream fi7("C:\\Users\\User\\Desktop\\v0\\7.txt");
	fi7>>e;

	std::ifstream fi8("C:\\Users\\User\\Desktop\\v0\\8.txt");
	fi8>>Bmass;

	std::ifstream fi9("C:\\Users\\User\\Desktop\\v0\\9.txt");
	fi9>>yes;

	if(yes ==2)
	{
		wall_impact = true;
	}
	if(yes == 3)
	{
		wall_oblique = true;
	}
	if(yes == 4)
	{
		finals = true;
	}

	// register callbacks
	glutDisplayFunc(drawfunction);
	glutReshapeFunc(changeSize);
	glutIdleFunc(drawfunction);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	fraction = fr(uk,mass,gravity);
	if(!wall_oblique && !finals)
	{glutTimerFunc(1000,moveBall,1);
	glutTimerFunc(1000,impact,1);
	glutTimerFunc(1000,ball2ballImpact,1);
	glutTimerFunc(1000,ball2ballImpact2,1);
	glutTimerFunc(1000,ball2WallImpact,1);}
	if(wall_oblique && !finals)
	{
	glutTimerFunc(1,OWTimer,1);
	glutTimerFunc(1,OWTimer2,1);
	}
	if(finals)
	{
	glutTimerFunc(1000,moveBall,1);
	glutTimerFunc(1000,impact,1);
	glutTimerFunc(1,ball2ballImpactFinal,1);
	glutTimerFunc(1,ball2ballImpact2,1);
	glutTimerFunc(1,ball2WallImpactFinal,1);
	glutTimerFunc(1,ball2ballImpact2Final,1);
	}

	
	init();
	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}