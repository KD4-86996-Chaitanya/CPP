#include <stdio.h>
struct Date {
    int day;
    int month;
    int year;
};

void initDate(struct Date* ptrDate);
void printDateOnConsole(const struct Date* ptrDate);
void acceptDateFromConsole(struct Date* ptrDate);

int main() {
    struct Date date;
    int choice;

    do {
        printf("\nDate Menu:\n");
        printf("1. Initialize Date\n");
        printf("2. Accept Date from Console\n");
        printf("3. Print Date on Console\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initDate(&date);
                break;
            case 2:
                acceptDateFromConsole(&date);
                break;
            case 3:
                printDateOnConsole(&date);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
void initDate(struct Date* ptrDate) {
    ptrDate->day = 1;
    ptrDate->month = 1;
    ptrDate->year = 1900;
    printf("Date initialized to 01/01/1900.\n");
}
void acceptDateFromConsole(struct Date* ptrDate) {
    printf("Enter day: ");
    scanf("%d", &ptrDate->day);
    printf("Enter month: ");
    scanf("%d", &ptrDate->month);
    printf("Enter year: ");
    scanf("%d", &ptrDate->year);
}

void printDateOnConsole(const struct Date* ptrDate) {
    printf("Date: %02d/%02d/%04d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}