#include <stdbool.h>
#include "budget_calculation.h"

// Calculates the sum of all elements in the array
float calculate_total(float values[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += values[i];
    }
    return total;
}

// Returns the remaining budget
float get_remaining_budget(float total_income, float total_expenses) {
    return total_income - total_expenses;
}

// Checks if the user is over budget
bool is_over_budget(float total_expenses, float budget_limit) {
    return total_expenses > budget_limit;
}

// Adds a new value to the array
void add_entry(float values[], int* count, float new_value) {
    values[*count] = new_value;
    (*count)++;
}

// Removes an entry by index
void remove_entry(float values[], int* count, int index) {
    if (index < 0 || index >= *count) return;
    for (int i = index; i < (*count) - 1; i++) {
        values[i] = values[i + 1];
    }
    (*count)--;
}