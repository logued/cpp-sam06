// Pointers, Arrays, Functions   Feb 2023

/**
 * Demonstrates :
 * - passing arrays into functions
 * - using pointers to access array elements passed into functions
 *
 * When a C++ array is passed to a function, what is actually passed in is
 * the ADDRESS of the first element of the array.
 * If we pass an address into a function as an argument, then a pointer parameter
 * (or an array parameter) must be defined in the function header to accept that address.
 *
 * When the address of an object (or array) is passed into a function,
 * the code in the function has access to the object that the pointer parameter is pointing at,
 * and may access and/or change its value.
 * (That is, unless the pointer is defined as a pointer to a 'const object').
 *
 * */

#include <iostream>
using namespace std;

// function prototypes
void increase( int* , int );
void display( const int* , int );

int main()
{
    int x[4] = { 10,20,30,40 };

    cout << "x[] = ";
    display(x, 4);		// passes the address of the array, and the number of elements

    // Remember, the name of array is the address of the first element in the array.
    // The number of elements must also be passed, as the function has no other way of knowing the length
    // of the array.

    increase(x, 4);

    cout << "After increase() \nx[] = ";
    display(x, 4);

    return 0;
}

// increase() accepts an array of ints, and uses a pointer-to-int parameter
// to accept the array and to access each element in the array
// by incrementing the pointer.
//
// ptr is a pointer to an int.
// It points to the first element of the array x[].
//
void increase(int* ptr, int length)
{
    // iterate over each array element using the pointer
    for(int i = 0; i < length; i++)
    {
        *ptr = *ptr + 1;         // add 1 to the element that ptr is pointing to.
        ptr++;                   // increment the pointer to point at the next array element
    }
}

/**
 * Use a pointer to a constant int to iterate over each element
 * in the passed array, and output each element by dereferencing the pointer.
 *
 * @param ptr
 * @param length
 */
void display(const int* ptr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << *ptr << ",";
        ptr++;
    }
    cout << endl;
}


//******************************* Exercise *******************************************

//TODO  Q.1.
// Declare two arrays of type int, each of length 5, in main() called y[] and z[]
// Populate the array y[] with five values.
// Write a function called copy(z,y,len) that will accept two array arguments, y and z,
//  - both of type 'pointer to int' -
// and will copy the contents of one array y(source) to the other array  z (target)
// using pointer notation.
// In main(), output z[] to confirm that your function has worked.
// You will need to pass in the length of the source array.
// Here is the function prototype:
//    void copy(int* pTarget, int* pSource, int length)

//TODO Q.2
// Write a function palindrome() that will accept an array of int
// and will output the elements in order, directly followed by the
// elements in reverse order to give a palindrome effect.
// e.g. if we use x[] from above, the output should be:
//          10,20,30,40,40,30,20,10
//



