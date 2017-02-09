#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


bool CheckStringforDigit ( string a );
void PrintEncryptText(string p, string k);

int main(int argc, string argv[]) {
    
    //If the user puts types two command line arguments it continues if not it throws an error
    if( argc == 2) {
        
        //If the command line argument contains no digits it continues if not throws error
        if(!CheckStringforDigit(argv[1])) {
            
            //store the command line argument so we can use it as a key
            string key = argv[1];
            
            //get a string from the user that they want to encrypt
            printf("plaintext:");
            string plainText = get_string();
            
            //make sure the string the user returned is ok
            if(plainText != NULL) {
                
                //encrypts the texts and prints to the terminal 
                //see PrintEncryptedText()
                printf("ciphertext:");
                PrintEncryptText(plainText, key);
                
                printf("\n");
                
                return 0;
                 
            } else { return 1; }
            
            
        } else { printf("you returned a digit, please enter a string\n"); return 1; }
        
    } else {
       printf("User must enter a command line argument!\n");
       return 1;
    }
    
}







//A function that checks a string for numeric chars and returns a bool
bool CheckStringforDigit ( string a ) {
    
    for (int i = 0, n = strlen(a); i < n; i++ ) {
        if ( isdigit(a[i])) {
            return true;
        }
    }
    
    return false;
}


//A function that takes a plain text trsing and uses a key string to rotate the chars in the text string

void PrintEncryptText(string p, string k) {
    
    //block will keep track of the number of times that the key has to wait for non alpha chars
    int block = 0;
    
    //loop through each individual char in the plain text string    
    for(int i = 0, n = strlen(p); i < n; i++) {
        
        //if the char is an alpha it will contine if not just print the char
        if( isalpha(p[i]) ) {
            
            //checks the slpha char for case
            if(isupper(p[i])) {
                
                //takes the the key and makes sure that the key only progresses for alpha chars
                //find the number of positions that the key converts to
                //add the key to rotate the char in the text making shure that if the rotation casuses the char to go beyond 'z' that it will loop back around to a
                 printf("%c",( ( p[i] + ( ( ( toupper( k[(i - block) % strlen( k ) ] ) - 65 ) % 26 ) ) - 65 ) % 26 ) + 65 );                       
                
            } else {
                printf("%c", ( ( p[i] + ( ( ( tolower( k[(i - block) % strlen( k ) ] ) - 97 ) % 26 ) ) - 97 ) % 26 ) + 97 );
            }
        } else {
            printf("%c", p[i]);
            block ++;
        }
    }
    
}
    
