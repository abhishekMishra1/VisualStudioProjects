#pragma once
#include "CommonTypes.h"
#include <string>

namespace ChessGame
{
	class ICharacters
	{
	protected:
		std::string m_Name;
		CharacterType m_Type;

	public:
		virtual void Move() = 0;
		const std::string GetName(const enum Characters& currChar)
		{
			std::string szCharName;
			switch (currChar)
			{	
			case Characters::CAMEL:
				szCharName = "camel";
				break;

			case Characters::ELEPHANT:
				szCharName = "elephant";
				break;

			case Characters::HORSE:
				szCharName = "horse";
				break;
				
			case Characters::KING:
				szCharName = "king";
				break;

			case Characters::QUEEN:
				szCharName = "queen";
				break;

			case Characters::SOLDIER:
				szCharName = "soldier";
				break;

			case Characters::INVALID:
			default:
				break;
			}

			return szCharName;
		}

		virtual void SetType(const CharacterType& type)
		{
			m_Type = type;
		}
		
		virtual const CharacterType& GetType()
		{
			return m_Type;
		}

	};
}