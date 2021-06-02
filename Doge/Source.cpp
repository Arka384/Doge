//will make this one in one file :-)
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

//Global constants
constexpr int window_width = 900;
constexpr int window_height = 800;
constexpr float pi = 3.14159;

//Player movement
float x = window_width / 2, y = window_height / 2;
float velocity_x = 0;
float velocity_y = 0;
float accleration_x = 0;
float accleration_y = 0;
float mx, my;

//Textures
Texture doge, cat;
Sprite Doge, Cat;

//Timing vars
Clock clk;
Time t;
double dt = 0;


//functions
void init_sprites(void);

void update_movements(void);



int main()
{
	RenderWindow window(VideoMode(window_width, window_height), "Doge", Style::Close);

	init_sprites();

	while (window.isOpen())
	{
		t = clk.restart();
		dt = t.asSeconds();

		Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (Keyboard::isKeyPressed(Keyboard::Escape))
					window.close();
			default:
				break;
			}
		}

		//updates
		mx = Mouse::getPosition(window).x;
		my = Mouse::getPosition(window).y;



		update_movements();
		Doge.setPosition(x, y);
		Cat.setPosition(mx, my);




		//renders
		window.clear();

		window.draw(Doge);
		window.draw(Cat);

		window.display();
	}
}

void init_sprites(void)
{
	doge.loadFromFile("Img/doge_2.jpg");
	doge.setSmooth(true);
	Doge.setTexture(doge);
	Doge.setScale(Vector2f(0.12, 0.12));
	Doge.setOrigin(Doge.getGlobalBounds().width / 2, Doge.getGlobalBounds().height / 2);

	cat.loadFromFile("Img/muffin_cat.png");
	cat.setSmooth(true);
	Cat.setTexture(cat);
	Cat.setScale(Vector2f(1, 1));
	Cat.setOrigin(Cat.getGlobalBounds().width / 2, Cat.getGlobalBounds().height / 2);
}

void update_movements(void)
{
	//updating positions
	//setting to rotation accordin to mouse position
	float dx = (x)-mx;
	float dy = y - my;
	float angle = atan2(dy, dx);
	angle = angle * (180 / pi);
	Doge.setRotation(angle + 180);

	//updation the velocity 
	velocity_x += accleration_x * dt;
	velocity_y += accleration_y * dt;
	x += velocity_x * dt;
	y += velocity_y * dt;

	float mx2 = mx - window_width / 2;
	float my2 = my - window_height / 2;
	velocity_x = mx2;
	velocity_y = my2;

}

