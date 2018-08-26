#pragma once
#include <vector>
#include <string>
#include <initializer_list>

class C11Concepts
{
public:
	C11Concepts();
	~C11Concepts();
	C11Concepts(const std::initializer_list<int>& v);
	//INITIALIZER'S LIST
private:
	std::vector<int> vInt;
};

class AggregateInit
{
public:
	int age;
	std::string name;
};

class dog
{
public:
	int age;
	std::string name;

public:
	dog(const std::initializer_list<int>& v)
	{
		age = *(v.begin());
		name = *(v.begin());
	}

	//dog(int a)
	//{
	//	age = a;
	//}
};


class delegatingCtor
{
	int a = 10;
public:
	delegatingCtor(int v);
	delegatingCtor();

};