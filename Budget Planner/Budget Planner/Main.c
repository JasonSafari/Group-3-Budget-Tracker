#include <stdio.h>
#include "Report.h"
#include "Input.h"
#define _CRT_SECURE_NO_WARNINGS
#define MAX_TRANSACTIONS 1000

int main(void) {
        int choice;

        do {
            printf("\n===== Budget Tracker Menu =====\n");
            printf("1. Add New Entry\n");
            printf("2. Exit\n");
            printf("Enter your choice: ");
            scanf_s("%d", &choice);
            while (getchar() != '\n'); // clear input buffer

            switch (choice) {
            case 1: {
                BudgetEntry entry = getUserInput();
                printEntrySummary(entry);
                break;
            }
            case 2:
                printf("\nExiting Budget Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please enter 1 or 2.\n");
            }

        } while (choice != 2);

        return 0;
    }
