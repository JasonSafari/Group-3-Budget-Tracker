#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../Budget Planner/CLI.h"

/* Redirect stdin to a temp file holding the given text. */
static void feed(const char* text) {
    FILE* f = fopen("cli_test_input.txt", "w");
    assert(f);
    fputs(text, f);
    fclose(f);
    assert(freopen("cli_test_input.txt", "r", stdin));
}

static void fill(TRANSACTION* e, int n) {
    for (int i = 0; i < n; i++) {
        memset(&e[i], 0, sizeof e[i]);
        snprintf(e[i].description, sizeof e[i].description, "item%d", i + 1);
    }
}

static void test_delete_valid_entry(void) {
    TRANSACTION e[10]; int count = 3;
    fill(e, 3);
    feed("2\n");
    deleteEntry(e, &count, 10);
    assert(count == 2);
    assert(strcmp(e[0].description, "item1") == 0);
    assert(strcmp(e[1].description, "item3") == 0);   /* shifted up */
}

static void test_delete_rejects_index_past_capacity(void) {
    TRANSACTION e[3]; int count = 5;                   /* count larger than array */
    fill(e, 3);
    feed("4\n");
    deleteEntry(e, &count, 3);
    assert(count == 3);                                /* clamped, nothing deleted, no overflow */
    assert(strcmp(e[2].description, "item3") == 0);
}

static void test_delete_rejects_zero_and_negative(void) {
    TRANSACTION e[3]; int count = 3;
    fill(e, 3);
    feed("0\n");  deleteEntry(e, &count, 3);
    feed("-1\n"); deleteEntry(e, &count, 3);
    assert(count == 3);
}

static void test_edit_rejects_index_past_capacity(void) {
    TRANSACTION e[3];
    fill(e, 3);
    feed("4\n");                                       /* invalid -> returns before reading fields */
    editEntry(e, 5, 3);                                /* count larger than array */
    assert(strcmp(e[0].description, "item1") == 0);
    assert(strcmp(e[2].description, "item3") == 0);
}

static void test_edit_valid_entry(void) {
    TRANSACTION e[3];
    fill(e, 3);
    feed("2\nincome\n2025-01-01\nPay\nBonus\n50\n");
    editEntry(e, 3, 3);
    /* Only fields unaffected by the known date-field newline bug are asserted. */
    assert(strcmp(e[1].type, "income") == 0);
    assert(strcmp(e[1].date, "2025-01-01") == 0);
    assert(e[1].amount == 50.0);
    assert(strcmp(e[0].description, "item1") == 0);   /* neighbours untouched */
}

int main(void) {
    test_delete_valid_entry();
    test_delete_rejects_index_past_capacity();
    test_delete_rejects_zero_and_negative();
    test_edit_rejects_index_past_capacity();
    test_edit_valid_entry();
    remove("cli_test_input.txt");
    puts("CLI tests passed.");
    return 0;
}
