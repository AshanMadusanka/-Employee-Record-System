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
void updateSalaryByID(Emp_Recodes_t *employee ,uint8_t *count);
void deleteEmployeeById(Emp_Recodes_t *employee, uint8_t *count);

int main(void) {



    while (1) {
        uint32_t user_choise = 0;
        displayMessages();
        scanf("%d",&user_choise);

        switch (user_choise) {
            case 1:
                addEmployee(employees,&count);
            break;
            case 2:
                displayAllEmployees(employees,&count);
            break;
            case 3:
                deleteEmployeeById(employees,&count);
            break;
            case 4:
                updateSalaryByID(employees,&count);
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
//****  Emp_Recodes_t *employee = Emp_Recodes_t employee[]

void displayAllEmployees(Emp_Recodes_t *employee, uint8_t *count) {

    for(uint32_t i = 0; i<*count; i++) {

        printf("Employee Name : %s\n", employee[i].name);
        printf("Employee Position : %s\n", employee[i].position);
        printf("Employee Salary : %0.3f\n", employee[i].salary);
        printf("Employee ID : %d\n\n", employee[i].employee_id);




    }

}
void updateSalaryByID(Emp_Recodes_t *employee ,uint8_t *count) {

    uint32_t emp_id = 0;
    scanf("%d",&emp_id);
    for (uint32_t i=0; i<*count; i++) {

        if(employee[i].employee_id == emp_id) {

            printf("Update Salary(Employee - %d ):",employee[i].employee_id);
            scanf("%f",&employee[i].salary);
        }
        else
            printf("Employee Doesnt Exited");

    }
}

void deleteEmployeeById(Emp_Recodes_t *employee, uint8_t *count) {

    uint32_t emp_id = 0;
    printf("Enter Employee Id: ");
    scanf("%d",&emp_id);
    for (uint32_t i=0; i<*count; i++) {

        if(employee[i].employee_id == emp_id) {

            for( uint32_t j=i; j<*count-1; j++ ) {

                employee[j] = employee[j+1];


            }
        }
        else
            printf("Employee Doesnt Exited");

    }

    (*count)--;
    printf("Employee Deleted");
}
