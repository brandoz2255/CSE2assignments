// Adopted from M.A. Weiss, DSAAC++ textbook
// by KV, Fall 2021
// for HW2
// erase() and insert() member functions to be added

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cassert>   
using namespace std;

template <typename T>
class Vector


{
public:
	Vector(int initSize = 0)
		: theSize{ initSize }, theCapacity{ initSize + SPARE_CAPACITY }
	{ data = new T[theCapacity]; }

	Vector(const Vector& rhs)
		: theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, data{ nullptr }
	{
		data = new T[theCapacity];
		for (int k = 0; k < theSize; ++k)
			data[k] = rhs.data[k];
	}

	Vector(Vector&& rhs)
		: theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, data{ rhs.data }
	{
		rhs.data = nullptr;
		rhs.theSize = 0;
		rhs.theCapacity = 0;
	}

	Vector& operator= (const Vector& rhs)
	{
		Vector copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	~Vector()
	{
		delete[] data;
	}

	bool empty() const
	{
		return size() == 0;
	}
	int size() const
	{
		return theSize;
	}
	int capacity() const
	{
		return theCapacity;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < theSize);
		return data[index];
	}

	const T& operator[](int index) const
	{
		assert(index >= 0 && index < theSize);
		return data[index];
	}

	void resize(int newSize)
	{
		if (newSize > theCapacity)
			reserve(newSize * 2);
		theSize = newSize;
	}

	void reserve(int newCapacity)
	{
		if (newCapacity < theSize)
			return;

		T* newArray = new T[newCapacity];
		for (int k = 0; k < theSize; ++k)
			newArray[k] = std::move(data[k]);

		theCapacity = newCapacity;
		std::swap(data, newArray);
		delete[] newArray;
	}

	void push_back(const T& x)
	{
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		data[theSize++] = x;
	}

	void pop_back()
	{
		assert(theSize >= 1);
		--theSize;
	}

	void clear()
	{
		theSize = 0;
	}

	const T& back() const
	{
		assert(theSize >= 1);
		return data[theSize - 1];
	}

	const T& front() const
	{
		assert(theSize >= 1);
		return data[0];
	}

	// Iterators (new concept)
	typedef T* iterator;
	typedef const T* const_iterator;

	iterator begin()
	{
		return &data[0];
	}
	const_iterator begin() const
	{
		return &data[0];
	}
	iterator end()
	{
		return &data[size()];
	}
	const_iterator end() const
	{
		return &data[size()];
	}

	// Lab5 Exercise 5

	void erase(int index)
	{
		assert(index >= 0 && index < theSize);
		if (index == theSize - 1)
		{
			pop_back();
			return;
		}
		// copy items one position to left
		// to overwrite value at index;
		for (int i = index; i < theSize; i++)
			data[i] = data[i + 1];
		pop_back(); // get rid of last duplicate item
		return;
	}

	void insert(iterator itr, T value)
	{
		if (itr == end())
		{
			push_back(value);
			return;
		}
		assert(itr >= begin() && itr < end());
		push_back(back());
		iterator itr1 = end() - 2;
		iterator itr2 = end() - 1;
		while (itr1 >= itr)
		{
			*itr2 = *itr1;
			itr1--;
			itr2--;
		}
		*itr = value;
		return;
	}

	// Lab 5/HW 2
	void erase(iterator itr)
	{
		assert(itr >= begin() && itr < end());

		if (itr == end() - 1)
		{
			pop_back();
			return;
		}

		iterator itr2 = itr;
		itr2++;
		while (itr2 != end())
		{
			*itr = *itr2;
			itr++;
			itr2++;
		}
		pop_back();
		return;
	}

	// HW
	void insert(int index, T value)
	{
		if (index == theSize)
		{
			push_back(value);
			return;
		}
		assert(index >= 0 && index < theSize);

		push_back(back()); // double up on last value

		// starting at back, move each item one position
		// to right, making space for new value at index
		for (int i = theSize; i >= index; i--)
			data[i] = data[i - 1];
		data[index] = value; // place new value
		return;
	}

	static const int SPARE_CAPACITY = 2;

private:
	int theSize;
	int theCapacity;
	T* data;
};

#endif

