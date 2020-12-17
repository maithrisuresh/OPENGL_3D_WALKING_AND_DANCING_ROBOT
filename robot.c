
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define TORSO_HEIGHT 5.0
#define TORSO_RADIUS 1.3

#define HEAD_HEIGHT 1.7
#define HEAD_RADIUS 1.3

#define UPPER_ARM_HEIGHT 3.0
#define LOWER_ARM_HEIGHT 2.0

#define UPPER_ARM_RADIUS  0.65
#define LOWER_ARM_RADIUS  0.5

#define LOWER_LEG_HEIGHT 3.0
#define UPPER_LEG_HEIGHT 3.0

#define UPPER_LEG_RADIUS  0.65
#define LOWER_LEG_RADIUS  0.5

#define SHOULDER_RADIUS 0.85
#define JOINT_RADIUS 0.85



#define SPHERE
#define COLOR
#define LIGHT
#define TORSO
#define HIP
#define SHOULDER
#define UPPER_ARM
#define LOWER_ARM
#define ROCKET_POD
#define UPPER_LEG
#define LOWER_LEG
#define NO_NORM
#define ANIMATION
#define DRAW_MECH
#define DRAW_ENVIRO
#define MOVE_LIGHT
/* end of compilation conditions */

/* start various header files needed */
#include<string.h>
#include <stdlib.h>
#include <math.h>
#define GLUT
#define GLUT_KEY
#define GLUT_SPEC
#include <GL/glut.h>
#include <time.h>

float firstwindow,secondwindow;
/* end of header files */
#define TEXTID      19
void DrawTextXY(double,double,double,double,char *);
/* start of display list definitions */
#define SOLID_MECH_TORSO       	1
#define SOLID_MECH_HIP          2
#define SOLID_MECH_SHOULDER     3
#define SOLID_MECH_UPPER_ARM    4
#define SOLID_MECH_FOREARM	5
#define SOLID_MECH_UPPER_LEG   	6
#define SOLID_MECH_FOOT        	7
#define SOLID_MECH_ROCKET      	8
#define SOLID_MECH_VULCAN	9
#define SOLID_ENVIRO		10
/* end of display list definitions */
/* start of motion  variables */
#ifndef M_PI
#define M_PI 3.14
#endif

int light_flag = 0;

typedef float point[3];
GLfloat seconds;
GLuint texture[4]; //the array for our texture

static GLfloat theta[11] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,
            180.0,0.0,180.0,0.0}; /* initial joint angles */

GLfloat theta_min[11];
GLfloat theta_max[11]; 
GLfloat theta_freq[11];
GLfloat knees_y, knees_z;
GLfloat mat_x, mat_y, mat_z;


        
static GLint angle = 3;
int flag_dance = 0;

GLUquadricObj *t, *gl, *h, *lua, *lla, *rua, *rla, *lll, *rll, *rul, *lul;
GLUquadricObj *rs, *ls, *rleg, *lleg, *elbow; 
GLUquadricObj *disk;

double size=1.0;
int i;

GLUquadricObj *qobj;

char leg = 0;

int shoulder1 = 0, shoulder2 = 0, shoulder3 = 0, shoulder4 = 0, lat1 = 20, lat2 = 20,
  elbow1 = 0, elbow2 = 0, pivot = 0, tilt = 10, ankle1 = 0, ankle2 = 0, heel1 = 0,
  heel2 = 0, hip11 = 0, hip12 = 10, hip21 = 0, hip22 = 10, fire = 0, solid_part = 0,
  anim = 0, turn = 0, turn1 = 0, lightturn = 0, lightturn1 = 0;

float elevation = 0.0, distance = 0.0, frame = 3.0
 /* foot1v[] = {} foot2v[] = {} */ ;

/* end of motion variables */

/* start of material definitions */
#ifdef LIGHT        // to change the color of robot box
GLfloat mat_specular[] = {0.0, 0.0, 1.0, 1.0};
GLfloat mat_ambient[] ={0.0, 0.0, 1.0, 1.0};
GLfloat mat_diffuse[] ={0.0, 0.0, 1.0, 1.0};
GLfloat mat_shininess[] ={128.0 * 0.4};

GLfloat mat_specular2[] ={0.508273, 0.508273, 0.508373};
GLfloat mat_ambient2[] ={0.19225, 0.19225, 0.19225};
GLfloat mat_diffuse2[] ={0.50754, 0.50754, 0.50754};
GLfloat mat_shininess2[] ={128.0 * 0.6};
//to change the wall colorfffffffff
GLfloat mat_specular3[] = {1.0, 1.0, 0.0};
GLfloat mat_ambient3[] ={1.0, 1.0, 0.0};
GLfloat mat_diffuse3[] ={1.0, 1.0, 0.0};
GLfloat mat_shininess3[] ={0.0 * 0.0};
//to change the plateform color
GLfloat mat_specular4[] = {0.633, 0.727811, 0.633};
GLfloat mat_ambient4[] = {0.0215, 0.1745, 0.0215};
GLfloat mat_diffuse4[] = {0.07568, 0.61424, 0.07568};
GLfloat mat_shininess4[] = {128 * 0.6};

GLfloat mat_specular5[] =
{0.60, 0.60, 0.50};
GLfloat mat_ambient5[] =
{0.0, 0.0, 0.0};
GLfloat mat_diffuse5[] =
{0.5, 0.5, 0.0};
GLfloat mat_shininess5[] =
{128.0 * 0.25};
#endif
/* end of material definitions */

/* start of the body motion functions */





GLfloat mat_specularf[]={0.0, 0.0, 1.0, 1.0};
GLfloat mat_diffusef[]={0.0, 0.0, 1.0, 1.0};
GLfloat mat_ambientf[]={0.0, 0.0, 1.0, 1.0};
GLfloat mat_shininessf={100.0};













void FreeTexture( GLuint texture )
{
  glDeleteTextures( 1, &texture );
}

void square (void) {
     glPushMatrix();
     
    glBindTexture( GL_TEXTURE_2D, texture[0] ); //bind our texture to our shape
   
    glBegin (GL_QUADS);
          glTexCoord2f(0.0, 0.0); glVertex3f(-5, -5, -010.0);
          glTexCoord2f(0.0, 1.0); glVertex3f(-5, 5, -10.0);
          glTexCoord2f(1.0, 1.0); glVertex3f(5, 5, -10.0);
          glTexCoord2f(1.0, 0.0); glVertex3f(5, -5, -10.0);
    glEnd();

     glBindTexture( GL_TEXTURE_2D, texture[2] ); //bind our texture to our shape
     
    glBegin (GL_QUADS);
        glTexCoord2f(0.0, 0.0); glVertex3f(-5.0,-5.0, -10.0);
          glTexCoord2f(0.0, 1.0); glVertex3f(-5, 5, -10.0);
          glTexCoord2f(1.0, 1.0); glVertex3f(-10, 10, 0.0);
          glTexCoord2f(1.0, 0.0); glVertex3f(-10, -10, 0.0);
    glEnd();
    
     glBindTexture( GL_TEXTURE_2D, texture[3] ); //bind our texture to our shape
     glBegin (GL_QUADS);
        glTexCoord2f(0.0, 0.0); glVertex3f(5.0,-5.0, -10.0);
          glTexCoord2f(0.0, 1.0); glVertex3f(5, 5, -10.0);
          glTexCoord2f(1.0, 1.0); glVertex3f(10, 10, 0.0);
          glTexCoord2f(1.0, 0.0); glVertex3f(10, -10, 0.0);
    glEnd();
    
     glBindTexture( GL_TEXTURE_2D, texture[1] ); //bind our texture to our shape
     glBegin (GL_QUADS);
         glTexCoord2f(0.0, 0.0); glVertex3f(-5.0,-5.0, -10.0);
          glTexCoord2f(0.0, 1.0); glVertex3f(5, -5, -10.0);
          glTexCoord2f(1.0, 1.0); glVertex3f(10, -10, 0.0);
          glTexCoord2f(1.0, 0.0); glVertex3f(-10, -10, 0.0);  
         
    glEnd();
    
    glPopMatrix();
}

void torso()
{
   glPushMatrix();
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   gluCylinder(t,TORSO_RADIUS, TORSO_RADIUS*1.5, TORSO_HEIGHT,10,10);	//(*obj, base, top, height, slices, stacks)
   glPopMatrix();
}

void head()
{
   glPushMatrix();
   glTranslatef(0.0, 0.5*HEAD_HEIGHT,0.0);
   glScalef(HEAD_RADIUS, HEAD_HEIGHT, HEAD_RADIUS);
   gluSphere(h,1.0,10,10);
   glPopMatrix();
}

void glass_bot()
{
   glPushMatrix();
   glTranslatef(0.0, 0.5*HEAD_HEIGHT,0.075);
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   
   gluCylinder(gl,HEAD_RADIUS, HEAD_RADIUS, HEAD_HEIGHT/2,10,10);
   glPopMatrix();
}

