#pragma once
#include"NodeLayout.h"
#include <vector>

namespace GraphicalTree
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
		void RenderShapes();
	protected:
		sf::RenderWindow m_window;
		int m_WindowHeight;
		int m_WindowBreadth;
		std::vector<GraphicalTree::NodeLayout> mvNodes;
	};
}