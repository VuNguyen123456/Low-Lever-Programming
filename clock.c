#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define SIZE 30

int main(){
    int hour, hour2;
    int min, min2;
    int input;
    int angle=0, angle2 = 0;
    char inBuf[SIZE];
    int hDegree, hDegree2;
    int mDegree, mDegree2;
    int count = 0;
    printf("Please enter between 0-180: \n");
    do{
    fgets(inBuf, SIZE, stdin);
    sscanf(inBuf, "%d", &input);
    }while(!(input>=0 && input <=180));
    for(hour = 0; hour < 24; hour++){
        for(min = 0; min < 60; min++){
            mDegree = min * 6;
            hDegree = (hour%12) * 30 + (min/12) * 6;
            angle = abs(hDegree - mDegree);
            angle = (360 - angle < angle)? 360-angle : angle; 
                if(angle == input){
                    count += 1;
                }
        }
    }
    if(count > 0){
        printf("\nThere are %d hours that is exactly %d degree\n", count, input);
        printf("\nThese hours are: ");
        angle2 = 0;
        for(hour2 = 0; hour2 < 24; hour2++){
            for(min2 = 0; min2 < 60; min2++){
                mDegree2 = min2 * 6;
                hDegree2 = (hour2%12) * 30 + (min2 / 12) * 6;
                angle2 = abs(hDegree2 - mDegree2);
                angle2 = (360 - angle2 < angle2)? 360-angle2 : angle2; 
                if(angle2 == input){
                if(hour2 < 10 && min2 < 10){
                    printf("0%d:0%d, ",hour2, min2);
                }
                else if(hour2 < 10 && min2 >= 10){
                    printf("0%d:%d, ",hour2, min2);
                }
                else if(hour2 >= 10 && min2 < 10){
                    printf("%d:0%d, ",hour2, min2);
                }
                else if(hour2 >= 10 && min2 >= 10){
                    printf("%d:%d, ",hour2, min2);
                }
            }
        }
    }
	printf("\n");
    }
    else{
        printf("There is no hour where the hands are %d degrees apart\n", input);
    }
    return 0;
}
