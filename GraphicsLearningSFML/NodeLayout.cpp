#include "NodeLayout.h"

using namespace GraphicalTree;

NodeLayout::NodeLayout()
{
	m_font.loadFromFile("OpenSans-Regular.ttf");
	m_text.setFont(m_font);

	m_radius = 2 * m_WindowSize.m_Length / (15 * 4);
	m_circle.setRadius(m_radius);
	sf::Vector2f center = m_circle.getPosition();

	m_LeftConnector[START] = sf::Vertex(sf::Vector2f(center.x, center.y), sf::Color::White);
	m_LeftConnector[END] = sf::Vertex(sf::Vector2f(center.x - 100, center.y + 100), sf::Color::Black);

	m_RightConnector[START] = sf::Vertex(sf::Vector2f(center.x, center.y), sf::Color::White);
	m_RightConnector[END] = sf::Vertex(sf::Vector2f(center.x + 100, center.y + 100), sf::Color::Black);
}

NodeLayout::~NodeLayout()
{

}

NodeLayout::NodeLayout(int windowLength, int windowHeight)
{
	m_WindowSize.m_Length = windowLength;
	m_WindowSize.m_width = windowHeight;
	
	m_radius = 2 * m_WindowSize.m_Length / (15 * 4);
	m_circle.setRadius(m_radius);

	m_circle.setPosition(sf::Vector2f(m_radius * 2, m_radius));
	sf::Vector2f center = m_circle.getPosition();
	m_circle.setFillColor(sf::Color::White);

	m_LeftConnector[START] = sf::Vertex(sf::Vector2f(center.x*2, center.y*2), sf::Color::Black);
	m_LeftConnector[END] = sf::Vertex(sf::Vector2f(center.x*2 - 100, center.y*2 + 100), sf::Color::White);

	m_RightConnector[START] = sf::Vertex(sf::Vector2f(center.x*2, center.y*2), sf::Color::Black);
	m_RightConnector[END] = sf::Vertex(sf::Vector2f(center.x*2 + 100, center.y*2 + 100), sf::Color::White);
}

NodeLayout::NodeLayout(int windowLength, int windowHeight, int circleOffset)
{
	m_WindowSize.m_Length = windowLength;
	m_WindowSize.m_width = windowHeight;

	m_radius = 2 * m_WindowSize.m_Length / (15 * 4);
	m_circle.setRadius(m_radius);
	m_circle.setPosition(sf::Vector2f(circleOffset*2, circleOffset*2));
	sf::Vector2f center = m_circle.getPosition();
	m_circle.setFillColor(sf::Color::White);

	m_LeftConnector[START] = sf::Vertex(sf::Vector2f(center.x, center.y), sf::Color::White);
	m_LeftConnector[END] = sf::Vertex(sf::Vector2f(center.x - 100, center.y + 100), sf::Color::Black);

	m_RightConnector[START] = sf::Vertex(sf::Vector2f(center.x, center.y), sf::Color::White);
	m_RightConnector[END] = sf::Vertex(sf::Vector2f(center.x + 100, center.y + 100), sf::Color::Black);
}

void NodeLayout::createNodes()
{}

void NodeLayout::DrawNode(sf::RenderWindow& window)
{
	window.draw(m_circle);
	window.draw(m_LeftConnector, 2, sf::Lines);
	window.draw(m_RightConnector, 2, sf::Lines);
}
