/*
 * 1_const_qualifier.cpp
 *
 *  Created on: Oct 21, 2019
 *      Author: nic
 */

#include <iostream>
#include <vector>

// Const specifier protects v1 from being overwritten anywhere
const int v1 = 100;
int v2 = 200;

int ChangeMyVector(std::vector<int>, std::vector<int>&, const std::vector<int>&);

const int Func1(int a);

//namespace Morp
//{
//	int v4;
//	// This is still wrong, only a class function can have a const decorator
//	void ChangeVar() const
//	{
//		v2 = 300;
//		v4 = 300;
//	}
//};

class Meep
{
public:
	int v3;
	void ConstChangeVar() const // As far as I know this is the only use for the const decorator on a function
	{
		v2 = 300; // Okay, const decorator permits changing non member variables
		//v3 = 300; // Not okay, const decorator prohibits changing member variables (compile time error)
	}
};

int main()
{
	v2 = 300; // Okay
	//v1 = 200; // Compile time error
	const int v3 = v2; // Okay, can have dynamic value as long as it doesn't change after creation


	Meep m;
	m.ConstChangeVar();

	const int b = Func1(v2); // Okay, but why?

	return EXIT_SUCCESS;
}

int ChangeMyVector(std::vector<int> vec1, std::vector<int>& vec2, const std::vector<int>& vec3)
{
	vec1[0] = 1;
	vec2[0] = 1;
	//vec3[0] = 1; // Compile time error. Useful because passing by reference doesn't copy the object (less overhead) and const ensures it isn't modified in the function.
	return 1;
}

// This is wrong, only member functions can be const
//void constChangeVar() const
//{
//	v2 = 300;
//}

const int Func1(int a)
{
	return 2 * a;
}

