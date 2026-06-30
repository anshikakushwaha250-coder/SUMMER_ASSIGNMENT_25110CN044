//Program to develop complete mini project using arrays,strings and functions
//MINI PROJECT on Hotel Management System
#include <stdio.h>
#include <string.h>

#define MAX 20

char customer[MAX][50];
char roomType[MAX][20];
char acType[MAX][10];
char food[MAX][10];
char checkIn[MAX][15];
char checkOut[MAX][15];
char service[MAX][30];
char season[MAX][20];

int booked[MAX];
int days[MAX];
int rating[MAX];

float totalBill[MAX];
float serviceCharge[MAX];
float seasonalCharge[MAX];
float totalRevenue = 0;

//Declaration of Functions
void menu();
void roomPackages();
void bookRoom();
int findRoom();
float calculateBill(char room[], char ac[], int days, char food[]);
void printBill(int room);

void viewBookings();
void searchCustomer();
void cancelBooking();
void roomService();
void revenueReport();
void customerRating();

//Main function
int main()
{
    int choice;

    for(int i = 0; i < MAX; i++)
        booked[i] = 0;

    while(1)
    {
        menu();
        printf("\nEnter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: roomPackages(); break;
            case 2: bookRoom(); break;
            case 3: viewBookings(); break;
            case 4: searchCustomer(); break;
            case 5: cancelBooking(); break;
            case 6: roomService(); break;
            case 7: revenueReport(); break;
            case 8: customerRating(); break;
            case 9:
                printf("\nThank You!\n");
                return 0;

            default:
                printf("\nInvalid Choice!\n");
        }
    }
}

//Hotel Menu
void menu()
{
    printf("\n=========================================\n");
    printf("        HOTEL MANAGEMENT SYSTEM\n");
    printf("=========================================\n");
    printf("1. View Room Packages\n");
    printf("2. Book Room\n");
    printf("3. View Bookings\n");
    printf("4. Search Customer\n");
    printf("5. Cancel Booking\n");
    printf("6. Room Service\n");
    printf("7. Revenue Report\n");
    printf("8. Customer Rating\n");
    printf("9. Exit\n");
}

//Room Packages
void roomPackages()
{
    printf("\n========== ROOM PACKAGES ==========\n");

    printf("\nSingle Room");
    printf("\nNon AC : Rs 1000 / Day");
    printf("\nAC     : Rs 1500 / Day\n");

    printf("\nDouble Room");
    printf("\nNon AC : Rs 1800 / Day");
    printf("\nAC     : Rs 2300 / Day\n");

    printf("\nFamily Room");
    printf("\nNon AC : Rs 3000 / Day");
    printf("\nAC     : Rs 3500 / Day\n");

    printf("\nVIP Suite");
    printf("\nAC Only : Rs 5000 / Day\n");

    printf("\nDiscount Offers:");
    printf("\n3+ Days = 10%% OFF");
    printf("\n7+ Days = 20%% OFF\n");
}


int findRoom()
{
    for(int i = 0; i < MAX; i++)
        if(booked[i] == 0)
            return i;

    return -1;
}

//Calculation of Bill
float calculateBill(char room[], char ac[], int days, char food[])
{
    float amount = 0;

    if(strcmp(room,"Single") == 0) amount = 1000;
    else if(strcmp(room,"Double") == 0) amount = 1800;
    else if(strcmp(room,"Family") == 0) amount = 3000;
    else if(strcmp(room,"VIP") == 0) amount = 5000;

    if(strcmp(ac,"AC") == 0)
        amount += 500;

    amount *= days;

    if(strcmp(food,"Yes") == 0)
        amount += days * 300;

    if(days >= 7)
        amount *= 0.80;
    else if(days >= 3)
        amount *= 0.90;

    return amount;
}


void bookRoom()
{
    int room = findRoom();

    if(room == -1)
    {
        printf("\nHotel Full!\n");
        return;
    }

    printf("\nCustomer Name : ");
    scanf(" %[^\n]", customer[room]);

    printf("Room Type (Single/Double/Family/VIP): ");
    scanf("%s", roomType[room]);

    printf("AC / Non-AC : ");
    scanf("%s", acType[room]);

    printf("Food (Yes/No): ");
    scanf("%s", food[room]);

    printf("Check-In Date : ");
    scanf("%s", checkIn[room]);

    printf("Check-Out Date : ");
    scanf("%s", checkOut[room]);

    printf("Number of Nights : ");
    scanf("%d", &days[room]);

    totalBill[room] =
        calculateBill(roomType[room], acType[room], days[room], food[room]);

    booked[room] = 1;
    totalRevenue += totalBill[room];

    printf("\nRoom Booked Successfully! Room No: %d\n", room + 1);

    printBill(room);
}

