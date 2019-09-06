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
	mvNodes.push_back(NodeLayout(m_WindowHeight, m_WindowHeight));
	m_pWindow = new sf::RenderWindow(sf::VideoMode(WindowHeight, WindowBreadth), "Graphical Nodes");
}

WindowLayout::~WindowLayout()
{

}


void WindowLayout::getWindowSize(int& length, int& breadth)
{
	sf::Vector2u dimension = m_pWindow->getSize();
	length = dimension.x;
	breadth = dimension.y;
}

void WindowLayout::setWindowSize(int length, int width)
{
	sf::Vector2u dimension(length, width);
	m_pWindow->setSize(dimension);
}

void WindowLayout::LaunchGraphicalTree()
{
	sf::Vector2u dimension = m_pWindow->getSize();
	if (dimension.x + dimension.y <= 0)	//This check fails to work if the window has still not been drawn
	{
		cout << "Window is not initialized!!";
		return;
	}

	while (m_pWindow->isOpen())
	{

		sf::Event event;
		while (m_pWindow->pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_pWindow->close();
				break;
			}
		}

		m_pWindow->clear();
		RenderShapes();
		m_pWindow->display();

	}

}

void WindowLayout::RenderShapes()
{
	int nNodes = mvNodes.size();
	bool bResizingRequired = (ImgSquareSize*nNodes) > m_WindowHeight;
	
	for (auto nodes : mvNodes)
		nodes.DrawNode(*m_pWindow);
}

void WindowLayout::update()
{
	m_pWindow->clear();
	m_pWindow->display();

}

#ifdef DEBUG
void WindowLayout::SetNumOfNodes(int n)
{

}
#endif // DEBUG
