/* Name: Reuben Thomas & Joshua Wee             Class: ES22 
This program is to generate a strong password based on a key that a user inputs 
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>


//declaring
int keygen, total, chr1, next, inNext, i, jump = 0, x = 0, check;
char key[50], pass[200], input[5];
char nextchar = '\0', inNextchar,cont = '!';
typedef int bool;

void clearInput () {
    for (int i = 0; i<5; ++i)
        input[i] = '\0';
}

void addval () {
    next = (int)key[x];
    clearInput();
        if (nextchar != '\0') {
            input[0] = inNextchar;
            nextchar = '\0';
        }
        else {
            sprintf(input, "%d", inNext);
        }
        strcat(pass, input);

        if (x == 0) 
            printf("%dst character = %s\n", x+1, input);     
        else if (x == 1) 
            printf("%dnd character = %s\n", x+1, input);
        else if (x == 2) 
            printf("%drd character = %s\n", x+1, input);
        else 
            printf("%dth character = %s\n", x+1, input);
     
    total = total + next;
}

void hex() {
    inNext = next;
    addval();
//printf("%s\n", key);
//printf("%c\n\n", key[x-1]);
}

void sine() {
    inNext = sin(next)*100;
    addval();
}

void spchar () {
    nextchar   = key[x];
    inNextchar = abs((char)next - 70) + 33;
    addval();
}

void caps () {
    nextchar   = key[x];
    inNextchar = toupper(nextchar);
    addval();
}

void resi () {
    inNext = (1.0/next)*10000;
    addval();
}

void checksum() {
    check    = total % 11;
    nextchar = ((char)check + 96);
    clearInput();
    input[0] = nextchar;
    strcat(pass, input);
    printf("Checksum      = %s\n", input);
}

void main(void) {
    while (cont != 'N') {
        x     = 0;
        total = 0;
        //clearing
        for(int i = 0; i < 50; ++i) {
            key[i] = '\0';
        } 
        for(int i = 0; i <200; ++i) {
            pass[i] = '\0';
            i++;
        }

        //user input
        printf("Enter key: ");
        scanf(" %s", &key);

        //table headings
        printf("\n\n\nGenerating password...");
        
        //calculation for first character
        chr1 = (int)key[0];
        addval();
    //    printf("%15s", pass);

        //calculating subsequent characters
        jump = chr1 % 5;
        while (key[x] != '\0' && key[x] != '\0') {
        
           // x++;
          
            switch (jump) {
                case 1 :
    //                printf("1\n");
                    hex();
                break;
        
                case 2 : 
    //                printf("2\n");
                    sine();
                break;

                case 3 :
    //                printf("3\n");
                    spchar();
                break;

                case 4 :
    //                printf("4\n");
                    caps();
                break;

                case 0 :
    //                printf("5\n");
                    resi();
                break;
            }
        jump = next % 5;

        x++;

        }

        checksum();
        printf("\nSecure password is %s\n", pass);
        printf("\nContinue? (Press any key)\n");
        printf("Exit? (Press 'N')\n\n");
        cont = getch();
        cont = toupper(cont);
    }
}


/* Sample dialogue

Sample dialogue 1

Enter key: ________ (User enter predetermined key)


Generating password...
1st character = __ (Output depends on key)
2nd character = __
3rd character = __
4th character = __
5th character = __ (Number of characters depends on key)
Checksum      = _  (Checksum depends on the characters in key)

Secure password is _______________ (Depends on output from above)

Continue? (Press any key)
Exit? (Press 'N')


Sample dialogue 2

Enter key: password

Generating password...
1st character = 112
2nd character = -88
3rd character = 37
4th character = 86
5th character = 86
6th character = O
7th character = 111
8th character = D
Checksum      = c

Secure password is 112-88378686011Dc

Continue? (Press any key)
Exit? (Press 'N')


Sample dialogue 3

Enter key: test01


Generating password...
1st character = 116
2nd character = 116
3rd character = 101
4th character = 86
5th character = 116
6th character = 7
Checksum      = f

Secure password is 116116101861167f

Continue? (Press any key)
Exit? Press ('N')
*/













