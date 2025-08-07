#pragma once

#include "Input.h"

void showMenu();
int getMenuChoice();
void showAllEntries(BudgetEntry entries[], int count);
void editEntry(BudgetEntry entries[], int count);
void deleteEntry(BudgetEntry entries[], int* count);