#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_SALESPERSONS 3

int main() {
    char salespeople[NUM_SALESPERSONS] = {'D', 'E', 'F'};
    char *names[NUM_SALESPERSONS] = {"Danielle", "Edward", "Francis"};
    double sales[NUM_SALESPERSONS] = {0, 0, 0};

    char initial;
    double saleAmount;

    while (1) {
        // Prompt for salesperson initial
        printf("Enter salesperson initial (D, E, F) or Z to quit: ");
        scanf(" %c", &initial);
        initial = toupper(initial); // Convert to uppercase for consistency

        // Check for exit condition
        if (initial == 'Z') {
            break;
        }

        // Find the corresponding salesperson index
        int index = -1;
        for (int i = 0; i < NUM_SALESPERSONS; i++) {
            if (initial == salespeople[i]) {
                index = i;
                break;
            }
        }

        // If initial is not found in the list
        if (index == -1) {
            printf("Error, invalid salesperson selected, please try again\n");
            continue;
        }

        // Prompt for sales amount
        printf("Enter the amount of the sale: ");
        if (scanf("%lf", &saleAmount) != 1 || saleAmount < 0) {
            printf("Invalid sale amount. Please enter a positive number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        // Update sales total for the respective salesperson
        sales[index] += saleAmount;
    }

    // Calculate total sales and find the top salesperson
    double totalSales = 0;
    double maxSales = sales[0];
    char topSalesperson = salespeople[0];

    for (int i = 0; i < NUM_SALESPERSONS; i++) {
        totalSales += sales[i];
        if (sales[i] > maxSales) {
            maxSales = sales[i];
            topSalesperson = salespeople[i];
        }
    }

    // Display results
    printf("\nSales Summary:\n");
    for (int i = 0; i < NUM_SALESPERSONS; i++) {
        printf("%s's total sales: $%.2f\n", names[i], sales[i]);
    }
    printf("Grand total sales: $%.2f\n", totalSales);
    printf("Top salesperson: %c\n", topSalesperson);

    return 0;
}
