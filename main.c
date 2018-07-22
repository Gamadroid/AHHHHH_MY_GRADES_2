/* Name: Reuben Thomas & Joshua Wee             Class: ES22 
This program is to generate a strong password based on a key that a user inputs. 
*/

// system clear
// system("cls");

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>

#define BLACK SetConsoleTextAttribute(whnd, 0x00)
#define BLUE SetConsoleTextAttribute(whnd, 0x01)
#define GREEN SetConsoleTextAttribute(whnd, 0x02)
#define LIGHTBLUE SetConsoleTextAttribute(whnd, 0x03)
#define RED SetConsoleTextAttribute(whnd, 0x04)
#define MAGENTA SetConsoleTextAttribute(whnd, 0x05)
#define BROWN SetConsoleTextAttribute(whnd, 0x06)
#define LIGHTGREY SetConsoleTextAttribute(whnd, 0x07)
#define DARKGREY SetConsoleTextAttribute(whnd, 0x08)
#define WHITE SetConsoleTextAttribute(whnd, 0x0F)

HANDLE whnd;

typedef int bool;

//declaring
int total, next, inNext, check;
char key[50], pass[200], input[5];
char nextchar = '\0', inNextchar, cont = '!';


void two (char Pass[]);

void clearInput (void);

void addval (int X);

void hex(int N);

void sine(int N);

void spchar(int N);

void caps(int N);

void resi(int N);

void checksum(void);

void one(void);

void bar(int p);

void main(void) {

    whnd = GetStdHandle(STD_OUTPUT_HANDLE);
    //declaring local variables 
    char choice;

    while (cont != 'N') {
        system("cls");
        WHITE;
        printf("SMARTPASS");
        DARKGREY;
        printf("\n________________________________________________________________________________________________________________________");
        WHITE;
        printf("\n\nPress A to generate a high security password from a key.");
        printf("\nPress B to check existing password strength.\n");
        choice = getch();

        
        if ((choice == 'A') || (choice == 'a')) {
            one();
        }
            
        else if ((choice == 'B') || (choice == 'b')) {
            two('\0');
        }
        else {
            system("cls");
            printf("SMARTPASS");
            DARKGREY;
            printf("\n________________________________________________________________________________________________________________________");
            WHITE;
            printf("\n\nInvalid choice. Please key in again.");
        }

        printf("\n\nPress Y to continue.");
        printf("\nPress N to exit.\n");
        cont = getch();
        cont = toupper(cont);

    }
    system("cls");
    printf("Thank you for using SMARTPASS");
    printf("\n\nA project by Joshua Wee and Reuben Thomas\n\n\n");


}

