#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "CLI.h"

void showMenu() {
    printf("\n===== Budget Tracker Menu =====\n");
    printf("1. Add New Entry\n");
    printf("2. View All Entries\n");
    printf("3. Edit an Entry\n");
    printf("4. Delete an Entry\n");
    printf("5. Exit\n");
}

int getMenuChoice() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);
    while (getchar() != '\n'); // clear buffer
    return choice;
}

void showAllEntries(BudgetEntry entries[], int count) {
    printf("\n================ All Budget Entries ================\n");
    if (count == 0) {
        printf("No entries found.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nEntry #%d:\n", i + 1);
        printEntrySummary(entries[i]);
    }
}

void editEntry(BudgetEntry entries[], int count) {
    int index;
    printf("Enter the entry number to edit (1-%d): ", count);
    scanf("%d", &index);
    while (getchar() != '\n');
    if (index < 1 || index > count) {
        printf("Invalid entry number.\n");
        return;
    }
    printf("\nEditing Entry #%d\n", index);
    entries[index - 1] = getUserInput();
    printf("Updated Entry:\n");
    printEntrySummary(entries[index - 1]);
}

void deleteEntry(BudgetEntry entries[], int* count) {
    int index;
    printf("Enter the entry number to delete (1-%d): ", *count);
    scanf("%d", &index);
    while (getchar() != '\n');
    if (index < 1 || index > *count) {
        printf("Invalid entry number.\n");
        return;
    }
    for (int i = index - 1; i < *count - 1; i++) {
        entries[i] = entries[i + 1];
    }
    (*count)--;
    printf("Entry #%d deleted successfully.\n", index);
}
