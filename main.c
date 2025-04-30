#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {

    char name[50];
    uint32_t employee_id;
    float salary;
    char position[30];
}Emp_Recodes_t;

Emp_Recodes_t employees[20];

uint8_t count;
uint8_t max_emp =20;

void displayMessages();
void addEmployee(Emp_Recodes_t *employee, uint8_t *count);
void displayAllEmployees(Emp_Recodes_t *employee, uint8_t *count);
int main(void) {



    while (1) {
        uint32_t user_choise = 0;
        displayMessages();
        scanf("%d",&user_choise);

        switch (user_choise) {
            case 1:
                addEmployee(employees,&count);
            break;
            default:
        }
    }



}


void displayMessages() {

    printf("Add Employee Press  (1)\n");
    printf("Display All Employee Press    (2)\n");
    printf("Delete Employee by ID Press   (3)\n");
    printf("Update Salary by Employee ID Press    (4)\n");
}

void addEmployee(Emp_Recodes_t *employee, uint8_t *count) {
    printf("Enter Employee ID: ");
    uint32_t emp_id =0;
    scanf("%d",&emp_id);
    for(uint8_t i=0; i<*count; i++) {
        if(employee[i].employee_id==emp_id) {

            printf("Employee ID Doesn't Exited\n");
            return;
        }

    }
    employee[*count].employee_id =emp_id;
    getchar();
    printf("Enter Employee Name: ");
    scanf("%50[^\n]",&employee[*count].name);
    printf("Enter Employee Salary: ");
    scanf("%f",&employee[*count].salary);
    getchar();
    printf("Enter Employee Position: ");
    scanf("%50[^\n]",&employee[*count].position);
    printf("Employee Added Successful\n");
    (*count)++;


}

void displayAllEmployees(Emp_Recodes_t *employee, uint8_t *count) {



}



