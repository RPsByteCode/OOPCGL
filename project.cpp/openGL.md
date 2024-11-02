To build a 2D and 3D animator using OpenGL, you’ll need several functions to handle the transformations (translate, rotate, scale) and rendering for both 2D and 3D shapes. Here’s a list of key OpenGL functions that would be essential for implementing your animator:

### 1. **Initialize OpenGL**
   - `glutInit()`: Initializes the GLUT library.
   - `glutInitDisplayMode()`: Sets the initial display mode (e.g., RGB color, double-buffering).
   - `glutCreateWindow()`: Creates a window for rendering.
   - `glutDisplayFunc()`: Sets the display callback for rendering the shapes.

### 2. **Setting Up 2D and 3D Views**
   - `glMatrixMode(GL_PROJECTION)`: Sets the current matrix to projection matrix, which determines how objects are projected onto the screen.
   - `glLoadIdentity()`: Resets the current matrix to the identity matrix, which is a standard starting point for transformations.
   - `glOrtho(left, right, bottom, top, near, far)`: Defines a 2D orthographic projection matrix.
   - `gluPerspective(fov, aspect, near, far)`: Defines a perspective projection matrix for 3D transformations.

### 3. **Transformations**
   - **Translation**
     - `glTranslatef(x, y, z)`: Moves (translates) objects along the x, y, and z axes.
   
   - **Rotation**
     - `glRotatef(angle, x, y, z)`: Rotates objects by a specified angle around the axis defined by the (x, y, z) vector.
   
   - **Scaling**
     - `glScalef(x, y, z)`: Scales objects by given factors along the x, y, and z axes.

### 4. **Drawing Shapes**
   - **Square**
     - `glBegin(GL_QUADS)`: Begins defining a quadrilateral shape (4-sided polygon).
     - `glVertex2f(x, y)`: Specifies each vertex for the square in 2D space.
   
   - **Triangle**
     - `glBegin(GL_TRIANGLES)`: Begins defining a triangle shape.
     - `glVertex2f(x, y)`: Specifies each vertex for the triangle in 2D space.
   
   - **Circle**
     - `glBegin(GL_POLYGON)`: Begins defining a circle as a polygon with multiple vertices.
     - `glVertex2f(x, y)`: Specifies vertices for the circle, calculated as points along its circumference.

### 5. **3D Transformation Setup**
   - `glEnable(GL_DEPTH_TEST)`: Enables depth testing for 3D shapes, allowing proper rendering of objects at different depths.
   - `glutSwapBuffers()`: Swaps the front and back buffers if using double-buffering (for smoother rendering).

### 6. **Clearing and Refreshing the Screen**
   - `glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)`: Clears the screen and the depth buffer for each frame.
   - `glFlush()`: Ensures that all OpenGL commands are executed.
   - `glutPostRedisplay()`: Marks the current window as needing to be redisplayed, which helps refresh the screen in animations.

### 7. **Handling User Input (Optional)**
   - `glutKeyboardFunc()`: Defines the callback function for handling keyboard input.
   - `glutMouseFunc()`: Sets the callback function for mouse input, useful for rotating or moving shapes interactively.

By combining these functions, you can set up an environment where the user can select each shape, apply translations, rotations, and scaling in 2D or 3D space, and carry out 3D perspective transformations to view the shapes from different angles.