/*  Name: Reuben Thomas         Class: ES22
    
    Project Description: 
    This program prompts and collects a user input username and password, and analyses
    the length of password, mixture of character types, password similarity to username 
    and presence of sequential alphabets and numbers in the password. The user is provided 
    with a strength score out of 100 and suggested solutions to improve password strength 
    in each of the 4 measured areas.
    
    Sample Dialogue(User enters username and password as 123):
    PASSWORD STRENGTH CALCULATOR

    Username: 123
    Password: 123
    
    ______________________________________________________________________________________________________________________________
    
    PASSWORD LENGTH: 0/40 points
    Insufficient Password Length!
    Your password only has 3 characters. Please enter a password with more than 8 characters.

    MIXTURE OF CHARACTERS: 0/30 points
    Insufficient mix of characters!
    Your password contains 0 lowercase letters, 0 capital letters, 3 numbers and 0 special characters.
    Please use a variety of character types for maximum password strength.
  
    PASSWORD & USERNAME SIMILARITY 0/15 points
    Your username and password are identical!
    Please ensure username and password are different for maximum password strength.
    
    PRESENCE OF SEQUENTIAL CHARACTERS: 5/15 points
    Your password contains sequential numbers!
    Please do not include sequential characters for maximum password strength.
    
    _______________________________________________________________________________________________________________________________
    
    PASSWORD STRENGTH SCORE = 5/100
    
    Poor Password Security!

    Research on strings from:
    https://www.tutorialspoint.com/cprogramming/c_strings.htm 
    
*/













