void shoulder_joints()
{
	glPushMatrix();
   	glScalef(SHOULDER_RADIUS, SHOULDER_RADIUS, SHOULDER_RADIUS);
   	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void elbow_joints()
{
	glPushMatrix();
   	glScalef(SHOULDER_RADIUS/1.2, SHOULDER_RADIUS/1.2, SHOULDER_RADIUS/1.2);
   	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void palms()
{
	glPushMatrix();
   	glScalef(SHOULDER_RADIUS/1.3, SHOULDER_RADIUS/1.3, SHOULDER_RADIUS/1.3);
   	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void leg_joints()
{
	glPushMatrix();
   	glScalef(JOINT_RADIUS, JOINT_RADIUS, JOINT_RADIUS);
   	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void knee_joints()
{
	glPushMatrix();
   	glScalef(JOINT_RADIUS, JOINT_RADIUS, JOINT_RADIUS);
   	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void torso_disk()
{
	glPushMatrix();
   	glScalef(1.5*TORSO_RADIUS, 0.1, 1.5*TORSO_RADIUS);
   	gluSphere(h,1.0,10,10);
	glPopMatrix();
}

void left_upper_arm()
{
   glPushMatrix();
   gluCylinder(lua,UPPER_ARM_RADIUS*1.2, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT,10,10);
   glPopMatrix();
}

void left_lower_arm()
{
   glPushMatrix();
   gluCylinder(lla,LOWER_ARM_RADIUS*1.1, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT,10,10);
   glPopMatrix();
}

void right_upper_arm()
{
   glPushMatrix();
   
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   gluCylinder(rua,UPPER_ARM_RADIUS*1.2, UPPER_ARM_RADIUS, UPPER_ARM_HEIGHT,10,10);
   glPopMatrix();
}

void right_lower_arm()
{
   glPushMatrix();
   glRotatef(-90.0, 1.0, 0.0, 0.0);
   gluCylinder(rla,LOWER_ARM_RADIUS*1.1, LOWER_ARM_RADIUS, LOWER_ARM_HEIGHT,10,10);
   glPopMatrix();
}

void left_upper_leg()
{
   glColor3f(1.0,0.0,1.0);
   glPushMatrix();
   glRotatef(-120.0, 1.0, 0.0, 0.0);
   gluCylinder(lul,UPPER_LEG_RADIUS*1.2, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT,10,10);
   glPopMatrix();
}

void left_lower_leg()
{
   glColor3f(1.0,0.0,0.0);
   glPushMatrix();
   glTranslatef(0.0,-0.25,-UPPER_LEG_HEIGHT/2);
   glRotatef(-70.0, 1.0, 0.0, 0.0);
   gluCylinder(lll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS*1.5, LOWER_LEG_HEIGHT,10,10);
   glPopMatrix();
}

void right_upper_leg()
{
   glColor3f(1.0f,0.0f,1.0f);
   glPushMatrix();
   glRotatef(-120.0, 1.0, 0.0, 0.0);
   gluCylinder(rul,UPPER_LEG_RADIUS*1.2, UPPER_LEG_RADIUS, UPPER_LEG_HEIGHT,10,10);
   glPopMatrix();
}

void right_lower_leg()
{
   glColor3f(1.0,0.0,0.0);
   glPushMatrix();
   glTranslatef(0.0,-0.25,-UPPER_LEG_HEIGHT/2);
   glRotatef(-70.0, 1.0, 0.0, 0.0);
   gluCylinder(rll,LOWER_LEG_RADIUS, LOWER_LEG_RADIUS*1.5, LOWER_LEG_HEIGHT,10,10);
   glPopMatrix();
}

void displayfinal(void)
{
     GLfloat rot_x=0.0, rot_y=0.0;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(0.0, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specularf);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambientf);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffusef);
    glMaterialf(GL_FRONT, GL_SHININESS, mat_shininessf);
        
    glEnable( GL_TEXTURE_2D );
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    
    gluLookAt(0.0,0.0,8.0,0.0,0.0,0.0,0.0,1.0,0.0);
    glTranslatef(0.0, 0.0, 10);
    square();
     
    glDisable(GL_TEXTURE_2D);
     
    glTranslatef(0.0, -3.0, 0.0); 
    glRotatef(theta[0], 0.0, 1.0, 0.0);
    torso();
    
    glPushMatrix();
    glTranslatef(0.0, TORSO_HEIGHT+0.5*HEAD_HEIGHT, 0.0);
    glRotatef(theta[1], 1.0, 0.0, 0.0);
    glRotatef(theta[2], 0.0, 1.0, 0.0);
    glTranslatef(0.0, -0.5*HEAD_HEIGHT, 0.0);
    head();
    glass_bot();
    glPopMatrix();
    
    //right arm
    if(flag_dance==1)
    {
                  rot_x=1.0;
                  rot_y=0.0;              
    }
    if(flag_dance==2)
    {
                  rot_x=0.0;
                  rot_y=1.0;              
    }
    glPushMatrix();
    glTranslatef(-(TORSO_RADIUS+UPPER_ARM_RADIUS), 0.9*TORSO_HEIGHT, 0.0);
    glRotatef(theta[3], rot_x, rot_y, 0.0);
    left_upper_arm();
    
    //glTranslatef(0.0, UPPER_ARM_HEIGHT, 0.0);
    glTranslatef(0.0, 0.0, UPPER_ARM_HEIGHT);
    elbow_joints();
    glRotatef(theta[4], 1.0, 0.0, 0.0);
    left_lower_arm();
    
    glTranslatef(0.0, 0.0,LOWER_ARM_HEIGHT);
    palms(); //left hand
    
    glPopMatrix();
    
    //torso_disk
    glPushMatrix();
    glTranslatef(0.0, TORSO_HEIGHT, 0.0);
    torso_disk();
    glPopMatrix();
    
    //shoulder_joints
    glPushMatrix();
    glTranslatef(1.5*TORSO_RADIUS, 0.9*TORSO_HEIGHT, 0.0);
    shoulder_joints();
    
    glTranslatef(-3.0*TORSO_RADIUS, 0.0, 0.0);
    shoulder_joints();
    glPopMatrix();
    
    //leg_joints
    glPushMatrix();
    glTranslatef(1.1*TORSO_RADIUS, 0.0, 0.0);
    leg_joints();
    
    glTranslatef(-2.2*TORSO_RADIUS, 0.0, 0.0);
    shoulder_joints();
    glPopMatrix();
    
    //left arm
    glPushMatrix();
    glTranslatef(TORSO_RADIUS+UPPER_ARM_RADIUS, 0.9*TORSO_HEIGHT, 0.0);
    glRotatef(theta[5], 1.0, 0.0, 0.0);
    right_upper_arm();

    glTranslatef(0.0, UPPER_ARM_HEIGHT, 0.0);
    elbow_joints();
    glRotatef(theta[6], 1.0, 0.0, 0.0);
    glColor3f(1.0,1.0,1.0);
    right_lower_arm();
    
    glTranslatef(0.0, LOWER_ARM_HEIGHT, 0.0);
    palms(); //left hand
    glPopMatrix();

    glPushMatrix(); 
  	glTranslatef(-(TORSO_RADIUS), 0.1*UPPER_LEG_HEIGHT, 0.0);
    glRotatef(theta[7], 1.0, 0.0, 0.0);
    left_upper_leg();
    
    glTranslatef(0.0, UPPER_LEG_HEIGHT, -1.5);
    knee_joints();
    glTranslatef(0.0, 0.0, 1.5); 
     
    glRotatef(theta[8], 1.0, 0.0, 0.0);
    left_lower_leg();
    glPopMatrix();

    glPushMatrix();
    //glTranslatef(TORSO_RADIUS+UPPER_LEG_RADIUS, 0.1*UPPER_LEG_HEIGHT, 0.0);
    glTranslatef((TORSO_RADIUS), 0.1*UPPER_LEG_HEIGHT, 0.0);
    glRotatef(theta[9], 1.0, 0.0, 0.0);
    right_upper_leg();

    glTranslatef(0.0, UPPER_LEG_HEIGHT, -1.5);
     knee_joints();
     glTranslatef(0.0, 0.0, 1.5); 
     
    glRotatef(theta[10], 1.0, 0.0, 0.0);
    right_lower_leg();
    glPopMatrix();
	
    glFlush();
    glutSwapBuffers();
   // glDisable(GL_TEXTURE_2D);
}

void menu(int id)
{
   if(id <11 ) 
   		angle=id;
   if(id ==11 ) 
   		exit(0);
}

float getAngle(float freq, float min, float max, float t){
  return (max - min)*sin(freq*M_PI*t) + 0.5*(min + max);
}

static void idle(void){
  GLfloat seconds = glutGet(GLUT_ELAPSED_TIME)/1000.0;
  if(seconds >= 3.6) flag_dance =1;
  if(seconds >= 13.6) flag_dance =2;
  if(seconds >= 18.6) flag_dance =1;
  if(seconds>=3.6 && seconds<=9.6 || seconds > 13.6)
  {
  theta[3] = getAngle(theta_freq[3], theta_min[3],theta_max[3], seconds);
  theta[5] = getAngle(theta_freq[5], theta_min[5],theta_max[5], seconds);

  theta[7] = getAngle(theta_freq[7], theta_min[7],theta_max[7], seconds);  
  theta[9] = getAngle(theta_freq[9], theta_min[9],theta_max[9], seconds);
  }
 theta[1] = getAngle(theta_freq[1], theta_min[1],theta_max[1], seconds);
  
theta[4] = getAngle(theta_freq[4], theta_min[4],theta_max[4], seconds);
  theta[6] = getAngle(theta_freq[6], theta_min[6],theta_max[6], seconds);
  theta[0] = getAngle(theta_freq[0], theta_min[0],theta_max[0], seconds);
 
  srand(time(NULL));
  mat_x = rand()%2;
  mat_y = rand()%2;
  mat_z = rand()%2;
 
  light_flag = rand()%4;
  if(light_flag <1)
  {
        glEnable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
        glDisable(GL_LIGHT3);       
  }
  
  if(light_flag <2 && light_flag >=1)
  {
        glEnable(GL_LIGHT1);
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT2);
        glDisable(GL_LIGHT3);       
  }
  
  if(light_flag <3 && light_flag >=2)
  {
        glEnable(GL_LIGHT2);
        glDisable(GL_LIGHT1);
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT3);       
  }
  
  if(light_flag <4 && light_flag >=3)
  {
        glEnable(GL_LIGHT3);
        glDisable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
        glDisable(GL_LIGHT0);       
  }
  
  mat_diffuse[0] = mat_x;
  mat_diffuse[1] = mat_y;
  mat_diffuse[2] = mat_z;
  
  //printf("\ntheta_max[3] = %f ; theta_max[5] = %f\n",theta_max[3],theta_max[5]);
  //printf("seconds = %f; theta_3 = %f ; theta_5 = %f\n",seconds, theta[3],theta[5]);
  
  glutPostRedisplay();
}

void myReshapefinal(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    if (w <= h)
        glOrtho(-10.0, 10.0, -10.0 * (GLfloat) h / (GLfloat) w,
            10.0 * (GLfloat) h / (GLfloat) w, -10.0, 10.0);
    else
        glOrtho(-10.0 * (GLfloat) w / (GLfloat) h,
            10.0 * (GLfloat) w / (GLfloat) h, -10.0, 10.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}

void myinitfinal()
{
        //light 1
        GLfloat light_ambient1[]={0.0, 0.0, 0.0, 1.0};
        GLfloat light_diffuse1[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_specular1[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_position1[]={10.0, 10.0, 10.0, 0.0};

        glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
        glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient1);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
        glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular1);
        
        //light 2
        GLfloat light_ambient2[]={0.0, 0.0, 0.0, 1.0};
        GLfloat light_diffuse2[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_specular2[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_position2[]={10.0, 0.0, 10.0, 0.0};

        glLightfv(GL_LIGHT1, GL_POSITION, light_position2);
        glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient2);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse2);
        glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular2);

        //light 3
        GLfloat light_ambient3[]={0.0, 0.0, 0.0, 1.0};
        GLfloat light_diffuse3[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_specular3[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_position3[]={0.0, -10.0, 10.0, 0.0};

        glLightfv(GL_LIGHT2, GL_POSITION, light_position3);
        glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient3);
        glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse3);
        glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular3);
        
        //light 4
        GLfloat light_ambient4[]={0.0, 0.0, 0.0, 1.0};
        GLfloat light_diffuse4[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_specular4[]={1.0, 1.0, 1.0, 1.0};
        GLfloat light_position4[]={-10.0, 10.0, 10.0, 0.0};

        glLightfv(GL_LIGHT3, GL_POSITION, light_position4);
        glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient4);
        glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse4);
        glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular4);
        
        
        glShadeModel(GL_SMOOTH);
        glEnable(GL_LIGHTING);

        glDepthFunc(GL_LEQUAL);
        glEnable(GL_DEPTH_TEST);

        //glClearColor(0.75, 0.75, 0.75, 1.0);
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glColor3f(0.0, 0.0, 0.0);

