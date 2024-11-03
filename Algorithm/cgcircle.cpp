#include <iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include<cmath>
int xc,yc,r;

using namespace std;

void circle(int r)
{
  int d , x , y;
  d = 3 - 2*r;
  
  x=0;
  y=r;
  
  do {
  glBegin(GL_POINTS);
      glVertex2d(x+xc,y+yc);
      glVertex2d(y+xc,x+yc);
      glVertex2d(-x+xc,y+yc);
      glVertex2d(-y+xc,x+yc);
      glVertex2d(-x+xc,-y+yc);
      glVertex2d(-y+xc,-x+yc);
      glVertex2d(x+xc,-y+yc);
      glVertex2d(y+xc,-x+yc);
      
      glEnd();
      if(d<0)
      {
        
        d  = d +  4*x + 6;
      }
      else
      {
        d = d + 4*(x-y) +10;
        y -=1;
      }
      
      x+=1;
     }while(x<=y);
}

void Draw()
{
  glClear(GL_COLOR_BUFFER_BIT);
  
  circle(r);
  
  glFlush(); 
  }

//Main function to call the draw fxn and execute basic req.tasks;
int main(int argc , char** argv)
{
  cout<<"Enter the Co-ordinates of the Center"<<endl;
  cin>>xc>>yc;
  
  cout<<"Enter the Radius of the Circle"<<endl;
  cin>>r;
  
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
  glutInitWindowPosition(0,0);  
  glutInitWindowSize(640,480);  
  glutCreateWindow("Pattern");  
  glClearColor(1.0,1.0,1.0,0.0);  
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(0,640,0,480); 
  glutDisplayFunc(Draw);  
  glutMainLoop(); 
  
  
  
  return 0;
}

