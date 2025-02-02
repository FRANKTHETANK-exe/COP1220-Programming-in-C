#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 0;

    // Find divisors and sum them
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    // A number is perfect if the sum of its divisors equals itself
    return sum == num;
}

int main() {
    printf("Perfect numbers from 1 to 10,000:\n");

    // Loop through numbers 1 to 10,000 and check if they are perfect
    for (int i = 1; i <= 10000; i++) {
        if (isPerfect(i)) {
            printf("%d\n", i);
        }
    }

    // User input to check if a specific number is perfect
    int userInput;
    printf("\nEnter a number to check if it's perfect: ");
    scanf("%d", &userInput);

    if (isPerfect(userInput)) {
        printf("Perfect Number\n");
    } else {
        printf("Not A Perfect Number\n");
    }

    return 0;
}
