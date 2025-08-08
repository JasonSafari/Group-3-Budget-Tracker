#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Input.h"
#include "CLI.h"
#include "fileio.h"   // New file I/O header
#include "Transactions.h"

#define MAX_ENTRIES 1000

int main(void) {
    TRANSACTION entries[MAX_ENTRIES];
    int count = 0;
    int choice;

    // Load existing transactions from file on startup
    LoadTransactionsFromFile("transactions.csv", entries, &count);

    do {
        showMenu();
        choice = getMenuChoice();

        switch (choice) {
        case 1:
            if (count < MAX_ENTRIES) {
                // You need to update getUserInput to return TRANSACTION, including date field!
                entries[count] = getUserInput();
                printEntrySummary(entries[count]);  // Also update this to handle TRANSACTION struct
                count++;
            }
            else {
                printf("Maximum entry limit reached.\n");
            }
            break;
        case 2:
            showAllEntries(entries, count);   // Make sure this expects TRANSACTION[]
            break;
        case 3:
            editEntry(entries, count);         // Same, update to TRANSACTION[]
            break;
        case 4:
            deleteEntry(entries, &count);      // Same, update to TRANSACTION[]
            break;
        case 5:
            // Save all transactions before exit
            SaveTransactionsToFile("transactions.csv", entries, count);
            printf("\nExiting Budget Tracker. Goodbye!\n");
            break;
        default:
            printf("Invalid option. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
