/*
 * function_pointer.cpp
 *
 *  Created on: Jan 31, 2013
 *      Author: titan
 */
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

enum list_number {
			one,
			two,
			three
};

map<string, list_number> s_mapString;

void
add(int a, int b)
{
	cout << "a + b = " << a + b << endl;
	return;
}

void
del(int a, int b)
{
	cout << "a - b = " << a - b << endl;
	return;
}

void
Init()
{
	s_mapString["1"] = one;
	s_mapString["2"] = two;
}


int main() {

	void (*fun_c)(int , int );
	string choice;
	Init();
	cout << "pick up one:" << endl;

	getline(cin,choice);

	switch (s_mapString[choice]) {
		case one:
			fun_c = add;
			break;
		case two:
			fun_c = del;
			break;
	}
	fun_c(3,4);

	cout << "End !!" << endl;

	return 0;
}



