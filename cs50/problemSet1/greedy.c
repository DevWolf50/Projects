#include <cs50.h>
#include <math.h>
#include <stdio.h>


int main(void) 
{
    float ch;
    int co = 0;
    
    do 
    {
       printf("Good Morning, How much change is owed?:");
       ch = get_float();
    }
    while (ch < 0);
    
    ch = round(ch*100);

    
    while( ch >= 25 ) {
        co += 1;
        ch -= 25; 
    }
    
    while(ch >= 10 ) {
        co += 1; 
        ch -= 10;
    }
    
    while(ch >= 5 ) {
        co += 1;
        ch -= 5;
    }
    
    while(ch >= 1 ) {
        co += 1;
        ch -= 1;
    }
    
    
    printf("%i\n", co);
}