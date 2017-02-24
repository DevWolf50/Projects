/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // linear searching: starts at the begining and compares one index at a time to the value

    if ( n < 0) {
        return false;
    }

    for ( int i = 0; i < n; i++ )  {
        if( value == values[i] ) {
            return true;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
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
