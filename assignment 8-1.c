#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char initial;
    float totalSales;
} SalesPerson;

int main() {
    FILE *fp;
    char initial;
    float sale;
    SalesPerson salespeople[3] = {
        {'D', 0},
        {'E', 0},
        {'F', 0}
    };

    fp = fopen("salesdata.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");                                                                                        return 1;
    }

    while (fscanf(fp, " %c %f", &initial, &sale) == 2) {
        int valid = 0;
        for (int i = 0; i < 3; i++) {
            if (salespeople[i].initial == initial) {
                salespeople[i].totalSales += sale;
                valid = 1;
                break;
            }
        }
        if (!valid) {
            printf("Error, invalid salesperson selected, please try again\n");
        }
    }

    fclose(fp);

    float grandTotal = 0;
    char topSalesperson = ' ';
    float highestSale = 0;

    for (int i = 0; i < 3; i++) {
        grandTotal += salespeople[i].totalSales;
        if (salespeople[i].totalSales > highestSale) {
            highestSale = salespeople[i].totalSales;
            topSalesperson = salespeople[i].initial;
        }
    }

    printf("Grand Total: $%.0f\n", grandTotal);
    printf("Highest Sale: %c\n", topSalesperson);

    return 0;
}
