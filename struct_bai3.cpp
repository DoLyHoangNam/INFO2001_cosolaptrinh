#include <stdio.h>
#include <string.h>

// Dinh nghia cau truc Employee
struct Employee {
    int employeeId;
    char name[50];
    char position[50];
    float salary;
};
// Ham nhap thong tin nhan vien
struct Employee inputEmployee() {
    struct Employee e;
    printf("Nhap ma nhan vien: ");
    scanf("%d", &e.employeeId);
    getchar();

    printf("Nhap ten nhan vien: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = '\0';

    printf("Nhap chuc vu: ");
    fgets(e.position, sizeof(e.position), stdin);
    e.position[strcspn(e.position, "\n")] = '\0';

    printf("Nhap luong: ");
    scanf("%f", &e.salary);
    return e;
}

// Ham hien thi thong tin nhan vien
void displayEmployee(struct Employee e) {
    printf("\nThong tin nhan vien:\n");
    printf("Ma nhan vien: %d\n", e.employeeId);
    printf("Ten: %s\n", e.name);
    printf("Chuc vu: %s\n", e.position);
    printf("Luong: %.2f\n", e.salary);
}

// Ham them nhan vien vao mang
void addEmployee(struct Employee arr[], int *n) {
    if (*n < 10) {
        arr[*n] = inputEmployee();
        (*n)++;
        printf("Da them nhan vien thanh cong!\n");
    } else {
        printf("Danh sach nhan vien da day, khong the them nhan vien moi!\n");
    }
}

// Ham xoa nhan vien theo ma nhan vien
int deleteEmployee(struct Employee arr[], int *n, int employeeId) {
    int found = 0;
    int newCount = 0;  // Bien dem so luong nhan vien moi sau khi xoa
    for (int i = 0; i < *n; i++) {
        if (arr[i].employeeId == employeeId) {
            found = 1;
        } else {
            arr[newCount] = arr[i];
            newCount++;
        }
    }

    if (found) {
        (*n)--;
        printf("Da xoa nhan vien co ma nhan vien %d!\n", employeeId);
        return 1;  
    } else {
        printf("Khong tim thay nhan vien co ma nhan vien %d!\n", employeeId);
        return 0;  
    }
}

// Ham sap xep nhan vien theo ma nhan vien
void sortEmployeesById(struct Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].employeeId > arr[j + 1].employeeId) {
                struct Employee temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Employee employees[10]; 
    int employeeCount = 0;

    // Them nhan vien
    addEmployee(employees, &employeeCount);

    // Hien thi thong tin nhan vien
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }

    // Them them nhan vien
    addEmployee(employees, &employeeCount);

    // Hien thi thong tin nhan vien
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }

    // Xoa nhan vien theo ma nhan vien
    int employeeIdToDelete;
    printf("Nhap ma nhan vien can xoa: ");
    scanf("%d", &employeeIdToDelete);
    deleteEmployee(employees, &employeeCount, employeeIdToDelete);

    // Hien thi thong tin nhan vien sau khi xoa
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }

    // Sap xep nhan vien theo ma nhan vien
    sortEmployeesById(employees, employeeCount);

    // Hien thi thong tin nhan vien sau khi sap xep
    printf("\nDanh sach nhan vien sau khi sap xep theo ma nhan vien:\n");
    for (int i = 0; i < employeeCount; i++) {
        displayEmployee(employees[i]);
    }

    return 0;
}

