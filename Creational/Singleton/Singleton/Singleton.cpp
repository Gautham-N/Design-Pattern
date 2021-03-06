// Singleton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<thread>
#include<chrono>
using namespace std;

class Singleton
{
	//constructed should be private or protected always
protected:
	Singleton(const string value):value_(value)
	{

	}
	string value_;
	static Singleton* singleton_;

public:
	//It should not be clonable
	Singleton(Singleton &other) = delete;

	//It should not be assignable
	void operator=(const Singleton&) = delete;

	//Creating an instance
	static Singleton *GetInstance(const string message);

	//Do some staff
	void DoSomeStaff()
	{

	}

	string retrunValue() const
	{
		return value_;
	}
};

Singleton* Singleton::singleton_ = nullptr;

Singleton *Singleton::GetInstance(const string message)
{
	//This is safer way to create instance
	if(singleton_ == nullptr)
	{
		singleton_ = new Singleton(message);
	}
	return singleton_;
}

void ThreadA()
{
	this_thread::sleep_for(chrono::milliseconds(1000));
	Singleton *sigleton_ = Singleton::GetInstance("Thread A");
	cout << sigleton_->retrunValue() << "\n";
}

void ThreadB()
{
	this_thread::sleep_for(chrono::milliseconds(1000));
	Singleton *sigleton_ = Singleton::GetInstance("Thread B");
	cout << sigleton_->retrunValue() << "\n";
}

int main()
{
	thread t1(ThreadA);
	thread t2(ThreadB);

	t1.join();
    t2.join();
	return 0;
}