void two(char Pass[])
{

    //declaring local variables

    char username[50], password[50];                                              //Universal
    int total_score;
     
    int p_length, bar1;                                                           //Part 1
    float length_score;

    int n, e, mix_score, bar2;
    int caps_count = 0, sc_count = 0, num_count = 0, lowercase_count = 0;          //Part 2

    float simy, simz;                                                              //Part 3
    float simx;
    int upsim_score, bar3;

    float sim1to3, sim3to1, simatoc, simctoa;                                      //Part 4
    int seqch_score, bar4;    
    char incnum[4] = {'1','2','3','\0'};
    char decnum[4] = {'3','2','1','\0'};
    char incalpha[4] = {'a','b','c','\0'};
    char decalpha[4] = {'c','b','a','\0'};

    system("cls");
                                      
    /*PROMPT AND COLLECTING USERNAME AND PASSWORD*/
    if (Pass == '\0') {
        printf("SMARTPASS - Password Strength Check\n");
        DARKGREY;
        printf("________________________________________________________________________________________________________________________");
        WHITE;
        printf("\n\nUsername: ");
        scanf("%s", &username);
        printf("Password: ");
        BLACK;
        scanf("%s", &password);
        DARKGREY;
        printf("________________________________________________________________________________________________________________________");
        WHITE;
    }
    else {
        printf("SMARTPASS - Password Strength Check\n");
        DARKGREY;
        printf("________________________________________________________________________________________________________________________");
        WHITE;
        printf("\n\nUsername: ");
        scanf("%s", &username);
        printf("Password has been generated");
        strcpy(password, Pass);
        printf("%s\n", password);
        // add password key 
        DARKGREY;
        printf("________________________________________________________________________________________________________________________");
        WHITE;
    }



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
        RED;
        printf(" - Insufficient Password Length!\n");
        WHITE;
        printf("Your password only has %d characters. ", p_length);
        printf("Please enter a password with more than 8 characters.");
        length_score = 0;
    }
    else
    {
        if(p_length < 15)
        {
            BROWN;
            printf(" - Moderate Password Length");
            WHITE;
        }
        else
        {
            GREEN;
            printf(" - Excellent Password Length!");
            WHITE;
        }       
        printf("\nYour password has %d characters. ", p_length);
    }
    bar1 = (length_score / 40);
    bar(bar1);

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
        RED;
        printf(" - Poor Mix of Characters!");
        WHITE;
        printf("\nYour password contains %d lowercase letters, %d capital letters, %d numbers and %d special characters. ", lowercase_count, caps_count, num_count, sc_count);
        printf("\nPlease use a variety of character types for maximum password strength.");      
    }
    else if(mix_score < 20)
    {
        BROWN;
        printf(" - Moderate Mix of Characters");
        WHITE;
        printf("\nYour password contains %d lowercase letters, %d capital letters, %d numbers and %d special characters. ", lowercase_count, caps_count, num_count, sc_count);
    }
    else
    {
        GREEN;
        printf(" - Excellent Mix of Characters!");
        WHITE;
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
            RED;
            printf(" - Identical Username & Password!");
            WHITE;
        }
        else
        {
            upsim_score = 7;
            printf("\n\nPASSWORD & USERNAME SIMILARITY: %d/15 points", upsim_score);
            BROWN;
            printf(" - Simiar Username & Password!");
            WHITE;
        }
        printf("\nPlease ensure username and password are different for maximum password strength.");
        
    }
    else
    {
        upsim_score = 15;
        printf("\n\nPASSWORD & USERNAME SIMILARITY: %d/15 points", upsim_score);
        GREEN;
        printf(" - Sufficiently Distinct Username & Password");
        WHITE;
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
            RED;
            printf(" - Sequential Numbers & Alphabets Present!");
            WHITE;
            printf("\nPlease do not include sequential characters to maximum password strength.");
        }
    else if( (sim1to3 != 0) || (sim3to1 != 0) )
        {
            seqch_score = 5;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/15 points", seqch_score);
            BROWN;
            printf(" - Sequential Numbers Present!");
            WHITE;
            printf("\nPlease do not include sequential characters to maximum password strength.");
        }
    else if( (simatoc != 0) || (simctoa != 0) )
        {
            seqch_score = 5;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/15 points", seqch_score);
            BROWN;
            printf(" - Sequential Alphabets Present!");
            WHITE;
            printf("\nPlease do not include sequential characters for maximum password strength.");
        }
    else
        {
            seqch_score = 15;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/15 points", seqch_score);
            GREEN;
            printf(" - No Sequential Numbers nor Alphabets Present");
            WHITE;
        }

    /*FINAL SCORING*/
    DARKGREY;
    printf("\n________________________________________________________________________________________________________________________");
    WHITE;

    total_score = length_score + upsim_score + seqch_score + mix_score;
    
    printf("\n\nPASSWORD STRENGTH SCORE = %d / 100", total_score);
    
    //score comment
    if(total_score >= 90) 
    {
        GREEN;
        printf("\n\nExcellent Password Security!\n");
        WHITE;
    }
    else if(total_score >= 75)
    {
        GREEN;
        printf("\n\nGood Password Security!\n");
        WHITE;
    }
    else if(total_score >= 50)
    {
        BROWN;
        printf("\n\nAverage Password Security.\n");
        WHITE;
    }
    else
    {
        RED;
        printf("\n\nPoor Password Security!\n");
        WHITE;
    }

}


void clearInput () {
    for (int i = 0; i<5; ++i)
        input[i] = '\0';
}

