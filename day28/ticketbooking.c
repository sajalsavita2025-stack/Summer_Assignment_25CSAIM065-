#include <stdio.h>

int main() {
    int totalSeats = 50;
    int choice, tickets;
    float price = 200.0, totalAmount;

    do {
        printf("\n===== TICKET BOOKING SYSTEM =====\n");
        printf("1. Book Ticket\n");
        printf("2. Check Available Seats\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of tickets to book: ");
                scanf("%d", &tickets);

                if (tickets <= totalSeats && tickets > 0) {
                    totalSeats -= tickets;
                    totalAmount = tickets * price;

                    printf("\nBooking Successful!\n");
                    printf("Tickets Booked : %d\n", tickets);
                    printf("Total Amount   : Rs. %.2f\n", totalAmount);
                    printf("Remaining Seats: %d\n", totalSeats);
                } else {
                    printf("Sorry! Requested tickets are not available.\n");
                }
                break;

            case 2:
                printf("Available Seats: %d\n", totalSeats);
                break;

            case 3:
                printf("Thank you for using the Ticket Booking System.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}