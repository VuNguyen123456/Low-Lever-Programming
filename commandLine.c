#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void InitArray(int *numArray, int arrayLength);
int* getMemory(int);
void printInfo();
void printListOfArray(int *numArray, int arrayLength);
void ShuffleArray(int *numArray, int arrayLength);

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int main(int argc,char **argv){
    //printf("Hello1\n");
    int S = atoi(argv[1]);
    int N = atoi(argv[2]);
    //printf("Hello2\n Value of S and N: %d, %d\n", S, N);
    int i;
    srand(S);
    //printf("Hello2\n Value of S and N: %d, %d\n", S, N);
    getMemory(N);
    //printf("Hello2\n Value of S and N: %d, %d\n", S, N);
    int *numArray = getMemory(N);
    if(numArray == NULL){
        printf("Error allocating memory\n");
        exit(-1);
    }
    printf("Hello3\n");
    printInfo();
    // printListOfArray(numArray, N);
    for(i = 0; i < 10; i++){
        InitArray(numArray, N);
        printf("Normal Array:           ");
        printListOfArray(numArray, N);
        ShuffleArray(numArray, N);
        printf("Shuffled Array:         ");
        printListOfArray(numArray, N);
        qsort(numArray, N, sizeof(int), cmpfunc);
        printf("Sorted (decen) Array:   ");
        printListOfArray(numArray, N);
        printf("\n");
    }

    free(numArray);
    return 0;
}

void InitArray(int *numArray, int arrayLength){
    int i;
    for(i=0; i< arrayLength; i++){
        numArray[i] = i + 1; //From 1...N
    }
}

int* getMemory(int N){
    if(!(N >= 2 && N <= 500)){
        printf("Err Msg\n");
        exit(-1);
    }
    return (int *)malloc(sizeof(int) * N);
}

void printInfo(){
    printf("Info**************\n");
    printf("This program will create permutations of numbers. The program wil take a random seed S, and an integer N, as command line arguments (CLA)\n");
}

void printListOfArray(int *numArray, int arrayLength){
    int i;
    for(i = 0; i < arrayLength; i++){
        printf("%d ", numArray[i]);
    }
    printf("\n");
}


void ShuffleArray(int *numArray, int arrayLength){
    int i, j;
    for(i = arrayLength-1; i >0; i--){
        j = rand()%(i+1);
        int tmp = numArray[j];
        numArray[j] = numArray[i];
        numArray[i]= tmp;
    }
}
