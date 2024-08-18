#ifndef _DICT_COMMON_H
#define _DICT_COMMON_H

#include <stdint.h>
#include <stdbool.h>

#define ARRAY_LEN(A)  sizeof(A) / sizeof(A[0])

#define A_Z_COUNT  26

typedef char * wordlist_t;

typedef struct dict_entry_t {
    const wordlist_t  p_wordlist;
    const uint16_t    len;
} dict_entry_t;


#endif // _DICT_COMMON_H


