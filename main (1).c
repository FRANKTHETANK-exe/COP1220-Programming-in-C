#include <stdio.h>

#define NUM_DAYS 5
#define MIN_TEMP -30
#define MAX_TEMP 130

int main() {
    int temperatures[NUM_DAYS];
    int i;
    double sum = 0;

    
    for (i = 0; i < NUM_DAYS; i++) {
        int temp;
        while (1) {
            printf("Enter Temperature for day %d: ", i + 1);
            scanf("%d", &temp);

            if (temp < MIN_TEMP || temp > MAX_TEMP) {
                printf("EXCEPTION: Temperature %d is invalid, Please enter a valid temperature between -30 and 130\n", temp);
            } else {
                break;
            }
        }
        temperatures[i] = temp;
        sum += temp;
    }

    // Determine trend
    int ascending = 1, descending = 1;

    for (i = 1; i < NUM_DAYS; i++) {
        if (temperatures[i] < temperatures[i - 1]) {
            ascending = 0;
        }
        if (temperatures[i] > temperatures[i - 1]) {
            descending = 0;
        }
    }

    // Output trend message
    if (ascending) {
        printf("OUTPUT: Getting Warmer\n");
    } else if (descending) {
        printf("OUTPUT: Getting Colder\n");
    } else {
        printf("OUTPUT: It's a mixed bag\n");
    }

    // Print temperatures
    printf("OUTPUT: 5-day Temperature [");
    for (i = 0; i < NUM_DAYS; i++) {
        printf("%d", temperatures[i]);
        if (i < NUM_DAYS - 1) printf(", ");
    }
    printf("]\n");

    // Print average temperature
    printf("OUTPUT: Average Temperature is %.1f degrees\n", sum / NUM_DAYS);

    return 0;
}
