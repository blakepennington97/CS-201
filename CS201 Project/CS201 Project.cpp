// CS201 Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include "circularDynamicArray.h"
#include "circularDynamicArray.cpp"
using namespace std;

int main()
{
	CDA<int> C(10);
	for (int i = 0; i < C.Length(); i++) C[i] = i;
	for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	// C => "0 1 2 3 4 5 6 7 8 9"
	C.DelEnd();
	for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	// C => "0 1 2 3 4 5 6 7 8"
	C.AddEnd(100);
	for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	// C => "0 1 2 3 4 5 6 7 8 100"
	C.AddEnd(101);
	for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	// C => "0 1 2 3 4 5 6 7 8 100 101"
	C.DelEnd(); C.DelEnd();
	C.AddFront(-100); C.AddFront(-200);
	for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	// C => "-200 -100 1 2 3 4 5 6 7 8"
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
