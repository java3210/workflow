#include <stdio.h>
#include <string.h>

float calc_tax_th(int income) {
    float tax = 0;
    if (income > 5000000) tax += (income - 5000000) * 0.35, income = 5000000;
    if (income > 2000000) tax += (income - 2000000) * 0.30, income = 2000000;
    if (income > 1000000) tax += (income - 1000000) * 0.25, income = 1000000;
    if (income > 750000)  tax += (income - 750000) * 0.20, income = 750000;
    if (income > 500000)  tax += (income - 500000) * 0.15, income = 500000;
    if (income > 300000)  tax += (income - 300000) * 0.10, income = 300000;
    if (income > 150000)  tax += (income - 150000) * 0.05;
    return tax;
}

int main() {
    int yearly_income;
    float tax_before_deduction, tax_after_deduction;
    int personal_deduction = 60000;
    int deduction_limits[3] = {9000, 100000, 100000};
    int deduction_selected[3] = {0};
    int actual_deductions[3] = {0};
    char input[100];
    int i, num;

    printf("กรุณากรอกเงินรายปีของคุณ (บาท): ");
    scanf("%d", &yearly_income);
    getchar();

    if (yearly_income <= 150000) {
        printf("รายได้ต่ำกว่า 150,000 บาท: ไม่ต้องจ่ายภาษี\n");
        return 0;
    }

    tax_before_deduction = calc_tax_th(yearly_income);
    printf("\nภาษีที่ต้องจ่ายก่อนลดหย่อน: %.2f บาท\n", tax_before_deduction);

    printf("\nเลือกการลดหย่อนภาษีเพิ่มเติม (พิมพ์เลข เช่น 1 2 แล้วกด Enter):\n");
    printf("1. ลดหย่อนประกันสังคม 9,000 บาท\n");
    printf("2. ลดหย่อนประกันชีวิต 100,000 บาท\n");
    printf("3. ลดหย่อนดอกเบี้ยบ้าน 100,000 บาท\n");
    printf("**หมายเหตุ: ลดหย่อนรวมข้อ 1-3 ได้สูงสุดไม่เกิน 100,000 บาท**\n");
    printf("กรุณาเลือก: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    while (token != NULL) {
        sscanf(token, "%d", &num);
        if (num >= 1 && num <= 3) {
            deduction_selected[num - 1] = 1;
        }
        token = strtok(NULL, " ");
    }

    int capped_total = 0;
    for (i = 0; i < 3; i++) {
        if (deduction_selected[i]) {
            if (capped_total + deduction_limits[i] > 100000) {
                actual_deductions[i] = 100000 - capped_total;
                capped_total = 100000;
                break;
            } else {
                actual_deductions[i] = deduction_limits[i];
                capped_total += deduction_limits[i];
            }
        }
    }

    int total_deduction = personal_deduction;
    for (i = 0; i < 3; i++) {
        total_deduction += actual_deductions[i];
    }

    int taxable_income = yearly_income - total_deduction;
    if (taxable_income < 0) taxable_income = 0;

    tax_after_deduction = calc_tax_th(taxable_income);

    if (tax_after_deduction <= 0) {
        printf("\nหลังจากหักลดหย่อนแล้ว: ไม่ต้องจ่ายภาษี\n");
        return 0;
    }

    printf("\n---- สรุปรายการ ----\n");
    printf("รายได้ต่อปี: %d บาท\n", yearly_income);
    printf("ภาษีก่อนลดหย่อน: %.2f บาท\n", tax_before_deduction);
    printf("ลดหย่อนส่วนตัว: %d บาท\n", personal_deduction);

    printf("ลดหย่อนเพิ่มเติม:\n");
    if (actual_deductions[0] > 0) printf(" - ประกันสังคม: %d บาท\n", actual_deductions[0]);
    if (actual_deductions[1] > 0) printf(" - ประกันชีวิต: %d บาท\n", actual_deductions[1]);
    if (actual_deductions[2] > 0) printf(" - ดอกเบี้ยบ้าน: %d บาท\n", actual_deductions[2]);
    if (actual_deductions[0] + actual_deductions[1] + actual_deductions[2] == 0)
        printf(" (ไม่มีรายการลดหย่อนเพิ่มเติมที่เลือก)\n");

    printf("รวมลดหย่อนทั้งหมด: %d บาท\n", total_deduction);
    printf("รายได้สุทธิหลังหักลดหย่อน: %d บาท\n", taxable_income);
    printf("ภาษีที่ต้องจ่ายหลังลดหย่อน: %.2f บาท\n", tax_after_deduction);
    printf("สามารถชำระได้ที่เว็ปไซต์ของสรรพกร");
    return 0; 
}
