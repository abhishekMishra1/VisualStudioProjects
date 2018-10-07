#pragma once
#include"NodeLayout.h"
#include <vector>

namespace GraphicsLayout
{
	class WindowLayout
	{
	public:
		void getWindowSize(int& length, int& breadth);
		void setWindowSize(int length, int breadth);
		void LaunchGraphicalTree();
		WindowLayout();
		~WindowLayout();
		void update();
	protected:
		sf::RenderWindow m_window;
		std::vector<GraphicsNodeLayout::NodeLayout> mvNodes;
	};
}