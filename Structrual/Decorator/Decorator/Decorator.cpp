// Decorator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;

class Notifier
{
public:
	virtual ~Notifier() {};
	virtual string SendNotification() const = 0;

};

class ConcreateNotifier:public Notifier
{
public:
	string SendNotification() const override
	{
		return "(Defualt SMS Message)";
	}
};

class Decorator:public Notifier
{
protected:
	Notifier *nt;

public:
	Decorator(Notifier *nt_) :nt(nt_)
	{

	}
	string SendNotification() const override
	{
		return this->nt->SendNotification();
	}

};

class SlackNotifier:public Decorator
{
public:
	SlackNotifier(Notifier *nt) :Decorator(nt)
	{

	}
	string SendNotification() const override
	{
		return "(Slack message"+Decorator::SendNotification()+")";
	}
};

class MailNotifier :public Decorator
{
public:
	MailNotifier(Notifier *nt) :Decorator(nt)
	{

	}
	string SendNotification() const override
	{
		return "(Mail message" + Decorator::SendNotification() + ")";
	}
};

int main()
{
	Notifier *n1 = new ConcreateNotifier();
	cout<<n1->SendNotification()<<"\n";
	Decorator *d1 = new SlackNotifier(n1);
	cout << d1->SendNotification() << "\n";
	Decorator *d2 = new MailNotifier(d1);
	cout << d2->SendNotification() << "\n";
	delete n1;
	delete d1;
	delete d2;
	return 0;
}


