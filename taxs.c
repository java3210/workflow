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

int main() {
    int yearly_income;
    float tax = 0;
    int deduction_choices[4] = {0};
    int deduction_amounts[4] = {60000, 9000, 100000, 100000};
    int total_deduction = 0;
    int i;
    char input[100];

    printf("กรุณากรอกเงินรายปีของคุณ (บาท): ");
    scanf("%d", &yearly_income);

    if (yearly_income < 150000) {
        printf("รายได้ต่ำกว่า 150,000 บาท: ไม่มีภาษี\n");
        return 0;
    }

    printf("เลือกการลดหย่อนภาษี (พิมพ์เลขแล้วกด Enter เช่น 1 3 4):\n");
    printf("1. ลดหย่อนส่วนตัว 60,000 บาท\n");
    printf("2. ลดหย่อนประกันสังคม 9,000 บาท\n");
    printf("3. ลดหย่อนประกันชีวิต 100,000 บาท\n");
    printf("4. ลดหย่อนดอกเบี้ยบ้าน 100,000 บาท\n");
    printf("กรุณาเลือก: ");

    getchar();
    fgets(input, sizeof(input), stdin);

    for (i = 0; i < 4; i++) {
        char choice_char = '1' + i;
        if (strchr(input, choice_char) != NULL) {
            deduction_choices[i] = 1;
            total_deduction += deduction_amounts[i];
        }
    }

    int taxable_income = yearly_income - total_deduction;
    if (taxable_income < 0) taxable_income = 0;

    tax = calc_tax_th(taxable_income);

    printf("รายได้ต่อปี: %d บาท\n", yearly_income);
    printf("ลดหย่อนภาษีรวม: %d บาท\n", total_deduction);
    printf("รายได้สุทธิหลังหักลดหย่อน: %d บาท\n", taxable_income);
    printf("ภาษีที่ต้องจ่ายประมาณ: %.2f บาท ต่อปี\n", tax);

    return 0;
}
