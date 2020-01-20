/*
 * 3_basic_templates.cpp
 *
 *  Created on: Oct 22, 2019
 *      Author: nic
 */

#include <iostream>
#include <string>

// A function that uses templated inputs and output
template <typename T>
inline T const& Min (T const& a, T const& b)
{
	return a < b ? a : b;
}

// A templated class
template <class T> class Array
{
public:
	T data[10];

	T Get(int i);
	void Set(int i, T d);
};

template <class T> T Array<T>::Get(int i)
{
	return data[i];
}

template <class T> void Array<T>::Set(int i, T d)
{
	data[i] = d;
}

int main()
{
	int a1 = 2;
	int b1 = 3;
	std::cout << Min(a1, b1) << std::endl;

	float a2 = 4.0;
	float b2 = 3.5;
	std::cout << Min(a2, b2) << std::endl;

	std::string a3 = "athing";
	std::string b3 = "bthing";
	std::cout << Min(a3, b3) << std::endl;

	Array<int> a_int;
	a_int.Set(0, 3);
	std::cout << a_int.Get(0) << std::endl;

	Array<float> a_flt;
	a_flt.Set(0, 3.14);
	std::cout << a_flt.Get(0) << std::endl;

	return EXIT_SUCCESS;
}
