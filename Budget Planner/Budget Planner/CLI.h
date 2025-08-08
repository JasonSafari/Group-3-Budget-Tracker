#pragma once

#include "Transactions.h"  // Use TRANSACTION struct now

void showMenu();
int getMenuChoice();
void showAllEntries(TRANSACTION entries[], int count);
void editEntry(TRANSACTION entries[], int count);
void deleteEntry(TRANSACTION entries[], int* count);
