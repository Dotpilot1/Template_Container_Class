#pragma once
#include "Vector.h"

template<class T>
class Queue : public Vector<T>
{
public:
	Queue();

	// constructor 
	Queue(int numberOfItems, T defaultValue);

	// conversion constructor - initializer list
	Queue(const std::initializer_list<T>& l);

	// conversion constructor - MyVector
	Queue(const Vector<T>& v);

	// copy constructor
	Queue(const Queue<T>& o);

	// move constructor
	Queue(Queue<T>&& o);

	T pop();
	

	T operator[](int idx) const = delete;
	T& operator[](int idx) = delete;

	T at(int idx) const = delete;
	T& at(int idx) = delete;
};




template<class T>
inline Queue<T>::Queue() :Vector<T>()
{
}

template<class T>
inline Queue<T>::Queue(int numberOfItems, T defaultValue)
	: Vector<T>(numberOfItems, defaultValue)
{
}

template<class T>
inline Queue<T>::Queue(const std::initializer_list<T>& l)
	: Vector<T>(l)
{
}

template<class T>
inline Queue<T>::Queue(const Vector<T>& v)
	: Vector<T>(v)
{
}

template<class T>
inline Queue<T>::Queue(const Queue<T>& o)
	: Vector<T>(o)
{
}

template<class T>
inline Queue<T>::Queue(Queue<T>&& o)
	: Vector<T>(o)
{
}

template<class T>
inline T Queue<T>::pop()
{
	T temp = Vector<T>::data[0];

	Vector<T>::size--;
	T* tempData = new T[Vector<T>::size];
	memcpy(tempData, &Vector<T>::data[1], Vector::size * sizeof(T));

	delete[] Vector<T>::data;
	Vector<T>::data = tempData;

	return temp;
}