/*	Setting the min, max and frequency for body parts*/
		for(i=0;i<11;i++)
		{
			theta_min[i] = 0.0;
			theta_max[i] = 0.0;
			theta_freq[i] = 0.0;
		}
	
        theta_freq[1] = 3.0;
        theta_max[1] = 15.0; theta_min[1] = -5.0;
        
		theta_freq[3] = 3.0; theta_freq[5] = 3.0;
 	    theta_max[3] = -90.0; theta_max[5] = 90.0;
 	    
 	    theta_freq[4] = 2.0; theta_freq[6] = 2.0;
 	    theta_max[4] = -35.0; theta_max[6] = -35.0;
 	    theta_min[4] = -10.0; theta_min[6] = -10.0;	    
	
		theta_freq[7] = 3.0; theta_freq[9] = 3.0;
		
		theta_max[7] = 200.0; theta_max[9] = 160.0;
		theta_min[7] = 160.0; theta_min[9] = 200.0;
		
		theta_min[0] = -30; theta_freq[0] = 0.5;
		theta_max[0] = 30;
		
/* allocate quadrics with filled drawing style */

        h=gluNewQuadric();
        gluQuadricDrawStyle(h, GLU_FILL);
        gluQuadricNormals(h, GLU_SMOOTH);
        
        t=gluNewQuadric();
        gluQuadricDrawStyle(t, GLU_FILL);
        gluQuadricNormals(t, GLU_SMOOTH);
        
        gl=gluNewQuadric();
        gluQuadricDrawStyle(gl, GLU_FILL);
        gluQuadricNormals(gl, GLU_SMOOTH);
        
        lua=gluNewQuadric();
        gluQuadricDrawStyle(lua, GLU_FILL);
        gluQuadricNormals(lua, GLU_SMOOTH);
        
        lla=gluNewQuadric();
        gluQuadricDrawStyle(lla, GLU_FILL);
        gluQuadricNormals(lla, GLU_SMOOTH);
        
        rua=gluNewQuadric();
        gluQuadricDrawStyle(rua, GLU_FILL);
        gluQuadricNormals(rua, GLU_SMOOTH);
        
        rla=gluNewQuadric();
        gluQuadricDrawStyle(rla, GLU_FILL);
        gluQuadricNormals(rla, GLU_SMOOTH);
        
        lul=gluNewQuadric();
        gluQuadricDrawStyle(lul, GLU_FILL);
        gluQuadricNormals(lul, GLU_SMOOTH);
        
        lll=gluNewQuadric();
        gluQuadricDrawStyle(lll, GLU_FILL);
        gluQuadricNormals(lll, GLU_SMOOTH);
        
        rul=gluNewQuadric();
        gluQuadricDrawStyle(rul, GLU_FILL);
        gluQuadricNormals(rul, GLU_SMOOTH);
        
        rll=gluNewQuadric();
        gluQuadricDrawStyle(rll, GLU_FILL);
        gluQuadricNormals(rll, GLU_SMOOTH);
}


void Heel1Add(void)
{
  heel1 = (heel1 + 3) % 360;
}
void Heel1Subtract(void)
{
  heel1 = (heel1 - 3) % 360;
}
void Heel2Add(void)
{
  heel2 = (heel2 + 3) % 360;
}
void Heel2Subtract(void)
{
  heel2 = (heel2 - 3) % 360;
}
void Ankle1Add(void)
{
  ankle1 = (ankle1 + 3) % 360;
}
void Ankle1Subtract(void)
{
  ankle1 = (ankle1 - 3) % 360;
}
void Ankle2Add(void)
{
  ankle2 = (ankle2 + 3) % 360;
}
void Ankle2Subtract(void)
{
  ankle2 = (ankle2 - 3) % 360;
}
void RotateAdd(void)
{
  pivot = (pivot + 3) % 360;
}
void RotateSubtract(void)
{
  pivot = (pivot - 10) % 360;
}
void MechTiltSubtract(void)
{
  tilt = (tilt - 10) % 360;
}
void MechTiltAdd(void)
{
  tilt = (tilt + 10) % 360;
}
void elbow1Add(void)
{
  elbow1 = (elbow1 + 2) % 360;
}
void elbow1Subtract(void)
{
  elbow1 = (elbow1 - 2) % 360;
}
void elbow2Add(void)
{
  elbow2 = (elbow2 + 2) % 360;
}
void elbow2Subtract(void)
{
  elbow2 = (elbow2 - 2) % 360;
}
void shoulder1Add(void)
{
  shoulder1 = (shoulder1 + 5) % 360;
}
void shoulder1Subtract(void)
{
  shoulder1 = (shoulder1 - 5) % 360;
}
void shoulder2Add(void)
{
  shoulder2 = (shoulder2 + 5) % 360;
}
void shoulder2Subtract(void)
{
  shoulder2 = (shoulder2 - 5) % 360;
}
void shoulder3Add(void)
{
  shoulder3 = (shoulder3 + 5) % 360;
}
void shoulder3Subtract(void)
{
  shoulder3 = (shoulder3 - 5) % 360;
}
void shoulder4Add(void)
{
  shoulder4 = (shoulder4 + 5) % 360;
}
void shoulder4Subtract(void)
{
  shoulder4 = (shoulder4 - 5) % 360;
}
void lat1Raise(void)
{
  lat1 = (lat1 + 5) % 360;
}
void lat1Lower(void)
{
  lat1 = (lat1 - 5) % 360;
}
void lat2Raise(void)
{
  lat2 = (lat2 + 5) % 360;
}
void lat2Lower(void)
{
  lat2 = (lat2 - 5) % 360;
}
void FireCannon(void)
{
  fire = (fire + 20) % 360;
}
void RaiseLeg1Forward(void)
{
  hip11 = (hip11 + 3) % 360;
}
void LowerLeg1Backwards(void)
{
  hip11 = (hip11 - 3) % 360;
}
void RaiseLeg1Outwards(void)
{
  hip12 = (hip12 + 10) % 360;
}
void LowerLeg1Inwards(void)
{
  hip12 = (hip12 - 10) % 360;
}
void RaiseLeg2Forward(void)
{
  hip21 = (hip21 + 3) % 360;
}
void LowerLeg2Backwards(void)
{
  hip21 = (hip21 - 3) % 360;
}
void RaiseLeg2Outwards(void)
{
  hip22 = (hip22 + 10) % 360;
}
void LowerLeg2Inwards(void)
{
  hip22 = (hip22 - 10) % 360;
}
/* end of body motion functions */

