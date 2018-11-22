#include "SFML\Graphics.hpp"
#include"WindowLayout.h"
#include <iostream>

using namespace std;

void test(int repeatation);

int main()
{
	test(1);
	//GraphicalTree::WindowLayout window;
	//window.LaunchGraphicalTree();
	return 0;

}

void test(int repeatation)
{
	sf::CircleShape circle(30);
	circle.setFillColor(sf::Color::Black);
	//circle.setPointCount(300);
	circle.setPosition(20, 20);	//This gives the offset with the x and y coordinates, but not the center of radius
	//circle.setOrigin(-10, -10);//This gives the offset, but not the center of radius
	sf::RectangleShape rect(sf::Vector2f(100, 100));
	//rect.setSize(80);
	

	sf::Vertex line1[] =
	{
		sf::Vertex(sf::Vector2f(50, 50), sf::Color::White),
		sf::Vertex(sf::Vector2f(0, 100), sf::Color::Black)
	};
	
	sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f(50, 50), sf::Color::White),
		sf::Vertex(sf::Vector2f(100, 100), sf::Color::Black)
	};

	sf::CircleShape circle1(30);
	circle1.setFillColor(sf::Color::Black);
	//circle.setPointCount(300);
	circle1.setPosition(120, 20);	//This gives the offset with the x and y coordinates, but not the center of radius
								//circle.setOrigin(-10, -10);//This gives the offset, but not the center of radius
	sf::RectangleShape rect1(sf::Vector2f(100, 100));
	rect1.setPosition(100, 0);


	sf::Vertex line3[] =
	{
		sf::Vertex(sf::Vector2f(150, 50), sf::Color::White),
		sf::Vertex(sf::Vector2f(100, 100), sf::Color::Black)
	};

	sf::Vertex line4[] =
	{
		sf::Vertex(sf::Vector2f(150, 50), sf::Color::White),
		sf::Vertex(sf::Vector2f(200, 100), sf::Color::Black)
	};

	//if (repeatation)
	//{
	//	for (int i = 1; i < repeatation; ++i)
	//	{
	//		sf::CircleShape circle(30);
	//		circle.setPosition()
	//	}
	//}

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Nodes");
	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			default:
				break;

			}
		}

		window.clear();
		window.draw(rect);
		window.draw(circle);
		window.draw(line1, 2, sf::Lines);
		window.draw(line2, 2, sf::Lines);

		window.draw(rect1);
		window.draw(circle1);
		window.draw(line3, 2, sf::Lines);
		window.draw(line4, 2, sf::Lines);
		window.display();

	}

	//sf::Time t = sf::seconds(1.0f);
	//sf::sleep(t);
	//sf::Font font;
	//if (!font.loadFromFile("OpenSans-Regular.ttf"))
	//{
	//	cout << "Error loading file\n";
	//}
	//sf::Text text;
	//text.setFont(font);
	//text.setString("Testing");
	////text.setColor(sf::Color::Blue);
	//text.setCharacterSize(40);
	//text.setFillColor(sf::Color::Blue);

}
