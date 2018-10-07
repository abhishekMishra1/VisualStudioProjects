#include "WindowLayout.h"
#include <iostream>
using namespace std;

using namespace GraphicsLayout;
WindowLayout::WindowLayout()
{

}

WindowLayout::~WindowLayout()
{

}


void WindowLayout::getWindowSize(int& length, int& breadth)
{
	sf::Vector2u dimension = m_window.getSize();
	length = dimension.x;
	breadth = dimension.y;
}

void WindowLayout::setWindowSize(int length, int width)
{
	sf::Vector2u dimension(length, width);
	m_window.setSize(dimension);
}

void WindowLayout::LaunchGraphicalTree()
{
	sf::Vector2u dimension = m_window.getSize();
	if(dimension.x + dimension.y <= 0)
	{ 
		cout << "Window is not initialized!!";
		return;
	}

	while (m_window.isOpen())
	{

		sf::Event event;
		while (m_window.pollEvent(event))
	{
			switch (event.type)
			{
				case sf::Event::Closed:
					m_window.close();
					break;
			}


		}

		m_window.clear();
		m_window.display();
	}
}

void WindowLayout::update()
{
	m_window.clear();
	m_window.display();

}