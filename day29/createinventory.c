#include <stdio.h>

int main() {
    int choice;
    char productName[50];
    int productID;
    int quantity = 0, addQty, removeQty;

    printf("===== INVENTORY MANAGEMENT SYSTEM =====\n");

    printf("Enter Product ID: ");
    scanf("%d", &productID);

    printf("Enter Product Name: ");
    scanf(" %[^\n]", productName);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Add Stock\n");
        printf("2. Remove Stock\n");
        printf("3. View Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter quantity to add: ");
                scanf("%d", &addQty);
                quantity += addQty;
                printf("Stock added successfully.\n");
                break;

            case 2:
                printf("Enter quantity to remove: ");
                scanf("%d", &removeQty);

                if (removeQty <= quantity) {
                    quantity -= removeQty;
                    printf("Stock removed successfully.\n");
                } else {
                    printf("Insufficient stock!\n");
                }
                break;

            case 3:
                printf("\n----- INVENTORY DETAILS -----\n");
                printf("Product ID   : %d\n", productID);
                printf("Product Name : %s\n", productName);
                printf("Available Stock : %d\n", quantity);
                break;

            case 4:
                printf("Thank you for using the Inventory Management System.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}