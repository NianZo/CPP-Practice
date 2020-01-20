/*
 * 2_constexpr_qualifier.cpp
 *
 *  Created on: Oct 21, 2019
 *      Author: nic
 */

#include <iostream>

constexpr int func1(int a);
int func2(int a);

constexpr int func1(int a) // It appears that this has to be defined before it is used, not just declared. Of note, this was only an issue for the g initialization. The rest were fine with it defined below.
{
	return a * 4 - 3;
}

int v1 = 52;

constexpr int func3(int a)
{
	return v1 * a; // Not okay because v1 is not a constexpr
}

int main()
{
	int a = 4;
	int b = 4 * 5;
	//constexpr int c = b - 5; // Compile time error - can't use b in constexpr
	constexpr int d = 8 - 5; // Okay, can be determined at compile time

	int e = func1(2);
	const int f = func1(2);
	constexpr int g = func1(2);

	int h = func2(2);
	const int i = func2(2);
	//constexpr int j = func2(2); // Compile time error - can't assign non constexpr to constexpr

	int k = func1(b); // Somehow this is fine? I guess constexpr is a suggestion and it falls back to non constexpr if the inputs are non constexpr.
	constexpr int l = func1(b); // Compile time error

	constexpr int m = func3(2); // Compile time error - seems like same issue as above, defaults to non constexpr with little warning.


	return EXIT_SUCCESS;
}



int func2(int a)
{
	return a * 4 - 3;
}


// I want to find a way to enforce that a method has to be a constexpr. But constexpr and const returns are not acting as I expect.
// Upon further research, constexpr for functions seems to be a suggestion that the function CAN but does not HAVE TO be a constexpr
// In C++20 there will be a keyword consteval which will require that the function be a constexpr.




