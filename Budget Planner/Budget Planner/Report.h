#pragma once


typedef struct transcation{
    char date[11];          // Format: YYYY-MM-DD
    char type[10];          // Income or Expense
    char category[20];
    char description[50];
    double amount;
} TRANSACTION;



void LoadTransactions(char* filename);


void ShowAllTransactions();


void SummarizeByCategory();


void SummarizeIncomeExpense();


void DetectOverBudget();


void GenerateTrendReport();