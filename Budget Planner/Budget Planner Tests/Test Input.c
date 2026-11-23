#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Budget Planner/Input.h"

static void test_valid_amounts(void) {
    assert(isValidAmount("12"));
    assert(isValidAmount("12.50"));
    assert(isValidAmount("0.5"));
    assert(isValidAmount(".5"));
    assert(isValidAmount("+7"));
    assert(isValidAmount("-7.25"));
    assert(isValidAmount("45\n"));            /* trailing newline is ignored */
}

static void test_invalid_amounts(void) {
    assert(!isValidAmount(""));
    assert(!isValidAmount("\n"));
    assert(!isValidAmount("+"));
    assert(!isValidAmount("-"));
    assert(!isValidAmount("."));
    assert(!isValidAmount("1.2.3"));
    assert(!isValidAmount("12a"));
    assert(!isValidAmount("abc"));
    assert(!isValidAmount("1,000"));
    assert(!isValidAmount(" 5"));
    assert(!isValidAmount(NULL));
}

static void test_length_limit(void) {
    char ok[65], too_long[66];
    memset(ok, '1', 64);       ok[64] = '\0';        /* exactly 64 digits */
    memset(too_long, '1', 65); too_long[65] = '\0';  /* 65 digits */
    assert(isValidAmount(ok));
    assert(!isValidAmount(too_long));
}

static void test_never_reads_past_terminator(void) {
    /* A tight buffer: reading past the NUL would be caught under AddressSanitizer. */
    char* tight = malloc(3);
    assert(tight);
    memcpy(tight, "-5", 3);
    assert(isValidAmount(tight));
    free(tight);
}

int main(void) {
    test_valid_amounts();
    test_invalid_amounts();
    test_length_limit();
    test_never_reads_past_terminator();
    puts("Input tests passed.");
    return 0;
}
