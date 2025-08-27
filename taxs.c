#include <stdio.h>
#include <string.h>

float calc_tax_th(int income) {
    float tax = 0;
    if (income > 5000000)      tax += (income - 5000000) * 0.35, income = 5000000;
    if (income > 2000000)      tax += (income - 2000000) * 0.30, income = 2000000;
    if (income > 1000000)      tax += (income - 1000000) * 0.25, income = 1000000;
    if (income > 750000)       tax += (income - 750000) * 0.20, income = 750000;
    if (income > 500000)       tax += (income - 500000) * 0.15, income = 500000;
    if (income > 300000)       tax += (income - 300000) * 0.10, income = 300000;
    if (income > 150000)       tax += (income - 150000) * 0.05;
    return tax;
}

float calc_tax_sg(int income) {
    float tax = 0;
    if (income > 320000)       tax += (income - 320000) * 0.22, income = 320000;
    if (income > 280000)       tax += (income - 280000) * 0.20, income = 280000;
    if (income > 240000)       tax += (income - 240000) * 0.19, income = 240000;
    if (income > 200000)       tax += (income - 200000) * 0.18, income = 200000;
    if (income > 160000)       tax += (income - 160000) * 0.17, income = 160000;
    if (income > 120000)       tax += (income - 120000) * 0.15, income = 120000;
    if (income > 80000)        tax += (income - 80000)  * 0.11, income = 80000;
    if (income > 40000)        tax += (income - 40000)  * 0.075, income = 40000;
    if (income > 30000)        tax += (income - 30000)  * 0.035, income = 30000;
    if (income > 20000)        tax += (income - 20000)  * 0.02;
    return tax;
}

float calc_tax_jp(int income) {
    float tax = 0;
    if (income > 40000000)     tax += (income - 40000000) * 0.45, income = 40000000;
    if (income > 18000000)     tax += (income - 18000000) * 0.40, income = 18000000;
    if (income > 9000000)      tax += (income - 9000000) * 0.33, income = 9000000;
    if (income > 6950000)      tax += (income - 6950000) * 0.23, income = 6950000;
    if (income > 3300000)      tax += (income - 3300000) * 0.20, income = 3300000;
    if (income > 1950000)      tax += (income - 1950000) * 0.10, income = 1950000;
    if (income > 0)            tax += income * 0.05;
    return tax;
}

int main() {
    char code[3];
    int monthly_income;
    int yearly_income;
    float tax = 0;

    printf("กรุณากรอกเลือกประเทศ (เช่น TH, SG, JP): ");
    scanf("%2s", code);

    printf("เงินรายเดือนของคุณ (บาท): ");
    scanf("%d", &monthly_income);

    yearly_income = monthly_income * 12;

    if (strcmp(code, "TH") == 0)
        tax = calc_tax_th(yearly_income);
    else if (strcmp(code, "SG") == 0)
        tax = calc_tax_sg(yearly_income);
    else if (strcmp(code, "JP") == 0)
        tax = calc_tax_jp(yearly_income);
    else {
        printf("ยังไม่มีข้อมูลภาษีสำหรับประเทศนี้\n");
        return 1;
    }

    printf("รายได้ต่อปี: %d บาท\n", yearly_income);
    printf("คุณต้องจ่ายภาษีประมาณ: %.2f บาท ต่อปี\n", tax);
    return 0;
}
