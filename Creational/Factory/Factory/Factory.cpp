// Factory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

/*
  The Product interface declares the operations that all concrete products must
  implement.
 */
class Product
{
public:
	virtual string doSomeOperation()const = 0;
};

class ProductA:public Product
{
public:
	string doSomeOperation() const override
	{
		return "Product A is Ready";
	}

};

class ProductB :public Product
{
public:
	string doSomeOperation() const override
	{
		return "Product B is Ready";
	}

};

/*
  The Creator class declares the factory method that is supposed to return an
  object of a Product class. The Creator's subclasses usually provide the
  implementation of this method.
 */

class Creator
{
public:
	virtual Product *FactoryMethod() const = 0;

	/*
    Also note that, despite its name, the Creator's primary responsibility is
    not creating products. Usually, it contains some core business logic that
    relies on Product objects, returned by the factory method. Subclasses can
    indirectly change that business logic by overriding the factory method and
    returning a different type of product from it.
   */


	string Operation() const
	{
		Product *pro= this->FactoryMethod();

		string result= "Creater called for product-" + pro->doSomeOperation();
		delete pro;
		return result;
	}
};

class Creator1:public Creator
{
public:
	Product *FactoryMethod() const override
	{
		return new ProductA();
	}
};

class Creator2 :public Creator
{
public:
	Product *FactoryMethod() const override
	{
		return new ProductB();
	}
};

int main()
{
	Creator *Cr1 = new Creator1();
	cout<<Cr1->Operation()<<"\n";

	Creator *Cr2 = new Creator2();
	cout << Cr2->Operation() << "\n";

	delete Cr1;
	delete Cr2;

	return 0;
}

