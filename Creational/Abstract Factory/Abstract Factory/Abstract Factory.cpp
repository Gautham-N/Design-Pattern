// Abstract Factory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

/*
  Each distinct product of a product family should have a base interface. All
  variants of the product must implement this interface.
 */
class ProductA
{
public:
	virtual string BuildProduct() const=0;
};

class ConcreteProA1:public ProductA
{
public:
	string BuildProduct() const override
	{
		return"Building Product A1";
	}

};

class ConcreteProA2 :public ProductA
{
public:
	string BuildProduct() const override
	{
		return"Building Product A2";
	}

};


class ProductB
{
public:
	virtual string BuildProduct() const = 0;

	/*
     ...but it also can collaborate with the ProductA.
   
     The Abstract Factory makes sure that all products it creates are of the
     same variant and thus, compatible.
   */
	virtual string Collabrate(const ProductA &colb) const = 0;
};

class ConcreteProB1 :public ProductB
{
public:
	string BuildProduct() const override
	{
		return"Building Product B1";
	}

	string Collabrate(const ProductA &colb) const override
	{
		return"Building Product B1 and collabrating with " + colb.BuildProduct();
	}

};

class ConcreteProB2 :public ProductB
{
public:
	string BuildProduct() const override
	{
		return"Building Product B2";
	}

	string Collabrate(const ProductA &colb) const override
	{
		return"Building Product B2 and collabrating with " + colb.BuildProduct();
	}
};

/*
  The Abstract Factory interface declares a set of methods that return
  different abstract products. These products are called a family and are
  related by a high-level theme or concept. Products of one family are usually
  able to collaborate among themselves. A family of products may have several
  variants, but the products of one variant are incompatible with products of
  another.
 */
class AbstractFactory
{
public:
	virtual ProductA *CreateProA() const = 0;
	virtual ProductB *CreateProB() const = 0;
};

class Factory1 :public AbstractFactory
{
public:

	ProductA *CreateProA() const override
	{
		return new ConcreteProA1;
	}

	ProductB *CreateProB() const override
	{
		return new ConcreteProB1;
	}
};

class Factory2 :public AbstractFactory
{
public:

	ProductA *CreateProA() const override
	{
		return new ConcreteProA2;
	}

	ProductB *CreateProB() const override
	{
		return new ConcreteProB2;
	}
};

int main()
{
	cout << "Client testing with first Factory" << "\n";
	AbstractFactory *F1 = new Factory1();
	const ProductA *ProA1 = F1->CreateProA();
	const ProductB *ProB1 = F1->CreateProB();
    cout<<ProB1->BuildProduct()<<"\n";
	cout << ProB1->Collabrate(*ProA1) << "\n";
	delete F1;
	delete ProA1;
	delete ProB1;
	cout << "\n";
	cout << "Client testing with Second Factory" << "\n";
	AbstractFactory *F2 = new Factory2();
	const ProductA *ProA2 = F2->CreateProA();
	const ProductB *ProB2 = F2->CreateProB();
	cout << ProB2->BuildProduct() << "\n";
	cout << ProB2->Collabrate(*ProA2) << "\n";
	delete F2;
	delete ProA2;
	delete ProB2;
	return 0;
}


