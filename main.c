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

//declaring
int keygen, total, chr1, next, inNext, i, jump = 0, x = 0, check;
char key[50], pass[200], input[5];
char nextchar = '\0', inNextchar, cont = '!';
typedef int bool;

char username[50], password[50];                                        //Universal
int total_score;
 
int p_length;                                                           //Part 1
float length_score;

int n, e, mix_score;
int caps_count = 0, sc_count = 0, num_count = 0, lowercase_count = 0;   //Part 2

float simy, simz;                                                       //Part 3
float simx;
int upsim_score;

float sim1to3, sim3to1, simatoc, simctoa;                               //Part 4
int seqch_score;    
char incnum[4] = {'1','2','3','\0'};
char decnum[4] = {'3','2','1','\0'};
char incalpha[4] = {'a','b','c','\0'};
char decalpha[4] = {'c','b','a','\0'};

void two ();

void clearInput ();

void addval ();

void hex();

void sine();

void spchar ();

void caps ();

void resi ();

void checksum();

void one();

void main(void) {

    whnd = GetStdHandle(STD_OUTPUT_HANDLE);
    //declaring local variables 
    char choice;

    while (cont != 'N') {
        system("cls");
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
            //insert code here
            two();
        }
        else 
            printf("\nInvalid choice. Please key in again.");

        printf("\nContinue? (Press any key)\n");
        printf("Exit? (Press 'N')\n\n");
        cont = getch();
        cont = toupper(cont);

    }
    system("cls");
    printf("Thank you for using SMARTPASS");
    printf("\n\nA project by Joshua Wee and Reuben Thomas\n\n\n");


}

void two()
{

    system("cls");





                                      
    /*PROMPT AND COLLECTING USERNAME AND PASSWORD*/
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
        }
        else
        {
            GREEN;
            printf(" - Excellent Password Length!");
        }       
        WHITE;
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
        RED;
        printf(" - Insufficient mix of characters!");
        WHITE;
        printf("\nYour password contains %d lowercase letters, %d capital letters, %d numbers and %d special characters. ", lowercase_count, caps_count, num_count, sc_count);
        printf("\nPlease use a variety of character types for maximum password strength.");
    }
    else if(mix_score < 20)
    {
        BROWN;
        printf(" - Moderate mix of characters.");
        WHITE;
        printf("\nYour password contains %d lowercase letters, %d capital letters, %d numbers and %d special characters. ", lowercase_count, caps_count, num_count, sc_count);
    }
    else
    {
        GREEN;
        printf(" - Good mix of characters. ");
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
            WHITE;
            printf("\n\nPASSWORD & USERNAME SIMILARITY: %d/15 points", upsim_score);
            RED;
            printf(" - Your username and password are identical!");
        }
        else
        {
            upsim_score = 7;
            WHITE;
            printf("\n\nPASSWORD & USERNAME SIMILARITY: %d/15 points", upsim_score);
            BROWN;
            printf(" - Your username and password are too similar!");
        }
        printf("\nPlease ensure username and password are different for maximum password strength.");
        
    }
    else
    {
        upsim_score = 15;
        WHITE;
        printf("\n\nPASSWORD & USERNAME SIMILARITY: %d/15 points", upsim_score);
        GREEN;
        printf(" - The username and password are sufficiently distinct.");
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
            printf(" - Your password contains sequential numbers and alphabets!");
            WHITE;
            printf("\nPlease do not include sequential characters to maximum password strength.");
        }
    else if( (sim1to3 != 0) || (sim3to1 != 0) )
        {
            seqch_score = 5;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/15 points", seqch_score);
            BROWN;
            printf(" - Your password contains sequential numbers!");
            WHITE;
            printf("\nPlease do not include sequential characters to maximum password strength.");
        }
    else if( (simatoc != 0) || (simctoa != 0) )
        {
            seqch_score = 5;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/15 points", seqch_score);
            BROWN;
            printf(" - Your password contains sequential alphabets!");
            WHITE;
            printf("\nPlease do not include sequential characters for maximum password strength.");
        }
    else
        {
            seqch_score = 15;
            printf("\n\nPRESENCE OF SEQUENTIAL CHARACTERS: %d/15 points", seqch_score);
            GREEN;
            printf(" - Your password does not contain any sequential numbers nor alphabets.");
        }





    /*FINAL SCORING*/
    DARKGREY;
    printf("\n\n________________________________________________________________________________________________________________________");
    WHITE;

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

void one() {
	
	system("cls");
	printf("SMARTPASS - Password Generator\n");
    DARKGREY;
	printf("________________________________________________________________________________________________________________________\n\n");
    WHITE;

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

}