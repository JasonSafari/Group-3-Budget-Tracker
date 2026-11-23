#include <assert.h>
#include <stdbool.h>   /* budget_calculation.h uses bool but does not include this */
#include <stdio.h>
#include "../Budget Planner/budget_calculation.h"

static void test_calculate_total(void) {
    float v[] = { 1.5f, 2.5f, 4.0f };
    assert(calculate_total(v, 3) == 8.0f);
    assert(calculate_total(v, 0) == 0.0f);
}

static void test_remaining_budget(void) {
    assert(get_remaining_budget(100.0f, 40.0f) == 60.0f);
    assert(get_remaining_budget(10.0f, 30.0f) == -20.0f);
}

static void test_over_budget(void) {
    assert(is_over_budget(50.0f, 40.0f));
    assert(!is_over_budget(40.0f, 40.0f));
    assert(!is_over_budget(10.0f, 40.0f));
}

static void test_add_remove_entry(void) {
    float v[4] = { 0 };
    int count = 0;
    add_entry(v, &count, 1.0f);
    add_entry(v, &count, 2.0f);
    add_entry(v, &count, 3.0f);
    assert(count == 3 && v[2] == 3.0f);

    remove_entry(v, &count, 1);              /* removes 2.0 */
    assert(count == 2 && v[0] == 1.0f && v[1] == 3.0f);

    remove_entry(v, &count, 5);              /* out of range: no change */
    remove_entry(v, &count, -1);
    assert(count == 2);
}

int main(void) {
    test_calculate_total();
    test_remaining_budget();
    test_over_budget();
    test_add_remove_entry();
    puts("All tests passed.");
    return 0;
}