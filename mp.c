// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct Ticket {
//     int pnr;
//     char name[30];
//     int age;
//     int train_no;
//     int seat_no;
//     struct Ticket *next;
// } Ticket;

// Ticket *start = NULL;
// int pnrCounter = 1000;   // PNR starts from 1000

// // -------------------------------------
// // Function to create a new node
// // -------------------------------------
// Ticket* createTicket(char name[], int age, int train_no, int seat_no) {
//     Ticket *newT = (Ticket*) malloc(sizeof(Ticket));
//     newT->pnr = pnrCounter++;
//     strcpy(newT->name, name);
//     newT->age = age;
//     newT->train_no = train_no;
//     newT->seat_no = seat_no;
//     newT->next = NULL;
//     return newT;
// }

// // -------------------------------------
// // Insert booking (Book Ticket)
// // -------------------------------------
// void bookTicket() {
//     char name[30];
//     int age, train_no, seat_no;

//     printf("Enter Passenger Name: ");
//     scanf("%s", name);
//     printf("Enter Age: ");
//     scanf("%d", &age);
//     printf("Enter Train Number: ");
//     scanf("%d", &train_no);
//     printf("Enter Seat Number: ");
//     scanf("%d", &seat_no);

//     Ticket *newT = createTicket(name, age, train_no, seat_no);

//     if (start == NULL)
//         start = newT;
//     else {
//         Ticket *temp = start;
//         while (temp->next != NULL)
//             temp = temp->next;
//         temp->next = newT;
//     }

//     printf("\nTicket Booked Successfully! PNR = %d\n", newT->pnr);
// }

// // -------------------------------------
// // Display all bookings
// // -------------------------------------
// void displayTickets() {
//     if (start == NULL) {
//         printf("No Bookings Available!\n");
//         return;
//     }

//     Ticket *temp = start;
//     printf("\n--- All Bookings ---\n");
//     while (temp != NULL) {
//         printf("\nPNR: %d\nName: %s\nAge: %d\nTrain No: %d\nSeat No: %d\n",
//                temp->pnr, temp->name, temp->age, temp->train_no, temp->seat_no);
//         temp = temp->next;
//     }
// }

// // -------------------------------------
// // Cancel Ticket (Delete Node)
// // -------------------------------------
// void cancelTicket() {
//     int pnr;
//     printf("Enter PNR to Cancel Ticket: ");
//     scanf("%d", &pnr);

//     if (start == NULL) {
//         printf("No Bookings Available!\n");
//         return;
//     }

//     Ticket *temp = start, *prev = NULL;

//     // If first ticket matches
//     if (temp != NULL && temp->pnr == pnr) {
//         start = temp->next;
//         free(temp);
//         printf("Ticket Cancelled Successfully.\n");
//         return;
//     }

//     // Search in linked list
//     while (temp != NULL && temp->pnr != pnr) {
//         prev = temp;
//         temp = temp->next;
//     }

//     if (temp == NULL) {
//         printf("PNR Not Found!\n");
//         return;
//     }

//     prev->next = temp->next;
//     free(temp);
//     printf("Ticket Cancelled Successfully.\n");
// }

// // -------------------------------------
// // Modify Ticket
// // -------------------------------------
// void modifyTicket() {
//     int pnr;
//     printf("Enter PNR to Modify: ");
//     scanf("%d", &pnr);

//     Ticket *temp = start;

//     while (temp != NULL) {
//         if (temp->pnr == pnr) {
//             printf("Enter New Name: ");
//             scanf("%s", temp->name);
//             printf("Enter New Age: ");
//             scanf("%d", &temp->age);
//             printf("Modification Successful!\n");
//             return;
//         }
//         temp = temp->next;
//     }

//     printf("PNR Not Found!\n");
// }

// // -------------------------------------
// // Save tickets to file
// // -------------------------------------
// void saveToFile() {
//     FILE *fp = fopen("tickets.txt", "w");
//     if (fp == NULL) {
//         printf("Error Saving File!\n");
//         return;
//     }

//     Ticket *temp = start;
//     while (temp != NULL) {
//         fprintf(fp, "%d %s %d %d %d\n",
//                 temp->pnr, temp->name, temp->age,
//                 temp->train_no, temp->seat_no);
//         temp = temp->next;
//     }

//     fclose(fp);
//     printf("Data Saved to File Successfully.\n");
// }

// // -------------------------------------
// // Load tickets from file
// // -------------------------------------
// void loadFromFile() {
//     FILE *fp = fopen("tickets.txt", "r");
//     if (fp == NULL)
//         return; // No file yet

//     int pnr, age, train_no, seat_no;
//     char name[30];

//     while (fscanf(fp, "%d %s %d %d %d",
//                   &pnr, name, &age, &train_no, &seat_no) != EOF) {

//         Ticket *newT = (Ticket*) malloc(sizeof(Ticket));
//         newT->pnr = pnr;
//         strcpy(newT->name, name);
//         newT->age = age;
//         newT->train_no = train_no;
//         newT->seat_no = seat_no;
//         newT->next = NULL;

//         if (start == NULL)
//             start = newT;
//         else {
//             Ticket *temp = start;
//             while (temp->next != NULL)
//                 temp = temp->next;
//             temp->next = newT;
//         }

