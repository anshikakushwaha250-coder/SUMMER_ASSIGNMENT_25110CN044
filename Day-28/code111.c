// Program to create Ticket Booking System
#include <stdio.h>
#include <string.h>

struct Ticket
{
    char place[30];
    char timing[20];
    int passengers;
    char name[10][50];
};

struct Ticket t;

void bookTicket()
{
    int choice, i;
    getchar();
    printf("\nEnter Destination: ");
    fgets(t.place, 30, stdin);
    t.place[strcspn(t.place, "\n")] = '\0';

    printf("\nAvailable Timings:\n");
    printf("1. 08:00 AM\n");
    printf("2. 01:00 PM\n");
    printf("3. 06:00 PM\n");

    printf("Choose Timing (1-3): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            strcpy(t.timing, "08:00 AM");
            break;
        case 2:
            strcpy(t.timing, "01:00 PM");
            break;
        case 3:
            strcpy(t.timing, "06:00 PM");
            break;
        default:
            printf("Invalid Choice! Timing set to Not Selected.\n");
            strcpy(t.timing, "Not Selected");
    }

    printf("Enter Number of Passengers: ");
    scanf("%d", &t.passengers);
    getchar();

    if(t.passengers > 10)
    {
        printf("Maximum 10 passengers allowed.\n");
        t.passengers = 10;
    }

    for(i=0;i<t.passengers; i++)
    {
        printf("Enter Name of Passenger %d: ", i + 1);
        fgets(t.name[i], 50, stdin);
        t.name[i][strcspn(t.name[i], "\n")] = '\0';
    }

    printf("\nTicket Booked Successfully!\n");
}

void displayTicket()
{
    int i;
    if(t.passengers == 0)
    {
        printf("\nNo Ticket Booked!\n");
        return;
    }

    printf("\n========== TICKET ==========\n");
    printf("Destination : %s\n", t.place);
    printf("Timing      : %s\n", t.timing);
    printf("Total Passengers : %d\n", t.passengers);

    printf("\nPassenger List:\n");
    for(i = 0; i < t.passengers; i++)
    {
        printf("Seat %d : %s\n", i + 1, t.name[i]);
    }
}

void cancelTicket()
{
    int seat, i;

    if(t.passengers == 0)
    {
        printf("\nNo tickets booked!\n");
        return;
    }

    printf("\nBooked Passengers:\n");
    for(i = 0; i < t.passengers; i++)
    {
        printf("Seat %d : %s\n", i + 1, t.name[i]);
    }

    printf("\nEnter Seat Number to Cancel: ");
    scanf("%d", &seat);

    if(seat < 1 || seat > t.passengers)
    {
        printf("\nInvalid Seat Number!\n");
        return;
    }

    printf("\nTicket of %s cancelled successfully!\n", t.name[seat - 1]);

    for(i = seat - 1; i < t.passengers - 1; i++)
    {
        strcpy(t.name[i], t.name[i + 1]);
    }

    t.passengers--;

    if(t.passengers == 0)
    {
        strcpy(t.place, "");
        strcpy(t.timing, "");
        printf("All tickets have been cancelled.\n");
    }
}

int main()
{
    int choice = 0;

    while(choice != 4)
    {
        printf("\n==============================");
        printf("\n   Ticket Booking System");
        printf("\n==============================");
        printf("\n1. Book Ticket");
        printf("\n2. Display Ticket");
        printf("\n3. Cancel Ticket");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                bookTicket();
                break;

            case 2:
                displayTicket();
                break;

            case 3:
                cancelTicket();
                break;

            case 4:
                printf("\nThank You! Visit Again.\n");
                break;

            default:
                printf("\nInvalid Choice! Please try again.\n");
        }
    }

    return 0;
}