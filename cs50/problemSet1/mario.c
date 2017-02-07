#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int steps = -1;
    
    while(steps < 0 || steps > 24) {
         printf("Height:");
        steps = get_int();
    }
    for(int i = 1; i < steps +1; i++) {
    
        for(int b = 0; b < steps - i; b++) {
            printf(" ");
        }
        
        for(int n = 0; n < i; n++)
        {
          printf("#");  
        }
        for(int g = 0; g < 2; g++) 
        {
            printf(" "); 
        }
        for(int k = 0; k < i; k++)
        {
          printf("#");  
        }
    
        printf("\n");
    } 
        
}