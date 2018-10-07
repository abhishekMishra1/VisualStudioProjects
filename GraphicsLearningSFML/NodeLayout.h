#pragma once
#include "SFML\Graphics.hpp"

namespace GraphicsNodeLayout
{


	class NodeLayout
	{
	public:
		NodeLayout(int windowLength, int windowHeigth);

		~NodeLayout();
	protected:
		NodeLayout();

	protected:
		struct windowDimensions
		{
			int m_Length;
			int m_width;
		};
		enum LinePosition
		{
			START,
			END
		};

		sf::Font m_font;
		sf::Text m_text;
		sf::CircleShape m_circle;
		sf::Vertex m_LeftConnector[2];
		sf::Vertex m_RightConnector[2];
		float m_radius;
		float m_lineLength;
		windowDimensions m_WindowSize;
	};
}