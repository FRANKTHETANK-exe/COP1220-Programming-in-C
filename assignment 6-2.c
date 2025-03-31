#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Caesar Cipher
void caesarCipher(char* input, int shift, char* output) {
    int i;
    shift = shift % 26; // Normalize shift
    for (i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            output[i] = ((c - base + shift + 26) % 26) + base;
        } else {
            output[i] = c;
        }
    }
    output[i] = '\0';
}

// Check for vowels (for Pig Latin)
int isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Pig Latin Translator
void pigLatin(char* input, char* output) {
    char word[100], result[10000] = "";
    int i = 0, j = 0;
    int len = strlen(input);

    while (i <= len) {
        if (isalpha(input[i]) || input[i] == '\'') {
            word[j++] = input[i];
        } else {
            if (j > 0) {
                word[j] = '\0';

                // Translate word
                if (isVowel(word[0])) {
                    sprintf(result + strlen(result), "%syay", word);
                } else {
                    int consonant_len = 0;
                    while (word[consonant_len] && !isVowel(word[consonant_len]) && isalpha(word[consonant_len])) {
                        consonant_len++;
                    }
                    sprintf(result + strlen(result), "%s%.*say", word + consonant_len, consonant_len, word);
                }
                j = 0;
            }

            // Preserve space or punctuation
            if (input[i] != '\0') {
                int rlen = strlen(result);
                result[rlen] = input[i];
                result[rlen + 1] = '\0';
            }
        }
        i++;
    }

    strcpy(output, result);
}

int main() {
    char text[1000], cipher[10000];
    int shift;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // remove newline

    printf("Enter shift: ");
    scanf("%d", &shift);

    printf("Text: %s\n", text);
    printf("Shift: %d\n", shift);

    if (shift >= 0 && shift <= 25) {
        caesarCipher(text, shift, cipher);
    } else {
        pigLatin(text, cipher);
    }

    printf("Cipher: %s\n", cipher);
    return 0;
}
