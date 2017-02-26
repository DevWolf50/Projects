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

  //check for error
  if ( n < 0) {
  return false;
  }

  // Binary search:  O(log n)

  //store the length of the values array, store the start of the array, store the end of the array
  int aLength = n;
  int left = 0;
  int right = n - 1;

  //keep splitting the array in half and checking the middle of the array to see if it matches the value
  while ( aLength > 0 ) {
      int half = aLength / 2;
      int middle = right - half;

      if( value == values[middle] ) {
          //success
          return true;
      } else if ( value < values[middle] ) {
          right = middle - 1;
      } else {
          left = middle + 1;
      }

      //reset the current array length
      aLength = right - left + 1;
  }
  //failure
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
