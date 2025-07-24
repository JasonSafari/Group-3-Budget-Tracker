#pragma once

typedef struct {
    char type[10];
    char category[30];
    char description[50];
    double amount;
} BudgetEntry;

BudgetEntry getUserInput();
void printEntrySummary(BudgetEntry entry);