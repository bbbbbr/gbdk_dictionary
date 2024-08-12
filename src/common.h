#ifndef _COMMON_H
#define _COMMON_H

#include <stdint.h>
#include <stdbool.h>

#define ARRAY_LEN(A)  sizeof(A) / sizeof(A[0])

// Alas, the preprocessor cannot merge tokens ending with a slash char: /
// and the assembler doesn't treat "quote""merged""strings" as a single string,
// so this constant can't be combined with a filename for the incbin() macro
//
// #define DICTPATH "src/dict/"

#define A_Z_COUNT  26

typedef char * wordlist_t;

typedef struct dict_entry_t {
    const wordlist_t  p_wordlist;
    const uint16_t    len;
} dict_entry_t;


#endif // _COMMON_H


