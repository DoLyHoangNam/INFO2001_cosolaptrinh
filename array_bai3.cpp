#include <stdio.h>

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    float diem[n];
    float tongDiem = 0;
    for (int i = 0; i < n; i++) {
        printf("Nhap diem cua sinh vien %d: ", i + 1);
        scanf("%f", &diem[i]);
        tongDiem += diem[i];
    }
    float diemTrungBinh = tongDiem / n;
    printf("Diem trung binh cua lop la: %.2f\n", diemTrungBinh);
    return 0;
}
