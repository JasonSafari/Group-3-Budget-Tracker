#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>  // for atof
#include "Input.h"

// Helper to trim newline from fgets input
void trimNewline(char* str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Helper to convert string to lowercase
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Validate type input (Income or Expense)
int isValidType(const char* type) {
    return strcmp(type, "income") == 0 || strcmp(type, "expense") == 0;
}

// Validate amount input (checks for numeric string)
int isValidAmount(const char* str) {
    int i = 0;
    int decimalFound = 0;
    // Optional leading + or -
    if (str[0] == '+' || str[0] == '-') i++;

    int digitsFound = 0;
    for (; str[i] != '\0' && str[i] != '\n'; i++) {
        if (isdigit((unsigned char)str[i])) {
            digitsFound = 1;
        }
        else if (str[i] == '.') {
            if (decimalFound) return 0;  // More than one decimal point not allowed
            decimalFound = 1;
        }
        else {
            return 0; // invalid char found
        }
    }
    return digitsFound; // must have at least one digit
}

TRANSACTION getUserInput() {
    TRANSACTION entry;
    char input[128];

    printf("\nEnter transaction details:\n");

    // Get type with validation
    do {
        printf("Type (Income/Expense): ");
        fgets(input, sizeof(input), stdin);
        trimNewline(input);
        toLowerCase(input);
        if (!isValidType(input)) {
            printf("Invalid type. Please enter 'Income' or 'Expense'.\n");
        }
    } while (!isValidType(input));
    strcpy(entry.type, input);

    // Get date
    printf("Date (YYYY-MM-DD): ");
    fgets(entry.date, sizeof(entry.date), stdin);
    trimNewline(entry.date);

    // Get category
    printf("Category: ");
    fgets(entry.category, sizeof(entry.category), stdin);
    trimNewline(entry.category);

    // Get description
    printf("Description: ");
    fgets(entry.description, sizeof(entry.description), stdin);
    trimNewline(entry.description);

    // Get amount with validation
    do {
        printf("Amount: ");
        fgets(input, sizeof(input), stdin);
        trimNewline(input);
        if (!isValidAmount(input)) {
            printf("Invalid amount. Please enter a valid numeric value.\n");
            continue;
        }
        entry.amount = atof(input);
        break;
    } while (1);

    return entry;
}

void printEntrySummary(TRANSACTION entry) {
    printf("Date       : %s\n", entry.date);
    printf("Type       : %s\n", entry.type);
    printf("Category   : %s\n", entry.category);
    printf("Description: %s\n", entry.description);
    printf("Amount     : $%.2f\n", entry.amount);
}
