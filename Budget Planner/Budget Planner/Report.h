#pragma once


typedef struct transcation{
    char date[11];          // Format: YYYY-MM-DD
    char type[10];          // Income or Expense
    char category[20];
    char description[50];
    double amount;
} TRANSACTION;



void LoadTransactions(char* filename);


void ShowAllTransactions(TRANSACTION* transactions, int transactionCount);


void SummarizeByCategory(TRANSACTION* transactions, int transactionCount);


void SummarizeIncomeExpense(TRANSACTION* transactions, int transactionCount);


void DetectOverBudget(TRANSACTION* transactions, int transactionCount);


void GenerateTrendReport(TRANSACTION* transactions, int transactionCount);