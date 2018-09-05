/*
 * Types: 
 *  1. Unary operators
 *  2. Binary operators
 */


class TestOpOverload
{
	int x;
public:

	TestOpOverload() :x(0){}
	TestOpOverload(int val) :x(val){}
	
	//Unary operators
	TestOpOverload operator++()
	{
		++x;
		return *this;
	}

	TestOpOverload operator ++(int)
	{
		x++;
		return *this;
	}

	//Binary operator
	TestOpOverload operator + (const TestOpOverload& val)
	{
		TestOpOverload temp;
		temp.x = x + val.x;
		return temp;
	}

	int getValue() const
	{
		return x;
	}

	// Conversion operators
	operator float()
	{
		return static_cast<float>(x);
	}

	
	//Global operators
	friend TestOpOverload operator+(const TestOpOverload& obj1, const TestOpOverload& obj2);
};


TestOpOverload operator+(const TestOpOverload& obj1, const TestOpOverload& obj2)
{
	return TestOpOverload(obj1.x + obj2.x);
}

class TestOpOverload2
{
	int x;

public:
	TestOpOverload2(const TestOpOverload& obj)
	{
		x = obj.getValue();
	}
	TestOpOverload2():x(0){}

	operator float()
	{
		return x;
	}

	int getValue()
	{
		return x;
	}
};


class Test2
{
	int y;
};

class Test
{
	int x;
	Test2 t2;
public:
	operator Test2 ()  { return t2; }
	operator int() { return x; }
};

void fun(int x) { cout << "fun(int) called"; }
void fun(Test2 t) { cout << "fun(Test 2) called"; }