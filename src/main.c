#include <gbdk/platform.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "data/dict_lookup.h"


void test_word(const char * str) {
    bool result = dict_check_word(str);

    printf("%s = %hu\n", (const char *)str, (uint8_t)result);
}


void run_test(void) {

    test_word("ace");
    test_word("coz");
    test_word("guy");
    test_word("syn");
    test_word("yuk");
    test_word("zag");
    test_word("zoo");
    test_word("zzz");
    test_word("qqq");

    test_word("ache");
    test_word("azon");
    test_word("syph");
    test_word("snog");
    test_word("zeps");
    test_word("zyme");
    test_word("zzzz");
    test_word("ssss");

    test_word("abide");
    test_word("azure");
    test_word("sysop");
    test_word("sabed");
    test_word("zymes");
    test_word("zzzzz");
    test_word("sssss");

    test_word("azygos");
    test_word("syzygy");
    test_word("sabbat");
    test_word("zymase");
    test_word("zaddik");
    test_word("zzzzzz");
    test_word("ssssss");
}


void main(void) {
    DISPLAY_ON;
    SHOW_BKG;

    run_test();

    while (1) {
        vsync();
    }
}