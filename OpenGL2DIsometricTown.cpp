#include <windows.h>  // for MS Windows
#include <GL/GLU.h>
#include <GL/glut.h>
#include <math.h>
struct Point
{
    int x, y;
};

void drawArc(Point center, GLfloat radius, GLfloat startingAngle, GLfloat endingAngle, GLfloat r,
             GLfloat g, GLfloat b)
{
    const float Pi = 4*atan(1.0);
    Point prev, current;
    glColor3f(r,g,b);
    glBegin(GL_LINES);
    glVertex2f(center.x, center.y);
    glVertex2f(center.x + radius * cos((startingAngle * Pi)/180), center.y + radius *
               sin((startingAngle * Pi)/180));
    glEnd();
    for(GLfloat angle = (startingAngle * Pi)/180; angle <= (endingAngle * Pi)/180; angle += Pi/180)
    {
        current.x = center.x + radius * cos(angle);
        current.y = center.y + radius * sin(angle);
        if(angle != (startingAngle * Pi)/180 )
        {
            glBegin(GL_LINES);
            glVertex2f(prev.x, prev.y);
            glVertex2f(current.x, current.y);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex2f(center.x, center.y);
            glVertex2f(prev.x, prev.y);
            glVertex2f(current.x, current.y);
            glEnd();
            glFlush();
        }
        prev.x = current.x;
        prev.y = current.y;
    }
    glBegin(GL_LINES);
    glVertex2f(prev.x, prev.y);
    glVertex2f(center.x, center.y);
    glEnd();
}

