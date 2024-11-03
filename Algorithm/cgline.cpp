#include <iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include <cmath>
int x1,Y1,x2,y2 ;

using namespace std;

//DDA Line drawing fxn:

void DDAline( int xa, int ya , int xb , int yb)
{
  /*Var req:- 2 pts. , dx , dy , steps ,xinc , yinc , cmath library  */
  
  int dx , dy , steps ;
  
  dx = xb - xa;
  dy = yb - ya;
  // int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
  if(abs(dx) > abs(dy))
  {
    steps = abs(dx);
  }
  else 
  {
    steps = abs(dy);
  }
  float xinc = dx/float(steps);
  float yinc = dy / float(steps);
  
  float x = xa;
  float y = ya;
  
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS);
  glVertex2f( xa , ya);
  for(int i = 0; i < steps; i++)
  {
    x = x + xinc;
    y = y + yinc;
    glVertex2f( x , y);
  }

}

//Draw function to give call to the algorithms in the program for their execution;
void Draw()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POINTS); //It invokes the OpenGL library;
  
  DDAline(x1 , Y1, x2 ,y2);

  glEnd();
  glFlush(); // Force OpenGL to execute the drawing commands
}

//Main function to call the draw fxn and execute basic req.tasks;
int main(int argc , char** argv)
{
  
  cout<<"Enter Point 1 :"<<endl;
  cin>>x1>>Y1;
  
  cout<<"Enter Point 2 :"<<endl;
  cin>>x2>>y2;
  
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);  // Set the initial window position;
  glutInitWindowSize(640,480);  // Set the window size;
  glutCreateWindow("Pattern");  // Create a window with the title "Pattern"
  glClearColor(1.0,1.0,1.0,0.0);  // Set the background color to white
  glColor3f(0.0,0.0,0.0); // Set the drawing color to black
  gluOrtho2D(0,640,0,480); // Set up a 2D orthographic projection
  glutDisplayFunc(Draw);  // Register the display callback function
  glutMainLoop(); // Enter the GLUT main event loop
  
  
  return 0;
}
