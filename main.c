#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LEN 1000

bool is_vowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Move leading consonants to the end and add "ay"
void to_pig_latin(char *word, char *result) {
    int len = strlen(word);
    if (len == 0) {
        strcpy(result, "");
        return;
    }

    // Handle punctuation
    char punctuation = '\0';
    if (ispunct(word[len - 1])) {
        punctuation = word[len - 1];
        word[len - 1] = '\0';
        len--;
    }

    if (is_vowel(word[0])) {
        sprintf(result, "%syay", word);
    } else {
        int i = 0;
        while (i < len && !is_vowel(word[i])) i++;
        if (i == len) {
            sprintf(result, "%say", word); // all consonants (e.g. "hmm")
        } else {
            sprintf(result, "%s%.*say", &word[i], i, word);
        }
    }

    if (punctuation != '\0') {
        int rlen = strlen(result);
        result[rlen] = punctuation;
        result[rlen + 1] = '\0';
    }
}

void translate_to_pig_latin(const char *input, char *output) {
    char word[100], translated[100];
    int out_index = 0;
    int i = 0;

    while (*input) {
        if (isspace(*input)) {
            output[out_index++] = *input++;
        } else {
            sscanf(input, "%99[^ \,\.;!?]", word);
            int word_len = strlen(word);
            to_pig_latin(word, translated);
            for (i = 0; translated[i]; i++) {
                output[out_index++] = translated[i];
            }

            input += word_len;

            // If next character is punctuation
            if (ispunct(*input)) {
                output[out_index++] = *input++;
            }
        }
    }
    output[out_index] = '\0';
}

int main() {
    char input[MAX_LEN];
    char output[MAX_LEN * 2];

    printf("Enter a sentence to translate to Pig Latin:\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline

    translate_to_pig_latin(input, output);

    printf("\nPig Latin Translation:\n%s\n", output);
    return 0;
}
