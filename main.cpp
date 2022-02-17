// Pointers, Arrays, Functions   Feb 2022

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

void increase(int* ptr_x, int length)   // ptr_x is a pointer to an int
{                                       // It will point to the first element in the array x[].
    for(int i = 0; i < length; i++)
    {
        *ptr_x = *ptr_x + 1;         // add one to the element that px is pointing to.
        ptr_x++;                     // increment the pointer to point at the next array element
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
// Declare two arrays of type int, of length 5, in main() called y[] and z[]
// Populate array x[] array with five values.
// Write a function called copy() that will accept two array arguments,
//  - both of type 'pointer to int' -
// and will copy the contents of one array (source) to the other array (target)
// using pointer notation.
// Pass in the length of the source array.
// Here is the function prototype:
//    void copy(int* pTarget, int* pSource, int length)