void display() {
   glClearColor(0.184314f, 0.184314f, 0.309804f, 1.0f); //Sky background
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    //RECTANGLE glRecti(-50,-50,50,50);

   //--------------------------------------STARS -----------------------------
   //-------------------------------------------------------------------------
  /* glBegin(GL_POLYGON);
	  glColor3f(1.0f,1.0f,1.0f);
	  glVertex2f(0.5f,0.8f);
	  glVertex2f(0.3f,0.8f);
	  glVertex2f(0.4f,0.83f);
	 glEnd();*/

	 //------------------------------------MOON---------------------
	 //-------------------------------------------------------------
	 /*Point center;
	 center.x = -0.6f;
	 center.y = 0.8f;
	 GLfloat radius = 0.25;
	 drawArc(center, radius, 0, 360, 1, 1, 1);*/

	 glBegin(GL_POLYGON);
		glColor3f(0.98431363f,1.0f,.80784314f);
		glVertex2f(-.85f,.6f);
		glVertex2f(-.9f,.67f);
		glVertex2f(-.9f,.76f);
		glVertex2f(-.85f,.82f);
		glVertex2f(-.8f,.82f);
		glVertex2f(-.76f,.76f);
		glVertex2f(-.76f,.67f);
	glEnd();
	 //-----------------------------------------MOUNTAIN---------
	 //----------------------------------------------------------
	glLineWidth(2.0f);
	 glBegin(GL_POLYGON);
	  glColor3f(0.729f,0.729f,0.7348f);
	  glVertex2f(0.7f,0.9f);
	  glVertex2f(1.0f,0.2f);
	  glVertex2f(0.5f,0.2f);
	 glEnd();

	 
	 glBegin(GL_LINE_LOOP);
	  glColor3f(0.0f,0.0f,0.0f);
	  glVertex2f(0.7f,0.9f);
	  glVertex2f(1.0f,0.2f);
	  glVertex2f(0.5f,0.2f);
	 glEnd();

	  glBegin(GL_POLYGON);
	  glColor3f(1.0f,1.0f,1.0f);
	  glVertex2f(0.64f,0.8f);
	  glVertex2f(0.74f,0.8f);
	  glVertex2f(0.7f,0.9f);
	 glEnd();

	glBegin(GL_LINE_LOOP);
	  glColor3f(0.0f,0.0f,0.0f);
	  glVertex2f(0.64f,0.8f);
	  glVertex2f(0.74f,0.8f);
	  glVertex2f(0.7f,0.9f);
	 glEnd();
   //----------------------------------------Snow ground----------
	//------------------------------------------------------------
    glBegin(GL_QUADS);             
      glColor3f(1.0f, 1.0f, 0.9937f);
      glVertex2f(-1.0f, -1.0f);    // x, y
      glVertex2f(1.0f,-1.0f);
      glVertex2f( 1.0f,  0.2f);
      glVertex2f(-1.0f,  0.2f);
    glEnd();

	glBegin(GL_LINE_LOOP);             
      glColor3f(0.0f,0.0f,0.0f);
      glVertex2f(-1.0f, -1.0f);    // x, y
      glVertex2f(1.0f,-1.0f);
      glVertex2f( 1.0f,  0.2f);
      glVertex2f(-1.0f,  0.2f);
    glEnd();
	//-------------------------------------------------ROAD -------
	//------------------------------------------------------------
    glBegin(GL_QUADS);
      glColor3f(0.012f, 0.023f, 0.075f);
      glVertex2f(-1.0f, -0.7f);    // x, y
      glVertex2f(1.0f, -0.7f);
      glVertex2f( 1.0f,  -0.3f);
      glVertex2f(-1.5f,  -0.3f);
    glEnd();

	//-----------------------------------ROAD LINES-----------------
	//-------------------------------------------------------------
	
	glBegin(GL_LINE_STRIP);
		glColor3f(0.8f,0.498309f,0.196078f);
		glVertex2f(-1.0f,-0.5f);
		glVertex2f(-0.05f,-0.5f);
	glEnd();
 
	glBegin(GL_LINE_STRIP);
		glVertex2f(0.4f,-0.5f);
		glVertex2f(1.0f,-0.5f);
	glEnd();
 	

	//--------------------------------------House 1 ----------------
	//BASE

	glBegin(GL_POLYGON); 
		glColor3f(0.556863f,0.137255f,0.137255f);
		glVertex2f(-.95f,0.0f);
		glVertex2f(-.7,0.0f);
		glVertex2f(-.7f,.4f);
		//glVertex2f(-.85f,.5f);
		glVertex2f(-1.0f,.4f);
		//glVertex2f(-.95f,.2f);
	glEnd();
	//SIDE
	glBegin(GL_POLYGON);
		glColor3f(0.386863f,0.137255f,0.137255f);
		glVertex2f(-.7f,0.0f);
		glVertex2f(-.55f,.2f);
		glVertex2f(-.55f,.5f);
		glVertex2f(-.7f,.4f);
	glEnd();
	//roof side
	glBegin(GL_POLYGON);
		glColor3f(0.52f,0.37f,0.39f);
		glVertex2f(-.7f,.4f);
		glVertex2f(-.55f,.5f);
		glVertex2f(-.65f,.7f);
		glVertex2f(-.8f,.65f);
	glEnd();
	//roof front 
	glBegin(GL_POLYGON);	
		glVertex2f(-.8f,.65f);
		glVertex2f(-1.0f,.4f);
		glVertex2f(-.7f,.4f);
	glEnd();
	//DOOR
	glBegin(GL_POLYGON);
		glColor3f(0.52f,0.37f,0.39f);
		glVertex2f(-.85f,0.0f);
		glVertex2f(-.75f,0.0f);
		glVertex2f(-.75f,.15f);
		glVertex2f(-.85f,.15f);
	glEnd();
	//HOUSE WINDOW
	glBegin(GL_POLYGON);
		glColor3f(0.74902f,0.847059f,0.847059f);
		glVertex2f(-.9f,.2f);
		glVertex2f(-.95f,.2f);
		glVertex2f(-.95f,.28f);
		glVertex2f(-.9f,.28f);
	glEnd();
	//HOUSE OUTLINE
	glBegin(GL_LINE_LOOP); 
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(-.95f,0.0f);
		glVertex2f(-.7,0.0f);
		glVertex2f(-.7f,.4f);
		//glVertex2f(-.85f,.5f);
		glVertex2f(-1.0f,.4f);
		//glVertex2f(-.95f,.2f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(-.7f,0.0f);
		glVertex2f(-.55f,.2f);
		glVertex2f(-.55f,.5f);
		glVertex2f(-.7f,.4f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(-.7f,.4f);
		glVertex2f(-.55f,.5f);
		glVertex2f(-.65f,.7f);
		glVertex2f(-.8f,.65f);
	glEnd();
	glBegin(GL_LINE_LOOP);	
		glVertex2f(-.8f,.65f);
		glVertex2f(-1.0f,.4f);
		glVertex2f(-.7f,.4f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(-.85f,0.0f);
		glVertex2f(-.75f,0.0f);
		glVertex2f(-.75f,.15f);
		glVertex2f(-.85f,.15f);
	glEnd();
	glBegin(GL_LINE_LOOP);
				glVertex2f(-.9f,.2f);
		glVertex2f(-.95f,.2f);
		glVertex2f(-.95f,.28f);
		glVertex2f(-.9f,.28f);
	glEnd();
	glEnd();

	//---------------------------------------------- HOUSE 2 ------------------/
	//-------------------------------------------------------------------------/
	//FRONT
	glBegin(GL_POLYGON); 
		glColor3f(0.52f,0.37255f,0.26f);
		glVertex2f(-.6f,0.0f);
		glVertex2f(-.25f,0.0f);
		glVertex2f(-.25f,.3f);
		glVertex2f(-.6f,.3f);
	glEnd();

	//WINDOW
	glBegin(GL_POLYGON);
		glColor3f(0.74902f,0.847059f,0.847059f);
		glVertex2f(-.5f,.2f);
		glVertex2f(-.55f,.2f);
		glVertex2f(-.55f,.28f);
		glVertex2f(-.5f,.28f);
	glEnd();

	//WINDOW 2 
	glBegin(GL_POLYGON);
		glColor3f(0.74902f,0.847059f,0.847059f);
		glVertex2f(-.4f,.2f);
		glVertex2f(-.45f,.2f);
		glVertex2f(-.45f,.28f);
		glVertex2f(-.4f,.28f);
	glEnd();
	//door
	glBegin(GL_POLYGON);
		glColor3f(0.52f,0.37f,0.39f);
		glVertex2f(-.35f,0.0f);
		glVertex2f(-.25f,0.0f);
		glVertex2f(-.25f,.15f);
		glVertex2f(-.35f,.15f);
	glEnd();
	//SIDE
	glBegin(GL_POLYGON); 
		glColor3f(0.50f,0.35255f,0.21f);
		glVertex2f(-.25f,0.0f);
		glVertex2f(-.1f,.15f);
		glVertex2f(-.1f,.45f);
		glVertex2f(-.25f,.3f);
	glEnd();

	glBegin(GL_POLYGON); 
		glColor3f(0.32f,0.39f,0.39f);
		glVertex2f(-.25f,.3f);
		glVertex2f(-.1f,.45f);
		glVertex2f(-.15f,.5f);
		glVertex2f(-.2f,.47f);
		
	glEnd();
	//roof front
	glBegin(GL_POLYGON); 
		glColor3f(0.32f,0.39f,0.39f);
		glVertex2f(-.2f,.47f);
		glVertex2f(-.25f,.3f);
		glVertex2f(-.6f,.3f);
		glVertex2f(-.55f,.47f);
	glEnd();
	//HOUSE 2 OUTLINE
	glBegin(GL_LINE_LOOP); 
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(-.6f,0.0f);
		glVertex2f(-.25f,0.0f);
		glVertex2f(-.25f,.3f);
		glVertex2f(-.6f,.3f);
	glEnd();
	//DOOR OUTLINE
	glBegin(GL_LINE_LOOP);
		glVertex2f(-.35f,0.0f);
		glVertex2f(-.25f,0.0f);
		glVertex2f(-.25f,.15f);
		glVertex2f(-.35f,.15f);
	glEnd();
	//window outline
	glBegin(GL_LINE_LOOP);
		glVertex2f(-.5f,.2f);
		glVertex2f(-.55f,.2f);
		glVertex2f(-.55f,.28f);
		glVertex2f(-.5f,.28f);
	glEnd();

	//WINDOW 2 
	glBegin(GL_LINE_LOOP);
		glVertex2f(-.4f,.2f);
		glVertex2f(-.45f,.2f);
		glVertex2f(-.45f,.28f);
		glVertex2f(-.4f,.28f);
	glEnd();


	glBegin(GL_LINE_LOOP); 
		glVertex2f(-.25f,0.0f);
		glVertex2f(-.1f,.15f);
		glVertex2f(-.1f,.45f);
		glVertex2f(-.25f,.3f);
	glEnd();

	glBegin(GL_LINE_LOOP); 
		glVertex2f(-.25f,.3f);
		glVertex2f(-.1f,.45f);
		glVertex2f(-.15f,.5f);
		glVertex2f(-.2f,.47f);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(-.2f,.47f);
		glVertex2f(-.25f,.3f);
		glVertex2f(-.6f,.3f);
		glVertex2f(-.55f,.47f);
	glEnd();


	//---------------------------------FIRST TREE----------------
	//----------------------------------------------------------

	//BARK
	glBegin(GL_POLYGON);
		glColor3f(0.36f,0.25f,0.20f);
		glVertex2f(0.0f,0.0f);
		glVertex2f(0.0f,.1f);
		glVertex2f(-.08f,.1f);
		glVertex2f(-.08,0.0f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(0.0f,0.0f);
		glVertex2f(0.0f,.1f);
		glVertex2f(-.08f,.1f);
		glVertex2f(-.08,0.0f);
	glEnd();
	//
	
	//GREENS
	glBegin(GL_POLYGON);
		glColor3f(0.419608f,0.556863f,0.137255f);
		glVertex2f(-.18f,.1f);
		glVertex2f(-.1f,.19f);
		glVertex2f(0.0f,.19f);
		glVertex2f(0.08f,.1f);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(-.18f,.19f);
		glVertex2f(0.08f,.19f);
		glVertex2f(0.0f,.34f);
		glVertex2f(-.1f,.34f);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(-.18f,.34f);
		glVertex2f(.08f,.34f);
		glVertex2f(-0.05f,.6f);
	glEnd();
	//----------------------------------HOUSE 3-----------------------
	//----------------------------------------------------------------
	//HOUSE FRONT
	glBegin(GL_POLYGON);
		glColor3f(0.556863f,0.137255f,0.137255f);
		glVertex2f(.1f,0.0f);
		glVertex2f(.3f,0.0f);
		glVertex2f(.3f,.3f);
		glVertex2f(.1f,.3f);
	glEnd();
	//door
	glBegin(GL_POLYGON);
		glColor3f(0.36f,0.25f,0.20f);
		glVertex2f(.15f,0.0f);
		glVertex2f(.23f,0.0f);
		glVertex2f(.23f,.15f);
		glVertex2f(.15f,.15f);
	glEnd();
	//building
	glBegin(GL_POLYGON);
		glColor3f(0.556863f,0.137255f,0.137255f);
		glVertex2f(.3f,0.0f);
		glVertex2f(.3f,.7f);
		glVertex2f(.6f,.7f);
		glVertex2f(.6f,0.0f);
	glEnd();

	//WINDOW
	glBegin(GL_POLYGON);
		glColor3f(0.74902f,0.847059f,0.847059f);
		glVertex2f(.33f,.2f);
		glVertex2f(.38f,.2f);
		glVertex2f(.38f,.28f);
		glVertex2f(.33f,.28f);
	glEnd();
	//window 2
	glBegin(GL_POLYGON);
		glVertex2f(.43f,.2f);
		glVertex2f(.48f,.2f);
		glVertex2f(.48f,.28f);
		glVertex2f(.43f,.28f);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(.53f,.2f);
		glVertex2f(.58f,.2f);
		glVertex2f(.58f,.28f);
		glVertex2f(.53f,.28f);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(.33f,.4f);
		glVertex2f(.38f,.4f);
		glVertex2f(.38f,.56f);
		glVertex2f(.33f,.56f);
	glEnd();
	//window 2
	glBegin(GL_POLYGON);
		glVertex2f(.43f,.4f);
		glVertex2f(.48f,.4f);
		glVertex2f(.48f,.56f);
		glVertex2f(.43f,.56f);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(.53f,.4f);
		glVertex2f(.58f,.4f);
		glVertex2f(.58f,.56f);
		glVertex2f(.53f,.56f);
	glEnd();
	//bottom roof
	glBegin(GL_POLYGON);
		glColor3f(0.386863f,0.137255f,0.137255f);
		glVertex2f(.1f,.3f);
		glVertex2f(.2f,.4f);
		glVertex2f(.3f,.4f);
		glVertex2f(.3f,.3f);
	glEnd();
	//building side
	glBegin(GL_POLYGON);
		glVertex2f(.6f,0.0f);
		glVertex2f(.6f,.7f);
		glVertex2f(.68f,.8f);
		glVertex2f(.68f,.15f);
	glEnd();
	
	//Building Roof
	glBegin(GL_POLYGON);
		glVertex2f(.68,.8f);
		glVertex2f(.6f,.7f);
		glVertex2f(.3f,.7f);
		glVertex2f(.4f,.8f);
	glEnd();
	//--------------------------OUTLINE
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(.3f,0.0f);
		glVertex2f(.3f,.7f);
		glVertex2f(.6f,.7f);
		glVertex2f(.6f,0.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(.15f,0.0f);
		glVertex2f(.23f,0.0f);
		glVertex2f(.23f,.15f);
		glVertex2f(.15f,.15f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(.1f,.3f);
		glVertex2f(.2f,.4f);
		glVertex2f(.3f,.4f);
		glVertex2f(.3f,.3f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(.1f,0.0f);
		glVertex2f(.3f,0.0f);
		glVertex2f(.3f,.3f);
		glVertex2f(.1f,.3f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(.6f,0.0f);
		glVertex2f(.6f,.7f);
		glVertex2f(.68f,.8f);
		glVertex2f(.68f,.15f);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(.68,.8f);
		glVertex2f(.6f,.7f);
		glVertex2f(.3f,.7f);
		glVertex2f(.4f,.8f);
	glEnd();
	//window
		//window
	glBegin(GL_LINE_LOOP);
		glVertex2f(.33f,.2f);
		glVertex2f(.38f,.2f);
		glVertex2f(.38f,.28f);
		glVertex2f(.33f,.28f);
	glEnd();

	//window 2
	glBegin(GL_LINE_LOOP);
		glVertex2f(.43f,.2f);
		glVertex2f(.48f,.2f);
		glVertex2f(.48f,.28f);
		glVertex2f(.43f,.28f);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(.53f,.2f);
		glVertex2f(.58f,.2f);
		glVertex2f(.58f,.28f);
		glVertex2f(.53f,.28f);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(.33f,.4f);
		glVertex2f(.38f,.4f);
		glVertex2f(.38f,.56f);
		glVertex2f(.33f,.56f);
	glEnd();
	//window 2
	glBegin(GL_LINE_LOOP);
		glVertex2f(.43f,.4f);
		glVertex2f(.48f,.4f);
		glVertex2f(.48f,.56f);
		glVertex2f(.43f,.56f);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glVertex2f(.53f,.4f);
		glVertex2f(.58f,.4f);
		glVertex2f(.58f,.56f);
		glVertex2f(.53f,.56f);
	glEnd();

	//STREET LAMP
	glBegin(GL_POLYGON);
		glColor3f(0.1f,0.123f,0.1234f);
		glVertex2f(.7f,-.1f);
		glVertex2f(.72f,-.1f);
		glVertex2f(.72f,.35f);
		glVertex2f(.7f,.35f);
	glEnd();
	//LIGHT STAND
	glBegin(GL_POLYGON);
		glVertex2f(.7f,.35f);
		glVertex2f(.6f,.33f);
		glVertex2f(.59f,.38f);
		glVertex2f(.72f,.38f);
		glVertex2f(.72f,.35f);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.858824f,0.858824f,0.439216f);
		glVertex2f(.7f,.35f);
		glVertex2f(.6f,.35f);
		glVertex2f(.65f,.3f);
	glEnd();
	//BASE
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(.7f,-.1f);
		glVertex2f(.72f,-.1f);
		glVertex2f(.72f,.35f);
		glVertex2f(.7f,.35f);
	glEnd();
	//LIGHT STAND
	glBegin(GL_LINE_LOOP);
		glVertex2f(.7f,.35f);
		glVertex2f(.6f,.33f);
		glVertex2f(.59f,.38f);
		glVertex2f(.72f,.38f);
		glVertex2f(.72f,.35f);
	glEnd();
	glBegin(GL_LINE_LOOP);
		glVertex2f(.7f,.35f);
		glVertex2f(.6f,.35f);
		glVertex2f(.65f,.3f);
	glEnd();
	//--------------------------------------------- HOUSE 4 ----------
	//----------------------------------------------------------------

	glBegin(GL_POLYGON);
		glColor3f(0.52f,0.37255f,0.26f);
		glVertex2f(.85f,0.0f);
		glVertex2f(.85f,.6f);
		glVertex2f(1.0f,.6f);
		glVertex2f(1.0f,0.0f);
	glEnd();

	//outline
	
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex2f(.85f,0.0f);
		glVertex2f(.85f,.6f);
		glVertex2f(1.0f,.6f);
		glVertex2f(1.0f,0.0f);
	glEnd();

   glFlush();  // Render now
}
 
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
     glutInitWindowSize(800, 550);   // Set the window's initial width & height
   glutCreateWindow("Problem 1 - Basic"); // Create a window with the given title
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
 
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the event-processing loop*/
   return 0;
}