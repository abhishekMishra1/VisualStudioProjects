#pragma once
#include<ostream>

class Integer
{
public:
	Integer()
	{
		m_Data = 0;
	}

	Integer(int val) :m_Data(val) {}
	//Operator overloadings
	Integer& operator = (const Integer& val)
	{
		Integer temp;
		temp.m_Data = val.m_Data;
		return temp;
	}

	operator int()
	{
		return m_Data;
	}

	int m_Data;

	//friend std::ostream& operator<<(std::ostream& op, const Integer& val);
};

//std::ostream& operator<<(std::ostream& op, const Integer& val)
//{
//	op << val.m_Data;
//	return op;
//}