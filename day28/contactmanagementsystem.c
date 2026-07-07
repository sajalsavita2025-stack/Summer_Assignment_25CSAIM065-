#include <stdio.h>

int main() {
    char name[50];
    char phone[15];
    char email[50];
    int choice;

    do {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Contact\n");
        printf("2. View Contact\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Name: ");
                scanf(" %[^\n]", name);

                printf("Enter Phone Number: ");
                scanf("%s", phone);

                printf("Enter Email: ");
                scanf("%s", email);

                printf("\nContact Added Successfully!\n");
                break;

            case 2:
                printf("\n----- Contact Details -----\n");
                printf("Name : %s\n", name);
                printf("Phone: %s\n", phone);
                printf("Email: %s\n", email);
                break;

            case 3:
                printf("Thank you for using the Contact Management System.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 3);

    return 0;
}