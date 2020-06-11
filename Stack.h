#pragma once
#include "Vector.h"

template<class S>
class Stack : public Vector<S>
{
	Stack();

	// constructor 
	Stack(int numberOfItems, S defaultValue);

	// conversion constructor - initializer list
	Stack(const std::initializer_list<S>& l);

	// conversion constructor - MyVector
	Stack(const Vector<S>& v);

	// copy constructor
	Stack(const Stack<S>& o);

	// move constructor
	Stack(Stack<S>&& o);

	S pop();
	

	S operator[](int idx) const = delete;
	S& operator[](int idx) = delete;

	S at(int idx) const = delete;
	S& at(int idx) = delete;

};




template<class S>
inline Stack<S>::Stack() :Vector<S>()
{
}

template<class S>
inline Stack<S>::Stack(int numberOfItems, S defaultValue)
	: Vector<S>(numberOfItems, defaultValue)
{
}

template<class S>
inline Stack<S>::Stack(const std::initializer_list<S>& l)
	: Vector<S>(l)
{
}

template<class S>
inline Stack<S>::Stack(const Vector<S>& o)
	: Vector<S>(o)
{
}

template<class S>
inline Stack<S>::Stack(const Stack<S>& o)
	: Vector<S>(o)
{
}

template<class S>
inline Stack<S>::Stack(Stack<S>&& o)
	: Vector<S>(o)
{
}

template<class S>
inline S Stack<S>::pop()
{
	S temp = Vector<S>::data[(Vector<S>::size) - 1];

	Vector<S>::size--;
	S* tempData = new S[Vector<S>::size];
	memcpy(tempData, &Vector<S>::data[0], Vector<S>::size * sizeof(S));

	delete[] Vector<S>::data;
	Vector<S>::data = tempData;

	return temp;
}