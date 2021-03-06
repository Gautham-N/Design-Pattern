// Protype.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<thread>
#include<string>
#include <unordered_map>
using namespace std;

enum shptype
{
	shape1,
	shape2
};

class shape
{
protected:
	string ShapeName;
	float Area;
public:
	shape();
	shape(string SpName) :ShapeName(SpName)
	{

	}
	virtual shape *clone() const = 0;
	virtual void metod(float AreaValue)
	{
		this->Area = AreaValue;
		cout << "Prototype Name " << ShapeName << " Area of Prototype " << Area << "\n";
	}

};

class Cirlce :public shape
{
private:
	float CirArea;
public:

	Cirlce(string name, float area) :shape(name), CirArea(Area)
	{

	}
	shape *clone() const override
	{
		return new Cirlce(*this);
	}
};

class square :public shape
{
private:
	float SquArea;
public:

	square(string name, float area) :shape(name), SquArea(Area)
	{

	}
	shape *clone() const override
	{
		return new square(*this);
	}
};

class prototype_builder
{
private:
	unordered_map<shptype, shape*, hash<int>> protypes;
public:
	prototype_builder()
	{
		protypes[shptype::shape1] = new Cirlce("circle1", 50.f);
		protypes[shptype::shape2] = new square("square1", 30.f);
	}
	~prototype_builder()
	{
		delete protypes[shptype::shape1];
	}
	shape *createPrototype(shptype type)
	{
		return protypes[type]->clone();
	}
};
int main()
{
	prototype_builder pb;
	shape* sp = pb.createPrototype(shptype::shape1);
	sp->metod(50);

	shape* sp1 = pb.createPrototype(shptype::shape1);
	sp1->metod(30);

	shape* sp2 = pb.createPrototype(shptype::shape1);
	sp2->metod(20);

	shape* sq = pb.createPrototype(shptype::shape2);
	sq->metod(20);

	delete sp;
	delete sp1;
	delete sp2;

	return 0;
}


