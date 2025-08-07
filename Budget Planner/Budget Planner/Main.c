#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Input.h"
#include "CLI.h"

#define MAX_ENTRIES 1000

int main(void) {
    BudgetEntry entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    do {
        showMenu();
        choice = getMenuChoice();

        switch (choice) {
        case 1:
            if (count < MAX_ENTRIES) {
                entries[count] = getUserInput();
                printEntrySummary(entries[count]);
                count++;
            }
            else {
                printf("Maximum entry limit reached.\n");
            }
            break;
        case 2:
            showAllEntries(entries, count);
            break;
        case 3:
            editEntry(entries, count);
            break;
        case 4:
            deleteEntry(entries, &count);
            break;
        case 5:
            printf("\nExiting Budget Tracker. Goodbye!\n");
            break;
        default:
            printf("Invalid option. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