/* start of light source position functions */
void TurnRight(void)
{
  turn = (turn - 10) % 360;
}

void TurnLeft(void)
{
  turn = (turn + 10) % 360;
}

void TurnForwards(void)
{
  turn1 = (turn1 - 10) % 360;
}

void TurnBackwards(void)
{
  turn1 = (turn1 + 10) % 360;
}
void LightTurnRight(void)
{
  lightturn = (lightturn + 10) % 360;
}

void LightTurnLeft(void)
{
  lightturn = (lightturn - 10) % 360;
}

void LightForwards(void)
{
  lightturn1 = (lightturn1 + 10) % 360;
}

void LightBackwards(void)
{
  lightturn1 = (lightturn1 - 10) % 360;
}

/* end of light source position functions */
void DrawTextXY(double x,double y,double z,double scale,char *s)
{
   int i;

   glPushMatrix();
   glTranslatef(x,y,z);
   glScalef(scale,scale,scale);
   for (i=0;i<strlen(s);i++)
  glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
 glPopMatrix();
}
/* start of geometric shape functions */
void Box(float width, float height, float depth, char solid)
{
  char i, j = 0;
  float x = width / 2.0, y = height / 2.0, z = depth / 2.0;

  for (i = 0; i < 4; i++) {
    glRotatef(90.0, 0.0, 0.0, 1.0);
    if (j) {
      if (!solid)
        glBegin(GL_LINE_LOOP);
      else
        glBegin(GL_QUADS);
      glNormal3f(-1.0, 0.0, 0.0);
      glVertex3f(-x, y, z);
      glVertex3f(-x, -y, z);
      glVertex3f(-x, -y, -z);
      glVertex3f(-x, y, -z);
      glEnd();
      if (solid) {
        glBegin(GL_TRIANGLES);
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, z);
        glVertex3f(-x, y, z);
        glVertex3f(-x, -y, z);
        glNormal3f(0.0, 0.0, -1.0);
        glVertex3f(0.0, 0.0, -z);
        glVertex3f(-x, -y, -z);
        glVertex3f(-x, y, -z);
        glEnd();
      }
      j = 0;
    } else {
      if (!solid)
        glBegin(GL_LINE_LOOP);
      else
        glBegin(GL_QUADS);
      glNormal3f(-1.0, 0.0, 0.0);
      glVertex3f(-y, x, z);
      glVertex3f(-y, -x, z);
      glVertex3f(-y, -x, -z);
      glVertex3f(-y, x, -z);
      glEnd();
      if (solid) {
        glBegin(GL_TRIANGLES);
        glNormal3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, z);
        glVertex3f(-y, x, z);
        glVertex3f(-y, -x, z);
        glNormal3f(0.0, 0.0, -1.0);
        glVertex3f(0.0, 0.0, -z);
        glVertex3f(-y, -x, -z);
        glVertex3f(-y, x, -z);
        glEnd();
      }
      j = 1;
    }
  }
}

void Octagon(float side, float height, char solid)
{
  char j;
  float x = sin(0.7) * side, y = side / 2.0, z = height / 2.0, c;

  c = x + y;
  for (j = 0; j < 8; j++) {
    glTranslatef(-c, 0.0, 0.0);
    if (!solid)
      glBegin(GL_LINE_LOOP);
    else
      glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(0.0, -y, z);
    glVertex3f(0.0, y, z);
    glVertex3f(0.0, y, -z);
    glVertex3f(0.0, -y, -z);
    glEnd();
    glTranslatef(c, 0.0, 0.0);
    if (solid) {
      glBegin(GL_TRIANGLES);
      glNormal3f(0.0, 0.0, 1.0);
      glVertex3f(0.0, 0.0, z);
      glVertex3f(-c, -y, z);
      glVertex3f(-c, y, z);
      glNormal3f(0.0, 0.0, -1.0);
      glVertex3f(0.0, 0.0, -z);
      glVertex3f(-c, y, -z);
      glVertex3f(-c, -y, -z);
      glEnd();
    }
    glRotatef(45.0, 0.0, 0.0, 1.0);
  }
}

/* end of geometric shape functions */
#ifdef NORM
void Normalize(float v[3])
{
  GLfloat d = sqrt(v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);

  if (d == 0.0) {
    printf("zero length vector");
    return;
  }
  v[1] /= d;
  v[2] /= d;
  v[3] /= d;
}

void NormXprod(float v1[3], float v2[3], float v[3], float out[3])
{
  GLint i, j;
  GLfloat length;

  out[0] = v1[1] * v2[2] - v1[2] * v2[1];
  out[1] = v1[2] * v2[0] - v1[0] * v2[2];
  out[2] = v1[0] * v2[1] - v1[1] * v2[0];
  Normalize(out);
}

#endif

void SetMaterial(GLfloat spec[], GLfloat amb[], GLfloat diff[], GLfloat shin[])
{

  glMaterialfv(GL_FRONT, GL_SPECULAR, spec);
  glMaterialfv(GL_FRONT, GL_SHININESS, shin);
  glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
  glMaterialfv(GL_FRONT, GL_DIFFUSE, diff);
}

void MechTorso(char solid)
{
  glNewList(SOLID_MECH_TORSO, GL_COMPILE);
#ifdef LIGHT
  SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
  glColor3f(1.0, 0.0, 0.0);//torso red color
  Box(1.0, 1.0, 3.0, solid);
  glTranslatef(0.75, 0.0, 0.0);
#ifdef LIGHT
  SetMaterial(mat_specular2, mat_ambient2, mat_diffuse2, mat_shininess2);
#endif
  glColor3f(0.0, 0.0, 1.0);//torso blue color
  Box(0.5, 0.6, 2.0, solid);
  glTranslatef(-1.5, 0.0, 0.0);
  Box(0.5, 0.6, 2.0, solid);
  glTranslatef(0.75, 0.0, 0.0);
  glEndList();
}

