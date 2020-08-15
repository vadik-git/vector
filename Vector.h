#pragma once

#include <iostream>
#include <ostream>
#include <istream>
class Vector
{
	static const size_t START_CAPACITY = 5;
	int* arr = nullptr;
	size_t m_capacity = 0;
	size_t m_size = 0;
	static int bad;
	void copy(const Vector& obj);
public:
	Vector(size_t m_size = 0, int value = 0) {
		reserve(m_size + START_CAPACITY);
		this->m_size = m_size;
		fill(value);
	}
	Vector(const Vector& obj)
	{
		copy(obj);
	}
	void reserve(size_t newcapacity = START_CAPACITY);
	size_t size()const
	{
		return m_size;
	}
	size_t capacity()const
	{
		return m_capacity;
	}
	void print()const;
	void pushBack(int elem);
	void insert(int elem, size_t index);
	void popIndex(size_t index);
	void popBack();
	int& front()const;
	int& back()const;
	bool empty()const
	{
		return m_size == 0;
	}
	void setValue(size_t index, int value);
	void resize(size_t newSize, int value = 0);
	void fill(int value);
	void clear();

	int &operator [](size_t number)const;
	Vector& operator=(const Vector& obj);
	Vector operator() (size_t start, size_t len);
	operator int()const;

	~Vector()
	{
		delete[]arr;
		arr = nullptr;
		m_capacity = 0;
		m_size = 0;
	};
};
Vector operator!(const Vector& obj);
bool operator ==(const Vector& left, const Vector& right);
bool operator !=(const Vector& left, const Vector& right);
Vector& operator +=(Vector& left, const Vector& right);
Vector operator +(const Vector& left, const Vector& right);
Vector operator ++(Vector& obj, int);
Vector& operator ++(Vector& obj);
Vector& operator*=(Vector& obj, const int number);
Vector operator*(const Vector& obj, const int number);
std::ostream& operator<<(std::ostream& out, const Vector& obj);
std::istream& operator>> (std::istream& is, Vector& obj);


