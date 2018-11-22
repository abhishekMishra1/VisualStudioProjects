#pragma once
#include "SFML\Graphics.hpp"

namespace GraphicalTree
{


	class NodeLayout
	{
	public:
		NodeLayout(int windowLength, int windowHeigth);

		~NodeLayout();
		void DrawNode(sf::RenderWindow& window);

	protected:
		NodeLayout();
		NodeLayout(int windowLength, int windowHeigth, int Circleoffset);
		void createNodes();

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
