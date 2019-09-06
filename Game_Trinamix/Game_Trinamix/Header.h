#pragma once
#include<chrono>
#include<iostream>
#include<string>

class Player
{
public:
	Player() :
		m_time(0)
	{}

	Player(std::chrono::milliseconds time, std::string name, unsigned life)
		:m_time(time)
		, m_PlayerName(name)
		, m_life(life)
	{}

	virtual ~Player() {}
	std::string GetName() const { return m_PlayerName; }

private:
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
	
protected:
	virtual void Attack(const Player&) = 0;
	std::chrono::milliseconds m_time;
	const std::string m_PlayerName;
	unsigned m_life;
};

class Hero :public Player
{
public:
	Hero():Player(){}
	~Hero() {}

protected:
	void Attack(const Player& monster) { std::cout << "Attacking monster " << monster.GetName() << "\n"; }

};

class Orc :public Player
{
public:
	Orc() :Player(1300, "Orc") {}

protected:
	void Attack(const Player& hero) { std::cout << "Attacking monster " << hero.GetName() << "\n"; }
};

class Dragon :public Player
{
public:
	Dragon() :Player(2500, "Dragon") {}

protected:
	void Attack(const Player& hero) { std::cout << "Attacking monster " << hero.GetName() << "\n"; }
};