/**
This program will crack a crypted password up to 4 chars long and only contains alphabetical characters
This program takes a 4 character hashed password that has been encrypted with c's crypt as a command line argument
This program will return that password unecrypted
*/


#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <crypt.h>

int main(int argc, string argv[]) {
    if(argc == 2) { //making sure that we dont have more than one comman line argument
        string pw = argv[1]; //storing the command line argument as the hashed password
        char guess[5];  //init an array that will hold our guess password
        char salt[3] = {argv[1][0],argv[1][1]}; //storing the first two chars of the hashed password as the "salt" per man crypt

        //Looping through the A to z so we can assign that char to the an array index(guess)
        for ( char i = 'A'; i <= 'z' ; i++) {
            guess[0] = i;

            //every time we assign the index to the next alphabet letter we need to clear the chars out of the rest of the array
            guess[1] = 0;
            guess[2] = 0;
            guess[3] = 0;

            string m = crypt(guess, salt);  //encyrpt and store the guess so we can compare the hashed guess to the hashed password(pw)

            //compares the hashed guess(m) to the hashed password(pw) if there is a match then print a message and end the program
            if( strcmp(pw, m) == 0) {
                printf("It worked, %s\n", guess);
                return 0;
            }

            //Once we hit Z we change i to the ascii code right before letter a
            if(i == 'Z') {i = 96;}

            //this process happens for each index, rotating the alphabent adding that char to the guess string and then encrypting and comparing
            //I need to refactor the design to eliminate repition
            for(char b = 'A'; b <= 'z'; b++) {
                guess[1] = b;
                guess[2] = 0;
                guess[3] = 0;

                m = crypt(guess, salt);
                if( strcmp(pw, m) == 0) {
                    printf("It worked, %s\n", guess);
                    return 0;
                }
                if(b == 'Z') {b = 96;}

                for(char c = 'A'; c <= 'z'; c++) {
                    guess[2] = c;
                    guess[3] = 0;

                    m = crypt(guess, salt);
                    if( strcmp(pw, m) == 0) {
                        printf("It worked, %s\n", guess);
                        return 0;
                    }
                    if(c == 'Z') {c = 96;}


                    for( char d = 'A'; d <= 'z'; d++) {
                        guess[3] = d;

                        m = crypt(guess, salt);
                        if( strcmp(pw, m) == 0) {
                            printf("It worked, %s\n", guess);
                            return 0;
                        }

                        if(d == 'Z') {d = 96;}

                    }
                }
            }


        }

        //if there was never a match, return an error message and end the program
        printf("No match, go ahead and cry\n");

        return 0;
    } else {
        printf("error, please provide one command line argument\n");
        return 1;
    }
}




//notes i made during building This

//use crypt to generate hashs and compare them to
//passwords are no longer than 4 chars
//each password has been encrypted by cs crypt function
//each password is completely made up of clpha chars



//how crypt works
//key is a users typed password
//salt is a two-char string used to encrypt the password
//first 2 chars of a hashed password
//consider storing an array of 5biits, one bit for each char for a total of 4 then a bit for the back slash 0


//create a loop that will loop every char and hash it then compare
//increase the single char by one if there isnt everytime you go through all the chars in the alophabet


//crypt a
//check a
//if good then end
//check aa
//if good then end
//check ab



//loops through A to z
//assigns an index of the guess with that alphabet character
//encrypts the guess
//checks to see if the hashed guess matches the hashed password