//         // Update PNR counter
//         if (pnr >= pnrCounter)
//             pnrCounter = pnr + 1;
//     }

//     fclose(fp);
// }

// // -------------------------------------
// // Main
// // -------------------------------------
// int main() {
//     loadFromFile();

//     int choice;
//     while (1) {
//         printf("\n--- Railway Ticket Reservation System ---\n");
//         printf("1. Book Ticket\n");
//         printf("2. Cancel Ticket\n");
//         printf("3. Modify Ticket\n");
//         printf("4. Display All Bookings\n");
//         printf("5. Save to File\n");
//         printf("6. Exit\n");
//         printf("Enter Your Choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1: bookTicket(); break;
//             case 2: cancelTicket(); break;
//             case 3: modifyTicket(); break;
//             case 4: displayTickets(); break;
//             case 5: saveToFile(); break;
//             case 6: saveToFile(); exit(0);
//             default: printf("Invalid Choice!\n");
//         }
//     }

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ticket {
    int pnr;
    char name[50];
    int age;
    int trainNo;
    int seatNo;
    struct Ticket *next;
};

struct Ticket *head = NULL;
int ticketCount = 0;

// Function to save linked list to file
void saveToFile() {
    FILE *fp = fopen("tickets.txt", "w");
    if (!fp) {
        printf("Error opening file!\n");
        return;
    }
    struct Ticket *temp = head;
    while (temp != NULL) {
        fprintf(fp, "%d %s %d %d %d\n", temp->pnr, temp->name, temp->age, temp->trainNo, temp->seatNo);
        temp = temp->next;
    }
    fclose(fp);
}

// Function to load linked list from file
void loadFromFile() {
    FILE *fp = fopen("tickets.txt", "r");
    if (!fp) return;

    struct Ticket *temp;
    while (!feof(fp)) {
        temp = (struct Ticket*)malloc(sizeof(struct Ticket));
        if (fscanf(fp, "%d %s %d %d %d\n", &temp->pnr, temp->name, &temp->age, &temp->trainNo, &temp->seatNo) != 5) {
            free(temp);
            break;
        }
        temp->next = head;
        head = temp;
        if (temp->pnr > ticketCount) ticketCount = temp->pnr;
    }
    fclose(fp);
}

// Book a ticket
void bookTicket() {
    struct Ticket *newTicket = (struct Ticket*)malloc(sizeof(struct Ticket));
    newTicket->pnr = ++ticketCount;

    printf("Enter passenger name: ");
    scanf("%s", newTicket->name);

    printf("Enter age: ");
    scanf("%d", &newTicket->age);

    printf("Enter train number: ");
    scanf("%d", &newTicket->trainNo);

    printf("Enter seat number: ");
    scanf("%d", &newTicket->seatNo);

    newTicket->next = head;
    head = newTicket;

    saveToFile();
    printf("Ticket booked successfully! PNR: %d\n", newTicket->pnr);
}

// Cancel a ticket
void cancelTicket() {
    if (!head) {
        printf("No bookings available.\n");
        return;
    }
    int pnr;
    printf("Enter PNR to cancel: ");
    scanf("%d", &pnr);

    struct Ticket *temp = head, *prev = NULL;
    while (temp != NULL && temp->pnr != pnr) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        printf("Ticket not found.\n");
        return;
    }

    if (prev == NULL) head = temp->next;
    else prev->next = temp->next;

    free(temp);
    saveToFile();
    printf("Ticket cancelled successfully.\n");
}

// Modify a ticket
void modifyTicket() {
    if (!head) {
        printf("No bookings available.\n");
        return;
    }
    int pnr;
    printf("Enter PNR to modify: ");
    scanf("%d", &pnr);

    struct Ticket *temp = head;
    while (temp != NULL && temp->pnr != pnr)
        temp = temp->next;

    if (!temp) {
        printf("Ticket not found.\n");
        return;
    }

    printf("Enter new name: ");
    scanf("%s", temp->name);
    printf("Enter new age: ");
    scanf("%d", &temp->age);
    printf("Enter new train number: ");
    scanf("%d", &temp->trainNo);
    printf("Enter new seat number: ");
    scanf("%d", &temp->seatNo);

    saveToFile();
    printf("Ticket modified successfully.\n");
}

// Display all bookings
void displayTickets() {
    if (!head) {
        printf("No bookings available.\n");
        return;
    }
    struct Ticket *temp = head;
    printf("\nPNR\tName\tAge\tTrain\tSeat\n");
    printf("-----------------------------------------\n");
    while (temp != NULL) {
        printf("%d\t%s\t%d\t%d\t%d\n", temp->pnr, temp->name, temp->age, temp->trainNo, temp->seatNo);
        temp = temp->next;
    }
}

int main() {
    loadFromFile();
    int choice;
    do {
        printf("\n--- Railway Ticket Reservation ---\n");
        printf("1. Book Ticket\n2. Cancel Ticket\n3. Modify Ticket\n4. Display All Bookings\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: bookTicket(); break;
            case 2: cancelTicket(); break;
            case 3: modifyTicket(); break;
            case 4: displayTickets(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 5);

    return 0;
}
