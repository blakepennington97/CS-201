#include <iostream>
#include "CDA.cpp"
#include <random>

using namespace std;

int main()
{
    /* ADD THIS TO YOUR CDA.cpp FILE TO UTILIZE PRINT
    template <class T>
    void CDA<T>::Print()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << this->array[((this->frontIndex + i)  % this->capacity)] << " ";
        }
        cout << endl;
    } */

    CDA<int> A;

    cout << "Testing with integers." << endl;
    cout << "Testing AddEnd & AddFront" << endl << endl;

    A.AddFront(4);
    A.Print();
    // 4

    A.AddEnd(23);
    A.Print();
    // 4 23

    A.AddFront(9);
    A.Print();
    // 9 4 23

    A.AddEnd(3);
    A.Print();
    // 9 4 23 3

    A.AddEnd(46);
    A.Print();
    // 9 4 23 3 46

    A.AddFront(34);
    A.Print();
    // 34 9 4 23 3 46

    A.AddEnd(4);
    A.Print();
    // 34 9 4 23 3 46 4

    A.AddFront(3);
    A.Print();
    // 3 34 9 4 23 3 46 4

    A.AddFront(9);
    A.Print();
    // 9 3 34 9 4 23 3 46 4

    A.AddEnd(3);
    A.Print();
    // 9 3 34 9 4 23 3 46 4 3

    A.AddEnd(6);
    A.Print();
    // 9 3 34 9 4 23 3 46 4 3 6

    A.AddFront(18);
    A.Print();
    // 18 9 3 34 9 4 23 3 46 4 3 6

    A.AddEnd(27);
    A.Print();
    // 18 9 3 34 9 4 23 3 46 4 3 6 27

    A.AddFront(19);
    A.Print();
    // 19 18 9 3 34 9 4 23 3 46 4 3 6 27

    A.AddFront(0);
    A.Print();
    // 0 19 18 9 3 34 9 4 23 3 46 4 3 6 27

    A.AddEnd(77);
    A.Print();
    // 0 19 18 9 3 34 9 4 23 3 46 4 3 6 27 77

    cout << "A's size is: " << A.Length() << endl;
    // 16
    cout << "A's capacity is: " << A.Capacity() << endl << endl << endl;
    // 16

    cout << "Testing overloaded [] operator" << endl << endl;

    cout << "A[0] is: " << A[0] << endl; // 0
    cout << "A[1] is: " << A[1] << endl; // 19
    cout << "A[2] is: " << A[2] << endl; // 18 
    cout << "A[3] is: " << A[3] << endl; // 9
    cout << "A[4] is: " << A[4] << endl; // 3
    cout << "A[5] is: " << A[5] << endl; // 34
    cout << "A[6] is: " << A[6] << endl; // 9
    cout << "A[7] is: " << A[7] << endl; // 4
    cout << "A[8] is: " << A[8] << endl; // 23
    cout << "A[9] is: " << A[9] << endl; // 3
    cout << "A[10] is: " << A[10] << endl; // 46
    cout << "A[11] is: " << A[11] << endl; // 4
    cout << "A[12] is: " << A[12] << endl; // 3
    cout << "A[13] is: " << A[13] << endl; // 6
    cout << "A[14] is: " << A[14] << endl; // 27
    cout << "A[15] is: " << A[15] << endl; // 77
    cout << "A[16] is: " << A[16] << endl << endl; // No such value. Should output out of bounds error and return a trash value

    cout << "Testing DelEnd & DelFront" << endl << endl;

    A.DelEnd();
    A.Print();
    // 0 19 18 9 3 34 9 4 23 3 46 4 3 6 27

    A.DelEnd();
    A.Print();
    // 0 19 18 9 3 34 9 4 23 3 46 4 3 6

    A.DelFront();
    A.Print();
    // 19 18 9 3 34 9 4 23 3 46 4 3 6 

    A.DelFront();
    A.Print();
    // 18 9 3 34 9 4 23 3 46 4 3 6

    A.DelFront();
    A.Print();
    // 9 3 34 9 4 23 3 46 4 3 6

    A.DelEnd();
    A.Print();
    // 9 3 34 9 4 23 3 46 4 3

    A.DelEnd();
    A.Print();
    // 9 3 34 9 4 23 3 46 4

    A.DelEnd();
    A.Print();
    // 9 3 34 9 4 23 3 46

    A.DelEnd();
    A.Print();
    // 9 3 34 9 4 23 3

    A.DelFront();
    A.Print();
    // 3 34 9 4 23 3

    A.DelFront();
    A.Print();
    // 34 9 4 23 3

    A.DelFront();
    A.Print();
    // 9 4 23 3

    A.DelEnd();
    A.Print();
    // 9 4 23

    A.DelEnd();
    A.Print();
    // 9 4

    A.DelEnd();
    A.Print();
    // 9

    A.DelEnd();
    A.Print();
    // blank

    A.DelFront(); // Deleting past Size = 0
    A.Print();
    // blank

    cout << "A's size is: " << A.Length() << endl;
    // 0
    cout << "A's capacity is: " << A.Capacity() << endl << endl << endl;
    // 1

    cout << "A's SetOrdered returns: " << A.SetOrdered() << endl;
    // -1

    cout << "Repopulating array.." << endl;

    A.AddFront(4);
    A.AddEnd(23);
    A.AddFront(9);
    A.AddEnd(3);
    A.AddEnd(46);
    A.AddFront(34);
    A.AddEnd(4);
    A.AddFront(3);
    A.AddFront(9);
    A.AddEnd(3);
    A.AddEnd(6);
    A.AddFront(18);
    A.AddEnd(27);
    A.AddFront(19);
    A.AddFront(0);
    A.AddEnd(77);

    A.Print();
    cout << endl;
    // 0 19 18 9 3 34 9 4 23 3 46 4 3 6 27 77

    cout << "Testing SetOrdered (with one CountingSort & one InsertionSort test for good measure)" << endl << endl;

    cout << "A's SetOrdered returns: " << A.SetOrdered() << endl << endl;
    // -1

    A.Print();
    cout << endl;

    A.CountingSort(77);
    cout << "A's SetOrdered returns: " << A.SetOrdered() << endl << endl;
    // 1

    A.Print();
    cout << endl;
    // 0 3 3 3 4 4 6 9 9 18 19 23 27 34 46 77

    A.AddFront(90);
    cout << "A's SetOrdered returns: " << A.SetOrdered() << endl << endl;
    // -1

    A.Print();
    cout << endl;
    // 90 0 3 3 3 4 4 6 9 9 18 19 23 27 34 46 77

    A.InsertionSort();
    cout << "A's SetOrdered returns: " << A.SetOrdered() << endl << endl;
    // 1

    A.Print();
    cout << endl;
    // 0 3 3 3 4 4 6 9 9 18 19 23 27 34 46 77 90

    A.AddEnd(1);
    cout << "A's SetOrdered returns: " << A.SetOrdered() << endl << endl;
    // -1

    A.Print();
    cout << endl;
    // 0 3 3 3 4 4 6 9 9 18 19 23 27 34 46 77 90 1

    A.QuickSort();
    cout << "A's SetOrdered returns: " << A.SetOrdered() << endl << endl;
    // 1

    A.Print();
    cout << endl;
    // 0 1 3 3 3 4 4 6 9 9 18 19 23 27 34 46 77 90

    cout << "Clearing array. Repopulating with previous values..." << endl;
    A.Clear(); // Test of Clear method

    A.AddFront(4);
    A.AddEnd(23);
    A.AddFront(9);
    A.AddEnd(3);
    A.AddEnd(46);
    A.AddFront(34);
    A.AddEnd(4);
    A.AddFront(3);
    A.AddFront(9);
    A.AddEnd(3);
    A.AddEnd(6);
    A.AddFront(18);
    A.AddEnd(27);
    A.AddFront(19);
    A.AddFront(0);
    A.AddEnd(77);

    A.Print();

    cout << "Testing Select method: " << endl << endl;

    cout << "The smallest element in the array is: " << A.Select(1) << endl; // 0
    cout << "The second smallest element in the array is: " << A.Select(2) << endl; // 3
    cout << "The third smallest element in the array is: " << A.Select(3) << endl; // 3
    cout << "The fourth smallest element in the array is: " << A.Select(4) << endl; // 3
    cout << "The fifth smallest element in the array is: " << A.Select(5) << endl; // 4
    cout << "The sixth smallest element in the array is: " << A.Select(6) << endl; // 4
    cout << "The seventh smallest element in the array is: " << A.Select(7) << endl; // 6
    cout << "The eighth smallest element in the array is: " << A.Select(8) << endl; // 9
    cout << "The ninth smallest element in the array is: " << A.Select(9) << endl; // 9
    cout << "The tenth smallest element in the array is: " << A.Select(10) << endl; // 18
    cout << "The eleventh smallest element in the array is: " << A.Select(11) << endl; // 19
    cout << "The twelfth smallest element in the array is: " << A.Select(12) << endl; // 23
    cout << "The thirteenth smallest element in the array is: " << A.Select(13) << endl; // 27
    cout << "The fourteenth smallest element in the array is: " << A.Select(14) << endl; // 34
    cout << "The fifteenth smallest element in the array is: " << A.Select(15) << endl; // 46
    cout << "The sixteenth smallest element in the array is: " << A.Select(16) << endl; // 77
    cout << "The seventeenth smallest element in the array is: " << A.Select(17) << endl << endl; // No such value. Should return out of bounds error.

    cout << "Testing Linear Search method" << endl << endl;

    A.Clear();
    //  Clearing and repopulating
    A.AddFront(4);
    A.AddEnd(23);
    A.AddFront(9);
    A.AddEnd(3);
    A.AddEnd(46);
    A.AddFront(34);
    A.AddEnd(4);
    A.AddFront(3);
    A.AddFront(9);
    A.AddEnd(3);
    A.AddEnd(6);
    A.AddFront(18);
    A.AddEnd(27);
    A.AddFront(19);
    A.AddFront(0);
    A.AddEnd(77);

    A.Print();

    // All should use linear search.

    cout << "Searching for 18 returns index " << A.Search(18) << endl; // 2
    cout << "Searching for 77 returns index " << A.Search(77) << endl; // 15
    cout << "Searching for 19 returns index " << A.Search(19) << endl; // 1
    cout << "Searching for 23 returns index " << A.Search(23) << endl; // 8
    cout << "Searching for 27 returns index " << A.Search(27) << endl; // 14
    cout << "Searching for 46 returns index " << A.Search(46) << endl; // 10
    cout << "Searching for 34 returns index " << A.Search(34) << endl; // 5
    cout << "Searching for 0 returns index " << A.Search(0) << endl << endl; // 0

    cout << "Testing Binary Search method" << endl << endl;

    A.QuickSort(); // Sort it real quick
    A.Print();

    cout << "Searching for 18 returns index " << A.Search(18) << endl; // 9
    cout << "Searching for 77 returns index " << A.Search(77) << endl; // 15
    cout << "Searching for 19 returns index " << A.Search(19) << endl; // 10
    cout << "Searching for 23 returns index " << A.Search(23) << endl; // 11
    cout << "Searching for 27 returns index " << A.Search(27) << endl; // 12
    cout << "Searching for 46 returns index " << A.Search(46) << endl; // 14
    cout << "Searching for 34 returns index " << A.Search(34) << endl; // 13
    cout << "Searching for 0 returns index " << A.Search(0) << endl << endl; // 0

    cout << "Testing InsertionSort method" << endl;

    A.Clear();

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 25; j++) // Populating with random values
        {
            int val = rand() % 100;

            if (j % 2 == 0)
                A.AddEnd(val);
            else
                A.AddFront(val);
        }
        cout << "Unsorted array of random values" << endl;
        A.Print();

        cout << "Sorted array of random values" << endl;
        A.InsertionSort();
        A.Print();
        cout << endl;
        A.Clear();
    }
    cout << endl;

    cout << "Biiiig test!" << endl;

    for (int i = 0; i < 50000; i++) // Populating with random values. 50,000 is about the most my InsertionSort can handle in a "timely" fashion. Took about 6 seconds on my laptop.
    {
        int val = rand() % 10000;

        if (i % 2 == 0)
            A.AddEnd(val);
        else
            A.AddFront(val);
    }

    A.InsertionSort();
    A.Print();
    cout << endl << endl;

    cout << "Testing QuickSort method" << endl;

    A.Clear();

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 25; j++) // Populating with random values
        {
            int val = rand() % 100;

            if (j % 2 == 0)
                A.AddEnd(val);
            else
                A.AddFront(val);
        }
        cout << "Unsorted array of random values" << endl;
        A.Print();

        cout << "Sorted array of random values" << endl;
        A.QuickSort();
        A.Print();
        cout << endl;
        A.Clear();
    }
    cout << endl;

    cout << "Biiiig test!" << endl;

    for (int i = 0; i < 1000000; i++)
    {
        int val = rand() % 10000;

        if (i % 2 == 0)
            A.AddEnd(val);
        else
            A.AddFront(val);
    }

    A.QuickSort();
    A.Print();
    cout << endl << endl;

    cout << "Testing CountingSort method" << endl;

    A.Clear();

    int max = 0;

    for (int i = 0; i < 10; i++)
    {
        max = 0;
        for (int j = 0; j < 25; j++) // Populating with random values
        {
            int val = rand() % 100;

            if (val > max)
                max = val;

            if (j % 2 == 0)
                A.AddEnd(val);
            else
                A.AddFront(val);
        }
        cout << "Unsorted array of random values" << endl;
        A.Print();

        cout << "Sorted array of random values" << endl;
        A.CountingSort(max);
        A.Print();
        cout << endl;
        A.Clear();
    }
    cout << endl;

    cout << "Biiiig test!" << endl;

    max = 0;

    for (int i = 0; i < 100000; i++)
    {
        int val = rand() % 10000;

        if (val > max)
            max = val;

        if (i % 2 == 0)
            A.AddEnd(val);
        else
            A.AddFront(val);
    }

    A.CountingSort(max);
    A.Print();
    cout << endl << endl;



    CDA<char> B;

    cout << "Testing with characters." << endl;
    cout << "Testing AddEnd & AddFront" << endl << endl;

    B.AddFront('D');
    B.Print();
    // D

    B.AddEnd('P');
    B.Print();
    // D P

    B.AddFront('H');
    B.Print();
    // H D P

    B.AddEnd('R');
    B.Print();
    // H D P R

    B.AddEnd('L');
    B.Print();
    // H D P R L

    B.AddFront('G');
    B.Print();
    // G H D P R L

    B.AddEnd('B');
    B.Print();
    // G H D P R L B

    B.AddFront('A');
    B.Print();
    // A G H D P R L B

    B.AddFront('V');
    B.Print();
    // V A G H D P R L B

    B.AddEnd('W');
    B.Print();
    // V A G H D P R L B W 

    B.AddEnd('Q');
    B.Print();
    // V A G H D P R L B W Q

    B.AddFront('O');
    B.Print();
    // O V A G H D P R L B W Q 

    B.AddEnd('X');
    B.Print();
    // O V A G H D P R L B W Q X 

    B.AddFront('E');
    B.Print();
    // E O V A G H D P R L B W Q X 

    B.AddFront('H');
    B.Print();
    // H E O V A G H D P R L B W Q X 

    B.AddEnd('Z');
    B.Print();
    // H E O V A G H D P R L B W Q X Z 

    cout << "B's size is: " << B.Length() << endl;
    // 16
    cout << "B's capacity is: " << B.Capacity() << endl << endl << endl;
    // 16

    cout << "Testing overloaded [] operator" << endl << endl;

    cout << "B[0] is: " << B[0] << endl; // H
    cout << "B[1] is: " << B[1] << endl; // E
    cout << "B[2] is: " << B[2] << endl; // O
    cout << "B[3] is: " << B[3] << endl; // V
    cout << "B[4] is: " << B[4] << endl; // A
    cout << "B[5] is: " << B[5] << endl; // G
    cout << "B[6] is: " << B[6] << endl; // H
    cout << "B[7] is: " << B[7] << endl; // D
    cout << "B[8] is: " << B[8] << endl; // P
    cout << "B[9] is: " << B[9] << endl; // R
    cout << "B[10] is: " << B[10] << endl; // L
    cout << "B[11] is: " << B[11] << endl; // B
    cout << "B[12] is: " << B[12] << endl; // W
    cout << "B[13] is: " << B[13] << endl; // Q 
    cout << "B[14] is: " << B[14] << endl; // X
    cout << "B[15] is: " << B[15] << endl; // Z
    cout << "B[16] is: " << B[16] << endl << endl; // No such value. Should output out of bounds error and return a trash value

    cout << "Testing DelEnd & DelFront" << endl << endl;

    B.DelEnd();
    B.Print();
    // H E O V A G H D P R L B W Q X

    B.DelEnd();
    B.Print();
    // H E O V A G H D P R L B W Q 

    B.DelFront();
    B.Print();
    // E O V A G H D P R L B W Q 

    B.DelFront();
    B.Print();
    // O V A G H D P R L B W Q 

    B.DelFront();
    B.Print();
    // V A G H D P R L B W Q 

    B.DelEnd();
    B.Print();
    // V A G H D P R L B W 

    B.DelEnd();
    B.Print();
    // V A G H D P R L B 

    B.DelEnd();
    B.Print();
    // V A G H D P R L 

    B.DelEnd();
    B.Print();
    // V A G H D P R 

    B.DelFront();
    B.Print();
    // A G H D P R 

    B.DelFront();
    B.Print();
    // G H D P R 

    B.DelFront();
    B.Print();
    // H D P R 

    B.DelEnd();
    B.Print();
    // H D P 

    B.DelEnd();
    B.Print();
    // H D

    B.DelEnd();
    B.Print();
    // H

    B.DelEnd();
    B.Print();
    // blank

    B.DelFront(); // Deleting past Size = 0
    B.Print();
    // blank

    cout << "B's size is: " << B.Length() << endl;
    // 0
    cout << "B's capacity is: " << B.Capacity() << endl << endl << endl;
    // 1

    cout << "Testing SetOrdered" << endl << endl;

    cout << "B's SetOrdered returns: " << B.SetOrdered() << endl;
    // -1

    cout << "Repopulating array.." << endl;

    B.AddFront('D');
    B.AddEnd('P');
    B.AddFront('H');
    B.AddEnd('R');
    B.AddEnd('L');
    B.AddFront('G');
    B.AddEnd('B');
    B.AddFront('A');
    B.AddFront('V');
    B.AddEnd('W');
    B.AddEnd('Q');
    B.AddFront('O');
    B.AddEnd('X');
    B.AddFront('E');
    B.AddFront('H');
    B.AddEnd('Z');

    B.Print();
    cout << endl;
    // H E O V A G H D P R L B W Q X Z

    cout << "Testing SetOrdered (with one CountingSort & one InsertionSort test for good measure)" << endl << endl;

    cout << "B's SetOrdered returns: " << B.SetOrdered() << endl << endl;
    // -1

    B.Print();
    cout << endl;

    B.CountingSort(90); // ASCII value of Z
    cout << "B's SetOrdered returns: " << B.SetOrdered() << endl << endl;
    // 1

    B.Print();
    cout << endl;
    // A B D E G H H L O P Q R V W X Z 

    B.AddFront('Z');
    cout << "B's SetOrdered returns: " << B.SetOrdered() << endl << endl;
    // -1

    B.Print();
    cout << endl;
    // Z A B D E G H H L O P Q R V W X Z

    B.InsertionSort();
    cout << "B's SetOrdered returns: " << B.SetOrdered() << endl << endl;
    // 1

    B.Print();
    cout << endl;
    // A B D E G H H L O P Q R V W X Z Z 

    B.AddEnd('A');
    cout << "B's SetOrdered returns: " << B.SetOrdered() << endl << endl;
    // -1

    B.Print();
    cout << endl;
    // A B D E G H H L O P Q R V W X Z Z A 

    B.QuickSort();
    cout << "B's SetOrdered returns: " << B.SetOrdered() << endl << endl;
    // 1

    B.Print();
    cout << endl;
    // A A B D E G H H L O P Q R V W X Z Z 

    cout << "Clearing array. Repopulating with previous values..." << endl;
    B.Clear(); // Test of Clear method

    B.AddFront('D');
    B.AddEnd('P');
    B.AddFront('H');
    B.AddEnd('R');
    B.AddEnd('L');
    B.AddFront('G');
    B.AddEnd('B');
    B.AddFront('A');
    B.AddFront('V');
    B.AddEnd('W');
    B.AddEnd('Q');
    B.AddFront('O');
    B.AddEnd('X');
    B.AddFront('E');
    B.AddFront('H');
    B.AddEnd('Z');

    B.Print();
    // H E O V A G H D P R L B W Q X Z

    cout << "Testing Select method: " << endl << endl;

    cout << "The smallest element in the array is: " << B.Select(1) << endl; // A
    cout << "The second smallest element in the array is: " << B.Select(2) << endl; // B
    cout << "The third smallest element in the array is: " << B.Select(3) << endl; // D
    cout << "The fourth smallest element in the array is: " << B.Select(4) << endl; // E
    cout << "The fifth smallest element in the array is: " << B.Select(5) << endl; // G
    cout << "The sixth smallest element in the array is: " << B.Select(6) << endl; // H
    cout << "The seventh smallest element in the array is: " << B.Select(7) << endl; // H
    cout << "The eighth smallest element in the array is: " << B.Select(8) << endl; // L
    cout << "The ninth smallest element in the array is: " << B.Select(9) << endl; // O
    cout << "The tenth smallest element in the array is: " << B.Select(10) << endl; // P
    cout << "The eleventh smallest element in the array is: " << B.Select(11) << endl; // Q
    cout << "The twelfth smallest element in the array is: " << B.Select(12) << endl; // R
    cout << "The thirteenth smallest element in the array is: " << B.Select(13) << endl; // V
    cout << "The fourteenth smallest element in the array is: " << B.Select(14) << endl; // W
    cout << "The fifteenth smallest element in the array is: " << B.Select(15) << endl; // X
    cout << "The sixteenth smallest element in the array is: " << B.Select(16) << endl; // Z
    cout << "The seventeenth smallest element in the array is: " << B.Select(17) << endl << endl; // No such value. Should return out of bounds error.

    cout << "Testing Linear Search method" << endl << endl;

    B.Clear();
    //  Clearing and repopulating
    B.AddFront('D');
    B.AddEnd('P');
    B.AddFront('H');
    B.AddEnd('R');
    B.AddEnd('L');
    B.AddFront('G');
    B.AddEnd('B');
    B.AddFront('A');
    B.AddFront('V');
    B.AddEnd('W');
    B.AddEnd('Q');
    B.AddFront('O');
    B.AddEnd('X');
    B.AddFront('E');
    B.AddFront('H');
    B.AddEnd('Z');

    B.Print();

    // All should use linear search.

    cout << "Searching for 'D' returns index " << B.Search('D') << endl; // 7
    cout << "Searching for 'P' returns index " << B.Search('P') << endl; // 8
    cout << "Searching for 'R' returns index " << B.Search('R') << endl; // 9
    cout << "Searching for 'L' returns index " << B.Search('L') << endl; // 10
    cout << "Searching for 'G' returns index " << B.Search('G') << endl; // 5
    cout << "Searching for 'B' returns index " << B.Search('B') << endl; // 11
    cout << "Searching for 'A' returns index " << B.Search('A') << endl; // 4
    cout << "Searching for 'V' returns index " << B.Search('V') << endl; // 3
    cout << "Searching for 'W' returns index " << B.Search('W') << endl; // 12
    cout << "Searching for 'Q' returns index " << B.Search('Q') << endl; // 13
    cout << "Searching for 'O' returns index " << B.Search('O') << endl; // 2
    cout << "Searching for 'X' returns index " << B.Search('X') << endl; // 14
    cout << "Searching for 'E' returns index " << B.Search('E') << endl; // 1
    cout << "Searching for 'Z' returns index " << B.Search('Z') << endl << endl; // 15

    cout << "Testing Binary Search method" << endl << endl;

    B.QuickSort(); // Sort it real quick
    B.Print();

    cout << "Searching for 'D' returns index " << B.Search('D') << endl; // 2
    cout << "Searching for 'P' returns index " << B.Search('P') << endl; // 9
    cout << "Searching for 'R' returns index " << B.Search('R') << endl; // 11
    cout << "Searching for 'L' returns index " << B.Search('L') << endl; // 7
    cout << "Searching for 'G' returns index " << B.Search('G') << endl; // 4
    cout << "Searching for 'B' returns index " << B.Search('B') << endl; // 1
    cout << "Searching for 'A' returns index " << B.Search('A') << endl; // 0
    cout << "Searching for 'V' returns index " << B.Search('V') << endl; // 12
    cout << "Searching for 'W' returns index " << B.Search('W') << endl; // 13
    cout << "Searching for 'Q' returns index " << B.Search('Q') << endl; // 10
    cout << "Searching for 'O' returns index " << B.Search('O') << endl; // 8
    cout << "Searching for 'X' returns index " << B.Search('X') << endl; // 14
    cout << "Searching for 'E' returns index " << B.Search('E') << endl; // 3
    cout << "Searching for 'Z' returns index " << B.Search('Z') << endl << endl; // 15

    cout << "Testing InsertionSort method" << endl;

    B.Clear();

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 25; j++) // Populating with random values
        {
            char val = rand() % (90 - 65 + 1) + 65;

            if (j % 2 == 0)
                B.AddEnd(val);
            else
                B.AddFront(val);
        }
        cout << "Unsorted array of random values" << endl;
        B.Print();

        cout << "Sorted array of random values" << endl;
        B.InsertionSort();
        B.Print();
        cout << endl;
        B.Clear();
    }
    cout << endl;

    cout << "Biiiig test!" << endl;

    for (int i = 0; i < 50000; i++) // Populating with random values. 50,000 is about the most my InsertionSort can handle in a "timely" fashion. Took about 6 seconds on my laptop.
    {
        char val = rand() % (90 - 65 + 1) + 65;

        if (i % 2 == 0)
            B.AddEnd(val);
        else
            B.AddFront(val);
    }

    B.InsertionSort();
    B.Print();
    cout << endl << endl;

    cout << "Testing QuickSort method" << endl;

    B.Clear();

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 25; j++) // Populating with random values
        {
            char val = rand() % (90 - 65 + 1) + 65;

            if (j % 2 == 0)
                B.AddEnd(val);
            else
                B.AddFront(val);
        }
        cout << "Unsorted array of random values" << endl;
        B.Print();

        cout << "Sorted array of random values" << endl;
        B.QuickSort();
        B.Print();
        cout << endl;
        B.Clear();
    }
    cout << endl;

    cout << "Biiiig test!" << endl;

    for (int i = 0; i < 1000000; i++)
    {
        char val = rand() % (90 - 65 + 1) + 65;

        if (i % 2 == 0)
            B.AddEnd(val);
        else
            B.AddFront(val);
    }

    B.QuickSort();
    B.Print();
    cout << endl << endl;

    cout << "Testing CountingSort method" << endl;

    B.Clear();

    for (int i = 0; i < 10; i++)
    {
        max = 0;
        for (int j = 0; j < 25; j++) // Populating with random values
        {
            char val = rand() % (90 - 65 + 1) + 65;

            if (j % 2 == 0)
                B.AddEnd(val);
            else
                B.AddFront(val);
        }
        cout << "Unsorted array of random values" << endl;
        B.Print();

        cout << "Sorted array of random values" << endl;
        B.CountingSort(90); // ASCII value of 'Z'
        B.Print();
        cout << endl;
        B.Clear();
    }
    cout << endl;

    cout << "Biiiig test!" << endl;

    for (int i = 0; i < 100000; i++)
    {
        char val = rand() % (90 - 65 + 1) + 65;

        if (i % 2 == 0)
            B.AddEnd(val);
        else
            B.AddFront(val);
    }

    B.CountingSort(90); // ASCII value of 'Z'
    B.Print();
    cout << endl << endl;



    cout << "Testing with strings." << endl;
    cout << "Testing AddEnd & AddFront" << endl << endl;

    CDA<string> C;

    C.AddFront("Dusty");
    C.Print();
    // Dusty

    C.AddEnd("Pressure");
    C.Print();
    // Dusty Pressure

    C.AddFront("Harambe");
    C.Print();
    // Harambe Dusty Pressure

    C.AddEnd("Rat");
    C.Print();
    // Harambe Dusty Pressure Rat

    C.AddEnd("Lounge");
    C.Print();
    // Harambe Dusty Pressure Rat Lounge

    C.AddFront("Grandma");
    C.Print();
    // Grandma Harambe Dusty Pressure Rat Lounge

    C.AddEnd("Bro");
    C.Print();
    // Grandma Hat Dusty Pressure Rat Lounge Bro

    C.AddFront("This class kind of sucks");
    C.Print();
    // This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro

    C.AddFront("Ventriloquist");
    C.Print();
    // Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Br0

    C.AddEnd("Wander");
    C.Print();
    // Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander

    C.AddEnd("Question");
    C.Print();
    // Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question

    C.AddFront("Oregon");
    C.Print();
    // Oregon Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question

    C.AddEnd("Xylophone");
    C.Print();
    // Oregon Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question Xylophone

    C.AddFront("Egg egg egg");
    C.Print();
    // Egg egg egg Oregon Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question Xylophone

    C.AddFront("Hat");
    C.Print();
    // Hat Egg egg egg Oregon Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question Xylophone

    C.AddEnd("Zip Car");
    C.Print();
    // Hat Egg egg egg Oregon Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question Xylophone Zip Car

    cout << "C's size is: " << C.Length() << endl;
    // 16
    cout << "C's capacity is: " << C.Capacity() << endl << endl << endl;
    // 16

    cout << "Testing overloaded [] operator" << endl << endl;

    cout << "C[0] is: " << C[0] << endl; // Hat
    cout << "C[1] is: " << C[1] << endl; // Egg egg egg
    cout << "C[2] is: " << C[2] << endl; // Oregon
    cout << "C[3] is: " << C[3] << endl; // Ventriloquist
    cout << "C[4] is: " << C[4] << endl; // This class kind of sucks
    cout << "C[5] is: " << C[5] << endl; // Grandma
    cout << "C[6] is: " << C[6] << endl; // Harambe
    cout << "C[7] is: " << C[7] << endl; // Dusty
    cout << "C[8] is: " << C[8] << endl; // Pressure
    cout << "C[9] is: " << C[9] << endl; // Rat
    cout << "C[10] is: " << C[10] << endl; // Lounge
    cout << "C[11] is: " << C[11] << endl; // Bro
    cout << "C[12] is: " << C[12] << endl; // Wander
    cout << "C[13] is: " << C[13] << endl; // Question
    cout << "C[14] is: " << C[14] << endl; // Xylophone
    cout << "C[15] is: " << C[15] << endl; // Zip Car
    cout << "C[16] is: " << C[16] << endl << endl; // No such value. Should output out of bounds error and return a trash value

    cout << "Testing DelEnd & DelFront" << endl << endl;

    C.DelEnd();
    C.Print();
    // Hat Egg egg egg Oregon Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question Xylophone

    C.DelEnd();
    C.Print();
    // Hat Egg egg egg Oregon Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question 

    C.DelFront();
    C.Print();
    // Egg egg egg Oregon Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question

    C.DelFront();
    C.Print();
    // Oregon Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question 

    C.DelFront();
    C.Print();
    // Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question

    C.DelEnd();
    C.Print();
    // Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander 

    C.DelEnd();
    C.Print();
    // Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro 

    C.DelEnd();
    C.Print();
    // Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge 

    C.DelEnd();
    C.Print();
    // Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat 

    C.DelFront();
    C.Print();
    // This class kind of sucks Grandma Harambe Dusty Pressure Rat 

    C.DelFront();
    C.Print();
    // Grandma Harambe Dusty Pressure Rat 

    C.DelFront();
    C.Print();
    // Harambe Dusty Pressure Rat 

    C.DelEnd();
    C.Print();
    // Harambe Dusty Pressure

    C.DelEnd();
    C.Print();
    // Harambe Dusty 

    C.DelEnd();
    C.Print();
    // Harambe

    C.DelEnd();
    C.Print();
    // blank

    C.DelFront(); // Deleting past Size = 0
    C.Print();
    // blank

    cout << "C's size is: " << C.Length() << endl;
    // 0
    cout << "C's capacity is: " << C.Capacity() << endl << endl << endl;
    // 1

    cout << "Testing SetOrdered" << endl << endl;

    cout << "C's SetOrdered returns: " << C.SetOrdered() << endl;
    // -1

    cout << "Repopulating array.." << endl;

    C.AddFront("Dusty");
    C.AddEnd("Pressure");
    C.AddFront("Harambe");
    C.AddEnd("Rat");
    C.AddEnd("Lounge");
    C.AddFront("Grandma");
    C.AddEnd("Bro");
    C.AddFront("This class kind of sucks");
    C.AddFront("Ventriloquist");
    C.AddEnd("Wander");
    C.AddEnd("Question");
    C.AddFront("Oregon");
    C.AddEnd("Xylophone");
    C.AddFront("Egg egg egg");
    C.AddFront("Hat");
    C.AddEnd("Zip Car");

    C.Print();
    cout << endl;
    // Hat Egg egg egg Oregon Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question Xylophone Zip Car

    cout << "Testing SetOrdered (with one CountingSort & one InsertionSort test for good measure)" << endl << endl;

    cout << "C's SetOrdered returns: " << C.SetOrdered() << endl << endl;
    // -1

    C.Print();
    cout << endl;

    C.QuickSort();
    cout << "C's SetOrdered returns: " << C.SetOrdered() << endl << endl;
    // 1

    C.Print();
    cout << endl;
    // Bro Dusty Egg egg egg Grandma Harambe Hat Lounge Oregon Pressure Question Rat This class kind of sucks Ventriloquist Wander Xylophone Zip Car

    C.AddFront("Toyota Man");
    cout << "C's SetOrdered returns: " << C.SetOrdered() << endl << endl;
    // -1

    C.Print();
    cout << endl;
    // Toyota Man Bro Dusty Egg egg egg Grandma Harambe Hat Lounge Oregon Pressure Question Rat This class kind of sucks Ventriloquist Wander Xylophone Zip Car

    C.InsertionSort();
    cout << "C's SetOrdered returns: " << C.SetOrdered() << endl << endl;
    // 1

    C.Print();
    cout << endl;
    // Bro Dusty Egg egg egg Grandma Harambe Hat Lounge Oregon Pressure Question Rat This class kind of sucks Toyota Man Ventriloquist Wander Xylophone Zip Car

    C.AddEnd("Armadillo");
    cout << "C's SetOrdered returns: " << C.SetOrdered() << endl << endl;
    // -1

    C.Print();
    cout << endl;
    // Bro Dusty Egg egg egg Grandma Harambe Hat Lounge Oregon Pressure Question Rat This class kind of sucks Toyota Man Ventriloquist Wander Xylophone Zip Car Armadillo

    C.QuickSort();
    cout << "C's SetOrdered returns: " << C.SetOrdered() << endl << endl;
    // 1

    C.Print();
    cout << endl;
    // Armadillo Bro Dusty Egg egg egg Grandma Harambe Hat Lounge Oregon Pressure Question Rat This class kind of sucks Toyota Man Ventriloquist Wander Xylophone Zip Car

    cout << "Clearing array. Repopulating with previous values..." << endl;
    C.Clear(); // Test of Clear method

    C.AddFront("Dusty");
    C.AddEnd("Pressure");
    C.AddFront("Harambe");
    C.AddEnd("Rat");
    C.AddEnd("Lounge");
    C.AddFront("Grandma");
    C.AddEnd("Bro");
    C.AddFront("This class kind of sucks");
    C.AddFront("Ventriloquist");
    C.AddEnd("Wander");
    C.AddEnd("Question");
    C.AddFront("Oregon");
    C.AddEnd("Xylophone");
    C.AddFront("Egg egg egg");
    C.AddFront("Hat");
    C.AddEnd("Zip Car");

    C.Print();
    // Hat Egg egg egg Oregon Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question Xylophone Zip Car

    cout << "Testing Select method: " << endl << endl;

    cout << "The smallest element in the array is: " << C.Select(1) << endl; // Bro
    cout << "The second smallest element in the array is: " << C.Select(2) << endl; // Dusty
    cout << "The third smallest element in the array is: " << C.Select(3) << endl; // Egg egg egg
    cout << "The fourth smallest element in the array is: " << C.Select(4) << endl; // Grandma
    cout << "The fifth smallest element in the array is: " << C.Select(5) << endl; // Harambe
    cout << "The sixth smallest element in the array is: " << C.Select(6) << endl; // Hat
    cout << "The seventh smallest element in the array is: " << C.Select(7) << endl; // Lounge
    cout << "The eighth smallest element in the array is: " << C.Select(8) << endl; // Oregon
    cout << "The ninth smallest element in the array is: " << C.Select(9) << endl; // Pressure
    cout << "The tenth smallest element in the array is: " << C.Select(10) << endl; // Question
    cout << "The eleventh smallest element in the array is: " << C.Select(11) << endl; // Rat
    cout << "The twelfth smallest element in the array is: " << C.Select(12) << endl; // This class kind of sucks
    cout << "The thirteenth smallest element in the array is: " << C.Select(13) << endl; // Ventriloquist
    cout << "The fourteenth smallest element in the array is: " << C.Select(14) << endl; // Wander
    cout << "The fifteenth smallest element in the array is: " << C.Select(15) << endl; // Xylophone
    cout << "The sixteenth smallest element in the array is: " << C.Select(16) << endl; // Zip Car
    cout << "The seventeenth smallest element in the array is: " << C.Select(17) << endl << endl; // No such value. Should return out of bounds error.

    cout << "Testing Linear Search method" << endl << endl;

    C.Clear();
    //  Clearing and repopulating
    C.AddFront("Dusty");
    C.AddEnd("Pressure");
    C.AddFront("Harambe");
    C.AddEnd("Rat");
    C.AddEnd("Lounge");
    C.AddFront("Grandma");
    C.AddEnd("Bro");
    C.AddFront("This class kind of sucks");
    C.AddFront("Ventriloquist");
    C.AddEnd("Wander");
    C.AddEnd("Question");
    C.AddFront("Oregon");
    C.AddEnd("Xylophone");
    C.AddFront("Egg egg egg");
    C.AddFront("Hat");
    C.AddEnd("Zip Car");

    C.Print();

    // Hat Egg egg egg Oregon Ventriloquist This class kind of sucks Grandma Harambe Dusty Pressure Rat Lounge Bro Wander Question Xylophone Zip Car

    cout << "Searching for 'Dusty' returns index " << C.Search("Dusty") << endl; // 7
    cout << "Searching for 'Pressure' returns index " << C.Search("Pressure") << endl; // 8
    cout << "Searching for 'Rat' returns index " << C.Search("Rat") << endl; // 9
    cout << "Searching for 'Lounge' returns index " << C.Search("Lounge") << endl; // 10
    cout << "Searching for 'Grandma' returns index " << C.Search("Grandma") << endl; // 5
    cout << "Searching for 'Bro' returns index " << C.Search("Bro") << endl; // 11
    cout << "Searching for 'This class kind of sucks' returns index " << C.Search("This class kind of sucks") << endl; // 4
    cout << "Searching for 'Ventriloquist' returns index " << C.Search("Ventriloquist") << endl; // 3
    cout << "Searching for 'Wander' returns index " << C.Search("Wander") << endl; // 12
    cout << "Searching for 'Question' returns index " << C.Search("Question") << endl; // 13
    cout << "Searching for 'Oregon' returns index " << C.Search("Oregon") << endl; // 2
    cout << "Searching for 'Xylophone' returns index " << C.Search("Xylophone") << endl; // 14
    cout << "Searching for 'Egg egg egg' returns index " << C.Search("Egg egg egg") << endl; // 1
    cout << "Searching for 'Zip Car' returns index " << C.Search("Zip Car") << endl; // 15
    cout << "Searching for 'Harambe' returns index " << C.Search("Harambe") << endl; // 6
    cout << "Searching for 'Hat' returns index " << C.Search("Hat") << endl << endl; // 0

    cout << "Testing Binary Search method" << endl << endl;

    C.QuickSort(); // Sort it real quick
    C.Print();

    cout << "Searching for 'Dusty' returns index " << C.Search("Dusty") << endl; // 1
    cout << "Searching for 'Pressure' returns index " << C.Search("Pressure") << endl; // 8
    cout << "Searching for 'Rat' returns index " << C.Search("Rat") << endl; // 10
    cout << "Searching for 'Lounge' returns index " << C.Search("Lounge") << endl; // 6
    cout << "Searching for 'Grandma' returns index " << C.Search("Grandma") << endl; // 3
    cout << "Searching for 'Bro' returns index " << C.Search("Bro") << endl; // 0
    cout << "Searching for 'This class kind of sucks' returns index " << C.Search("This class kind of sucks") << endl; // 11
    cout << "Searching for 'Ventriloquist' returns index " << C.Search("Ventriloquist") << endl; // 12
    cout << "Searching for 'Wander' returns index " << C.Search("Wander") << endl; // 13
    cout << "Searching for 'Question' returns index " << C.Search("Question") << endl; // 9
    cout << "Searching for 'Oregon' returns index " << C.Search("Oregon") << endl; // 7
    cout << "Searching for 'Xylophone' returns index " << C.Search("Xylophone") << endl; // 14
    cout << "Searching for 'Egg egg egg' returns index " << C.Search("Egg egg egg") << endl; // 2
    cout << "Searching for 'Zip Car' returns index " << C.Search("Zip Car") << endl; // 15
    cout << "Searching for 'Harambe' returns index " << C.Search("Harambe") << endl; // 4
    cout << "Searching for 'Hat' returns index " << C.Search("Hat") << endl << endl; // 5

    cout << "Testing InsertionSort method" << endl;

    C.Clear();

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 25; j++) // Populating with random values
        {
            int randomRange = rand() % ((10) - (4) + 1) + (4);

            string word;

            for (int z = 0; z < randomRange; z++)
            {
                char val = rand() % (90 - 65 + 1) + 65;
                word += val;
            }

            if (j % 2 == 0)
                C.AddEnd(word);
            else
                C.AddFront(word);
        }
        cout << "Unsorted array of random values" << endl;
        C.Print();

        cout << "Sorted array of random values" << endl;
        C.InsertionSort();
        C.Print();
        cout << endl;
        C.Clear();
    }
    cout << endl;

    cout << "Biiiig test!" << endl;

    for (int i = 0; i < 10000; i++) // Populating with random values. 10,000 is about the most my InsertionSort can handle in a "timely" fashion. Took about 6 seconds on my laptop.
    {
        int randomRange = rand() % ((10) - (4) + 1) + (4);

        string word;

        for (int z = 0; z < randomRange; z++)
        {
            char val = rand() % (90 - 65 + 1) + 65;
            word += val;
        }

        if (i % 2 == 0)
            C.AddEnd(word);
        else
            C.AddFront(word);
    }

    C.InsertionSort();
    C.Print();
    cout << endl << endl;

    cout << "Testing QuickSort method" << endl;

    C.Clear();

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 25; j++) // Populating with random values
        {
            int randomRange = rand() % ((10) - (4) + 1) + (4);

            string word;

            for (int z = 0; z < randomRange; z++)
            {
                char val = rand() % (90 - 65 + 1) + 65;
                word += val;
            }

            if (j % 2 == 0)
                C.AddEnd(word);
            else
                C.AddFront(word);
        }
        cout << "Unsorted array of random values" << endl;
        C.Print();

        cout << "Sorted array of random values" << endl;
        C.QuickSort();
        C.Print();
        cout << endl;
        C.Clear();
    }
    cout << endl;

    cout << "Biiiig test!" << endl;

    for (int i = 0; i < 100000; i++)
    {
        int randomRange = rand() % ((10) - (4) + 1) + (4);

        string word;

        for (int z = 0; z < randomRange; z++)
        {
            char val = rand() % (90 - 65 + 1) + 65;
            word += val;
        }

        if (i % 2 == 0)
            C.AddEnd(word);
        else
            C.AddFront(word);
    }

    C.QuickSort();
    C.Print();
    cout << endl << endl;

    return 0;
}