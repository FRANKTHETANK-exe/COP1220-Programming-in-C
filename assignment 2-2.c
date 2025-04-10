#include <stdio.h>

int main() {
    float windSpeed;  // Variable to store the wind speed

    // Ask the user for wind speed
    printf("Enter the wind speed in mph: ");
    scanf("%f", &windSpeed);

    // Determine the hurricane category
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

    return 0;
}
