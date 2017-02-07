#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {
    
    //prompt the user for their name
    string name = get_string();
        
    if(name != NULL) {
        
        //loop through their name so we look over each character
        for(int i = 0, n = strlen(name); i < n; i++) {
            
            
            if( i == 0) {   //print out the first char of the sting capatilized
    
                printf("%c", toupper(name[i]));
                
            } else if (name[i] == ' ') {    //print out the char right after a space within the string capatilized
                
                printf("%c", toupper(name[i + 1]));
            }
        }
        
        //print new line so initials are are on one line together
        printf("\n");
    }
}



