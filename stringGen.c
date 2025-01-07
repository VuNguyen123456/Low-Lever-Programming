#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define SIZE 20
#define WSIZE 50

void get_adjective(char letter, char adjective[]){
    char inBuf[SIZE];
    letter = toupper(letter);
    int AsciiTableVal = (int) letter;
    // adjective[0]= '\0';
    do{
    if(AsciiTableVal >= 65 && AsciiTableVal <= 69){
        strcpy(adjective, "The awesome ");
        break;
    }
    else if(AsciiTableVal >= 70 && AsciiTableVal <= 74){
        strcpy(adjective, "The funny ");
        break;
    }
    else if(AsciiTableVal >= 75 && AsciiTableVal <= 79){
        strcpy(adjective, "The dangerous ");
        break;
    }
    else if(AsciiTableVal >= 80 && AsciiTableVal <= 84){
        strcpy(adjective, "The lovely ");
        break;
    }
    else if(AsciiTableVal >= 85 && AsciiTableVal <= 90){
        strcpy(adjective, "The electrifying ");
        break;
    }
    else{
        printf("\tError! 12 is not valid, please enter a valid input\n");
        printf("\tEnter the first letter of your last name[A-Z] ");
        fgets(inBuf, SIZE, stdin);
        sscanf(inBuf, "%c", &letter);
        letter = toupper(letter);
        AsciiTableVal = (int) letter;
    }
    }while(1);
}
void get_subject(char month[], char subject[]){
    char inBuf[SIZE];
    int i;
    for(i = 0; i < strlen(month); i++){
        month[i]= toupper(month[i]);
    }
    // subject[0]='\0';
    do{
    if(strcmp(month, "JAN") == 0|| strcmp(month, "FEB") == 0|| strcmp(month, "MAR") == 0){
        strcpy(subject, "biography ");
        break;
    }
    else if(strcmp(month, "APR") == 0|| strcmp(month, "MAY") == 0|| strcmp(month, "JUN") == 0){
        strcpy(subject, "revenge ");
        break;
    }
    else if(strcmp(month, "JUL") == 0|| strcmp(month, "AUG") == 0|| strcmp(month, "SEP") == 0){
        strcpy(subject, "battle ");
        break;
    }
    else if(strcmp(month, "OCT") == 0|| strcmp(month, "NOV") == 0|| strcmp(month, "DEC") == 0){
        strcpy(subject, "fairy tale ");
        break;
    }
    else{
        printf("\tError! 12 is not valid, please enter a valid input\n");
        printf("\tEnter your birth month [JAN|FEB|...|DEC]");
        fgets(inBuf, SIZE, stdin);
        sscanf(inBuf, "%s", month);
        for(i = 0; i < strlen(month); i++){
        month[i]= toupper(month[i]);
    }
    }
    }while(1);
}

void get_complement(int digit, char complement[]){
    char inBuf[SIZE];
    int end = 0;
    // complement[0]= '\0';
    do{
        switch (digit)
        {
        case 0:
        case 1:
            strcpy(complement, "of a movie star \n");
            end = 0;
            break;
        case 2:
        case 3:
            strcpy(complement, "of a hero \n");
            end = 0;
            break;
        case 4:
        case 5:
            strcpy(complement, "of a jedi \n");
            end = 0;
            break;
        case 6:
        case 7:
            strcpy(complement, "of a ogre \n");
            end = 0;
            break;
        case 8:
        case 9:
            strcpy(complement, "of a dreamer \n");
            end = 0;
            break;
        default:
            end = 1;
            printf("\tError! 12 is not valid, please enter a valid input\n");
            printf("\tEnter the last digit of your cellphone [0-9]");
            fgets(inBuf, SIZE, stdin);
            sscanf(inBuf, "%d", &digit);
            break;
        }
    }while(end == 1);
}

void resetString(char string[]){
    string[0]='\0';
}

int main(){
    char quit;
    char adjective[SIZE], subject[SIZE], complement[SIZE];
    char movieTitle[WSIZE];  
    printf("\n*** Welcome to the Title Movie creator program ***\n");

    do{
    char letter;
    char month[SIZE];
    int num = 0;
    char inBuf[SIZE];

    printf("\tEnter the first letter of your last name[A-Z] ");
    fgets(inBuf, SIZE, stdin);
    sscanf(inBuf, "%c", &letter);
    get_adjective(letter, adjective);

    printf("\tEnter your birth month [JAN|FEB|...|DEC] ");
    fgets(inBuf, SIZE, stdin);
    sscanf(inBuf, "%s", month);
    get_subject(month, subject);

    printf("\tEnter the last digit of your cellphone [0-9] ");
    fgets(inBuf, SIZE, stdin);
    sscanf(inBuf, "%d", &num);
    get_complement(num, complement);
    // printf("%s", adjective);
    // printf("%s", subject);
    // printf("%s", complement);

    //After calling function use strcat to create the title
    strcat(movieTitle, adjective);
    strcat(movieTitle, subject);
    strcat(movieTitle, complement);
    printf("\nThe Movie Title for your life is: \n\t");
    printf("%s", movieTitle);
    movieTitle[0] = '\0';
    // resetString(adjective);
    // resetString(subject);
    // resetString(complement);

    printf("\nDo you want to quit [Y|y]?");
    fgets(inBuf, SIZE, stdin);
    sscanf(inBuf, "%c", &quit);
    quit = toupper(quit);
    }while(quit != 'Y');


    return 0;
}
