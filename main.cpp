// Pointers, Arrays, Functions   Feb 2026

/**
 * Demonstrates :
 * - passing arrays into functions
 * - using pointers to access arrays passed into functions
 *
 * When an array is passed to a function, what is actually passed is
 * the ADDRESS of the first element of the array.
 * If we pass an address into a function as an argument, then a pointer parameter
 * (or an array parameter) must be defined in the function header to accept the address.
 *
 * When the address of an object (or array) is passed into a function,
 * the code in the function has access to the object that the pointer is pointing at,
 * and may access and/or change its value.
 * (unless the pointer is defined as a pointer to a 'const object').
 *
 * */

#include <iostream>
using namespace std;

void increase(int* , int );  // function prototypes
void display(int* , int );

int main()
{
    int x[4] = { 10,20,30,40 };

    cout << "x[] = ";
    display(x, 4);		// passes the address of the array, and the number of elements

    // Remember, the name of array is the address of the first element in the array.
    // The number of elements must also be passed, as the function has no other way of knowing the length
    // of the array... (Arrays in Java are objects, and have a length field inbuilt)

    increase(x, 4);

    cout << "After increase() \nx[] = ";
    display(x, 4);

    return 0;
}

void increase(int* array_ptr, int length)   // arr_ptr is an array pointer - a pointer to an int
{                                       // It will point to the first element in the array x[].
    for(int i = 0; i < length; i++)
    {
        *array_ptr = *array_ptr + 1;         // add one to the element that arr_ptr is pointing to.
        array_ptr++;                     // increment the pointer to point at the next array element
    }
}

void display(int* array_ptr, int length)    // pointer to int array, length of array
{
    for (int i = 0; i < length; i++)
    {
        cout << *array_ptr << ",";
        array_ptr++;
    }
    cout << endl;
}


//******************************* Exercise *******************************************

//TODO  Q.1.
// Declare two arrays of type int, each of length 5, in main() called y[] and z[]
// Populate the array y[] with five values.
// Write a function called copy() that will accept two array arguments, y and z,
//  - both of type 'pointer to int' -
// and will copy the contents of one array y(source) to the other array  z (target)
// using pointer notation.
// In main(), output z[] to confirm that your function has worked.
// You will need to pass in the length of the source array.
// Here is the function prototype:
//    void copy(int* pTarget, int* pSource, int length)

//TODO Q.2
// Write a function pallindrome() that will accept an array of int
// and will output the elements in order, directly followed by the
// elements in reverse order to give a pallindrome effect.
// e.g. if we use x[] from above, the output should be:
//          10,20,30,40,40,30,20,10
//



