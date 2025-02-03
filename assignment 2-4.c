#include <stdio.h>
#include <ctype.h>

int main() {
    char initial;
    double dSales = 0, eSales = 0, fSales = 0, saleAmount;

    while (1) {
        // Prompt for salesperson initial
        printf("Enter salesperson initial (D, E, F) or Z to quit: ");
        scanf(" %c", &initial);
        initial = toupper(initial); // Convert to uppercase for consistency

        // Check for exit condition
        if (initial == 'Z') {
            break;
        }

        // Validate initial
        if (initial != 'D' && initial != 'E' && initial != 'F') {
            printf("Invalid salesperson initial. Please enter D, E, F, or Z to quit.\n");
            continue;
        }

        // Prompt for sales amount
        printf("Enter the amount of the sale: ");
        if (scanf("%lf", &saleAmount) != 1 || saleAmount < 0) {
            printf("Invalid sale amount. Please enter a positive number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        // Update sales totals
        switch (initial) {
            case 'D': dSales += saleAmount; break;
            case 'E': eSales += saleAmount; break;
            case 'F': fSales += saleAmount; break;
        }
    }

    // Calculate total sales
    double totalSales = dSales + eSales + fSales;

    // Determine top salesperson
    char topSalesperson = 'D';
    double maxSales = dSales;
    if (eSales > maxSales) {
        maxSales = eSales;
        topSalesperson = 'E';
    }
    if (fSales > maxSales) {
        maxSales = fSales;
        topSalesperson = 'F';
    }

    // Display results
    printf("\nSales Summary:\n");
    printf("Danielle's total sales: $%.2f\n", dSales);
    printf("Edward's total sales: $%.2f\n", eSales);
    printf("Francis' total sales: $%.2f\n", fSales);
    printf("Grand total sales: $%.2f\n", totalSales);
    printf("Top salesperson: %c\n", topSalesperson);

    return 0;
}
