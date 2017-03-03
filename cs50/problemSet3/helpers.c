/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

bool binarySearch( int value, int values[], int left, int right );

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{

    if ( n < 0) {

    return false;

    } else {

        //binary search
        return binarySearch( value, values, 0, n - 1 );
    }
}

/**
 * Sorts array of n values.
 * Using Bubbble sort O(n2)
 */
void sort(int values[], int n)
{
    //run through the array
    for ( int i = 0; i < n; i ++) {

        //keep track of swaps
        bool swap = false;

        //run through the array minus the number of spots you dont need to look at anymore(i)
        for (int j = 0; j < n - 1 - i; j++) {

            //bubble sort and track if there was a swap performed
            if (values[j] > values[j + 1] ) {

                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;

                swap = true;
            }
        }

        //if there was no swaps then get out of loop
        if( !swap ) {
            return;
        }
    }

    return;
}



/**
 * Sorts array of n values.
 * Using counting sort O(n)
 */
void sortC(int values[], int n)
{
    //set our known max length, initialize our placer array and then our sorted array
    int maxLength = 65536;
    int placer[maxLength];
    int sorted[n];

    //so we can know which indexes in our placer array are in values array
    for ( int i = 0; i < n; i++ ) {
      placer[ values[i] ] += 1;
    }

    //store the sum of previous elements in each element at each index because this will give us the sorted position
    for (int i = 0; i < maxLength; i++ ) {
      placer[ i + 1 ] += placer[i];
    }

    //fill the sorted array with the values elements using the corresponding placer index
    for ( int i = 0; i < n; i++ ) {
      sorted[ placer[ values[i] ] - 1 ] = values[i];
      placer [ values[i] ] -= 1;

    }

    //set the unsorted values array to the sorted array
    for (int i = 0; i < n; i++) {
      values[i] = sorted[i];
    }

}


/**
 * Uses binary search O(log n). Returns true if the values is in the value array false if it's not. Recursive
 */
bool binarySearch( int value, int values[], int left, int right ) {

    //keep track of when the array will be empty and return false
    if ( right < left ) {
        return false;
    }

    //Find the middle of the array
    int mid = left + ( right - left ) / 2;

    //compare the value to the middle of the array. If it's a match return true, else move the left position and right position accordingly
    if( value == values[ mid ] ) {
        return true;
    } else if ( value < values[ mid ] ) {
        right = mid - 1;
    } else {
        left = mid + 1;
    }

    //return the function
    return binarySearch( value, values, left, right );
}
