#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 50

typedef struct Data{
    char name[SIZE];
    int dob;
    int mob;
    int yob;
    struct Data *next;
}Data;

void freeAll(Data *firstData){
    if (firstData == NULL) {
        return; 
    }
    Data* curr = firstData->next;
    Data* prev = firstData;
    while(curr != NULL){
        free(prev);
        prev = curr;
        curr = curr->next;
    }
    free(prev);
}

Data fillData(){
    Data new;
    char inBuf[SIZE];
    while(1){
        printf("Name: ");
        fgets(inBuf, SIZE, stdin);
        sscanf(inBuf, "%[^\n]", new.name);
        if(strlen(new.name) == 0){
            printf("Must have something for name\n");
        }
        else{
            break;
        }
    }
    while(1){
        printf("\nMonth of birth: ");
        fgets(inBuf, SIZE, stdin);
        sscanf(inBuf, "%d", &new.mob);
        if(new.mob < 1 || new.mob > 12){
            printf("Input out of range: please re-enter\n");
        }
        else{
            break;
        }
    }
    while(1){
        printf("\nDay of birth: ");
        fgets(inBuf, SIZE, stdin);
        sscanf(inBuf, "%d", &new.dob);
        if(new.dob < 1 || new.dob > 31){
            printf("Input out of range: please re-enter\n");
        }
        else{
            break;
        }
    }
    while(1){
        printf("\nYear of birth: ");
        fgets(inBuf, SIZE, stdin);
        sscanf(inBuf, "%d", &new.yob);
        if(new.yob < 1930 || new.yob > 2022){
            printf("Input out of range: please re-enter\n");
        }
        else{
            break;
        }
    }
    return new;
}


int insertNode(Data *firstData, Data data){
    Data *curr = firstData->next;
    Data *prev = firstData;
    Data *node = (Data*)malloc(sizeof(Data));
    if(node == NULL){
        printf("Couldn't allocated memory\n");
        exit(-1);
    }
    //Add the data provided to a node
    strcpy(node->name, data.name);
    node->dob = data.dob;
    node->mob = data.mob;
    node->yob = data.yob;
    node->next = NULL;

    //Check ifnone element is in here
    if(prev->next == NULL){
        prev->next = node;
        // firstData->next->next = NULL;
        return 1;
    }

    while(curr != NULL){//HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        if(strncmp(curr->name, node->name,SIZE) == 0){
            printf("Friend already appear in the list\n");
            free(node);
            return 0;
        }
        //Comparing in ascending order
        if(curr->mob > node->mob || 
           (curr->mob == node->mob && (curr->dob > node->dob ||
           (curr->dob == node->dob && curr->yob > node->yob)))) {
            prev->next = node;
            node->next = curr;
            // free(node);
            return 1;
        }
        prev = curr;
        curr = curr->next;//Here I think!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    prev->next = node;
    return 0;
    
    
}


//Also need to work on this as returning the wrong one: MIGHT NEED TO SKIP DUMMY CODE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Data *deleteNode(Data *firstData, Data data){
    Data *curr = firstData;
    Data *deletedNode;
    if(firstData->next == NULL){
        printf("################ Data Does not exist ###############\n");
        return NULL;
    }

    while(curr->next != NULL){
            if(strncmp(curr->next->name, data.name, SIZE) == 0 && curr->next->mob == data.mob && curr->next->mob == data.mob && curr->next->yob == data.yob){
                deletedNode = curr->next;
                curr->next = curr->next->next;
                // free(deletedNode);
                printf("Exiting from deletedNote into Main menu:\n");
                return deletedNode;
            }
            curr = curr->next;//Here I think!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    printf("################ Data Does not exist ###############\n");
    return NULL;
}

void printList(Data *firstData){
    Data *curr = firstData->next;
    while(curr != NULL){
        printf("%02d/%02d/%d %s\n",curr->mob, curr->dob, curr->yob, curr->name);
        if (curr->next == NULL) // Null check to prevent accessing curr->next when curr is NULL
            break;
        curr = curr->next;//Here I think!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
}


int main(){
    int  check,friendList=0, input;
    char inBuf[SIZE];
    Data *firstData = (Data *)malloc(sizeof(Data)), data;
    if(firstData == NULL){
        printf("Cannot allocate memory:\n");
        exit(-1);
    }
    strcpy(firstData->name,"WHO?");
    firstData->mob = 1;
    firstData->dob = 1;
    firstData->yob = 1999;
    firstData->next = NULL;
    
    do{
        printf("************ Friends birthday list ************\n\
Friends in the list: %d\n\
\t(1)     Insert data\n\
\t(2)     Delete data\n\
\t(3)     Print List\n\
\t(4)     Quit\n\
*****************************************\n\
Enter your choice: ", friendList);
        fgets(inBuf, SIZE, stdin);
        sscanf(inBuf, "%d", &input);
        switch (input)
        {
        case 1:
            printf("*** Insert data ***\n");
            data = fillData();
            check = insertNode(firstData, data);
            if(check == 1){
                friendList += 1;
            }
            break;
        case 2:
            printf("*** Delete data ***\n");
            data = fillData();
            Data* del = deleteNode(firstData, data); //Data* removed = deleteNode(firstData, data);
            if(del != NULL){
                friendList -= 1;
                free(del);
            }
            printf("In the main menu rn \n");
            break;
        case 3:
            printf("************ List content ************\n");
            printList(firstData);
            break;
        case 4:
            printf("Quit...\nGoodbye\n");
            break;
        default:
            printf("Input is wrong please re-enter:\n\n");
            break;
        }
    }while(input!=4);
    
    //MIGHT NEED TO ADD A FUNCTION TO SPECIFICALLY FREE EVERYTHING
    freeAll(firstData);
    // free(deleted);
    //free(firstData); //have to free all of the node too with loops
    return 0;
}
