#include "BinarySearchTree.h"
#include "GameConstants.h"
#include <iostream>
#include <string>
#include "../SFML/include/SFML/Graphics.hpp"

using namespace std;

int main()
{
	//sf::RenderWindow window(sf::VideoMode(600,400), "Trying SFML");
	//sf::Texture texture;
	//if (!texture.loadFromFile("test.png"))
	//{
	//	cout << "Failed to load image from file\n";
	//}


	//sf::Sprite sprite(texture);

	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		switch (event.type)
	//		{
	//		case sf::Event::Closed:
	//			window.close();
	//			break;
	//		
	//			case sf::Event::Resized:
	//			std::cout << "Resized dimensions are WxH : " << event.size.width << "x" << event.size.height << endl;
	//			break;
	//		
	//			case sf::Event::LostFocus:
	//				std::cout << "Lost focus\n";
	//				break;

	//			case sf::Event::GainedFocus:
	//				std::cout << "Gained focus\n";
	//				break;

	//		default:
	//			break;
	//		}
	//	}

	//	window.clear();
	//	window.draw(sprite);
	//	window.display();
	//}

	//BinarySearchTree b;
	//b.Insert(4);
	//b.Insert(5);
	//b.Insert(4456);
	//b.Insert(5);
	//b.Insert(8);
	//b.Insert(13);
	//b.Insert(4432);
	//b.Insert(513);
	//b.Insert(63);
	//b.Insert(4);
	//b.Insert(1);
	//b.Insert(313);
	//b.Insert(154);
	//b.Insert(3);

	//cout << "Depth of tree is " << b.GetDepth() << endl;
	//cout << "Pre-Order  :";
	//b.TraverseTree(Trees::PREORDER);
	//cout << "\nIn-Order   :";
	//b.TraverseTree(Trees::INORDER);
	//cout << "\nPost-Order :";
	//b.TraverseTree(Trees::POSTORDER);
	//cout << endl;



	//Testing Generic BST
	string SampleString = "1 + 3 / 1 - ( 3 + 3 ) * ( 4 / 9)";
	GenericBST<char> gBST;
	gBST.InsertString(SampleString);
	gBST.TraverseTree(Trees::PREORDER);
	return 0;
}

#if 0
			case sf::Event::KeyPressed:
				cout << "Key pressed\n";
				break;

			case sf::Event::KeyReleased:
				cout << "Key released\n";
				break;

			case sf::Event::MouseButtonPressed:
				cout << "Mouse button pressed";
				switch (event.key.code)
				{
				case sf::Mouse::Left:
					cout << " Left\n";
					break;

				case sf::Mouse::Right:
					cout << " Right\n";
					break;

				case sf::Mouse::Middle:
					cout << " Middle\n";
					break;

				}
				break;

			case sf::Event::MouseButtonReleased:
				cout << "Mouse button released";
				switch (event.key.code)
				{
				case sf::Mouse::Left:
					cout << " Left\n";
					break;

				case sf::Mouse::Right:
					cout << " Right\n";
					break;

				case sf::Mouse::Middle:
					cout << " Middle\n";
					break;

				}
				break;

			case sf::Event::MouseEntered:
				cout << "Mouse entered\n";
				break;

			case sf::Event::MouseWheelMoved:
				cout << "Mouse wheel moved\n";
				break;

			case sf::Event::MouseMoved:
				cout << "Mouse moved. ";
				cout << "Coordinates are (" << event.mouseMove.x << "," << event.mouseMove.y << ")\n";
				break;

#endif