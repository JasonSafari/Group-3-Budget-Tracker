#pragma once
#include "Transactions.h"





void LoadTransactions(TRANSACTION* transactions, char* filename, int* transactionCount);


void ShowAllTransactions(TRANSACTION* transactions, int transactionCount);


void SummarizeByCategory(TRANSACTION* transactions, int transactionCount);


void SummarizeIncomeExpense(TRANSACTION* transactions, int transactionCount);


void DetectOverBudget(TRANSACTION* transactions, int transactionCount);


void GenerateTrendReport(TRANSACTION* transactions, int transactionCount);