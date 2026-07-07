#include <stdio.h>

int main() {
    char ans;
    int score = 0;

    printf("=== Quiz Application ===\n");

    printf("\n1. What is the capital of India?\n");
    printf("A. Mumbai\nB. Delhi\nC. Chennai\n");
    printf("Enter Answer: ");
    scanf(" %c", &ans);

    if (ans == 'B' || ans == 'b')
        score++;

    printf("\n2. Which language is used for system programming?\n");
    printf("A. C\nB. HTML\nC. CSS\n");
    printf("Enter Answer: ");
    scanf(" %c", &ans);

    if (ans == 'A' || ans == 'a')
        score++;

    printf("\n3. 5 + 7 = ?\n");
    printf("A. 10\nB. 12\nC. 15\n");
    printf("Enter Answer: ");
    scanf(" %c", &ans);

    if (ans == 'B' || ans == 'b')
        score++;

    printf("\nYour Score = %d/3\n", score);

    if (score == 3)
        printf("Excellent!\n");
    else if (score == 2)
        printf("Good Job!\n");
    else
        printf("Keep Practicing!\n");

    return 0;
}