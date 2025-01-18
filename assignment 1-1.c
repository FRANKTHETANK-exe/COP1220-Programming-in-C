#include <stdio.h>

int main() {
    char name[50];
    char birthdate[15];
    char workPhone[15];
    char cellPhone[15];

    // Prompt user for details
    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter birthdate (MM/DD/YYYY): ");
    fgets(birthdate, sizeof(birthdate), stdin);

    printf("Enter work phone number (format 000-000-0000): ");
    fgets(workPhone, sizeof(workPhone), stdin);

    printf("Enter cell phone number (format 000-000-0000): ");
    fgets(cellPhone, sizeof(cellPhone), stdin);

    // Display the information in the specified format
    printf("\n%s", name);
    printf("%s", birthdate);
    printf("work %s", workPhone);
    printf("cell %s", cellPhone);

    return 0;
}