//Bill
void printBill(int room)
{
    printf("\n=====================================\n");
    printf("             HOTEL BILL\n");
    printf("=====================================\n");

    printf("Customer   : %s\n", customer[room]);
    printf("Room No    : %d\n", room + 1);
    printf("Room Type  : %s\n", roomType[room]);
    printf("AC Type    : %s\n", acType[room]);
    printf("Food       : %s\n", food[room]);
    printf("Check-In   : %s\n", checkIn[room]);
    printf("Check-Out  : %s\n", checkOut[room]);
    printf("Nights     : %d\n", days[room]);
    printf("Total Bill : Rs %.2f\n", totalBill[room]);

    printf("=====================================\n");
}
// View Bookings
void viewBookings()
{
    int found = 0;

    printf("\n========== ALL BOOKINGS ==========\n");

    for(int i = 0; i < MAX; i++)
    {
        if(booked[i])
        {
            found = 1;

            printf("\nRoom %d", i + 1);
            printf("\nName   : %s", customer[i]);
            printf("\nType   : %s", roomType[i]);
            printf("\nAC     : %s", acType[i]);
            printf("\nFood   : %s", food[i]);
            printf("\nNights : %d", days[i]);
            printf("\nBill   : %.2f", totalBill[i]);
            printf("\n---------------------------\n");
        }
    }

    if(!found)
        printf("\nNo Bookings Found.\n");
}

//Search customer
void searchCustomer()
{
    char name[50];
    int found = 0;

    printf("\nEnter Customer Name: ");
    scanf(" %[^\n]", name);

    for(int i = 0; i < MAX; i++)
    {
        if(booked[i] && strcmp(customer[i], name) == 0)
        {
            found = 1;

            printf("\nBooking Found!");
            printf("\nRoom No : %d", i + 1);
            printf("\nBill    : %.2f\n", totalBill[i]);
            break;
        }
    }

    if(!found)
        printf("\nNot Found!\n");
}

//Cancel Booking
void cancelBooking()
{
    int room;

    printf("\nEnter Room Number: ");
    scanf("%d", &room);

    room--;

    if(room < 0 || room >= MAX || booked[room] == 0)
    {
        printf("\nInvalid Room!\n");
        return;
    }

    totalRevenue -= totalBill[room];

    booked[room] = 0;

    printf("\nBooking Cancelled!\n");
}

//Room Service
void roomService()
{
    int room, choice;

    printf("\nRoom No: ");
    scanf("%d", &room);

    room--;

    if(room < 0 || room >= MAX || booked[room] == 0)
    {
        printf("\nInvalid Room!\n");
        return;
    }

    printf("\n1 Tea (50)\n2 Breakfast (200)\n3 Lunch (400)\n4 Dinner (500)\n5 Laundry (300)\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            strcpy(service[room], "Tea");
            serviceCharge[room] = 50;
            break;

        case 2:
            strcpy(service[room], "Breakfast");
            serviceCharge[room] = 200;
            break;

        case 3:
            strcpy(service[room], "Lunch");
            serviceCharge[room] = 400;
            break;

        case 4:
            strcpy(service[room], "Dinner");
            serviceCharge[room] = 500;
            break;

        case 5:
            strcpy(service[room], "Laundry");
            serviceCharge[room] = 300;
            break;

        default:
            printf("\nInvalid!\n");
            return;
    }

    totalBill[room] += serviceCharge[room];

    printf("\nService Added! New Bill: %.2f\n", totalBill[room]);
}

//Revenue Report
void revenueReport()
{
    int count = 0;

    printf("\n========== REVENUE REPORT ==========\n");

    for(int i = 0; i < MAX; i++)
        if(booked[i]) count++;

    printf("Total Bookings : %d\n", count);
    printf("Total Revenue  : Rs %.2f\n", totalRevenue);

    if(count > 0)
        printf("Avg Revenue    : Rs %.2f\n", totalRevenue / count);
}

// Customer Rating
void customerRating()
{
    int room;

    printf("\nRoom No: ");
    scanf("%d", &room);

    room--;

    if(room < 0 || room >= MAX || booked[room] == 0)
    {
        printf("\nInvalid!\n");
        return;
    }

    printf("Rating (1-5): ");
    scanf("%d", &rating[room]);

    printf("Thank You for Feedback!\n");
}