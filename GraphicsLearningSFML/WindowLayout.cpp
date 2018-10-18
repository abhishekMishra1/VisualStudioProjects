#include "WindowLayout.h"
#include "Constants.h"
#include <iostream>
using namespace std;

using namespace GraphicalTree;
WindowLayout::WindowLayout()
{
	sf::Vector2u vec(WindowHeight, WindowBreadth);
	m_WindowHeight = WindowHeight;
	m_WindowBreadth = WindowBreadth;
	m_window.setSize(vec);
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
		RenderShapes();
		m_window.display();
	}
}

void WindowLayout::RenderShapes()
{
	int nNodes = mvNodes.size();
	bool bResizingRequired = (ImgSquareSize*nNodes) > m_WindowHeight;
}

void WindowLayout::update()
{
	m_window.clear();
	m_window.display();

}