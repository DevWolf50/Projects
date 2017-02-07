#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main() 
{
    printf("Credit card, please:");
    long long c = get_long_long();
    long long cn = c;
    int i = 0;
    int f = 0;
    int u = 0;

    while( c > 0 ) {
        
        i = ((c % 100)/10);
        u += c % 10;

        int d = i*2;
        
        while( d > 0) {
            
         f += d % 10;
         d /= 10;
         
        }
        
        c /= 100;
    }
    
    int r = (f + u) % 10;
    
    if( r == 0) {
        int cl = 0;

       for(long long n = cn; n > 0; n/=10) {
           cl++;
       }
       
        if( cl == 13 ) {
            if(cn/1000000000000 == 4) {
                printf("VISA\n");
            }
           
       }
       
       
       if( cl == 15 ) {
           if(cn/10000000000000 == 37 ) {
               printf("AMEX\n");
           } 
       }
       
       if( cl == 16) {
           if(cn/100000000000000 == 51 || cn/100000000000000 == 52 || cn/100000000000000 == 53 || cn/100000000000000 == 54 || cn/100000000000000 == 55) {
               printf("MASTERCARD\n");
           } else if (cn/1000000000000000 == 4 ) {
              printf("VISA\n"); 
           }
       }
    
       
    } else {
    
            printf("INVALID\n");
    }
    
  
   return 0;
}