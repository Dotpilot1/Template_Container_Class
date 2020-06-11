#pragma once
#include <iostream>

using namespace std;

template<class V>
class Vector
{
	//operator-overloading for "<<" to prompt for this class.
	friend ostream& operator<<(ostream& out, const Vector<V>& v)
	{
		for (auto i{ 0 }; i < v.size - 1;++i)
			out << v[i] << ",";

		if (v.size > 0)
			out << v[v.size - 1];
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, Vector<V>& v)
	{
		for (auto i{ 0 };i < v.getSize();++i) {
			in >> v.data[i];
		}
		return in;
	}

public:
	//default constructor
	 Vector();
	//constructor for number of items & an assingned value
	Vector(int numberOfItems, const V& defaultValue);
	//constructor for initiliazer list which ensure listed assignment
	Vector(const std::initializer_list<V>& l);
	//constructor for number of items
	explicit Vector(int numberOfItems);
	//copy constructor for copying from other objects
	Vector(const Vector<V>& c);
	//move constructor for dynamic memory management
	Vector(Vector<V>&& m);
	//Virtual destructor
	 ~Vector();
	//copy assignment "=" operator-overloading
	Vector<V>& operator=(Vector<V>& c);
	//move assignment "=" operator-overloading
	Vector<V>& operator=(Vector<V>&& m);
	// operator-overloading for comparision operators
	bool operator == (const Vector<V> & v) const;
	bool operator != (const Vector<V>& v) const;
	bool operator >= (const Vector<V>& v) const;
	bool operator <= (const Vector<V>& v) const;
	bool operator < (const Vector<V>& v) const;
	bool operator > (const Vector<V>& v) const;

	// "+=" operator 
	Vector<V>& operator+=(const Vector<V>& c);
	// "[]" subscript operator
	V operator[](int idx)const;//const object
	V& operator[](int idx);//non-const object

	//size function which give the size of the array
	int getSize()const;
	//at function same as the subscription
	V at(int idx) const;//const
	V& at(int idx) ;//non-const
	//check for clearfying memory position
	bool clear();
	// adding new item end of the container
	void push(const V& newItem);

	

protected:
	V* data;
	int size;

};

template<class V>
inline Vector<V>::Vector() :size{ 0 }, data{ nullptr }
{
}

template<class V>
inline Vector<V>::Vector(int numberOfItems, const V& defaultValue)
{
	if (numberOfItems > 0)
	{
		size = numberOfItems;
		data = new V[numberOfItems];

		for (auto i{ 0 }; i < size;++i)
			data[i] = defaultValue;
	}
	else Vector();
}
template<>
Vector<char>::Vector(int numberOfItems, const char& defaultValue)
{
	if (numberOfItems > 0)
	{
		size = numberOfItems;
		data = new char[numberOfItems];

		memset(data, defaultValue, size * sizeof(char));
	}
	else Vector();
}

template<class V>
inline Vector<V>::Vector(const std::initializer_list<V>& l) :size(l.size)
{
	data = new V[size];
	uninitialized_copy(l.begin(), l.end(), data);
}

template<class V>
inline Vector<V>::Vector(int numberOfItems)
{
	if (numberOfItems > 0)
	{
		size = numberOfItems;
		data = new V[numberOfItems];
	}
	else Vector();
}

template<class V>
inline Vector<V>::Vector(const Vector<V>& c) :size{ c.size }
{
	data = new V[size];

	memcpy(data, c.data, size * sizeof(V));
}

template<class V>
inline Vector<V>::Vector(Vector<V>&& m) :size(m.size), data{ m.data }
{
	m.size = 0;
	m.data = nullptr;
}

template<class V>
inline Vector<V>::~Vector()
{
	if (data)
		delete[]data;
}

template<class V>
Vector<V>& Vector<V>::operator=(Vector<V>& c)
{
	if (this == &c)
		return *this;

	if (size != c.size)
	{
		size = c.size;
		if (data)
			delete[]data;

		data = new V[size];
	}
	memcpy(data, c.data, size * sizeof(V));

	return *this;
}

template<class V>
inline Vector<V>& Vector<V>::operator=(Vector<V>&& c)
{
	if (this != &c)
	{
		if (data)
			delete[]data;

		size = c.size;
		data = c.data;

		c.size = 0;
		c.data = nullptr;
	}

	return *this;
}

template<class V>
inline bool Vector<V>::operator==(const Vector<V>& v) const
{
	if (size != v.size)
		return false;

	for (auto i{ 0 };i < size;++i)
		if (data[i] != v.data[i])
			return false;

	return true;

}

template<class V>
inline bool Vector<V>::operator!=(const Vector<V>& v) const
{
	return !(*this == v);
}

template<class V>
inline bool Vector<V>::operator>=(const Vector<V>& v) const
{
	return ((*this > v) || (*this == v));
}

template<class V>
inline bool Vector<V>::operator<=(const Vector<V>& v) const
{
	return !(*this > v);
}

template<class V>
inline bool Vector<V>::operator<(const Vector<V>& v) const
{
	return (!(*this > v) && (*this != v));
}

template<class V>
inline bool Vector<V>::operator>(const Vector<V>& v) const
{
	auto minSize = (size >= v.size) ? v.size : size;

	for (auto i{ 0 };i < minSize;++i)
		if (data[i] <= v.data[i])
			return false;

	if (size < v.size)
		return false;

	return true;
}

template<class V>
inline Vector<V>& Vector<V>::operator+=(const Vector<V>& c)
{
	int newSize = size + c.size;

	if (newSize <= 0)
		return *this;

	V* ptr = new V[newSize];
	if (!ptr)
		exit(-1);

	if (size > 0)
		memcpy(ptr, data, size * sizeof(V));
	if (c.size > 0)
		memcpy(ptr + size, c.data, c.size * sizeof(V));

	size = newSize;
	if (data)
		delete[]data;

	data = ptr;

	return *this;
}

template<class V>
inline V Vector<V>::operator[](int idx) const
{
	return data[idx];
}

template<class V>
inline V& Vector<V>::operator[](int idx)
{
	return data[idx];
}

template<class V>
inline int Vector<V>::getSize() const
{
	return size;
}

template<class V>
inline V Vector<V>::at(int idx) const
{
	if (idx < 0 && idx >= size)
		throw("Out-of-range");

	return data[idx];
}

template<class V>
inline V& Vector<V>::at(int idx)
{
	if (idx < 0 && idx >= size)
		throw("Out-of-range");

	return data[idx];
}

template<class V>
inline bool Vector<V>::clear()
{
	size = 0;
	delete[]data;
	return true;
}

template<class V>
inline void Vector<V>::push(const V& newItem)
{
	size++;
	V* tempData = new V[size];
	memcpy(tempData, &data[0], (size - 1) * sizeof(V));

	delete[]data;
	data = tempData;
}


