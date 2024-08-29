#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>


void drawMenu() {
    // Set background color
    setbkcolor(LIGHTGRAY);
    cleardevice();

    // Draw Destination Menu
    setcolor(BLUE);
    rectangle(50, 50, 250, 300);
    outtextxy(100, 60, "Destinations:");
    outtextxy(70, 100, "1. Destination 1");
    outtextxy(70, 140, "2. Destination 2");
    outtextxy(70, 180, "3. Destination 3");
    outtextxy(70, 220, "4. Destination 4");

    // Draw Ticket Menu
    rectangle(300, 50, 500, 300);
    outtextxy(350, 60, "Ticket Type:");
    outtextxy(320, 100, "1. Adult Ticket");
    outtextxy(320, 140, "2. Child Ticket");
    outtextxy(320, 180, "3. Senior Ticket");

    // Draw Price Information
    rectangle(550, 50, 750, 300);
    outtextxy(580, 60, "Prices:");
    outtextxy(570, 100, "Dest 1 - Adult: $15.0");
    outtextxy(570, 120, "Dest 1 - Child: $7.5");
    outtextxy(570, 140, "Dest 1 - Senior: $10.0");
    outtextxy(570, 180, "Dest 2 - Adult: $20.0");
    outtextxy(570, 200, "Dest 2 - Child: $10.0");
    outtextxy(570, 220, "Dest 2 - Senior: $12.5");

    // Draw Total Cost Section
    rectangle(50, 350, 400, 450);
    outtextxy(70, 380, "Total Cost:");
    outtextxy(180, 380, "$0.00");

    // Draw Receipt Section
    rectangle(450, 350, 750, 450);
    outtextxy(470, 360, "----- Receipt -----");
    outtextxy(470, 400, "Destination: ");
    outtextxy(470, 420, "Ticket Type: ");
    outtextxy(470, 440, "Total Cost: $0.00");
    outtextxy(670, 360, "-------------------");
}

// Define ticket prices for destinations
#define DEST1_ADULT_TICKET_PRICE 15.0
#define DEST1_CHILD_TICKET_PRICE 7.5
#define DEST1_SENIOR_TICKET_PRICE 10.0

#define DEST2_ADULT_TICKET_PRICE 20.0
#define DEST2_CHILD_TICKET_PRICE 10.0
#define DEST2_SENIOR_TICKET_PRICE 12.5

#define DEST3_ADULT_TICKET_PRICE 25.0
#define DEST3_CHILD_TICKET_PRICE 12.5
#define DEST3_SENIOR_TICKET_PRICE 15.0

#define DEST4_ADULT_TICKET_PRICE 50.0
#define DEST4_CHILD_TICKET_PRICE 40.5
#define DEST4_SENIOR_TICKET_PRICE 45.0

void displayDestinationMenu() {
    printf("Select your destination:\n");
    printf("1. Destination 1\n");
    printf("2. Destination 2\n");
    printf("3. Destination 3\n");
    printf("4. Destination 4\n");
    printf("4. Exit\n");
}

void displayTicketMenu() {
    printf("Select the type of ticket you want to purchase:\n");
    printf("1. Adult Ticket\n");
    printf("2. Child Ticket\n");
    printf("3. Senior Ticket\n");
    printf("4. Exit\n");
}

int main() {
    int destChoice;
    int ticketChoice;
    int numberOfTickets;
    float totalCost = 0.0;

    while (1) {
        displayDestinationMenu();
        printf("Enter your choice: ");
        scanf("%d", &destChoice);

        if (destChoice == 9) {
            printf("Thank you for using the Ticket Vending Machine. Goodbye!\n");
            break;
        }

        switch (destChoice) {
            case 1:
            case 2:
            case 3:
            case 4:
                displayTicketMenu();
                printf("Enter your choice: ");
                scanf("%d", &ticketChoice);

                if (ticketChoice == 9) {
                    printf("Exiting ticket selection...\n");
                    break;
                }

                printf("Enter the number of tickets: ");
                scanf("%d", &numberOfTickets);

                switch (ticketChoice) {
                    case 1:
                        if (destChoice == 1)
                            totalCost = numberOfTickets * DEST1_ADULT_TICKET_PRICE;
                        else if (destChoice == 2)
                            totalCost = numberOfTickets * DEST2_ADULT_TICKET_PRICE;
                        else if (destChoice == 3)
                            totalCost = numberOfTickets * DEST3_ADULT_TICKET_PRICE;
                        break;
                    case 2:
                        if (destChoice == 1)
                            totalCost = numberOfTickets * DEST1_CHILD_TICKET_PRICE;
                        else if (destChoice == 2)
                            totalCost = numberOfTickets * DEST2_CHILD_TICKET_PRICE;
                        else if (destChoice == 3)
                            totalCost = numberOfTickets * DEST3_CHILD_TICKET_PRICE;
                        break;
                    case 3:
                        if (destChoice == 1)
                            totalCost = numberOfTickets * DEST1_SENIOR_TICKET_PRICE;
                        else if (destChoice == 2)
                            totalCost = numberOfTickets * DEST2_SENIOR_TICKET_PRICE;
                        else if (destChoice == 3)
                            totalCost = numberOfTickets * DEST3_SENIOR_TICKET_PRICE;
                        break;
                     case 4:
                        if (destChoice == 1)
                            totalCost = numberOfTickets * DEST1_SENIOR_TICKET_PRICE;
                        else if (destChoice == 2)
                            totalCost = numberOfTickets * DEST2_SENIOR_TICKET_PRICE;
                        else if (destChoice == 3)
                            totalCost = numberOfTickets * DEST3_SENIOR_TICKET_PRICE;
                        break;
                    default:
                        printf("Invalid ticket choice. Please try again.\n");
                        continue;
                }

                printf("Total cost: $%.2f\n", totalCost);
                printf("Printing receipt...\n");
                printf("----- Receipt -----\n");
                printf("Destination: %d\n", destChoice);
                printf("Ticket Type: %s\n", ticketChoice == 1 ? "Adult" : (ticketChoice == 2 ? "Child" : "Senior"));
                printf("Number of Tickets: %d\n", numberOfTickets);
                printf("Total Cost: $%.2f\n", totalCost);
                printf("-------------------\n");
                break;
            default:
                printf("Invalid destination choice. Please try again.\n");
                break;
        }
    }


    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    drawMenu();

    getch();
    closegraph();    return 0;
}
