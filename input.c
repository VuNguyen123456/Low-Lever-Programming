#include <stdio.h>
#include <math.h>
#define SIZE 30
int main(){
float H, W;
double T;
char inBuff[SIZE];

fgets(inBuff, SIZE, stdin);
sscanf(inBuff, "%f", &H);

fgets(inBuff, SIZE, stdin);
sscanf(inBuff, "%f", &W);

T = 0.007184 * pow(W,0.425) * pow(H,0.725);

printf("The Height is: %.1f cms\n",H);
printf("The weight is: %.1f kgs\n",W);
printf("BSA: %.4lf meter square\n",T);
return 0;
}
