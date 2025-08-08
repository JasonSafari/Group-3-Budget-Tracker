#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "CLI.h"
#include "Input.h"  // For getUserInput()

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
    int result = scanf("%d", &choice);
    if (result != 1) {
        printf("Invalid input. Please enter a number.\n");
        while (getchar() != '\n'); // clear buffer
        return -1; // signal invalid input
    }
    while (getchar() != '\n'); // clear buffer
    return choice;
}

void showAllEntries(TRANSACTION entries[], int count) {
    printf("\n================ All Budget Entries ================\n");
    if (count == 0) {
        printf("No entries found.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        printf("\nEntry #%d:\n", i + 1);
        printf("Date       : %s\n", entries[i].date);
        printf("Type       : %s\n", entries[i].type);
        printf("Category   : %s\n", entries[i].category);
        printf("Description: %s\n", entries[i].description);
        printf("Amount     : $%.2f\n", entries[i].amount);
    }
}

void editEntry(TRANSACTION entries[], int count) {
    int index;
    printf("Enter the entry number to edit (1-%d): ", count);
    int result = scanf("%d", &index);
    if (result != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n'); // clear buffer
        return;
    }
    while (getchar() != '\n'); // clear buffer

    if (index < 1 || index > count) {
        printf("Invalid entry number.\n");
        return;
    }

    printf("\nEditing Entry #%d\n", index);
    entries[index - 1] = getUserInput();  // Assumes getUserInput returns TRANSACTION
    printf("Updated Entry:\n");
    printf("Date       : %s\n", entries[index - 1].date);
    printf("Type       : %s\n", entries[index - 1].type);
    printf("Category   : %s\n", entries[index - 1].category);
    printf("Description: %s\n", entries[index - 1].description);
    printf("Amount     : $%.2f\n", entries[index - 1].amount);
}

void deleteEntry(TRANSACTION entries[], int* count) {
    int index;
    printf("Enter the entry number to delete (1-%d): ", *count);
    int result = scanf("%d", &index);
    if (result != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        while (getchar() != '\n'); // clear buffer
        return;
    }
    while (getchar() != '\n'); // clear buffer

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
