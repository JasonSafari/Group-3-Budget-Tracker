#pragma once
#include "Transactions.h"


void SaveTransactionsToFile(const char* filename, TRANSACTION* transactions, int transactionCount);


void LoadTransactionsFromFile(const char* filename, TRANSACTION* transactions, int* transactionCount);

