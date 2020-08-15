
#include "Vector.h"

int Vector::bad = 0;
void Vector::reserve(size_t newcapacity)
{
	if (this->m_capacity >= newcapacity)
	{
		return;
	}
	int* temp = new int[newcapacity];
	for (size_t i = 0; i < this->m_size; i++)
	{
		temp[i] = arr[i];
	}
	this->m_capacity = newcapacity;
	delete[]arr;
	arr = temp;
}

void Vector::copy(const Vector& obj)
{
	reserve(obj.m_capacity);
	m_size = obj.m_size;
	for (size_t i = 0; i < m_size; i++)
	{
		arr[i] = obj.arr[i];
	}
	for (size_t i = m_size; i < m_capacity; i++)
	{
		arr[i] = 0;
	}

}

void Vector::print() const
{
	for (size_t i = 0; i < m_size; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << "\n";
}

void Vector::pushBack(int elem)
{
	resize(m_size + 1, elem);

}

void Vector::insert(int elem, size_t index)
{
	if (index <= m_size)
	{
		resize(m_size + 1, elem);

		for (size_t i = m_size - 1; i > index; i--)
		{
			std::swap(arr[i], arr[i - 1]);
		}
	}
}

void Vector::popIndex(size_t index)
{
	if (index <= m_size)
	{
		int* temp = new int[--m_size];
		for (size_t i = 0; i < m_size; i++)
		{
			if (i < index)
			{
				temp[i] = arr[i];
			}
			else if (i >= index)
			{
				temp[i] = arr[i + 1];
			}
		}
		delete[]arr;
		arr = temp;
	}
}

void Vector::popBack()
{
	if (m_size > 0)
	{
		arr[m_size] = 0;
		m_size--;
	}
}

int& Vector::front()const
{
	if (m_size == 0)
	{
		return bad;
	}
	return arr[0];
}

int& Vector::back()const
{
	if (m_size == 0)
	{
		return bad;
	}
	return arr[m_size];
}

int& Vector::operator[](size_t number)const
{
	if (number <= m_size)
	{
		return arr[number];
	}
	return bad;
}

void Vector::setValue(size_t index, int value)
{
	if (index < m_size)
	{
		arr[index] = value;
	}
}

void Vector::resize(size_t newSize, int value)
{
	if (newSize >= m_capacity)
	{
		reserve(newSize + START_CAPACITY);
	}
	for (size_t i = m_size; i < newSize; i++)
	{
		arr[i] = value;
	}
	m_size = newSize;
}

void Vector::fill(int value)
{
	for (size_t i = 0; i < m_size; i++)
	{
		arr[i] = value;
	}
}

void Vector::clear()
{
	for (size_t i = 0; i < m_size; i++)
	{
		arr[i] = 0;
	}
	m_size = 0;
}

Vector& Vector::operator=(const Vector& obj)
{
	if (this != &obj)
	{
		copy(obj);
	}
	return *this;
}

Vector Vector::operator()(size_t start, size_t len)
{
	if (start >= m_size)
	{
		return bad;
	}
	if (len > m_size)
	{
		len = m_size - start;
	}
	Vector result(len);
	for (size_t i = 0; i <= len; i++)
	{
		result[i] = arr[i + start];
	}
	return result;
}

Vector::operator int() const
{
	int result = 0;
	for (size_t i = 0; i < m_size; i++)
	{
		result += arr[i];
	}
	return result;
}

Vector operator!(const Vector& obj)
{
	Vector result(obj);

	int temp = result[0];
	for (int i = 0; i < obj.size() / 2; ++i)
	{
		result[i] = temp;
		temp = result[obj.size() - i - 1];
		result[obj.size() - i - 1] = result[i];
		result[i] = temp;
	}
	return result;
}

bool operator==(const Vector& left, const Vector& right)
{
	if (left.size() != right.size())
	{
		return false;
	}
	for (size_t i = 0; i < left.size(); i++)
	{
		if (left[i] != right[i])
		{
			return false;
		}
	}
	return true;
}

bool operator!=(const Vector& left, const Vector& right)
{
	return !(left == right);
}

Vector& operator+=(Vector& left, const Vector& right)
{
	for (size_t i = 0; i < right.size(); i++)
	{
		left.pushBack(right[i]);
	}
	return left;
}

Vector operator+(const Vector& left, const Vector& right)
{
	Vector result(left);
	for (size_t i = 0; i < right.size(); i++)
	{
		result.pushBack(right[i]);
	}
	return result;
}

Vector operator++(Vector& obj, int)
{
	Vector temp(obj);
	++obj;
	return temp;
}

Vector& operator++(Vector& obj)
{
	for (size_t i = 0; i < obj.size(); i++)
	{
		obj[i];
	}
	return obj;
}

Vector& operator*=(Vector& obj, const int number)
{
	return (obj = obj * number);
}

Vector operator*(const Vector& obj, int number)
{
	Vector result(obj);
	for (size_t i = 0; i < result.size(); i++)
	{
		result[i] *= number;
	}
	return result;
}

std::ostream& operator<<(std::ostream& out, const Vector& obj)
{
	for (size_t i = 0; i < obj.size(); i++)
	{
		out << obj[i] << "\t";
	}
	out << "\n";
	return out;
}

std::istream& operator>>(std::istream& is, Vector& obj)
{
	for (size_t i = 0; i < obj.size(); i++)
	{
		std::cout << "Enter element " << i << " : ";
		is >> obj[i];
	}
	return is;
}
