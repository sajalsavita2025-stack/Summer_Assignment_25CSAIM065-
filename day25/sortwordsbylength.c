#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

int main() {
    char input[500];
    char words[MAX_WORDS][MAX_LENGTH];
    char temp[MAX_LENGTH];
    int count = 0;
    printf("Enter a sentence: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1;
    }
    input[strcspn(input, "\n")] = '\0';
    char *token = strtok(input, " ,.");
    while (token != NULL && count < MAX_WORDS) {
        strncpy(words[count], token, MAX_LENGTH - 1);
        words[count][MAX_LENGTH - 1] = '\0'; 
        count++;
        token = strtok(NULL, " ,.");
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            size_t len1 = strlen(words[j]);
            size_t len2 = strlen(words[j + 1]);

            if ((len1 > len2) || (len1 == len2 && strcmp(words[j], words[j + 1]) > 0)) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j + 1]);
                strcpy(words[j + 1], temp);
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (length: %lu)\n", words[i], (unsigned long)strlen(words[i]));
    }

    return 0;
}