// Facade.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include <unordered_map>
using namespace std;

class subsystem1
{
public:
	string Operation()
	{
		return"Subsystem1 is initialized /n";
	}
	string Start()
	{
		return "Operation running /n";
	}
};
class subsystem2
{
public:
	string Operation()
	{
		return"Subsystem1 is initialized /n";
	}
	string Finish()
	{
		return "Operation ended /n";
	}
};

class Face
{
protected:
	subsystem1 *sub1_;
	subsystem2 *sub2_;
public:
	Face(subsystem1 *sub1 = nullptr, subsystem2 *sub2 = nullptr)
	{
		this->sub1_ = new  subsystem1();
		this->sub2_ = new subsystem2();
	}

	string CreateOperation(Face *fc)
	{
		string Result;
		Result+= "Initializing :/n";
		Result += this->sub1_->Operation();
		Result += this->sub2_->Operation();
		cout << ":/n";
		Result += this->sub1_->Start();
		Result += this->sub2_->Finish();
		return Result;
	}
};
int main()
{
	subsystem1 *s1 = new subsystem1();
	subsystem2 *s2 = new subsystem2();
	Face *fa=new Face(s1,s2);
	cout<<fa->CreateOperation(fa);
   
	return 0;
}


