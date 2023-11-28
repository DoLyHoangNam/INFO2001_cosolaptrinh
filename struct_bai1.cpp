#include <stdio.h>

// Dinh nghia cau truc Student
struct Student {
    char name[50];
    int id;
    int age;
};

// Ham nhap thong tin sinh vien
struct Student inputStudent() {
    struct Student x;

    printf("Nhap ten: ");
    fgets(x.name, sizeof(x.name), stdin);
    printf("Nhap ma so: ");
    scanf("%d", &x.id);
    printf("Nhap tuoi: ");
    scanf("%d", &x.age);
    return x;
}

// Ham hien thi thong tin sinh vien
void displayStudent(struct Student x) {
    printf("\nThong tin sinh vien:\n");
    printf("Ten: %s", x.name);
    printf("Ma so: %d\n", x.id);
    printf("Tuoi: %d\n", x.age);
}

int main() {
    struct Student students[13];  

    // Nhap thong tin sinh vien
    for (int i = 0; i < 13; i++) {
        printf("\nNhap thong tin cho sinh vien thu %d:\n", i + 1);
        students[i] = inputStudent();
    }

    // Hien thi thong tin sinh vien
    for (int i = 0; i < 13; i++) {
        displayStudent(students[i]);
    }

    return 0;
}