#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void main(void)
{

    /*DECLARATION*/
    char username[50], password[50];                                        //Universal
    int total_score;
 
    int p_length;                                                           //Part 1
    float length_score;

    int n, e, mix_score;
    int caps_count = 0, sc_count = 0, num_count = 0, lowercase_count = 0;   //Part 2

    float simy, simz;                                                       //Part 3
    int simx, upsim_score;  

    float sim1to3, sim3to1, simatoc, simctoa;                               //Part 4
    int seqch_score;    
    char incnum[4] = {'1','2','3','\0'};
    char decnum[4] = {'3','2','1','\0'};
    char incalpha[4] = {'a','b','c','\0'};
    char decalpha[4] = {'c','b','a','\0'};





                                      
    /*PROMPT AND COLLECTING USERNAME AND PASSWORD*/
    printf("PASSWORD STRENGTH CALCULATOR\n\n");
    printf("Username: ");
    scanf("%s", &username);
    printf("Password: ");
    scanf("%s", &password);
    printf("\n________________________________________________________________________________________________________________________");






    /*Part 1 - PASSWORD STRENGTH BY LENGTH*/
    //finding length of password and calculating score
    p_length = strlen(password);                           
    length_score = ((p_length - 8.0)/12.0) * 40.0;
    
    //ensures score is within limits
    if(length_score > 40)
        length_score = 40;
    else if(length_score < 0)
        length_score = 0;
    
    //displaying output to user
    printf("\n\nPASSWORD LENGTH: %.0f/40 points", length_score);

    if(p_length <= 8)
    {
        printf("\nInsufficient Password Length!\n");
        printf("Your password only has %d characters. ", p_length);
        printf("Please enter a password with more than 8 characters.");
        length_score = 0;
    }
    else
    {
        if(p_length < 15)
        {
            printf("\nModerate Password Length");
        }
        else
        {
            printf("\nExcellent Password Length!");
        }       
        printf("\nYour password has %d characters. ", p_length);
    }





    /*Part 2 - PASSWORD STRENGTH BY MIX OF CHARACTER TYPES*/
    //counting number of each type of character
    for(n = 0; n < (p_length + 1); n += 1)
    {
        e = password[n];
        
        if((e >= 65)&&(e <= 90))
            caps_count += 1;
        else if( ((e >= 32)&&(e <= 47)) || ((e >= 58)&&(e <= 64)) || ((e >= 91)&&(e <= 96)) || ((e >= 123)&&(e <=126)) )
            sc_count += 1;
        else if((e >= 48)&&(e <= 57))
            num_count += 1;
        else if((e >= 97)&&(e <= 122))
            lowercase_count += 1;
    }
    
    //determining the most common character type and calculating score of mixture
    if( (lowercase_count >= num_count)&&(lowercase_count >= caps_count)&&(lowercase_count >= sc_count) )
        mix_score = 5.0*(sc_count + num_count + caps_count);
    else if( (num_count >= lowercase_count)&&(num_count >= caps_count)&&(num_count >= sc_count) )
        mix_score = 5.0*(sc_count + lowercase_count + caps_count);
    else if( (caps_count >= num_count)&&(caps_count >= lowercase_count)&&(caps_count >= sc_count) )
        mix_score = 5.0*(sc_count + lowercase_count + num_count);
    else
        mix_score = 5.0*(lowercase_count + num_count + caps_count);
    
    //ensures score is within limits
    if(mix_score > 30)
        mix_score = 30;
    
    //displaying output to user
    printf("\n\nMIXTURE OF CHARACTERS: %d/30 points", mix_score);
    
    if(mix_score < 5)
    {
        printf("\nInsufficient mix of characters!");
        printf("\nYour password contains %d lowercase letters, %d capital letters, %d numbers and %d special characters. ", lowercase_count, caps_count, num_count, sc_count);
        printf("\nPlease use a variety of character types for maximum password strength.");
    }
    else if(mix_score < 20)
    {
        printf("\nModerate mix of characters.");
        printf("\nYour password contains %d lowercase letters, %d capital letters, %d numbers and %d special characters. ", lowercase_count, caps_count, num_count, sc_count);
    }
    else
    {
        printf("\nGood mix of characters. ");
        printf("\nYour password contains %d lowercase letters, %d capital letters, %d numbers and %d special characters. ", lowercase_count, caps_count, num_count, sc_count);
    }






    /*Part 3 - PASSWORD STRENGTH BY SIMILARITY TO USERNAME*/
    //assigning value to variable for similarities
    simx = strcmp(username, password);
    simy = strstr(username, password);
    simz = strstr(password, username);
    
    //determining output to user, score calculation and display
    if((simx == 0) || (simy != 0) || (simz != 0))
    {
        if(simx == 0)
        {
            upsim_score = 0;
            printf("\n\nPASSWORD & USERNAME SIMILARITY: %d/15 points", upsim_score);
            printf("\nYour username and password are identical!");
        }
        else
        {
            upsim_score = 5;
            printf("\n\nPASSWORD & USERNAME SIMILARITY: %d/15 points", upsim_score);
            printf("\nYour username and password are too similar!");
        }
        printf("\nPlease ensure username and password are different for maximum password strength.");
        
    }
    else
    {
        upsim_score = 15;
        printf("\n\nPASSWORD & USERNAME SIMILARITY: %d/15 points", upsim_score);
        printf("\nThe username and password are sufficiently distinct.");
    }






    /*Part 4 - PASSWORD STRENGTH BY PRESENCE OF SEQUENTIAL NUMBERS AND ALPHABETS*/
    //assigning value to variable for similarity
    sim1to3 = strstr(password, incnum);
    sim3to1 = strstr(password, decalpha);
    simatoc = strstr(password, incalpha);
    simctoa = strstr(password, decalpha);

    //determining and displaying output to user and calculating score
    if( ((sim1to3 != 0) || (sim3to1 != 0)) && ((simatoc != 0) || (simctoa != 0)) )
        {
            seqch_score = 0;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/15 points", seqch_score);
            printf("\nYour password contains sequential numbers and alphabets!");
            printf("\nPlease do not include sequential characters to maximum password strength.");
        }
    else if( (sim1to3 != 0) || (sim3to1 != 0) )
        {
            seqch_score = 5;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/15 points", seqch_score);
            printf("\nYour password contains sequential numbers!");
            printf("\nPlease do not include sequential characters to maximum password strength.");
        }
    else if( (simatoc != 0) || (simctoa != 0) )
        {
            seqch_score = 5;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/15 points", seqch_score);
            printf("\nYour password contains sequential alphabets!");
            printf("\nPlease do not include sequential characters for maximum password strength.");
        }
    else
        {
            seqch_score = 15;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/15 points", seqch_score);
            printf("\nYour password does not contain any sequential numbers nor alphabets.");
        }





    /*FINAL SCORING*/
    printf("\n\n________________________________________________________________________________________________________________________");
   
    total_score = length_score + upsim_score + seqch_score + mix_score;
    
    printf("\n\nPASSWORD STRENGTH SCORE = %d / 100", total_score);
    
    //score comment
    if(total_score >= 90) 
        printf("\n\nExcellent Password Security!\n");
    else if(total_score >= 75)
        printf("\n\nGood Password Security!\n");
    else if(total_score >= 50)
        printf("\n\nAverage Password Security.\n");
    else
        printf("\n\nPoor Password Security!\n");
        
        
  

}

