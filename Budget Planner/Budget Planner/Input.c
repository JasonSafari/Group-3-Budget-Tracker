#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"

void cleanNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
}

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

int isValidType(const char* type) {
    return strcmp(type, "income") == 0 || strcmp(type, "expense") == 0;
}

BudgetEntry getUserInput() {
    BudgetEntry entry;

    printf("\n--- Add a New Budget Entry ---\n");

    // Validate type
    do {
        printf("Type (income/expense): ");
        fgets(entry.type, sizeof(entry.type), stdin);
        cleanNewline(entry.type);
        toLowerCase(entry.type);

        if (!isValidType(entry.type)) {
            printf("Invalid type. Please enter either 'income' or 'expense'.\n");
        }
    } while (!isValidType(entry.type));

    // Category
    printf("Category: ");
    fgets(entry.category, sizeof(entry.category), stdin);
    cleanNewline(entry.category);

    // Description
    printf("Description: ");
    fgets(entry.description, sizeof(entry.description), stdin);
    cleanNewline(entry.description);

    // Amount
    printf("Amount: ");
    scanf_s("%lf", &entry.amount);
    while (getchar() != '\n'); // Clear input buffer

    return entry;
}

void printEntrySummary(BudgetEntry entry) {
    printf("\n+------------------------ Entry Summary ------------------------+\n");
    printf("| %-10s | %-12s | %-30s |\n", "Type", "Category", "Description");
    printf("| %-10s | %-12s | %-30s |\n", entry.type, entry.category, entry.description);
    printf("+---------------------------------------------------------------+\n");
    printf("| %-25s : $%8.2f |\n", "Amount", entry.amount);
    printf("+---------------------------------------------------------------+\n");
}