#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"

//kenneth oluoch
#define MAX_LINE_LENGTH 256

// Save transactions to CSV file
void SaveTransactionsToFile(const char* filename, TRANSACTION* transactions, int transactionCount) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return;
    }

    for (int i = 0; i < transactionCount; i++) {
        fprintf(file, "%s,%s,%s,%s,%.2f\n",
            transactions[i].date,
            transactions[i].type,
            transactions[i].category,
            transactions[i].description,
            transactions[i].amount);
    }

    fclose(file);
    printf("Transactions saved successfully to %s.\n", filename);
}

// Load transactions from CSV file
void LoadTransactionsFromFile(const char* filename, TRANSACTION* transactions, int* transactionCount) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s for reading.\n", filename);
        *transactionCount = 0;
        return;
    }

    char line[MAX_LINE_LENGTH];
    *transactionCount = 0;

    while (fgets(line, sizeof(line), file)) {
        TRANSACTION t;

        // Parse CSV line into transaction fields
        if (sscanf(line, "%10[^,],%9[^,],%19[^,],%49[^,],%lf",
            t.date, t.type, t.category, t.description, &t.amount) == 5) {
            transactions[(*transactionCount)++] = t;
        }
    }

    fclose(file);
    printf("%d transactions loaded from %s.\n", *transactionCount, filename);
}
