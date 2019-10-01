#include "Graphics.hpp"
#include <iostream>

Celestia::Graphics::Graphics (int h, int w) {
    height = h;
    width = w;
}

void Celestia::Graphics::init (int argc, char **argv, std::vector <Celestia::Body> bodies) {
    glutInit(&argc, argv);
    glutInitWindowSize (width, height);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	Celestia::Graphics::bodies = bodies;
}

void Celestia::Graphics::create () {
    glutCreateWindow("n body");
}

void Celestia::Graphics::draw () {
    glPointSize(1.0f);
    glBegin(GL_POINTS);
    for (auto it = bodies.begin(); it != bodies.end(); it++)
    {
        glColor3f(0.3, 0.3, 0.3);
		glPointSize(Celestia::Graphics::bodies.size());
        glVertex3f(it->position[0], it->position[1], it->position[2]);
    }

	std::cout<< "Draw is called";
    glEnd();
	glFlush();
}

void Celestia::Graphics::display () {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//	Funtion pointer and it's use
//	void (Celestia::Graphics::* drw) (void);
//	drw = &Celestia::Graphics::draw;
	Celestia::Graphics graphic;
//	(graphic.*dis)();
//	or
//	Celestia::Graphic *graphix = &graphic;
//	(graphix->*dis)();

	std::cout<< "Display is called";
	draw();
//	graphic.draw();
}

//Trampoline function for staticing a non-static function call
extern "C" void display_callback() {
	Celestia::Graphics *graphic;
	return graphic->display();
}

void Celestia::Graphics::update () {
//	std::cout<< "Update is called" << std::endl;
	glutDisplayFunc(display_callback);
}