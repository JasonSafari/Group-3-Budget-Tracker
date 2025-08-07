#pragma once

typedef struct {
    char type[20];
    char category[30];
    char description[100];
    double amount;
} BudgetEntry;

BudgetEntry getUserInput();
void printEntrySummary(BudgetEntry entry);

