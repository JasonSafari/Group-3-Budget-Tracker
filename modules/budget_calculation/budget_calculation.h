// budget_calculation.h

#ifndef BUDGET_CALCULATION_H
#define BUDGET_CALCULATION_H

#include <stdbool.h>

// Function Prototypes
float calculate_total(float values[], int count);
float get_remaining_budget(float total_income, float total_expenses);
bool is_over_budget(float total_expenses, float budget_limit);
void add_entry(float values[], int *count, float new_value);
void remove_entry(float values[], int *count, int index);

#endif
