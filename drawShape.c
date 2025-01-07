#include <stdio.h>
#include <math.h>
#define SIZE 30
int validatingCorect(char C, int N){
    if(C == '\0' || N == 0){
        printf("Please re-enter your initial values: \n");
        return 0;
    }
    else{
        return 1;
    }

}
char menu(){
	/*printf("Menu Choice             Input Choices\n");
    printf("Enter/Change Character  'C' or 'c'\n");
    printf("Enter/Change Number     'N' or 'n'\n");
    printf("DrawLine                'L' or 'l'\n");
    printf("Draw Square             'S' or 's'\n");
    printf("Draw Rectangle          'R' or 'r'\n");
    printf("Draw Triangle           'T' or 't'\n");
    printf("Quit Program            'Q' or 'q'\n");*/
    printf("Enter input: \n");
    char input = '\0';
    char inBuff[SIZE];
    while(1){
    fgets(inBuff, SIZE,stdin);
    if(sscanf(inBuff, "%c", &input) == 1){
            return input;
    }
    else{
        printf("Invalid input: \n");
        fgets(inBuff, SIZE,stdin);
    }
    }
    return input;
}
char changeIcon(){
    char input = '\0';
    char inBuff[SIZE];
    printf("Please enter a icon: \n");
    fgets(inBuff, SIZE,stdin);
    sscanf(inBuff, "%c", &input);
    return input;
}
int changeInt(){
    int input = 0;
    char inBuff[SIZE];
    int check = 0;
    while(check == 0){
        printf("Please enter a number between 1-15 (inclusive)\n");
        fgets(inBuff, SIZE,stdin);
        sscanf(inBuff, "%d", &input);
    if(input >= 1 && input <= 15){
        return input;
    }
    else{
        continue;
    }
    }
    return input;
}
void drawLine(char icon, int num){
    int i;
    for(i = 0; i<num; i++){
        printf("%c\n", icon);
    }
}
void drawSquare(char icon, int num){
    int i;
    int j;
    for(j = 0; j < num; j++){
        for(i =0 ; i < num; i++){
            printf("%c", icon);
        }
        printf("\n");
    }
}
void drawRec(char icon, int num){
    int i;
    int j;
    for(j = 0; j < num; j++){
        for(i =0 ; i < num+5; i++){
            printf("%c", icon);
        }
        printf("\n");
    }
}
void drawTriangle(char icon, int num){
    int i;
    int j;
    int cap = 1;
    for(j = 0; j < num; j++){
        for(i =0 ; i < cap; i++){
            printf("%c", icon);
        }
        cap++;
        printf("\n");
    }
}

int main(){
    char icon = '\0';
    char input = '\0';
    int num = 0;
    printf("Menu Choice             Input Choices\n");
    printf("Enter/Change Character  'C' or 'c'\n");
    printf("Enter/Change Number     'N' or 'n'\n");
    printf("DrawLine                'L' or 'l'\n");
    printf("Draw Square             'S' or 's'\n");
    printf("Draw Rectangle          'R' or 'r'\n");
    printf("Draw Triangle           'T' or 't'\n");
    printf("Quit Program            'Q' or 'q'\n");

    icon = changeIcon();
    num = changeInt();
    while(!validatingCorect(icon, num)){
        icon = menu();
        num = changeInt();
    }
    
    do {
        input = menu();
        switch (input) {
            case 'q':
            case 'Q':
                printf("Bye Bye\n");
                break;
            case 'c':
            case 'C':
                icon = changeIcon();
                break;
            case 'n':
            case 'N':
                num = changeInt();
                break;
            case 'l':
            case 'L':
                drawLine(icon, num);
                break;
            case 's':
            case 'S':
                drawSquare(icon, num);
                break;
            case 'r':
            case 'R':
                drawRec(icon, num);
                break;
            case 't':
            case 'T':
                drawTriangle(icon, num);
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    } while (input != 'q' && input != 'Q');
    return 0;
}
