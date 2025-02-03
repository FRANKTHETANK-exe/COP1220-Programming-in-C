#include <stdio.h>

int main() {
    char salesperson, choice;
    double salesD = 0, salesE = 0, salesF = 0, saleAmount;
    double grandTotal = 0; // Running total of all sales
    char topSeller = 'N';  // Tracks highest seller
    double highestSale = 0; // Tracks highest sales amount

    while (1) {
        // Prompt for salesperson initial
        printf("Enter salesperson initial (D, E, F): ");
        scanf(" %c", &salesperson);  // Space before %c fixes input issues

        // Convert lowercase to uppercase
        if (salesperson >= 'a' && salesperson <= 'z') {
            salesperson -= 32;
        }

        // Validate the input
        if (salesperson == 'D' || salesperson == 'E' || salesperson == 'F') {
            printf("Enter sale amount: ");
            if (scanf("%lf", &saleAmount) != 1 || saleAmount < 0) { 
                printf("Invalid sale amount. Try again.\n");
                while (getchar() != '\n'); // Clear buffer
                continue;
            }

            // Add sale amount to the respective salesperson
            if (salesperson == 'D') {
                salesD += saleAmount;
            } else if (salesperson == 'E') {
                salesE += saleAmount;
            } else if (salesperson == 'F') {
                salesF += saleAmount;
            }
        } else {
            printf("Error: Invalid salesperson selected, please try again.\n");
            continue; // Restart loop without asking to continue
        }

        // Ask the user if they want to continue
        printf("Do you want to enter another sale? (Y/N): ");
        scanf(" %c", &choice);

        // Convert lowercase to uppercase
        if (choice >= 'a' && choice <= 'z') {
            choice -= 32;
        }

        if (choice == 'N') {
            break; // Exit loop if user chooses not to continue
        }
    }

    // Compute totals
    grandTotal = salesD + salesE + salesF;
    topSeller = 'D';
    highestSale = salesD;

    if (salesE > highestSale) {
        highestSale = salesE;
        topSeller = 'E';
    }
    if (salesF > highestSale) {
        highestSale = salesF;
        topSeller = 'F';
    }

    // Display final results
    printf("\nTotal Sales:\n");
    printf("Danielle (D): $%.0f\n", salesD);
    printf("Edward (E): $%.0f\n", salesE);
    printf("Francis (F): $%.0f\n", salesF);
    printf("\nGrand Total: $%.0f\n", grandTotal);
    printf("Highest Sale: %c\n", topSeller);

    return 0;
}