void MechHip(char solid)
{
  int i;

  glNewList(SOLID_MECH_HIP, GL_COMPILE);
#ifdef LIGHT
  SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
  glColor3f(0.0, 1.0, 0.0);//hip lines form green
  Octagon(0.7, 0.5, solid);
#ifdef SPHERE
  for (i = 0; i < 2; i++) {
    if (i)
      glScalef(-1.0, 1.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
#ifdef LIGHT
    SetMaterial(mat_specular2, mat_ambient2, mat_diffuse2, mat_shininess2);
#endif
    glColor3f(0.0, 1.0, 0.0);//hip line form green
    if (!solid)
      gluQuadricDrawStyle(qobj, GLU_LINE);
    gluSphere(qobj, 0.2, 16, 16);
    glTranslatef(-1.0, 0.0, 0.0);
  }
  glScalef(-1.0, 1.0, 1.0);
#endif
  glEndList();
}

void Shoulder(char solid)
{
  glNewList(SOLID_MECH_SHOULDER, GL_COMPILE);
#ifdef LIGHT
  SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
  glColor3f(0.0, 1.0, 0.0);//sholder color green
  Box(1.0, 0.5, 0.5, solid);
  glTranslatef(0.9, 0.0, 0.0);
#ifdef LIGHT
  SetMaterial(mat_specular2, mat_ambient2, mat_diffuse2, mat_shininess2);
#endif
  glColor3f(0.0, 1.0, 0.0);// sholder color green
#ifdef SPHERE
  if (!solid)
    gluQuadricDrawStyle(qobj, GLU_LINE);
  gluSphere(qobj, 0.6, 16, 16);
#endif
  glTranslatef(-0.9, 0.0, 0.0);
  glEndList();
}

void UpperArm(char solid)
{
  int i;

  glNewList(SOLID_MECH_UPPER_ARM, GL_COMPILE);
#ifdef LIGHT
  SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
  glColor3f(1.0, 0.0, 0.0);//arm red
  Box(1.0, 2.0, 1.0, solid);
  glTranslatef(0.0, -0.95, 0.0);
  glRotatef(90.0, 1.0, 0.0, 0.0);
#ifdef LIGHT
  SetMaterial(mat_specular2, mat_ambient2, mat_diffuse2, mat_shininess2);
#endif
  glColor3f(1.0, 0.0, 0.0);//arm red
  if (!solid)
    gluQuadricDrawStyle(qobj, GLU_LINE);
  gluCylinder(qobj, 0.4, 0.4, 1.5, 16, 10);
#ifdef LIGHT
  SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
  glColor3f(0.0, 1.0, 0.0);// arm joint green
  glRotatef(-90.0, 1.0, 0.0, 0.0);
  glTranslatef(-0.4, -1.85, 0.0);
  glRotatef(90.0, 0.0, 1.0, 0.0);
  for (i = 0; i < 2; i++) {
    if (!solid)
      gluQuadricDrawStyle(qobj, GLU_LINE);
    if (i)
      gluCylinder(qobj, 0.5, 0.5, 0.8, 16, 10);
    else
      gluCylinder(qobj, 0.2, 0.2, 0.8, 16, 10);
  }
  for (i = 0; i < 2; i++) {
    if (i)
      glScalef(-1.0, 1.0, 1.0);
    if (!solid)
      gluQuadricDrawStyle(qobj, GLU_LINE);
    if (i)
      glTranslatef(0.0, 0.0, 0.8);
    gluDisk(qobj, 0.2, 0.5, 16, 10);
    if (i)
      glTranslatef(0.0, 0.0, -0.8);
  }
  glScalef(-1.0, 1.0, 1.0);
  glRotatef(-90.0, 0.0, 1.0, 0.0);
  glTranslatef(0.4, 2.9, 0.0);
  glEndList();
}

void VulcanGun(char solid)
{
  int i;

  glNewList(SOLID_MECH_VULCAN, GL_COMPILE);

#ifdef LIGHT
  SetMaterial(mat_specular2, mat_ambient2, mat_diffuse2, mat_shininess2);
#endif
  glColor3f(0.0, 0.0, 1.0);//gun color

  if (!solid) {
    gluQuadricDrawStyle(qobj, GLU_LINE);
  }
  gluCylinder(qobj, 0.5, 0.5, 0.5, 16, 10);

  glTranslatef(0.0, 0.0, 0.5);
 gluDisk(qobj, 0.0, 0.5, 16, 10);


  for (i = 0; i < 5; i++) {

    glRotatef(72.0, 0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.3, 0.0);

    if (!solid) {
      gluQuadricDrawStyle(qobj, GLU_LINE);
    }
    gluCylinder(qobj, 0.15, 0.15, 2.0, 16, 10);
    gluCylinder(qobj, 0.06, 0.06, 2.0, 16, 10);
    glTranslatef(0.0, 0.0, 2.0);
    gluDisk(qobj, 0.1, 0.15, 16, 10);
    gluCylinder(qobj, 0.1, 0.1, 0.1, 16, 5);
    glTranslatef(0.0, 0.0, 0.1);
    gluDisk(qobj, 0.06, 0.1, 16, 5);
      glTranslatef(0.0, -0.3, -2.1);
    }
  glEndList();
}

void ForeArm(char solid)
{
  char i;

  glNewList(SOLID_MECH_FOREARM, GL_COMPILE);
#ifdef LIGHT
  SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
  glColor3f(0.0, 1.0, 1.0);//fore arm light green
  for (i = 0; i < 5; i++) {
    glTranslatef(0.0, -0.1, -0.15);
    Box(0.6, 0.8, 0.2, solid);
    glTranslatef(0.0, 0.1, -0.15);
    Box(0.4, 0.6, 0.1, solid);
  }
  glTranslatef(0.0, 0.0, 2.45);
  Box(1.0, 1.0, 2.0, solid);
  glTranslatef(0.0, 0.0, -1.0);
  glEndList();
}

void UpperLeg(char solid)
{
  int i;

  glNewList(SOLID_MECH_UPPER_LEG, GL_COMPILE);
#ifdef LIGHT
  SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
  glColor3f(1.0, 1.0, 0.0);//color yellow
  if (!solid) {
    gluQuadricDrawStyle(qobj, GLU_LINE);
  }
  glTranslatef(0.0, -1.0, 0.0);
  Box(0.4, 1.0, 0.7, solid);
  glTranslatef(0.0, -0.65, 0.0);
  for (i = 0; i < 5; i++) {
    Box(1.2, 0.3, 1.2, solid);
    glTranslatef(0.0, -0.2, 0.0);
    Box(1.0, 0.1, 1.0, solid);
    glTranslatef(0.0, -0.2, 0.0);
  }
  glTranslatef(0.0, -0.15, -0.4);
  Box(2.0, 0.5, 2.0, solid);
  glTranslatef(0.0, -0.3, -0.2);
  glRotatef(90.0, 1.0, 0.0, 0.0);
#ifdef LIGHT
  SetMaterial(mat_specular2, mat_ambient2, mat_diffuse2, mat_shininess2);
#endif
  glColor3f(0.5, 0.5, 0.5);//leg joints grey
  gluCylinder(qobj, 0.6, 0.6, 3.0, 16, 10);
#ifdef LIGHT
  SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
  glColor3f(0.0, 1.0, 0.0);//above the leg joint n below the fore leg
  glRotatef(-90.0, 1.0, 0.0, 0.0);
  glTranslatef(0.0, -1.5, 1.0);
  Box(1.5, 3.0, 0.5, solid);
  glTranslatef(0.0, -1.75, -0.8);
  Box(2.0, 0.5, 2.0, solid);
  glTranslatef(0.0, -0.9, -0.85);
#ifdef LIGHT
  SetMaterial(mat_specular2, mat_ambient2, mat_diffuse2, mat_shininess2);
#endif
  glColor3f(1.0, 0.0, 0.0);//leg joints between fore leg and leg
  gluCylinder(qobj, 0.8, 0.8, 1.8, 16, 10);
  for (i = 0; i < 2; i++) {
    if (i)
      glScalef(-1.0, 1.0, 1.0);
    if (!solid)
      gluQuadricDrawStyle(qobj, GLU_LINE);
    if (i)
      glTranslatef(0.0, 0.0, 1.8);
    gluDisk(qobj, 0.0, 0.8, 16, 10);
    if (i)
      glTranslatef(0.0, 0.0, -1.8);
  }
  glScalef(-1.0, 1.0, 1.0);
  glEndList();
}

void Foot(char solid)
{

  glNewList(SOLID_MECH_FOOT, GL_COMPILE);
#ifdef LIGHT
  SetMaterial(mat_specular2, mat_ambient2, mat_diffuse2, mat_shininess2);
#endif
  glColor3f(1.0, 0.0, 0.0);// color foot
  glRotatef(90.0, 1.0, 0.0, 0.0);
  Octagon(1.5, 0.6, solid);
  glRotatef(-90.0, 1.0, 0.0, 0.0);
  glEndList();
}

void LowerLeg(char solid)
{
  float k, l;

#ifdef LIGHT
  SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
  glColor3f(1.0, 0.0, 0.0);//leg joint
  for (k = 0.0; k < 2.0; k++) {
    for (l = 0.0; l < 2.0; l++) {
      glPushMatrix();
      glTranslatef(k, 0.0, l);
#ifdef LIGHT
      SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
      glColor3f(1.0, 0.0, 0.0);//red
      Box(1.0, 0.5, 1.0, solid);
      glTranslatef(0.0, -0.45, 0.0);
#ifdef LIGHT
      SetMaterial(mat_specular2, mat_ambient2, mat_diffuse2, mat_shininess2);
#endif
      glColor3f(1.0, 0.0, 0.0);
#ifdef SPHERE
      if (!solid)
        glutWireSphere(0.2, 16, 10);
      else
        glutSolidSphere(0.2, 16, 10);
#endif
      if (leg)
        glRotatef((GLfloat) heel1, 1.0, 0.0, 0.0);
      else
        glRotatef((GLfloat) heel2, 1.0, 0.0, 0.0);
      /* glTranslatef(0.0, -0.2, 0.0); */
      glTranslatef(0.0, -1.7, 0.0);
#ifdef LIGHT
      SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
      glColor3f(1.0, 0.0, 0.0);//color of the below leg( pillers)
      Box(0.25, 3.0, 0.25, solid);
      glTranslatef(0.0, -1.7, 0.0);
#ifdef LIGHT
      SetMaterial(mat_specular2, mat_ambient2, mat_diffuse2, mat_shininess2);
#endif
      glColor3f(0.0, 0.0, 1.0);//joints
#ifdef SPHERE
      if (!solid)
        glutWireSphere(0.2, 16, 10);
      else
        glutSolidSphere(0.2, 16, 10);
#endif
      if (leg)
        glRotatef((GLfloat) - heel1, 1.0, 0.0, 0.0);
      else
        glRotatef((GLfloat) - heel2, 1.0, 0.0, 0.0);
      glTranslatef(0.0, -0.45, 0.0);
#ifdef LIGHT
      SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
      glColor3f(0.0, 1.0, 0.0);// leg n foot joints color
      Box(1.0, 0.5, 1.0, solid);
      if (!k && !l) {
        int j;

        glTranslatef(-0.4, -0.8, 0.5);
        if (leg)
          glRotatef((GLfloat) ankle1, 1.0, 0.0, 0.0);
        else
          glRotatef((GLfloat) ankle2, 1.0, 0.0, 0.0);
        glRotatef(90.0, 0.0, 1.0, 0.0);
        if (!solid)
          gluQuadricDrawStyle(qobj, GLU_LINE);
        gluCylinder(qobj, 0.8, 0.8, 1.8, 16, 10);
        for (j = 0; j < 2; j++) {
          if (!solid)
            gluQuadricDrawStyle(qobj, GLU_LINE);
          if (j) {
            glScalef(-1.0, 1.0, 1.0);
            glTranslatef(0.0, 0.0, 1.8);
          }
          gluDisk(qobj, 0.0, 0.8, 16, 10);
          if (j)
            glTranslatef(0.0, 0.0, -1.8);
        }
        glScalef(-1.0, 1.0, 1.0);
        glRotatef(-90.0, 0.0, 1.0, 0.0);
        glTranslatef(0.95, -0.8, 0.0);
        glCallList(SOLID_MECH_FOOT);
      }
      glPopMatrix();
    }
  }
}

void RocketPod(char solid)
{

  int i, j, k = 0;

  glNewList(SOLID_MECH_ROCKET, GL_COMPILE);
#ifdef LIGHT
  SetMaterial(mat_specular2, mat_ambient2, mat_diffuse2, mat_shininess2);
#endif
  glColor3f(0.0, 1.0, 0.0);//rocket port color
  glScalef(0.4, 0.4, 0.4);
  glRotatef(45.0, 0.0, 0.0, 1.0);
  glTranslatef(1.0, 0.0, 0.0);
  Box(2.0, 0.5, 3.0, solid);
  glTranslatef(1.0, 0.0, 0.0);
  glRotatef(45.0, 0.0, 0.0, 1.0);
  glTranslatef(0.5, 0.0, 0.0);
  Box(1.2, 0.5, 3.0, solid);
  glTranslatef(2.1, 0.0, 0.0);
  glRotatef(-90.0, 0.0, 0.0, 1.0);
#ifdef LIGHT
  SetMaterial(mat_specular, mat_ambient, mat_diffuse, mat_shininess);
#endif
  glColor3f(1.0, 1.0, 0.0);
  Box(2.0, 3.0, 4.0, solid);
  glTranslatef(-0.5, -1.0, 1.3);
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j++) {
      if (!solid) {
        gluQuadricDrawStyle(qobj, GLU_LINE);
      }
      glTranslatef(i, j, 0.6);
#ifdef LIGHT
      SetMaterial(mat_specular3, mat_ambient3, mat_diffuse3, mat_shininess3);
#endif
      glColor3f(1.0, 1.0, 1.0);
      gluCylinder(qobj, 0.4, 0.4, 0.3, 16, 10);
      glTranslatef(0.0, 0.0, 0.3);
#ifdef LIGHT
      SetMaterial(mat_specular4, mat_ambient4, mat_diffuse4, mat_shininess4);
#endif
      glColor3f(0.0, 1.0, 0.0);
      gluCylinder(qobj, 0.4, 0.0, 0.5, 16, 10);
      k++;
      glTranslatef(-i, -j, -0.9);
    }
  }
  glEndList();
}

