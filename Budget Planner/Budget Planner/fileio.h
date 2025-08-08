#pragma once
//kenneth oluoch
#include "Transactions.h"

// Saves the array of transactions to a CSV file.
// Parameters:
// - filename: path to the file to write.
// - transactions: array of TRANSACTION structs.
// - transactionCount: number of transactions in the array.
void SaveTransactionsToFile(const char* filename, TRANSACTION* transactions, int transactionCount);

// Loads transactions from a CSV file into the array.
// Parameters:
// - filename: path to the file to read.
// - transactions: array to load transactions into.
// - transactionCount: pointer to an int to store number of transactions loaded.
void LoadTransactionsFromFile(const char* filename, TRANSACTION* transactions, int* transactionCount);
