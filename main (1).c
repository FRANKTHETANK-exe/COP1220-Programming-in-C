#include <stdio.h>

// Function to determine hurricane category
void determineCategory(float windSpeed) {
    if (windSpeed >= 157) {
        printf("Category Five Hurricane\n");
    } else if (windSpeed >= 130) {
        printf("Category Four Hurricane\n");
    } else if (windSpeed >= 111) {
        printf("Category Three Hurricane\n");
    } else if (windSpeed >= 96) {
        printf("Category Two Hurricane\n");
    } else if (windSpeed >= 74) {
        printf("Category One Hurricane\n");
    } else {
        printf("Not a Hurricane\n");
    }
}

// Function to get user input
float getWindSpeed() {
    float windSpeed;
    printf("Enter the wind speed in mph: ");
    scanf("%f", &windSpeed);
    return windSpeed;
}

int main() {
    // Get wind speed from the user
    float windSpeed = getWindSpeed();

    // Determine and print the hurricane category
    determineCategory(windSpeed);

    return 0;
}
