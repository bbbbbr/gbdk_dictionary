#include <gbdk/platform.h>
#include <gbdk/incbin.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "../data/dict_common.h"
#include "../data/dict_lookup.h"


// This source file and it's functions should NOT BE BANKED
// since it will be switching various banked data in and out to test it

#define STR_SZ 10
uint16_t pass = 0;
uint16_t fail = 0;

typedef struct far_ptr_t {
    const void * ptr;
    uint8_t bank;
} far_ptr_t;

INCBIN_EXTERN(raw_wordlist_chunk_0)
INCBIN_EXTERN(raw_wordlist_chunk_1)
INCBIN_EXTERN(raw_wordlist_chunk_2)
INCBIN_EXTERN(raw_wordlist_chunk_3)
INCBIN_EXTERN(raw_wordlist_chunk_4)
INCBIN_EXTERN(raw_wordlist_chunk_5)
INCBIN_EXTERN(raw_wordlist_chunk_6)
INCBIN_EXTERN(raw_wordlist_chunk_7)
INCBIN_EXTERN(raw_wordlist_chunk_8)
INCBIN_EXTERN(raw_wordlist_chunk_9)
INCBIN_EXTERN(raw_wordlist_chunk_10)
INCBIN_EXTERN(raw_wordlist_chunk_11)

const static far_ptr_t wordlist_chunks[] = {
    {.ptr = (const void *)&raw_wordlist_chunk_0,  .bank = (uint8_t)BANK(raw_wordlist_chunk_0)  },
    {.ptr = (const void *)&raw_wordlist_chunk_1,  .bank = (uint8_t)BANK(raw_wordlist_chunk_1)  },
    {.ptr = (const void *)&raw_wordlist_chunk_2,  .bank = (uint8_t)BANK(raw_wordlist_chunk_2)  },
    {.ptr = (const void *)&raw_wordlist_chunk_3,  .bank = (uint8_t)BANK(raw_wordlist_chunk_3)  },
    {.ptr = (const void *)&raw_wordlist_chunk_4,  .bank = (uint8_t)BANK(raw_wordlist_chunk_4)  },
    {.ptr = (const void *)&raw_wordlist_chunk_5,  .bank = (uint8_t)BANK(raw_wordlist_chunk_5)  },
    {.ptr = (const void *)&raw_wordlist_chunk_6,  .bank = (uint8_t)BANK(raw_wordlist_chunk_6)  },
    {.ptr = (const void *)&raw_wordlist_chunk_7,  .bank = (uint8_t)BANK(raw_wordlist_chunk_7)  },
    {.ptr = (const void *)&raw_wordlist_chunk_8,  .bank = (uint8_t)BANK(raw_wordlist_chunk_8)  },
    {.ptr = (const void *)&raw_wordlist_chunk_9,  .bank = (uint8_t)BANK(raw_wordlist_chunk_9)  },
    {.ptr = (const void *)&raw_wordlist_chunk_10, .bank = (uint8_t)BANK(raw_wordlist_chunk_10) },
    {.ptr = (const void *)&raw_wordlist_chunk_11, .bank = (uint8_t)BANK(raw_wordlist_chunk_11) },
};

const uint8_t num_chunks = ARRAY_LEN(wordlist_chunks);

uint16_t word_count;
char * temp_str[STR_SZ];

bool test_entire_wordlist(void) {

    uint8_t saved_bank = CURRENT_BANK;


    for (uint8_t c; c < num_chunks; c++) {

        // Load the current wordlist chunk and switch it's bank in
        const char * raw_wordlist = (const char * )wordlist_chunks[c].ptr;
        SWITCH_ROM(wordlist_chunks[c].bank);

        // Wordlist is encoded as packed null terminated word strings
        // Read number of words in chunk
        word_count = atoi(raw_wordlist);
        // Next entry is located by adding (length of string + terminator char)
        raw_wordlist += strlen(raw_wordlist) + 1;

        printf("%hu(%u):", (uint8_t)c, word_count);

        while (word_count--) {
            // Need to make a RAM copy of the BANKED ROM string since
            // it will get switched out during the word check
            strncpy(temp_str, raw_wordlist, STR_SZ - 1);

            bool word_found = dict_check_word(temp_str);
            if (word_found) pass++;
            else {
                fail++;
                printf("%s\n", temp_str);
            }

            // Print a progress indicator every 256 words
            if ((uint8_t)word_count == 0x00) printf(".");
            // Next entry is located by adding (length of string + terminator char)
            raw_wordlist += strlen(raw_wordlist) + 1;
        }
        printf("\n");
    }

    printf("PASS: %u\n", (uint16_t)pass);
    printf("FAIL: %u\n", (uint16_t)fail);
    printf("TOTAL: %u\n", (uint16_t)(pass + fail));

    SWITCH_ROM(saved_bank);
    return true;
}