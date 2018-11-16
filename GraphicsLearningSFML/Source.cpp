#include <iostream>
#include "SFML\Graphics.hpp"

using namespace std;

void test();

int main()
{
	test();
	return 0;
}

void test()
{
	sf::CircleShape circle(40);
	circle.setFillColor(sf::Color::Magenta);
	//circle.setPosition(20, 20);
	//circle.setPointCount(300);
	sf::RectangleShape rect(sf::Vector2f(80, 80));
	//rect.setSize(80)
	sf::Font font;
	if (!font.loadFromFile("OpenSans-Regular.ttf"))
	{
		cout << "Error loading file\n";
	}
	sf::Text text;
	text.setFont(font);
	text.setString("Testing");
	//text.setColor(sf::Color::Blue);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Blue);
	sf::Vertex line1[] =
	{
		sf::Vertex(sf::Vector2f(25, 20)),
		sf::Vertex(sf::Vector2f(400, 100))
	};

	sf::Vertex line2[] =
	{
		sf::Vertex(sf::Vector2f(25, 20)),
		sf::Vertex(sf::Vector2f(400, 100))
	};

	sf::RenderWindow window(sf::VideoMode(600, 600), "Trying");
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
		window.draw(line1, 2, sf::Lines);
		window.draw(line2, 2, sf::Lines);
		window.display();
	}
}