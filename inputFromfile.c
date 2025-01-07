#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100
int main(int argc, char** argv){
    /*The variable needed to stor all of the information of the sutdent*/
    char inBuf[SIZE];
    int remain;
    int Gnum;
    char name[SIZE];
    int semester;
    char course[SIZE];
    int credits;
    float grade;
    /*If the commandline argument doesn't include 3 element. The exe file, input and output file display error*/
    if(argc != 3){
        printf("Err Msg!\n");
        exit(-1);
    }
    //File pointer
    FILE* inputFile,*outputFile;
    /*Open the input and output file entered in the 2nd and 3rd command line argument*/
    inputFile = fopen(argv[1],"r");
    outputFile= fopen(argv[2],"w");
    if(inputFile == NULL || outputFile == NULL){
    	printf("Err Msg!");
	exit(-1);
    }
    /*Get the first line that contain a number of remaining student*/
    fgets(inBuf, SIZE, inputFile);
    sscanf(inBuf, "%d", &remain);
    int i;
    /*Loop through the same number of remain assigned*/
    for(i = 0; i < remain; ++i){
	/*Read the line and get the information need then print them into the output file as formatted*/
        fgets(inBuf, SIZE, inputFile);
        sscanf(inBuf,"%d %[^,], %d %s %d %f",&Gnum, name, &semester, course, &credits, &grade);
        fprintf(outputFile,"%-25s G%-10d %-8.2f %-10s %-3d %3d\n",name,Gnum,grade,course,credits,semester);
    }
    /*Close both file*/
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
