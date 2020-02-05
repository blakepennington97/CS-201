// CS201 Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include "circularDynamicArray.h"
#include "circularDynamicArray.cpp"
using namespace std;

void foo(CDA<int> x) {
	for (int i = 0; i < x.Length() / 2; i++) {
		int temp = x[i];
		x[i] = x[x.Length() / 2 + i];
		x[x.Length() / 2 + i] = temp;
	}
	cout << "SetOrdered in foo is " << x.SetOrdered() << endl;
	// x => "5 6 7 8 9 1 1 2 3 4 10" SetOrdered => -1	
}

int main()
{
	CDA<float> C(10);
	for (int i = 0; i < C.Length(); i++) C[i] = i;
	for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	// C => "0 1 2 3 4 5 6 7 8 9"
	C.DelFront();
	for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8 9"
	C.DelEnd();
	for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8"
	C.AddEnd(100.0);
	for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8 100"
	C.AddEnd(101.0);
	for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	// C => "1 2 3 4 5 6 7 8 100 101"
	C.DelEnd(); C.DelEnd();
	C.AddFront(-100.0); C.AddFront(-200.0);
	for (int i = 0; i < C.Length(); i++) cout << C[i] << " ";  cout << endl;
	// C => "-200 -100 1 2 3 4 5 6 7 8"

	CDA<int> A;
	for (int i = 0; i < 10; i++) A.AddEnd(i);
	cout << "SetOrdered is " << A.SetOrdered() << endl;
	// A => "0 1 2 3 4 5 6 7 8 9" SetOrdered => 1
	cout << "Select is " << A.Select(3) << endl;
	// A => "0 1 2 3 4 5 6 7 8 9" Select => 2
	cout << "Select is " << A.Search(5) << endl;
	// A => "0 1 2 3 4 5 6 7 8 9" Search => 6
	A.AddFront(10);
	// A => "10 0 1 2 3 4 5 6 7 8 9"
	cout << "SetOrdered is " << A.SetOrdered() << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9" SetOrdered => -1
	cout << "Select is " << A.Select(3) << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9" Select => 2
	cout << "Select is " << A.Search(5) << endl;
	// A => "10 0 1 2 3 4 5 6 7 8 9" Search => 6
	A.InsertionSort();
	// A => "0 1 2 3 4 5 6 7 8 9 10"
	cout << "SetOrdered is " << A.SetOrdered() << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 10" SetOrdered => 1
	A.AddEnd(-1);
	// A => "0 1 2 3 4 5 6 7 8 9 10 -1"
	cout << "Ordered is " << A.Ordered() << endl;
	// A => "0 1 2 3 4 5 6 7 8 9 10 -1" Ordered => False
	A.QuickSort();
	// A => "-1 0 1 2 3 4 5 6 7 8 9 10"
	cout << "Ordered is " << A.Ordered() << endl;
	// A => "-1 0 1 2 3 4 5 6 7 8 9 10" Ordered => True
	A.DelFront(); A.DelFront(); A.AddEnd(1);
	// A => "1 2 3 4 5 6 7 8 9 10 1"
	A.CountingSort(10);
	// A => "1 1 2 3 4 5 6 7 8 9 10"
	for (int i = 0; i < A.Length(); i++) cout << A[i] << " ";  cout << endl;

	foo(A);
	cout << "Ordered is " << A.Ordered() << endl;
	// A => "1 1 2 3 4 5 6 7 8 9 10" Ordered => True
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
