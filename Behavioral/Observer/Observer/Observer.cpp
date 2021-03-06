// Observer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<list>
using namespace std;
class IObserver
{
public:
	virtual ~IObserver() {};
	virtual void Update(string st)const = 0;

};

class ISubject
{
public:
	virtual ~ISubject() {};
	virtual void Attach(IObserver* ob)  = 0;
	

	virtual void Dettach(IObserver* ob)  = 0;
	

	virtual void notify(string message) = 0;
	
};



class Subject:public ISubject
{
public :
	virtual ~Subject()
	{
		cout << "I was a subject";
	}

	void Attach(IObserver* ob) override
	{
		ls.push_back(ob);
	}

	void Dettach(IObserver* ob) override
	{
		ls.remove(ob);
	}

	void notify(string message) override
	{
		list<IObserver*>::iterator it = ls.begin();
		while (it!=ls.end())
		{
			(*it)->Update(message);
			++it;
		}
	}

private:
	list<IObserver*> ls;
};

class Observer :public IObserver
{
public:
	Observer(Subject& sb_) :sb(sb_)
	{
		this->sb.Attach(this);
		++Observer::count;
		num = count;
	}
	void Update(const string mess)const override
	{
		cout << mess << this->num;
	}
	void remove()
	{
		this->sb.Dettach(this);
	}
private:
	Subject &sb;
	static int count;
	int num;
};
int Observer::count = 0;
int main()
{
	Subject *s = new Subject();
	Observer *b = new Observer(*s);
	Observer *b1 = new Observer(*s);
	b->remove();
	s->notify("new product");
	return 0;
}

