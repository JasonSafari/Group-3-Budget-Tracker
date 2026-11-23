#pragma once

#include "Transactions.h"  // Use TRANSACTION struct now

void showMenu();
int getMenuChoice();
void showAllEntries(TRANSACTION entries[], int count);
// capacity = real size of the entries array, so indexes can be bounds-checked.
void editEntry(TRANSACTION entries[], int count, int capacity);
void deleteEntry(TRANSACTION entries[], int* count, int capacity);
