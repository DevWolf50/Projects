#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    
    //get name from user so we can find initials
    string name = get_string();
    
    //check that name is not null
    if (name != NULL) {
        
        //loop over evry char in the name so we can deterimne which char to use as an initial
        for (int i = 0, n = strlen(name); i < n; i++) {
    
            //check to see if the first char is not a string and if so then print it capitlized
            if ( i == 0 && name[i] != ' ') {
                printf("%c", toupper(name[i]));
            
            //check to see if the char is a string and that the next char is not a string and that the next index is still within the string, if so then print it capitilized
            } else if (name[i] == ' ' && name[i + 1] != ' ' && i + 1 < n ) {
                printf("%c", toupper(name[i + 1]));
            }
        }
        
        //print a new line so all the initials are on one line together
        printf("\n");
    }
}