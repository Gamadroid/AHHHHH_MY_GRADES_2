/* Name: Reuben Thomas & Joshua Wee             Class: ES22 
This program is to generate a strong password based on a key that a user inputs. 
*/


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

void barline(float x, int colour, int length);

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

    char username[100], password[100];                                               //Universal
    int total_score, colour;
     
    int p_length;                                                                  //Part 1
    int length_score;

    int i, e, mix_score;
    int caps_count = 0, sc_count = 0, num_count = 0, lowercase_count = 0;          //Part 2

    float simy, simz;                                                              //Part 3
    float simx;
    int upsim_score;

    float sim1to3, sim3to1, simatoc, simctoa;                                      //Part 4
    int seqch_score;    

    int n = 0, n1 = 0, c, cn, x = 1, repch_count = 0, repch_score;                              //Part 5 

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
        printf("Password Generated: ");
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
    
    //displaying score, comments and barline to user
    printf("\n\nPASSWORD LENGTH: %d/40 points", length_score);

    if(p_length <= 8)
    {
        RED;
        printf(" - Insufficient Password Length!\n");
        LIGHTGREY;
        printf("Your password only has %d characters. ", p_length);
        printf("Please enter a password with more than 8 characters.");
        length_score = 0;
        colour = 1;
        WHITE;
    }
    else
    {
        if(p_length < 15)
        {
            BROWN;
            printf(" - Moderate Password Length");
            WHITE;
            colour = 2;
        }
        else
        {
            GREEN;
            printf(" - Excellent Password Length!");
            WHITE;
            colour = 3;
        }       
        LIGHTGREY;
        printf("\nYour password has %d characters. ", p_length);
        WHITE;
    }
    barline((length_score / 40.0), colour, 50);

    /*Part 2 - PASSWORD STRENGTH BY MIX OF CHARACTER TYPES*/
    //counting number of each type of character
    for(i = 0; i < (p_length + 1); i += 1)
    {
        e = password[i];
        
        if((e >= 65)&&(e <= 90))
            caps_count += 1;
        else if( ((e >= 32)&&(e <= 47)) || ((e >= 58)&&(e <= 64)) || ((e >= 91)&&(e <= 96)) || ((e >= 123)&&(e <=126)) )
            sc_count += 1;
        else if((e >= 48)&&(e <= 57))
            num_count += 1;
        else if((e >= 97)&&(e <= 122))
            lowercase_count += 1;
    }
    
    //determining the most common character type, comparing the ratio of all characters to the most common to calculate the score
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

    //displaying score, comments and barline to user
    printf("\n\nMIXTURE OF CHARACTERS: %d/30 points", mix_score);
    
    if(mix_score < 5)
    {
        RED;
        colour = 1;
        printf(" - Poor Mix of Characters!");
        LIGHTGREY;
        printf("\nYour password contains %d lowercase letters, %d capital letters, %d numbers and %d special characters. ", lowercase_count, caps_count, num_count, sc_count);
        printf("\nPlease use a variety of character types for maximum password strength.");      
        WHITE;  
    }
    else if(mix_score < 20)
    {
        BROWN;
        colour = 2;
        printf(" - Moderate Mix of Characters");
        LIGHTGREY;
        printf("\nYour password contains %d lowercase letters, %d capital letters, %d numbers and %d special characters. ", lowercase_count, caps_count, num_count, sc_count);
        WHITE;
    }
    else
    {
        GREEN;
        colour = 3;
        printf(" - Excellent Mix of Characters!");
        LIGHTGREY;
        printf("\nYour password contains %d lowercase letters, %d capital letters, %d numbers and %d special characters. ", lowercase_count, caps_count, num_count, sc_count);
        WHITE;
    }
    barline((mix_score / 30.0), colour, 50);

    /*Part 3 - PASSWORD STRENGTH BY SIMILARITY TO USERNAME*/
    //assigning value to variable for similarities
    simx = strcmp(username, password);                  //checks if username and password are identical
    simy = strstr(username, password);                  //checks for the presence of username in the password
    simz = strstr(password, username);                  //checks for the presence of password within the username
    
    //determining output to user, score calculation and displaying results and comments to user
    if((simx == 0) || (simy != 0) || (simz != 0))
    {
        if(simx == 0)
        {
            upsim_score = 0;
            printf("\n\nPASSWORD & USERNAME SIMILARITY: %d/10 points", upsim_score);
            RED;
            colour = 1;
            printf(" - Identical Username & Password!");
            WHITE;
        }
        else
        {
            upsim_score = 5;
            printf("\n\nPASSWORD & USERNAME SIMILARITY: %d/10 points", upsim_score);
            BROWN;
            colour = 2;
            printf(" - Simiar Username & Password!");
            WHITE;
        }

        LIGHTGREY;
        printf("\nPlease ensure username and password are different for maximum password strength.");
        WHITE;
    }
    else
    {
        upsim_score = 10;
        printf("\n\nPASSWORD & USERNAME SIMILARITY: %d/10 points", upsim_score);
        GREEN;
        colour = 3;
        printf(" - Sufficiently Distinct Username & Password");
        WHITE;
    }

    barline((upsim_score / 10.0), colour, 50);


    /*Part 4 - PASSWORD STRENGTH BY PRESENCE OF SEQUENTIAL NUMBERS AND ALPHABETS*/
    //assigning value to variable for similarity
    sim1to3 = strstr(password, incnum);             //checks for increasing numbers in password
    sim3to1 = strstr(password, decnum);             //checks for decreasing numbers in password
    simatoc = strstr(password, incalpha);           //checks for increasing alphabets in password
    simctoa = strstr(password, decalpha);           //checks for decreasing alphabets in username

    //determining and displaying score, comments, bargraph to user and calculating score
    if( ((sim1to3 != 0) || (sim3to1 != 0)) && ((simatoc != 0) || (simctoa != 0)) )
        {
            seqch_score = 0;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/10 points", seqch_score);
            RED;
            colour = 1;
            printf(" - Sequential Numbers & Alphabets Present!");
            LIGHTGREY;
            printf("\nPlease do not include sequential characters to maximise password strength.");
            WHITE;
        }
    else if( (sim1to3 != 0) || (sim3to1 != 0) )
        {
            seqch_score = 5;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/10 points", seqch_score);
            BROWN;
            colour = 2;
            printf(" - Sequential Numbers Present!");
            LIGHTGREY;
            printf("\nPlease do not include sequential characters to maximise password strength.");
            WHITE;
        }
    else if( (simatoc != 0) || (simctoa != 0) )
        {
            seqch_score = 5;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/10 points", seqch_score);
            BROWN;
            colour = 2;
            printf(" - Sequential Alphabets Present!");
            LIGHTGREY;
            printf("\nPlease do not include sequential characters to maximise password strength.");
            WHITE;
        }
    else
        {
            seqch_score = 10;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/10 points", seqch_score);
            GREEN;
            colour = 3;
            printf(" - No Sequential Numbers nor Alphabets Present");
            WHITE;
        }

    barline((seqch_score / 10.0), colour, 50);

    /*PART 5 - TEST FOR REPATING CHARACTERS*/
    for(n = 0; n < p_length; n++)        
    {
        x = 0;

        c  = password[n];
        cn = password[n+1];

        for(n1 = 1; cn == c; n1++)
        {
            cn = password[n + n1];
            x++;
        }
        
        if(x >= 3)
        {
            n = n + (x - 1);
            repch_count++;
        }   
    }
    repch_score = 10 - (repch_count * 2);

    if(repch_score < 0)
        repch_score = 0;

    printf("\n\nPRESENCE OF REPETITIVE CHARACTERS: %d/10 points", repch_score);

    if(repch_score < 5)
    {
        RED;
        colour = 1;
    }
    else if(repch_score <= 7)
    {
        BROWN;
        colour = 2;
    }
    else
    {
        GREEN;
        colour = 3;
    }

    if(repch_count == 0)
    {
        printf(" - No Repetition of Characters Present");
        LIGHTGREY;
        printf("\nYour password has %d occurences of consequtive repetitive characters.", repch_count);
        WHITE;  
    }
    else
    {
        printf(" - Repeating Characters Present!");
        LIGHTGREY;
        printf("\nYour password has %d occurences of a character repeated consequtively 3 times or more.", repch_count);
        printf("\nPlease do not include repeating characters to maximise password strength.");
        WHITE;
    }
    barline((repch_score / 10.0), colour, 50);


    /*FINAL SCORING*/
    DARKGREY;
    printf("\n________________________________________________________________________________________________________________________");
    WHITE;

    total_score = length_score + upsim_score + seqch_score + mix_score + repch_score;
    
    printf("\n\nPASSWORD STRENGTH SCORE = %d / 100", total_score);
    
    //score comment
    if(total_score >= 90) 
    {
        GREEN;
        colour = 3;
        printf(" - Excellent Password Security!");
        WHITE;
    }
    else if(total_score >= 75)
    {
        GREEN;
        colour = 3;
        printf(" - Good Password Security!");
        WHITE;
    }
    else if(total_score >= 50)
    {
        BROWN;
        colour = 2;
        printf(" - Average Password Security.");
        WHITE;
    }
    else
    {
        RED;
        colour = 1;
        printf(" - Poor Password Security!");
        WHITE;
    }
    barline((total_score / 100.0), colour, 119);
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

void barline(float x, int colour, int length)
{
    int number, n, i;

    printf("\n");

    if(colour == 1)
        RED;
    else if(colour == 2)
        BROWN;
    else if(colour == 3)
        GREEN;

    for(n = 0; n < ((length * x) + 0.00001); n++) 
    {
        printf("%c", 178);
    }

    if((length - n) >= 1)
    {
        printf("%c", 177);
        n++;
    }
    
    if((length - n) >= 2)
    {
        printf("%c", 176);
        n++;
    }

    for(i = 0; i <= (length - n); i++)
    {
        DARKGREY;
        printf("%c", 176);
        WHITE;
    }
    WHITE;
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

