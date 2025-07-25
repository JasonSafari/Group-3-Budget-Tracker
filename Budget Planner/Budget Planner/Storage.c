#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Storage.h"

#define MAX_TRANSACTIONS 1000



// Function to save transactions to a CSV file
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

// Function to load transactions from a CSV file
void LoadTransactionsFromFile(const char* filename, TRANSACTION* transactions, int* transactionCount) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s for reading.\n", filename);
        return;
    }

    char line[200];
    *transactionCount = 0;

    while (fgets(line, sizeof(line), file)) {
        TRANSACTION t;
        if (sscanf(line, "%10[^,],%9[^,],%19[^,],%49[^,],%lf",
            t.date, t.type, t.category, t.description, &t.amount) == 5) {
            transactions[(*transactionCount)++] = t;
        }
    }

    fclose(file);
    printf("%d transactions loaded from %s.\n", *transactionCount, filename);
}