void addval (int X) {
    next = (int)key[X];
    clearInput();
        if (nextchar != '\0') {
            input[0] = inNextchar;
            nextchar = '\0';
        }
        else {
            sprintf(input, "%d", inNext);
        }
        strcat(pass, input);

        if (X == 0) 
            printf("%dst character = %s\n", X+1, input);     
        else if (X == 1) 
            printf("%dnd character = %s\n", X+1, input);
        else if (X == 2) 
            printf("%drd character = %s\n", X+1, input);
        else 
            printf("%dth character = %s\n", X+1, input);
     
    total = total + next;
}

void hex(int N) {
    inNext = next;
    addval(N);
}

void sine(int N) {
    inNext = sin(next)*100;
    addval(N);
}

void spchar (int N) {
    nextchar   = key[N];
    inNextchar = abs((char)next - 70) + 33;
    addval(N);
}

void caps (int N) {
    nextchar   = key[N];
    inNextchar = toupper(nextchar);
    addval(N);
}

void resi (int N) {
    inNext = (1.0/next)*10000;
    addval(N);
}

void checksum() {
    check    = total % 11;
    nextchar = ((char)check + 96);
    clearInput();
    input[0] = nextchar;
    strcat(pass, input);
    printf("Checksum      = %s\n", input);
}

void one() {

    char checkpass;
    int jump = 0, chr1;
    
    system("cls");
    printf("SMARTPASS - Password Generator\n");
    DARKGREY;
    printf("________________________________________________________________________________________________________________________\n\n");
    WHITE;

    int x     = 0;
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
    printf("\nGenerating password...\n");
    
    //calculation for first character
    chr1 = (int)key[0];
//    printf("%15s", pass);

    //calculating subsequent characters
    jump = chr1 % 5;
    while (key[x] != '\0' && key[x] != '\0') {
      
        switch (jump) {
            case 1 :
//                printf("1\n");
                hex(x);
            break;
    
            case 2 : 
//                printf("2\n");
                sine(x);
            break;

            case 3 :
//                printf("3\n");
                spchar(x);
            break;

            case 4 :
//                printf("4\n");
                caps(x);
            break;

            case 0 :
//                printf("5\n");
                resi(x);
            break;
        }
    jump = next % 5;

    x++;

    }

    checksum();
    printf("\nSecure password is %s\n", pass);

    printf("\nWould you like to check your password strength? \n");
    printf("Press Y to continue. \n");
    printf("Press N to exit.\n");
    checkpass = getch();

    if (checkpass == 'y' || checkpass == 'Y') 
        two(pass);

}

void bar(int p)
{
    int n;

    for(n = 0; n < p; n++)
    {
        printf("%c", 178);
    }
}

/* 
SMARTPASS
__________________________________________________________________________________
Press A to generate a high security password from a key.
Press B to check existing password strength.

SMARTPASS - Password Generator
__________________________________________________________________________________
Enter key: password

Generating password...
1st character = 0
2nd character = -88
3rd character = 37
4th character = 86
5th character = 86
6th character = O
7th character = 111
8th character = D
Checksum      = c

Secure password is 0-88378686O111Dc


Press Y to continue.
Press N to exit.





 
SMARTPASS
__________________________________________________________________________________
Press A to generate a high security password from a key.
Press B to check existing password strength.

SMARTPASS - Password Strength Check
__________________________________________________________________________________

Username: test
Password: password (password is blacked out for security) 
__________________________________________________________________________________
PASSWORD LENGTH: 0/40 points - Insufficient Password Length!
Your password only has 8 characters. Please enter a password with more than 8 characters.

MIXTURE OF CHARACTERS: 0/30 points - Poor Mix of Characters!
Your password contains 8 lowercase letters, 0 capital letters, 0 numbers and 0 special characters.
Please use a variety of character types for maximum password strength.

PASSWORD & USERNAME SIMILARITY: 15/15 points - Sufficiently Distinct Username & Password

PRESENCE OF SEQUENTIAL CHARACTERS: 15/15 points - No Sequential Numbers nor Alphabets Present
__________________________________________________________________________________

PASSWORD STRENGTH SCORE = 30 / 100

Poor Password Security!

Press Y to continue.
Press N to exit.





 
SMARTPASS
__________________________________________________________________________________
Press A to generate a high security password from a key.
Press B to check existing password strength.

SMARTPASS
__________________________________________________________________________________
Invalid choice. Please key in again.

Press Y to continue.
Press N to exit.

*/

