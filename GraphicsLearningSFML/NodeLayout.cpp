#include "NodeLayout.h"

using namespace GraphicalTree;

NodeLayout::NodeLayout()
{
	m_font.loadFromFile("OpenSans-Regular.ttf");
	m_text.setFont(m_font);

	m_radius = 2 * m_WindowSize.m_Length / (15 * 4);
	m_circle.setRadius(m_radius);
	sf::Vector2f center = m_circle.getPosition();

	m_LeftConnector[START].position.x = center.x;
	m_LeftConnector[START].position.y = center.y;
	m_RightConnector[START].position.x = center.x;
	m_RightConnector[START].position.y = center.y;

}

NodeLayout::~NodeLayout()
{

}

NodeLayout::NodeLayout(int windowLength, int windowHeight)
{
	m_WindowSize.m_Length = windowLength;
	m_WindowSize.m_width = windowHeight;
	NodeLayout();
}