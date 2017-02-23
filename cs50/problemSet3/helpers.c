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
    // TODO: implement an O(n^2) sorting algorithm
    
    int swaps = 1;
    int t = 0;
    while ( swaps > 0 ) {
        swaps = 0;
        for ( int i = 0; i < n - 1 - t; i ++ )  {
            if ( values[i] > values[i + 1] ) {
                int temp = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temp;
                swaps++;
            }
            
        }
        t++;
        for(int i = 0; i < n; i++) {
            printf("%i", values[i]);
        }
        printf("\n");
    }
    
    return;
}


