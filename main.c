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
