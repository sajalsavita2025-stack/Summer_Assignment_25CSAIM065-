#include <stdio.h>

int main() {
    int choice;
    char name[50];
    int accNo;
    float balance = 0, amount;

    printf("===== BANK ACCOUNT SYSTEM =====\n");

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", name);

    printf("Enter Account Number: ");
    scanf("%d", &accNo);

    do {
        printf("\n----- MENU -----\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                balance += amount;
                printf("Rs. %.2f deposited successfully.\n", amount);
                break;

            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if(amount <= balance) {
                    balance -= amount;
                    printf("Rs. %.2f withdrawn successfully.\n", amount);
                } else {
                    printf("Insufficient balance!\n");
                }
                break;

            case 3:
                printf("\nAccount Holder: %s\n", name);
                printf("Account Number: %d\n", accNo);
                printf("Current Balance: Rs. %.2f\n", balance);
                break;

            case 4:
                printf("Thank you for using the Bank Account System.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 4);

    return 0;
}