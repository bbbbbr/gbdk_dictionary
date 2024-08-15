#include <gbdk/platform.h>
#include <gbdk/incbin.h>
#include <stdint.h>
#include <stdbool.h>
#include "dict_common.h"

#pragma bank 255


#define FIRST_LETTER 'k'
#define LAST_LETTER  's'
#define WORD_LEN 5u
#define WORD_INC_SIZE (WORD_LEN - 1u)

INCBIN(dict_5_k, "src/data/dict/5_k_words.txt")
INCBIN(dict_5_l, "src/data/dict/5_l_words.txt")
INCBIN(dict_5_m, "src/data/dict/5_m_words.txt")
INCBIN(dict_5_n, "src/data/dict/5_n_words.txt")
INCBIN(dict_5_o, "src/data/dict/5_o_words.txt")
INCBIN(dict_5_p, "src/data/dict/5_p_words.txt")
INCBIN(dict_5_q, "src/data/dict/5_q_words.txt")
INCBIN(dict_5_r, "src/data/dict/5_r_words.txt")
INCBIN(dict_5_s, "src/data/dict/5_s_words.txt")

INCBIN_EXTERN(dict_5_k)
INCBIN_EXTERN(dict_5_l)
INCBIN_EXTERN(dict_5_m)
INCBIN_EXTERN(dict_5_n)
INCBIN_EXTERN(dict_5_o)
INCBIN_EXTERN(dict_5_p)
INCBIN_EXTERN(dict_5_q)
INCBIN_EXTERN(dict_5_r)
INCBIN_EXTERN(dict_5_s)

const static dict_entry_t dictionary[A_Z_COUNT] = {
    {.p_wordlist = (wordlist_t)&dict_5_k, .len = (uint16_t)INCBIN_SIZE(dict_5_k) },
    {.p_wordlist = (wordlist_t)&dict_5_l, .len = (uint16_t)INCBIN_SIZE(dict_5_l) },
    {.p_wordlist = (wordlist_t)&dict_5_m, .len = (uint16_t)INCBIN_SIZE(dict_5_m) },
    {.p_wordlist = (wordlist_t)&dict_5_n, .len = (uint16_t)INCBIN_SIZE(dict_5_n) },
    {.p_wordlist = (wordlist_t)&dict_5_o, .len = (uint16_t)INCBIN_SIZE(dict_5_o) },
    {.p_wordlist = (wordlist_t)&dict_5_p, .len = (uint16_t)INCBIN_SIZE(dict_5_p) },
    {.p_wordlist = (wordlist_t)&dict_5_q, .len = (uint16_t)INCBIN_SIZE(dict_5_q) },
    {.p_wordlist = (wordlist_t)&dict_5_r, .len = (uint16_t)INCBIN_SIZE(dict_5_r) },
    {.p_wordlist = (wordlist_t)&dict_5_s, .len = (uint16_t)INCBIN_SIZE(dict_5_s) },
};


bool dict_check_word_5_ks(const char * word) BANKED {

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