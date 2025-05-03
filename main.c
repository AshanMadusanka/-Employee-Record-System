#include <stdio.h>
#include <stdint.h>
#include <string.h>

/**
 * @brief Structure to store employee records.
 *
 * @param name Employee's name (max 50 characters).
 * @param employee_id Employee's unique ID.
 * @param salary Employee's salary.
 * @param position Employee's position (max 30 characters).
 */
typedef struct {
    char name[50];
    uint32_t employee_id;
    float salary;
    char position[30];
} Emp_Recodes_t;

// Array to store employee records.
Emp_Recodes_t employees[20];

// Global variables to track the number of employees and the maximum allowed employees.
uint8_t count;
uint8_t max_emp = 20;

/**
 * @brief Displays the menu options for the user.
 */
void displayMessages();

/**
 * @brief Adds a new employee to the records.
 *
 * @param employee Pointer to the array of employee records.
 * @param count Pointer to the current count of employees.
 */
void addEmployee(Emp_Recodes_t *employee, uint8_t *count);

/**
 * @brief Displays all employee records.
 *
 * @param employee Pointer to the array of employee records.
 * @param count Pointer to the current count of employees.
 */
void displayAllEmployees(Emp_Recodes_t *employee, uint8_t *count);

/**
 * @brief Updates the salary of an employee by their ID.
 *
 * @param employee Pointer to the array of employee records.
 * @param count Pointer to the current count of employees.
 */
void updateSalaryByID(Emp_Recodes_t *employee, uint8_t *count);

/**
 * @brief Deletes an employee record by their ID.
 *
 * @param employee Pointer to the array of employee records.
 * @param count Pointer to the current count of employees.
 */
void deleteEmployeeById(Emp_Recodes_t *employee, uint8_t *count);

int main(void) {
    while (1) {
        uint32_t user_choise = 0;
        displayMessages();
        scanf("%d", &user_choise);

        switch (user_choise) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                displayAllEmployees(employees, &count);
                break;
            case 3:
                deleteEmployeeById(employees, &count);
                break;
            case 4:
                updateSalaryByID(employees, &count);
                break;
            default:
                // No action for invalid input.
                break;
        }
    }
}

/**
 * @brief Prints the menu options for the user.
 */
void displayMessages() {
    printf("Add Employee Press  (1)\n");
    printf("Display All Employee Press    (2)\n");
    printf("Delete Employee by ID Press   (3)\n");
    printf("Update Salary by Employee ID Press    (4)\n");
}

/**
 * @brief Adds a new employee to the records.
 *
 * @param employee Pointer to the array of employee records.
 * @param count Pointer to the current count of employees.
 */
void addEmployee(Emp_Recodes_t *employee, uint8_t *count) {
    printf("Enter Employee ID: ");
    uint32_t emp_id = 0;
    scanf("%d", &emp_id);

    // Check if the employee ID already exists.
    for (uint8_t i = 0; i < *count; i++) {
        if (employee[i].employee_id == emp_id) {
            printf("Employee ID Doesn't Exist\n");
            return;
        }
    }

    // Add employee details.
    employee[*count].employee_id = emp_id;
    getchar(); // Clear input buffer.
    printf("Enter Employee Name: ");
    scanf("%50[^\n]", &employee[*count].name);
    printf("Enter Employee Salary: ");
    scanf("%f", &employee[*count].salary);
    getchar(); // Clear input buffer.
    printf("Enter Employee Position: ");
    scanf("%50[^\n]", &employee[*count].position);
    printf("Employee Added Successfully\n");
    (*count)++;
}

/**
 * @brief Displays all employee records.
 *
 * @param employee Pointer to the array of employee records.
 * @param count Pointer to the current count of employees.
 */
void displayAllEmployees(Emp_Recodes_t *employee, uint8_t *count) {
    for (uint32_t i = 0; i < *count; i++) {
        printf("Employee Name : %s\n", employee[i].name);
        printf("Employee Position : %s\n", employee[i].position);
        printf("Employee Salary : %0.3f\n", employee[i].salary);
        printf("Employee ID : %d\n\n", employee[i].employee_id);
    }
}

/**
 * @brief Updates the salary of an employee by their ID.
 *
 * @param employee Pointer to the array of employee records.
 * @param count Pointer to the current count of employees.
 */
void updateSalaryByID(Emp_Recodes_t *employee, uint8_t *count) {
    uint32_t emp_id = 0;
    scanf("%d", &emp_id);

    // Search for the employee by ID and update their salary.
    for (uint32_t i = 0; i < *count; i++) {
        if (employee[i].employee_id == emp_id) {
            printf("Update Salary (Employee - %d): ", employee[i].employee_id);
            scanf("%f", &employee[i].salary);
            return;
        }
    }
    printf("Employee Doesn't Exist\n");
}

/**
 * @brief Deletes an employee record by their ID.
 *
 * @param employee Pointer to the array of employee records.
 * @param count Pointer to the current count of employees.
 */
void deleteEmployeeById(Emp_Recodes_t *employee, uint8_t *count) {
    uint32_t emp_id = 0;
    printf("Enter Employee ID: ");
    scanf("%d", &emp_id);

    // Search for the employee by ID and delete their record.
    for (uint32_t i = 0; i < *count; i++) {
        if (employee[i].employee_id == emp_id) {
            for (uint32_t j = i; j < *count - 1; j++) {
                employee[j] = employee[j + 1];
            }
            (*count)--;
            printf("Employee Deleted\n");
            return;
        }
    }
    printf("Employee Doesn't Exist\n");
}