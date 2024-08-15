#include <gbdk/platform.h>
#include <gbdk/incbin.h>
#include <stdint.h>
#include <stdbool.h>
#include "dict_common.h"

#pragma bank 255

#define FIRST_LETTER 't'
#define LAST_LETTER  'z'
#define WORD_LEN 5u
#define WORD_INC_SIZE (WORD_LEN - 1u)

INCBIN(dict_5_t, "src/data/dict/5_t_words.txt")
INCBIN(dict_5_u, "src/data/dict/5_u_words.txt")
INCBIN(dict_5_v, "src/data/dict/5_v_words.txt")
INCBIN(dict_5_w, "src/data/dict/5_w_words.txt")
INCBIN(dict_5_x, "src/data/dict/5_x_words.txt")
INCBIN(dict_5_y, "src/data/dict/5_y_words.txt")
INCBIN(dict_5_z, "src/data/dict/5_z_words.txt")

INCBIN_EXTERN(dict_5_t)
INCBIN_EXTERN(dict_5_u)
INCBIN_EXTERN(dict_5_v)
INCBIN_EXTERN(dict_5_w)
INCBIN_EXTERN(dict_5_x)
INCBIN_EXTERN(dict_5_y)
INCBIN_EXTERN(dict_5_z)

const static dict_entry_t dictionary[A_Z_COUNT] = {
    {.p_wordlist = (wordlist_t)&dict_5_t, .len = (uint16_t)INCBIN_SIZE(dict_5_t) },
    {.p_wordlist = (wordlist_t)&dict_5_u, .len = (uint16_t)INCBIN_SIZE(dict_5_u) },
    {.p_wordlist = (wordlist_t)&dict_5_v, .len = (uint16_t)INCBIN_SIZE(dict_5_v) },
    {.p_wordlist = (wordlist_t)&dict_5_w, .len = (uint16_t)INCBIN_SIZE(dict_5_w) },
    {.p_wordlist = (wordlist_t)&dict_5_x, .len = (uint16_t)INCBIN_SIZE(dict_5_x) },
    {.p_wordlist = (wordlist_t)&dict_5_y, .len = (uint16_t)INCBIN_SIZE(dict_5_y) },
    {.p_wordlist = (wordlist_t)&dict_5_z, .len = (uint16_t)INCBIN_SIZE(dict_5_z) }
};


bool dict_check_word_5_tz(const char * word) BANKED {

    static wordlist_t p_words;
    static uint16_t dict_word_count;

    // Bounds check input based on first letter
    const char first_letter  = word[0];
    if ((first_letter < FIRST_LETTER) || (first_letter > LAST_LETTER)) return false;

    // Load a letter dictionary based on the first letter
    // of the word (so no need to test first letter)
    // (make "a" == 0, or equivalent for to index into the letter arrays)
    const dict_entry_t * p_dict = &dictionary[ first_letter - FIRST_LETTER ];
    p_words = p_dict->p_wordlist;
    dict_word_count = p_dict->len / 2;

    // Search the wordlist for matches
    const char second_letter = word[1];
    const char third_letter  = word[2];
    const char fourth_letter = word[3];
    const char fifth_letter  = word[4];

    while (dict_word_count--) {
        // Return true if a match was found, otherwise advance pointer to next word
        if ((second_letter == *p_words) &&
            (third_letter  == *(p_words + 1)) &&
            (fourth_letter == *(p_words + 2)) &&
            (fifth_letter  == *(p_words + 3)) ) return true;
        else p_words += WORD_INC_SIZE;

        // Don't scan the rest of the list if we've moved beyond the second letter in the word list
        if (*p_words > second_letter) return false;
    }
    return false;
}