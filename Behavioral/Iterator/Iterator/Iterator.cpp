// Iterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
using namespace std;

template <typename T, typename U>
class Iterator
{
public:
	typedef typename std::vector<T>::iterator iter_type;
	Iterator(U *p_data, bool reverse = false) : m_p_data_(p_data) {
		m_it_ = m_p_data_->m_data_.begin();
	}

	void First() {
		m_it_ = m_p_data_->m_data_.begin();
	}

	void Next() {
		m_it_++;
	}

	bool IsDone() {
		return (m_it_ == m_p_data_->m_data_.end());
	}

	iter_type Current() {
		return m_it_;
	}

private:
	U *m_p_data_;
	iter_type m_it_;
};

/**
 * Generic Collections/Containers provides one or several methods for retrieving
 * fresh iterator instances, compatible with the collection class.
 */

template <class T>
class Container {
	friend class Iterator<T, Container>;

public:
	void Add(T a) 
	{
		m_data_.push_back(a);
	}

	Iterator<T, Container> *CreateIterator() {
		return new Iterator<T, Container>(this);
	}

private:
	std::vector<T> m_data_;
};


int main()
{
	Container<int> ct;
	ct.Add(1);
	Iterator<int, Container<int>> *it_r = ct.CreateIterator();
	for (it_r->First(); !it_r->IsDone(); it_r->Next())
	{
		cout << *it_r->Current();
	}

    
	return 0;
}


