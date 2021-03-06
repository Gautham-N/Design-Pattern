// Proxy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

class DataFecher
{
public:
	virtual void Operation() const = 0;

};

class RealDataFecher:public DataFecher
{
public:
	void Operation() const override
	{
		//running query
		cout<< "Getting data...\n";
	}
};

class ProxyDataFecher:public DataFecher
{
private:
	RealDataFecher *rd;

	bool CheckAccess() const
	{
		cout << "Checking the Access \n";
		return true;
	}

	string Log() const
	{
		return "Logg 1";
	}
public:
	ProxyDataFecher(RealDataFecher *rd_) :rd(new RealDataFecher(*rd_))
	{
		
	}
	void Operation() const override
	{
		if (this->CheckAccess())
		{
			this->rd->Operation();
			cout<<this->Log()<<"\n";
		}
	}
};
int main()
{
	RealDataFecher *dt = new RealDataFecher();
	dt->Operation();
	cout << "Proxy \n";
	DataFecher *pt1 = new ProxyDataFecher(dt);
	pt1->Operation();

	return 0;
}


