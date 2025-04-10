#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char initial;
    char name[20];
    float sales;
} SalesPerson;

int main() {
    SalesPerson people[3] = {
        {'D', "Danielle", 0.0},
        {'E', "Edward", 0.0},
        {'F', "Francis", 0.0}
    };

    char input;
    float sale;
    float grandTotal = 0.0;
    int highestIndex = 0;

    while (1) {
        printf("Enter salesperson initial (D, E, F) or Z to quit: ");
        scanf(" %c", &input);
        input = toupper(input);

        if (input == 'Z') break;

        int valid = 0;
        for (int i = 0; i < 3; i++) {
            if (input == people[i].initial) {
                printf("Enter sale amount: ");
                scanf("%f", &sale);
                people[i].sales += sale;
                valid = 1;
                break;
            }
        }

        if (!valid) {
            printf("Error, invalid salesperson selected, please try again\n");
        }
    }

    // Calculate grand total and highest salesperson
    for (int i = 0; i < 3; i++) {
        grandTotal += people[i].sales;
        if (people[i].sales > people[highestIndex].sales) {
            highestIndex = i;
        }
    }

    printf("\nGrand Total: $%.0f\n", grandTotal);
    printf("Highest Sale: %c\n", people[highestIndex].initial);

    return 0;
}
