// Visitor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<array>
using namespace std;

class ConcreateComponentA;
class ConcreateComponentB;

class Visitor
{
public:
	virtual void VistConcreateComponentA(const ConcreateComponentA* element)const=0 ;
	virtual void VistConcreateComponentB(const ConcreateComponentB* element) const = 0;
};

class Component
{
public:
	virtual void Accept(Visitor* vs) const = 0;
};

class ConcreateComponentA:public Component
{
public:
	void Accept(Visitor* vs)const override
	{
		vs->VistConcreateComponentA(this);
	}
	string CCA() const
	{
		return "A";
	}
};

class ConcreateComponentB :public Component
{
public:
	void Accept(Visitor* vs)const override
	{
		vs->VistConcreateComponentB(this);
	}

	string CCB() const
	{
		return "B";
	}
};

class component1 :public Visitor
{
public:
	void VistConcreateComponentA(const ConcreateComponentA* element)const override
	{
		cout << element->CCA() << "visitor1 /n";
	}
	void VistConcreateComponentB(const ConcreateComponentB* element) const override
	{
		cout << element->CCB() << "visitor1 /n";
	}
};

class component2 :public Visitor
{
public:
	void VistConcreateComponentA(const ConcreateComponentA* element)const override
	{
		cout << element->CCA() << "visitor2 /n";
	}
	void VistConcreateComponentB(const ConcreateComponentB* element) const override
	{
		cout << element->CCB() << "visitor2 /n";
	}
};

void call(std::array<const Component *, 2> cmps,Visitor *v)
{
	for (const Component *c : cmps)
	{
		c->Accept(v);
	}
}
int main()
{
	std::array<const Component *,2> components = { new ConcreateComponentA, new ConcreateComponentB };
	component1 *c1 = new component1();
	call(components, c1);
	cout << "/n";
	component2 *c2 = new component2();
	call(components, c2);
	return 0;
}