void Enviro(char solid)
{

  int i, j;

  glNewList(SOLID_ENVIRO, GL_COMPILE);
  SetMaterial(mat_specular4, mat_ambient4, mat_diffuse4, mat_shininess4);
  glColor3f(1.0, 1.0, 0.0);//out line of the walking path
  Box(20.0, 0.5, 30.0, solid);
  SetMaterial(mat_specular4, mat_ambient3, mat_diffuse2, mat_shininess);
  glColor3f(1.0, 0.0, 0.0);//the surrounding area color
  glTranslatef(0.0, 0.0, -10.0);
  for (j = 0; j < 6; j++) {
    for (i = 0; i < 2; i++) {
      if (i)
        glScalef(-1.0, 1.0, 1.0);
      glTranslatef(10.0, 4.0, 0.0);
      Box(4.0, 8.0, 2.0, solid);
      glTranslatef(0.0, -1.0, -3.0);
      Box(4.0, 6.0, 2.0, solid);
      glTranslatef(-10.0, -3.0, 3.0);
    }
    glScalef(-1.0, 1.0, 1.0);
    glTranslatef(0.0, 0.0, 5.0);
  }
  glEndList();
}

void Toggle(void)
{
  if (solid_part)
    solid_part = 0;
  else
    solid_part = 1;
}

void disable(void)
{
  glDisable(GL_LIGHTING);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_NORMALIZE);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void lighting(void)
{

  GLfloat position[] =
  {0.0, 0.0, 2.0, 1.0};

#ifdef MOVE_LIGHT
  glRotatef((GLfloat) lightturn1, 1.0, 0.0, 0.0);
  glRotatef((GLfloat) lightturn, 0.0, 1.0, 0.0);
  glRotatef(0.0, 1.0, 0.0, 0.0);
#endif
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_NORMALIZE);
  glDepthFunc(GL_LESS);
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

  glLightfv(GL_LIGHT0, GL_POSITION, position);
  glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 80.0);

  glTranslatef(0.0, 0.0, 2.0);
  glDisable(GL_LIGHTING);
  Box(0.1, 0.1, 0.1, 0);
  glEnable(GL_LIGHTING);
}

void DrawMech(void)
{
  int i, j;

  glScalef(0.5, 0.5, 0.5);
  glPushMatrix();
  glTranslatef(0.0, -0.75, 0.0);
  glRotatef((GLfloat) tilt, 1.0, 0.0, 0.0);

  glRotatef(90.0, 1.0, 0.0, 0.0);
#ifdef HIP
  glCallList(SOLID_MECH_HIP);
#endif
  glRotatef(-90.0, 1.0, 0.0, 0.0);

  glTranslatef(0.0, 0.75, 0.0);
  glPushMatrix();
  glRotatef((GLfloat) pivot, 0.0, 1.0, 0.0);
  glPushMatrix();
#ifdef TORSO
  glCallList(SOLID_MECH_TORSO);
#endif
  glPopMatrix();
  glPushMatrix();
  glTranslatef(0.5, 0.5, 0.0);
#ifdef ROCKET_POD
  glCallList(SOLID_MECH_ROCKET);
#endif
  glPopMatrix();
  for (i = 0; i < 2; i++) {
    glPushMatrix();
    if (i)
      glScalef(-1.0, 1.0, 1.0);
    glTranslatef(1.5, 0.0, 0.0);
#ifdef SHOULDER
    glCallList(SOLID_MECH_SHOULDER);
#endif
    glTranslatef(0.9, 0.0, 0.0);
    if (i) {
      glRotatef((GLfloat) lat1, 0.0, 0.0, 1.0);
      glRotatef((GLfloat) shoulder1, 1.0, 0.0, 0.0);
      glRotatef((GLfloat) shoulder3, 0.0, 1.0, 0.0);
    } else {
      glRotatef((GLfloat) lat2, 0.0, 0.0, 1.0);
      glRotatef((GLfloat) shoulder2, 1.0, 0.0, 0.0);
      glRotatef((GLfloat) shoulder4, 0.0, 1.0, 0.0);
    }
    glTranslatef(0.0, -1.4, 0.0);
#ifdef UPPER_ARM
    glCallList(SOLID_MECH_UPPER_ARM);
#endif
    glTranslatef(0.0, -2.9, 0.0);
    if (i)
      glRotatef((GLfloat) elbow1, 1.0, 0.0, 0.0);
    else
      glRotatef((GLfloat) elbow2, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.9, -0.2);
#ifdef LOWER_ARM
    glCallList(SOLID_MECH_FOREARM);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 2.0);
    glRotatef((GLfloat) fire, 0.0, 0.0, 1.0);
    glCallList(SOLID_MECH_VULCAN);
    glPopMatrix();
#endif
    glPopMatrix();
  }
  glPopMatrix();

  glPopMatrix();

  for (j = 0; j < 2; j++) {
    glPushMatrix();
    if (j) {
      glScalef(-0.5, 0.5, 0.5);
      leg = 1;
    } else {
      glScalef(0.5, 0.5, 0.5);
      leg = 0;
    }
    glTranslatef(2.0, -1.5, 0.0);
    if (j) {
      glRotatef((GLfloat) hip11, 1.0, 0.0, 0.0);
      glRotatef((GLfloat) hip12, 0.0, 0.0, 1.0);
    } else {
      glRotatef((GLfloat) hip21, 1.0, 0.0, 0.0);
      glRotatef((GLfloat) hip22, 0.0, 0.0, 1.0);
    }
    glTranslatef(0.0, 0.3, 0.0);
#ifdef UPPER_LEG
    glPushMatrix();
    glCallList(SOLID_MECH_UPPER_LEG);
    glPopMatrix();
#endif
    glTranslatef(0.0, -8.3, -0.4);
    if (j)
      glRotatef((GLfloat) - hip12, 0.0, 0.0, 1.0);
    else
      glRotatef((GLfloat) - hip22, 0.0, 0.0, 1.0);
    glTranslatef(-0.5, -0.85, -0.5);
#ifdef LOWER_LEG
    LowerLeg(1);
#endif
    glPopMatrix();
  }
}

