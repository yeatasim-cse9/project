#include <stdio.h>
#include <string.h>

#define MAX_ATTENDEES 100

struct Attendee 
{
    char fullName[100];
    char email[100];
    char institute[100];
    char phoneNumber[12];
    char interests[100];
};

int main() 
{
    struct Attendee attendees[MAX_ATTENDEES];
    int numAttendees = 0;

    printf("Advanced Event Attendee Management System\n");
    printf("Enter the number of attendees: ");
    scanf("%d", &numAttendees);

    if (numAttendees <= 0 || numAttendees > MAX_ATTENDEES)
     {
        printf("Invalid number of attendees. Please enter a value between 1 and %d.\n", MAX_ATTENDEES);
       
     }

    for (int i = 0; i < numAttendees; i++)
     {
        printf("\nEnter attendee details for Attendee %d:\n", i + 1);
        printf("Full Name: ");
        scanf(" %[^\n]", attendees[i].fullName);
        printf("Email: ");
        scanf(" %[^\n]", attendees[i].email);
        printf("Institute: ");
        scanf(" %[^\n]", attendees[i].institute);
        printf("Phone Number (11 digits): ");
        scanf(" %[^\n]", attendees[i].phoneNumber);
        printf("Interests: ");
        scanf(" %[^\n]", attendees[i].interests);
     }

    int searchAgain = 1;
    while (searchAgain) 
    {
        char searchName[100];
        printf("\nSearch for an Attendee by Full Name: ");
        scanf(" %[^\n]", searchName);

        int found = 0;
        for (int i = 0; i < numAttendees; i++) 
        {
            if (strcmp(attendees[i].fullName, searchName) == 0) 
            {
                found = 1;
                printf("Attendee Found:\n");
                printf("Full Name: %s\n", attendees[i].fullName);
                printf("Email: %s\n", attendees[i].email);
                printf("Institute: %s\n", attendees[i].institute);
                printf("Phone Number: %s\n", attendees[i].phoneNumber);
                printf("Interests: %s\n", attendees[i].interests);
                break;
            }
        }

        if (!found) 
        {
            printf("Attendee not found.\n");
        }

        printf("\nDo you want to search again? (1 for yes, 0 for no): ");
        scanf("%d", &searchAgain);
    }

    return 0;
}