#include <gbdk/platform.h>
#include <gbdk/incbin.h>
#include <stdint.h>
#include <stdbool.h>
#include "dict_common.h"

#pragma bank 255


#define FIRST_LETTER 'a'
#define LAST_LETTER  'j'
#define WORD_LEN 5u
#define WORD_INC_SIZE (WORD_LEN - 1u)

INCBIN(dict_5_a, "src/data/dict/5_a_words.txt")
INCBIN(dict_5_b, "src/data/dict/5_b_words.txt")
INCBIN(dict_5_c, "src/data/dict/5_c_words.txt")
INCBIN(dict_5_d, "src/data/dict/5_d_words.txt")
INCBIN(dict_5_e, "src/data/dict/5_e_words.txt")
INCBIN(dict_5_f, "src/data/dict/5_f_words.txt")
INCBIN(dict_5_g, "src/data/dict/5_g_words.txt")
INCBIN(dict_5_h, "src/data/dict/5_h_words.txt")
INCBIN(dict_5_i, "src/data/dict/5_i_words.txt")
INCBIN(dict_5_j, "src/data/dict/5_j_words.txt")

INCBIN_EXTERN(dict_5_a)
INCBIN_EXTERN(dict_5_b)
INCBIN_EXTERN(dict_5_c)
INCBIN_EXTERN(dict_5_d)
INCBIN_EXTERN(dict_5_e)
INCBIN_EXTERN(dict_5_f)
INCBIN_EXTERN(dict_5_g)
INCBIN_EXTERN(dict_5_h)
INCBIN_EXTERN(dict_5_i)
INCBIN_EXTERN(dict_5_j)

const static dict_entry_t dictionary[A_Z_COUNT] = {
    {.p_wordlist = (wordlist_t)&dict_5_a, .len = (uint16_t)INCBIN_SIZE(dict_5_a) },
    {.p_wordlist = (wordlist_t)&dict_5_b, .len = (uint16_t)INCBIN_SIZE(dict_5_b) },
    {.p_wordlist = (wordlist_t)&dict_5_c, .len = (uint16_t)INCBIN_SIZE(dict_5_c) },
    {.p_wordlist = (wordlist_t)&dict_5_d, .len = (uint16_t)INCBIN_SIZE(dict_5_d) },
    {.p_wordlist = (wordlist_t)&dict_5_e, .len = (uint16_t)INCBIN_SIZE(dict_5_e) },
    {.p_wordlist = (wordlist_t)&dict_5_f, .len = (uint16_t)INCBIN_SIZE(dict_5_f) },
    {.p_wordlist = (wordlist_t)&dict_5_g, .len = (uint16_t)INCBIN_SIZE(dict_5_g) },
    {.p_wordlist = (wordlist_t)&dict_5_h, .len = (uint16_t)INCBIN_SIZE(dict_5_h) },
    {.p_wordlist = (wordlist_t)&dict_5_i, .len = (uint16_t)INCBIN_SIZE(dict_5_i) },
    {.p_wordlist = (wordlist_t)&dict_5_j, .len = (uint16_t)INCBIN_SIZE(dict_5_j) },
};


bool dict_check_word_5_aj(const char * word) BANKED {

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