void display(void)
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
 //glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glPushMatrix();
  glRotatef((GLfloat) turn, 0.0, 1.0, 0.0);
  glRotatef((GLfloat) turn1, 1.0, 0.0, 0.0);
#ifdef LIGHT
  if (solid_part) {
    glPushMatrix();
    lighting();
    glPopMatrix();
  } else
    disable();
#endif
#ifdef DRAW_MECH
  glPushMatrix();
  glTranslatef(0.0, elevation, 0.0);
  DrawMech();
  glPopMatrix();
#endif
#ifdef DRAW_ENVIRO
  glPushMatrix();
  if (distance >= 20.136)
    distance = 0.0;
  glTranslatef(0.0, -5.0, -distance);
  glCallList(SOLID_ENVIRO);
  glTranslatef(0.0, 0.0, 10.0);
  glCallList(SOLID_ENVIRO);
  glPopMatrix();
#endif
  glPopMatrix();


  glutSwapBuffers();

}


void myinit(void)
{
  char i = 1;

  qobj = gluNewQuadric();
#ifdef LIGHT
  SetMaterial(mat_specular2, mat_ambient2, mat_diffuse2, mat_shininess2);
#endif
  glEnable(GL_DEPTH_TEST);
  MechTorso(i);
  MechHip(i);
  Shoulder(i);
  RocketPod(i);
  UpperArm(i);
  ForeArm(i);
  UpperLeg(i);
  Foot(i);
  VulcanGun(i);
  Enviro(i);
}

void myReshape(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(65.0, (GLfloat) w / (GLfloat) h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0, 1.2, -5.5);  /* viewing transform  */
}

#ifdef ANIMATION
 void animation_walk(void)

{
  float angle;
  static int step;

  if (step == 0 || step == 2) {

    if (frame >= 0.0 && frame <= 21.0) {
      if (frame == 0.0)
        frame = 3.0;
      angle = (180 / M_PI) * (acos(((cos((M_PI / 180) * frame) * 2.043) + 1.1625) / 3.2059));
      if (frame > 0) {
        elevation = -(3.2055 - (cos((M_PI / 180) * angle) * 3.2055));
      } else
        elevation = 0.0;
      if (step == 0) {
        hip11 = -(frame * 1.7);
        if (1.7 * frame > 15)
          heel1 = frame * 1.7;
        heel2 = 0;
        ankle1 = frame * 1.7;
        if (frame > 0)
          hip21 = angle;
        else
          hip21 = 0;
        ankle2 = -hip21;
        shoulder1 = frame * 1.5;
        shoulder2 = -frame * 1.5;
        elbow1 = frame;
        elbow2 = -frame;
      } else {
        hip21 = -(frame * 1.7);
        if (1.7 * frame > 15)
          heel2 = frame * 1.7;
        heel1 = 0;
        ankle2 = frame * 1.7;
        if (frame > 0)
          hip11 = angle;
        else
          hip11 = 0;
        ankle1 = -hip11;
        shoulder1 = -frame * 1.5;
        shoulder2 = frame * 1.5;
        elbow1 = -frame;
        elbow2 = frame;
      }
      if (frame == 21)
        step++;
      if (frame < 21)
        frame = frame + 3.0;
    }
  }
  if (step == 1 || step == 3) {

    if (frame <= 21.0 && frame >= 0.0) {
      angle = (180 / M_PI) * (acos(((cos((M_PI / 180) * frame) * 2.043) + 1.1625) / 3.2029));
      if (frame > 0)
        elevation = -(3.2055 - (cos((M_PI / 180) * angle) * 3.2055));
      else
        elevation = 0.0;
      if (step == 1) {
        elbow2 = hip11 = -frame;
        elbow1 = heel1 = frame;
        heel2 = 15;
        ankle1 = frame;
        if (frame > 0)
          hip21 = angle;
        else
          hip21 = 0;
        ankle2 = -hip21;
        shoulder1 = 1.5 * frame;
        shoulder2 = -frame * 1.5;
      } else {
        elbow1 = hip21 = -frame;
        elbow2 = heel2 = frame;
        heel1 = 15;
        ankle2 = frame;
        if (frame > 0)
          hip11 = angle;
        else
          hip11 = 0;
        ankle1 = -hip11;
        shoulder1 = -frame * 1.5;
        shoulder2 = frame * 1.5;
      }
      if (frame == 0.0)
        step++;
      if (frame > 0)
        frame = frame - 3.0;
    }
  }
  if (step == 4)
    step = 0;
  distance += 0.1678;
  glutPostRedisplay();
}

void animation(void)
{
  animation_walk();
}

#endif

#ifdef GLUT
#ifdef GLUT_KEY
/* ARGSUSED1 */
void keyboard(unsigned char key, int x, int y)
{

  int i = 0;
if (key == 27) exit (0);
  switch (key) {
    /* start arm control functions */
  case 'q':{
      shoulder2Subtract();
      i++;
	  i++;
    }
    break;
   case 'b':{
      shoulder2Subtract();

      i++;
	  i++;
     shoulder1Subtract();
        i++;
    }
    break;
  case 'a':{
      shoulder2Add();
      i++;
    }
    break;
  case 'w':{
      shoulder1Subtract();
      i++;
    }
    break;
  case 's':{
      shoulder1Add();
      i++;
    }
    break;
  case 'P':{
      shoulder2Add();
      i++;
      shoulder1Add();
      i++;
    }
    break;
  case '2':{
      shoulder3Add();
      i++;
    }
    break;
  case '1':{
      shoulder4Add();
      i++;
    }
    break;
  case '4':{
      shoulder3Subtract();
      i++;
    }
    break;
  case '3':{
      shoulder4Subtract();
      i++;
    }
    break;

  case 'z':{
      lat2Raise();
      i++;
    }
    break;
  case 'Z':{
      lat2Lower();
      i++;
    }
    break;
  case 'x':{
      lat1Raise();
      i++;
    }
    break;
  case 'X':{
      lat1Lower();
      i++;
    }
    break;

  case 'A':{
      elbow2Add();
      i++;
    }
    break;
  case 'Q':{
      elbow2Subtract();
      i++;
    }
    break;
  case 'S':{
      elbow1Add();
      i++;
    }
    break;
  case 'W':{
      elbow1Subtract();
      i++;
    }
    break;
    /* end of arm control functions */

    /* start of torso control functions */
  case 'd':{
      RotateAdd();
      i++;
    }
    break;
  case 'g':{
      RotateSubtract();
      i++;
    }
    break;
  case 'r':{
      MechTiltAdd();
      i++;
    }
    break;
  case 'f':{
      MechTiltSubtract();
      i++;
    }
    break;
    /* end of torso control functions */

    /* start of leg control functions */
  case 'h':{
      RaiseLeg2Forward();
      i++;
    }
    break;
   /*case 'D':{
      RaiseLeg2Forward();
      i++;
      RaiseLeg1Forward();
      i++;
    }
    break;*/
  case 'y':{
      LowerLeg2Backwards();
      i++;
    }
    break;
  case 'T':{
      LowerLeg2Backwards();
      i++;
      LowerLeg1Backwards();
      i++;
    }
    break;
   case 'v':{
	RaiseLeg2Forward();
        i++;
        RaiseLeg1Forward();
        i++;
}
  case 'Y':{
      RaiseLeg2Outwards();
      i++;
    }
    break;
  case 'H':{
      LowerLeg2Inwards();
      i++;
    }
    break;

  case 'j':{
      RaiseLeg1Forward();
      i++;
    }
    break;
  case 'u':{
      LowerLeg1Backwards();
      i++;
    }
    break;
  case 'U':{
      RaiseLeg1Outwards();
      i++;
    }
    break;
  case 'J':{
      LowerLeg1Inwards();
      i++;
    }
    break;

  case 'N':{
      Heel2Add();
      i++;
    }
    break;
  case 'n':{
      Heel2Subtract();
      i++;
    }
    break;
  case 'M':{
      Heel1Add();
      i++;
    }
    break;
  case 'm':{
      Heel1Subtract();
      i++;
    }
    break;
  case 'E':{
      Heel2Subtract();
      i++;
      Heel1Subtract();
      i++;
    }
    break;
  case 'e':{
      Heel2Add();
      i++;
      Heel1Add();
      i++;
    }
    break;

  case 'k':{
      Ankle2Add();
      i++;
    }
    break;
  case 'K':{
      Ankle2Subtract();
      i++;
    }
    break;
  case 'l':{
      Ankle1Add();
      i++;
    }
    break;
  case 'L':{
      Ankle1Subtract();
      i++;
    }
    break;
    /* end of leg control functions */

    /* start of light source position functions */
  case 'p':{
      LightTurnRight();
      i++;
    }
    break;
  case 'i':{
      LightTurnLeft();
      i++;
    }
    break;
  case 'o':{
      LightForwards();
      i++;
    }
    break;
  case '9':{
      LightBackwards();
      i++;
    }
    break;

    /* end of light source position functions */
  }
  if (i)
    glutPostRedisplay();
}

