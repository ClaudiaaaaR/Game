// Projekt.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

const int WIN_SIZE_X = 640;
const int WIN_SIZE_Y = 480;
int x = 0;
bool space;
double winkel;

class GameWindow : public Gosu::Window {
public:
	double x, y;
	Gosu::Color c1,c2,c3;
	Gosu::Image bild;
	GameWindow()
		: Window(WIN_SIZE_X, WIN_SIZE_Y), bild("einhorn.png")	{
		set_caption("Masterplan");	}
		
	void update() override {
		x = input().mouse_x();
		y = input().mouse_y();
		space = input().down(Gosu::KB_SPACE);
		if(space)
		{
			c1=Gosu::Color::FUCHSIA;
			c2 = Gosu::Color::AQUA;
			c3 = Gosu::Color::WHITE;
		}
		else
		{
			c1=Gosu::Color::BLACK;
			c2= Gosu::Color::BLACK;
			c3= Gosu::Color::BLACK;
		}
		if (input().down(Gosu::MS_LEFT)) { winkel = winkel + 5; }
		if (input().down(Gosu::MS_RIGHT)) { winkel = winkel - 5; }
	} 
	void draw() override {
		//Gosu::Graphics::draw_line(x, 20, Gosu::Color::GREEN, 200, x, Gosu::Color::GREEN, 0.0);
		Gosu::Graphics::draw_triangle(
		640, 240, c1,
		0, 480, c2,
		0,0, c3,
		0.0);
		///TESTTESTTES
		bild.draw_rot(x, y, 0.0,winkel);
		
	}
};

int main()
{
	GameWindow window;
	window.show();

    return 0;
}

