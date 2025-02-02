#include <stdio.h>
#include <string.h>

// MAximun allowed characters
#define MAX_LENGTH 140  

int main() {
    char message[500];  
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin);  // Read user input

    // Remove newline character if present
    size_t length = strlen(message);
    if (length > 0 && message[length - 1] == '\n') {
        message[length - 1] = '\0';
        length--;  // Adjust length after removing newline
    }

    // Check if message length is within limit
    if (length <= MAX_LENGTH) {
        printf("Posted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
