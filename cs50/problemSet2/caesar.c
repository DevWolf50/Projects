//This program will take a numer from a user and use that number as a key to rotate and encrypt a word(s) from the user

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
    
    //checks to make sure that they are 1 command line argument and that its greater than 0
    if ( argc == 2 && argv[1] >= 0 ) {
        
        //store the command line argument as the key
        int k = atoi(argv[1]);
        
        //get a word(s) from a user so we can encrypt it
        printf("plaintext:");
        string s = get_string();

        
        printf("ciphertext:");
        
        //loop over every char within the word(s) 
        for ( int i = 0, n = strlen(s); i < n; i++ ) {
            
           //if the char is an alphabet letter then continue if not then print char
           if ( isalpha(s[i]) ) {
                
                //checks to see if the char is upper case or lower case
                //then rotate each char by the key making sure that if the char becomes bigger then the respective letter z that it will wrap back around
                if ( isupper(s[i])) {
                    printf("%c", ( (s[i] + k - 65 ) % 26) + 65 );
                } else {
                    printf("%c", ( (s[i] + k - 97 ) % 26) + 97 );
                }
               
           } else {
               printf("%c", s[i]);
           } 
        }
        
        //print new line so the the cypher text is one one line
        printf("\n");
        
        //return the good to go code
        return 0;
        
        
    } else {    //if there are more than 1 command line argument or if its a negative number return an error
        printf("Error: requires command line argument that is not a negative number. Try again please");
        return 1;
    }
}
