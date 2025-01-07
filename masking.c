#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define BYTETOBINARYPATTERN "%d%d%d%d%d%d%d%d"
#define BYTETOBINARY(byte) \
(byte & 0x80 ? 1 : 0), \
(byte & 0x40 ? 1 : 0), \
(byte & 0x20 ? 1 : 0), \
(byte & 0x10 ? 1 : 0), \
(byte & 0x08 ? 1 : 0), \
(byte & 0x04 ? 1 : 0), \
(byte & 0x02 ? 1 : 0), \
(byte & 0x01 ? 1 : 0)
#define PRINTBIN(x) printf(BYTETOBINARYPATTERN, BYTETOBINARY(x))

void setlsbs(unsigned char *p, unsigned char b0){
    int i;
    for(i = 0; i < 8; ++i){
        //Masking
        //Clear least significant
        p[i] = (p[i] & 0xFE);
        //Add byte0 in
        p[i] = (p[i] | 0X01);

    }
}

unsigned char getlsbs(unsigned char *p){
    //return byte0
    int i;
    unsigned char byte0 = 0;
    for(i = 0; i < 8; ++i){
        byte0 |= (p[i] & 0x01) << (7-i);//shift  
    }
    return byte0;
}

void printALL(unsigned char *p, unsigned char byte0){
    printf("Printing in decimal format\n");
    int i;
    for(i = 0; i < 8; ++i){
        printf("p[%d]-value: %d\n", i, p[i]);
    }
    printf("byte0: %d\n", byte0);

    printf("Printing in binary format\n");
    for(i = 0; i < 8; ++i){
        PRINTBIN(p[i]);
        printf("\n");
    }
    printf("byte0: ");
    PRINTBIN(byte0);
    printf("\n");
}


int main(int argc, char **argv){
    srand(atoi(argv[1]));
    unsigned char p[8] = {0};
    int i;
    for(i = 0; i < 8; ++i){
        p[i] = rand()%256;
    }
    unsigned char byte0 = rand();
    
    printALL(p,byte0);
    printf("------------------------------------------------------\n");
    setlsbs(p, byte0);;
    printALL(p,byte0);
    printf("------------------------------------------------------\n");
    getlsbs(p);
    printALL(p, byte0);

    return 0;
}
