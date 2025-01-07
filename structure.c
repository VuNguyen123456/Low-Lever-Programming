#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 100

typedef struct
{
    int day;
    int month;
    int year;
}DOB;


typedef struct workerInfo
{
    int ID;
    char FirstName [SIZE];
    char LastName [SIZE];
    DOB birthday;
    double Salary;
}Employee;

void insertData(Employee **employee, int *numberOFEmploy, int *N) {
    char inBuf[SIZE];
    Employee newEmployee;

    // Assign ID
    printf("Enter ID:\n");
    fgets(inBuf, SIZE, stdin);
    sscanf(inBuf, "%d", &newEmployee.ID);

    // Check if ID already exists in the database
    for (int i = 0; i < *numberOFEmploy; ++i) {
        if (newEmployee.ID == (*employee)[i].ID) {
            printf("Error! ID is already in the database\n");
            return;
        }
    }

    printf("Enter First name:\n");
    fgets(inBuf, SIZE, stdin);
    sscanf(inBuf, "%s", newEmployee.FirstName);

    printf("Enter Last name:\n");
    fgets(inBuf, SIZE, stdin);
    sscanf(inBuf, "%s", newEmployee.LastName);

    printf("Enter DOB: day, month, year\n");
    fgets(inBuf, SIZE, stdin);
    sscanf(inBuf, "%d%d%d", &newEmployee.birthday.day, &newEmployee.birthday.month, &newEmployee.birthday.year);

    printf("Enter salary:\n");
    fgets(inBuf, SIZE, stdin);
    sscanf(inBuf, "%lf", &newEmployee.Salary);

    if (*numberOFEmploy == *N) {
        *N *= 2;
        (*employee) = realloc(*employee, sizeof(Employee) * (*N));
        if (employee == NULL) {
            printf("Err Msg! Memory allocation failed\n");
            exit(-1);
        }
    }

    // Insert new employee into the array
    (*employee)[*numberOFEmploy] = newEmployee;
    (*numberOFEmploy)++;

    printf("Employee Added!\n");
    //printf("SIZE of N: %d\n", *N);
    //printf("SIZE of employees: %d\n", *numberOFEmploy);
}

void updateData(Employee * employee ,int *numberOfEmploy, int ID){
    char inBuf[SIZE];
    int i, thisEmploy, ifExist = 0,choice, end = 1;
    for(i = 0; i < *numberOfEmploy; ++i){
        if(ID == employee[i].ID){
            thisEmploy = i;
            ifExist = 1;
            break;
        }
    }
    if(ifExist == 0){
        printf("ID doesn't exist'");
        return;
    }

    printf("Which data do you want to update?\n \
\t1 – First Name \n \
\t2 – Last Name\n \
\t3 – DOB\n \
\t4 – Salary\n \
\t5 – Do not update\n");

    do{
	fgets(inBuf, SIZE, stdin);                                                                                                                                                                                        sscanf(inBuf, "%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Updating first name....");
            fgets(inBuf, SIZE, stdin);
            sscanf(inBuf, "%s", employee[thisEmploy].FirstName);
            end = 0;
            break;
        case 2:
            printf("Updating last name....");
            fgets(inBuf, SIZE, stdin);
            sscanf(inBuf, "%s", employee[thisEmploy].LastName);
            end = 0;
            break;
        case 3:
            printf("Updating DOB (day month year)....");
            fgets(inBuf, SIZE, stdin);
            sscanf(inBuf, "%d%d%d", &employee[thisEmploy].birthday.day,&employee[thisEmploy].birthday.month,&employee[thisEmploy].birthday.year);
            end = 0;
            break;
        case 4:
            printf("Updating Salary....");
            fgets(inBuf, SIZE, stdin);
            sscanf(inBuf, "%lf", &employee[thisEmploy].Salary);
            end = 0;
            break;
        case 5:
            printf("No update\n");
            end = 0;
            break;
        default:
            printf("Option is not valid, try again\n");
            break;
        }
    }while(end);
}

void searchEmploy(Employee *employee, int numberOfEmploy, int ID){
    int i, exist=0;
    for(i = 0; i < numberOfEmploy; ++i){
        if(ID == employee[i].ID){
            printf("ID: %d\nFirst Name: %s\nLast Nam: %s\nDOB: %d/%d/%d\nSalay: %.2lf\n",employee[i].ID, employee[i].FirstName, employee[i].LastName, employee[i].birthday.day, employee[i].birthday.month, employee[i].birthday.year, employee[i].Salary);
            exist = 1;
        }
    }
    if(exist == 0){
        printf("ID doesn't exist\n");
    }
}

void printDataBase(Employee *employee, int numberOfEmploy){
    int i;
    char date[SIZE];
    if(numberOfEmploy != 0){
    printf("ID        Name                DOB            Salary\n");
    for(i = 0; i < numberOfEmploy; i++){
        sprintf(date, "%d/%d/%d", employee[i].birthday.day,employee[i].birthday.month, employee[i].birthday.year);
        printf("%-10d%-10s%-10s%-15s%-.2lf\n", employee[i].ID,employee[i].FirstName, employee[i].LastName, date, employee[i].Salary);
    }
    }
    else{
    printf("No data to print\n");
    }
}
int main(){
    //DIDNT ADD THE NUMBEROF EMPLOYEE COUNTER YET???!!!!
    char inBuf[SIZE];
    char input;
    int end = 1, N = 3, id;
    int numberOfEmploy = 0;
    
    Employee *employee = (Employee* )malloc(sizeof(Employee) * N);
    if(employee == NULL){
        printf("ERR Msg!\n");
        exit(-1);
    }

    do{
        printf("\nEnter your Choice:\n \
    'i' - Insert data\n \
    'u' - Update data\n \
    's' - Search employee\n \
    'p' – Print the database\n \
    'q' - Quit\n");
        printf("Enter your input: ");
        fgets(inBuf, SIZE, stdin);
        sscanf(inBuf, "%c", &input);
        input = tolower(input);
        switch (input)
        {
        case 'i':
            insertData(&employee, &numberOfEmploy, &N);
            break;
        case 'u':
            printf("Enter update id: \n");
            fgets(inBuf, SIZE, stdin);
            sscanf(inBuf, "%d", &id);
            updateData(employee, &numberOfEmploy,id);
            break;
        case 's':
            printf("Enter search id: \n");
            fgets(inBuf, SIZE, stdin);
            sscanf(inBuf, "%d", &id);
            searchEmploy(employee, numberOfEmploy,id);
            break;
        case 'p':
            printDataBase(employee, numberOfEmploy);
            break;
        case 'q':
            printf("Goodbye\n");
            end = 0;
            break;
        default:
            printf("%c is not a valid choice \n", input);
            break;
        }
    }while(end);



    free (employee);
    return 0;
}
