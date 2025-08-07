#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Report.h"
#include "Transactions.h"
#include "Storage.h"

#define MAX_TRANSACTIONS 1000
#define MAX_CATEGORIES 50

void LoadTransactions(TRANSACTION* transactions, char* filename, int* transactionCount) {

    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char line[200];
    while (fgets(line, sizeof(line), file)) {
        TRANSACTION t;
        if (sscanf(line, "%10[^,],%9[^,],%19[^,],%49[^,],%lf",
            t.date, t.type, t.category, t.description, &t.amount) == 5) {
            transactions[(*transactionCount)++] = t;
        }
    }
    fclose(file);
}

void ShowAllTransactions(TRANSACTION* transactions, int transactionCount) {
    printf("Date       | Type     | Category         | Description              | Amount\n");
    printf("--------------------------------------------------------------------------\n");
    for (int i = 0; i < transactionCount; i++) {
        printf("%-10s | %-8s | %-16s | %-22s | $%.2f\n",
            transactions[i].date,
            transactions[i].type,
            transactions[i].category,
            transactions[i].description,
            transactions[i].amount);
    }
}

void SummarizeByCategory(TRANSACTION* transactions, int transactionCount) {
    char categories[MAX_CATEGORIES][20];
    double totals[MAX_CATEGORIES] = { 0 };
    int categoryCount = 0;

    for (int i = 0; i < transactionCount; i++) {
        if (strcmp(transactions[i].type, "Expense") == 0) {
            int found = 0;
            for (int j = 0; j < categoryCount; j++) {
                if (strcmp(categories[j], transactions[i].category) == 0) {
                    totals[j] += transactions[i].amount;
                    found = 1;
                    break;
                }
            }
            if (!found && categoryCount < MAX_CATEGORIES) {
                strcpy(categories[categoryCount], transactions[i].category);
                totals[categoryCount] = transactions[i].amount;
                categoryCount++;
            }
        }
    }

    printf("\nCategory         | Total Spent\n");
    printf("----------------|-------------\n");
    for (int i = 0; i < categoryCount; i++) {
        printf("%-16s | $%.2f\n", categories[i], totals[i]);
    }
}

void SummarizeIncomeExpense(TRANSACTION* transactions, int transactionCount) {
    double income = 0.0, expense = 0.0;
    for (int i = 0; i < transactionCount; i++) {
        if (strcmp(transactions[i].type, "Income") == 0) {
            income += transactions[i].amount;
        }
        else if (strcmp(transactions[i].type, "Expense") == 0) {
            expense += transactions[i].amount;
        }
    }
    printf("\nTotal Income:   $%.2f\n", income);
    printf("Total Expenses: $%.2f\n", expense);
    printf("Net Balance:    $%.2f\n", income - expense);
}

void DetectOverBudget(TRANSACTION* transactions, int transactionCount) {
    const char* budgetCategories[] = { "Food", "Transport", "Entertainment" };
    double budgetLimits[] = { 100.0, 50.0, 30.0 };
    double spent[MAX_CATEGORIES] = { 0 };
    int budgetCount = sizeof(budgetLimits) / sizeof(budgetLimits[0]);

    for (int i = 0; i < transactionCount; i++) {
        if (strcmp(transactions[i].type, "Expense") == 0) {
            for (int j = 0; j < budgetCount; j++) {
                if (strcmp(transactions[i].category, budgetCategories[j]) == 0) {
                    spent[j] += transactions[i].amount;
                }
            }
        }
    }

    printf("\nBudget Check:\n");
    for (int i = 0; i < budgetCount; i++) {
        if (spent[i] > budgetLimits[i]) {
            printf("⚠️  Over budget in %s by $%.2f\n",
                budgetCategories[i], spent[i] - budgetLimits[i]);
        }
        else {
            printf("✔️  Within budget for %s.\n", budgetCategories[i]);
        }
    }
}

void GenerateTrendReport(TRANSACTION* transactions, int transactionCount) {
    printf("\nDate-wise Spending:\n");
    printf("Date       | Total Spent\n");
    printf("--------------------------\n");

    for (int i = 0; i < transactionCount; i++) {
        if (strcmp(transactions[i].type, "Expense") == 0) {
            double total = transactions[i].amount;
            for (int j = i + 1; j < transactionCount; j++) {
                if (strcmp(transactions[i].date, transactions[j].date) == 0 &&
                    strcmp(transactions[j].type, "Expense") == 0) {
                    total += transactions[j].amount;
                    transactions[j].amount = 0; // Mark as counted
                }
            }
            if (transactions[i].amount > 0)
                printf("%-10s | $%.2f\n", transactions[i].date, total);
        }
    }
}