#endif

#ifdef GLUT_SPEC
/* ARGSUSED1 */
void special(int key, int x, int y)
{

  int i = 0;

  switch (key) {
    /* start of view position functions */
  case GLUT_KEY_RIGHT:{
      TurnRight();
      i++;
    }
    break;
  case GLUT_KEY_LEFT:{
      TurnLeft();
      i++;
    }
    break;
  case GLUT_KEY_DOWN:{
      TurnForwards();
      i++;
    }
    break;
  case GLUT_KEY_UP:{
      TurnBackwards();
      i++;
    }
    break;
    /* end of view postions functions */
    /* start of miseclleneous functions */
  case GLUT_KEY_PAGE_UP:{
      FireCannon();
      i++;
    }
    break;
    /* end of miscelleneous functions */

  }
  if (i)
    glutPostRedisplay();
}
void dance(void)
{
glutInitWindowSize(1000, 1000);
    glutCreateWindow("robot");
  //sndPlaySound("bird_FINAL.wav",SND_ASYNC);
    myinitfinal();
    glutReshapeFunc(myReshapefinal);
    glutDisplayFunc(displayfinal);
	glutIdleFunc(idle);

}
#endif
#endif
void menu_select(int mode)
{
  switch (mode) {
#ifdef ANIMATION
  case 1:
   glutIdleFunc(animation);
    break;
#endif
  case 2:
    glutIdleFunc(NULL);
    break;
  case 3:
    Toggle();
    glutPostRedisplay();
    break;
  /*case 4:
  assemble();
  break;*/
  case 4:
dance();
glutPostRedisplay();
break;
  case 5:
    exit(EXIT_SUCCESS);

  }
}

/* ARGSUSED */
void null_select(int mode)
{
}

void glutMenu(void)
{

  int glut_menu[13];

  glut_menu[5] = glutCreateMenu(null_select);
  glutAddMenuEntry("forward       : q,w", 0);
  glutAddMenuEntry("backwards     : a,s", 0);
  glutAddMenuEntry("outwards      : z,x", 0);
  glutAddMenuEntry("inwards       : Z,X", 0);

  glut_menu[6] = glutCreateMenu(null_select);
  glutAddMenuEntry("upwards       : Q,W", 0);
  glutAddMenuEntry("downwards     : A,S", 0);
  glutAddMenuEntry("outwards      : 1,2", 0);
  glutAddMenuEntry("inwards       : 3,4", 0);



  glut_menu[8] = glutCreateMenu(null_select);
  glutAddMenuEntry("forward       : y,u", 0);
  glutAddMenuEntry("backwards     : h.j", 0);
  glutAddMenuEntry("outwards      : Y,U", 0);
  glutAddMenuEntry("inwards       : H,J", 0);

  glut_menu[9] = glutCreateMenu(null_select);
  glutAddMenuEntry("forward       : n,m", 0);
  glutAddMenuEntry("backwards     : N,M", 0);


  glut_menu[10] = glutCreateMenu(null_select);
  glutAddMenuEntry("toes up       : K,L", 0);
  glutAddMenuEntry("toes down     : k,l", 0);

  glut_menu[11] = glutCreateMenu(null_select);
  glutAddMenuEntry("right         : right arrow", 0);
  glutAddMenuEntry("left          : left arrow", 0);
  glutAddMenuEntry("down          : up arrow", 0);
  glutAddMenuEntry("up            : down arrow", 0);

 

  glut_menu[4] = glutCreateMenu(NULL);
  glutAddSubMenu("at the shoulders? ", glut_menu[5]);
  glutAddSubMenu("at the elbows?", glut_menu[6]);

  glut_menu[7] = glutCreateMenu(NULL);
  glutAddSubMenu("at the bottompart? ", glut_menu[8]);
  glutAddSubMenu("at the knees?", glut_menu[9]);
  glutAddSubMenu("at the ankles? ", glut_menu[10]);

  glut_menu[2] = glutCreateMenu(null_select);
  glutAddMenuEntry("turn left    : d", 0);
  glutAddMenuEntry("turn right    : g", 0);
  

  glut_menu[3] = glutCreateMenu(null_select);
  glutAddMenuEntry("tilt backwards : f", 0);
  glutAddMenuEntry("tilt forwards  : r", 0);

  glut_menu[0] = glutCreateMenu(NULL);
  glutAddSubMenu("move the arms", glut_menu[4]);
  //glutAddSubMenu("fire the vulcan guns?", glut_menu[1]);
  glutAddSubMenu("move the legs ", glut_menu[7]);
  glutAddSubMenu("move the torso", glut_menu[2]);
  glutAddSubMenu("move the upper portion", glut_menu[3]);
  glutAddSubMenu("rotate the scene", glut_menu[11]);


  glutCreateMenu(menu_select);
#ifdef ANIMATION
  glutAddMenuEntry("START WALK", 1);
  glutAddMenuEntry("STOP WALK", 2);
#endif
  glutAddMenuEntry("CHANGE VIEW", 3);
  
  glutAddSubMenu("HOW TO MOVE DIFFERENT PARTS?", glut_menu[0]);
 //glutAddMenuEntry("ASSEMBLE", 4);
  glutAddMenuEntry("DANCE", 4);
  glutAddMenuEntry("QUIT", 5);
  glutAttachMenu(GLUT_LEFT_BUTTON);
  glutAttachMenu(GLUT_RIGHT_BUTTON);
}





























void Display_on_screen(char *string)
{
	while(*string)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*string++);
	}

}

void init()
{
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0,50,0,50,0,10);
}


void mymouse(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
     	glutDestroyWindow(firstwindow);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(1000, 1000);
  secondwindow=glutCreateWindow("WALKING ROBOT");
  myinit();
  glutDisplayFunc(display);
  glutReshapeFunc(myReshape);
#ifdef GLUT_KEY
  glutKeyboardFunc(keyboard);
#endif
#ifdef GLUT_SPEC
  glutSpecialFunc(special);
#endif
 glutMenu();

	glPointSize(2.0);
 

	}
/*if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
{
glutDestroyWindow(firstwindow);
    
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("robot");

    myinitfinal();
    glutReshapeFunc(myReshapefinal);
    glutDisplayFunc(displayfinal);
	glutIdleFunc(idle);
	
    glutCreateMenu(menu);
    glutAddMenuEntry("torso", 0);
    glutAddMenuEntry("head1", 1);
    glutAddMenuEntry("head2", 2);
    glutAddMenuEntry("right_upper_arm", 3);
    glutAddMenuEntry("right_lower_arm", 4);
    glutAddMenuEntry("left_upper_arm", 5);
    glutAddMenuEntry("left_lower_arm", 6);
    glutAddMenuEntry("right_upper_leg", 7);
    glutAddMenuEntry("right_lower_leg", 8);
    glutAddMenuEntry("left_upper_leg", 9);
    glutAddMenuEntry("left_lower_leg", 10);
    glutAddMenuEntry("quit", 11);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);

 
    glutMainLoop();*/


//}
}
void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,1.0);
    glRasterPos2i(15,40);

    glRasterPos3f(16,40,0);
    Display_on_screen("3D WALKING ROBOT");

    glColor3f(1.0,1.0,1.0);

    glRasterPos3f(12,26,0);
    Display_on_screen("NAME");


    glRasterPos3f(26,26,0);
    Display_on_screen("USN");

    glColor3f(1.0,1.0,1.0);

    glRasterPos3f(12,22,0);
    Display_on_screen("MAHIMA");

    glRasterPos3f(23,22,0);
    Display_on_screen("->");

    glRasterPos3f(26,22,0);
    Display_on_screen("4NM17CS096");

    glRasterPos3f(12,20,0);
    Display_on_screen("MAITHRI SURESH");

    glRasterPos3f(23,20,0);
    Display_on_screen("->");

    glRasterPos3f(26,20,0);
    Display_on_screen("4NM17CS097");

    glRasterPos3f(12,18,0);
    Display_on_screen("MALLIKA");

    glRasterPos3f(23,18,0);
    Display_on_screen("->");

    glRasterPos3f(26,18,0);
    Display_on_screen("4NM17CS098");
       glRasterPos3f(12,16,0);
    Display_on_screen("MADAN");

    glRasterPos3f(23,16,0);
    Display_on_screen("->");

    glRasterPos3f(26,16,0);
    Display_on_screen("4NM17CS095");


  glRasterPos3f(28,14,0);
    Display_on_screen("NEXT");

    glColor3f(1.0,1.0,1.0);
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2i(15,39);
    glVertex2i(26,39);
    glEnd();
    glFlush();

}








































































int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(1,1);
    glutInitWindowSize(1000,1000);
   firstwindow = glutCreateWindow("WALKINGROBOT");
    init();
    glutDisplayFunc(display2);
    glutMouseFunc(mymouse);


    glutMainLoop();

}

  


