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

// Function to print all perfect numbers within a given range
void printPerfectNumbers(int limit) {
    printf("Perfect numbers from 1 to %d:\n", limit);
    for (int i = 1; i <= limit; i++) {
        if (isPerfect(i)) {
            printf("%d\n", i);
        }
    }
}

// Function to check user input for perfection
void checkUserInput() {
    int userInput;
    printf("\nEnter a number to check if it's perfect: ");
    scanf("%d", &userInput);

    if (isPerfect(userInput)) {
        printf("Perfect Number\n");
    } else {
        printf("Not A Perfect Number\n");
    }
}

int main() {
    // Print perfect numbers in the range 1 to 10,000
    printPerfectNumbers(10000);

    // Check if user input is a perfect number
    checkUserInput();

    return 0;
}
