# Drawing Shapes with Computer Graphics Algorithms:

> This file contains the codes for drawing various shapes using computer graphics algorithms:


## 1. Digital Differential Analyzer (DDA) Line Code:

> This C++ program uses OpenGL to draw a line based on the DDA (Digital Differential Analyzer) Line Drawing Algorithm, which calculates intermediate points between two user-defined endpoints to create a smooth line segment.


```cpp
#include <iostream>
#include <GL/glut.h>
#include <GL/glu.h>
#include <cmath>

int x1, Y1, x2, y2;

using namespace std;

// DDA Line drawing function
void DDAline(int xa, int ya, int xb, int yb)
{
    /* Variables required: 2 points, dx, dy, steps, xinc, yinc, cmath library */
    int dx, dy, steps;

    dx = xb - xa;
    dy = yb - ya;

    // Determine the number of steps
    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    float xinc = dx / float(steps);
    float yinc = dy / float(steps);

    float x = xa;
    float y = ya;

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2f(xa, ya);

    for (int i = 0; i < steps; i++)
    {
        x += xinc;
        y += yinc;
        glVertex2f(x, y);
    }

    glEnd();
}

// Draw function to execute the algorithm
void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS); // Invoke the OpenGL library

    // Draw the rectangle using DDA lines
    DDAline(x1, Y1, x1, y2);
   
    glEnd();
    glFlush(); // Force OpenGL to execute the drawing commands
}

// Main function to call the draw function and handle basic tasks
int main(int argc, char** argv)
{
    cout << "Enter Point 1:" << endl;
    cin >> x1 >> Y1;

    cout << "Enter Point 2:" << endl;
    cin >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0); // Set the initial window position
    glutInitWindowSize(640, 480); // Set the window size
    glutCreateWindow("Pattern");  // Create a window with the title "Pattern"
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set the background color to white
    glColor3f(0.0, 0.0, 0.0); // Set the drawing color to black
    gluOrtho2D(0, 640, 0, 480); // Set up a 2D orthographic projection
    glutDisplayFunc(Draw); // Register the display callback function
    glutMainLoop(); // Enter the GLUT main event loop

    return 0;
}


```
- The code implements the Digital Differential Analyzer (DDA) algorithm to draw a line segment between two user-defined points.
- It incrementally calculates pixel coordinates based on the line’s slope, ensuring a smooth and accurate line rendering.
- User-defined start and end points allow for interactive, precise line drawing.
- The design emphasizes both efficiency and simplicity, making it suitable for graphical applications.
int xc,yc,r;

## 2. Bresenham's Circle Drawing Code:

>Bresenham's Circle Drawing Algorithm in OpenGL:
>This C++ program uses OpenGL to draw a circle based on Bresenham's Circle >Drawing Algorithm. The algorithm takes a user-defined center and radius to >draw a circle using efficient pixel calculations. Below is the code with >explanations.

```cpp
//This C++ program uses OpenGL to draw a circle based on Bresenham's Circle Drawing Algorithm.
//The algorithm takes a user-defined center and radius to draw a circle using efficient pixel calculations.

#include <iostream>
#include <GL/glut.h> // OpenGL Utility Toolkit for rendering
#include <GL/glu.h>  // OpenGL Utility Library
#include <cmath>     // Math library for calculations

int xc, yc, r; // Global variables for circle center and radius

using namespace std;

// Function to draw a circle using Bresenham's Circle Drawing Algorithm
void circle(int r) {
    int d, x, y;
    d = 3 - 2 * r; // Initial decision parameter
    x = 0;
    y = r;

    do {
        glBegin(GL_POINTS); // Start drawing points
        // Plot the eight symmetric points
        glVertex2d(x + xc, y + yc);
        glVertex2d(y + xc, x + yc);
        glVertex2d(-x + xc, y + yc);
        glVertex2d(-y + xc, x + yc);
        glVertex2d(-x + xc, -y + yc);
        glVertex2d(-y + xc, -x + yc);
        glVertex2d(x + xc, -y + yc);
        glVertex2d(y + xc, -x + yc);
        glEnd();

        // Update decision parameter and coordinates
        if (d < 0) {
            d = d + 4 * x + 6;
        } else {
            d = d + 4 * (x - y) + 10;
            y -= 1;
        }

        x += 1;
    } while (x <= y);
}

// Function to clear the screen and draw the circle
void Draw() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
    circle(r);                     // Draw the circle
    glFlush();                     // Render all graphics to the screen
}

// Main function to initialize and start the OpenGL program
int main(int argc, char** argv) {
    cout << "Enter the Coordinates of the Center" << endl;
    cin >> xc >> yc;

    cout << "Enter the Radius of the Circle" << endl;
    cin >> r;

    // Initialize GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Circle Drawing using Bresenham's Algorithm");

    // Set background and drawing colors
    glClearColor(1.0, 1.0, 1.0, 0.0); // White background
    glColor3f(0.0, 0.0, 0.0);         // Black color for points
    gluOrtho2D(0, 640, 0, 480);       // Set coordinate system

    // Register the display callback function
    glutDisplayFunc(Draw);
    glutMainLoop(); // Enter the main event loop

    return 0;
}
```

- The code implements Bresenham's Circle Drawing Algorithm to render a circle based on a user-defined center point and radius.
- It incrementally calculates pixel coordinates, efficiently approximating the circle using integer operations.
- Symmetry is utilized to plot points in each octant, reducing computation while maintaining accuracy.
- The design emphasizes precision and performance, making it ideal for applications requiring efficient circular rendering.
