#include <gbdk/platform.h>
#include <gbdk/incbin.h>
#include <stdint.h>
#include <stdbool.h>
#include "common.h"

#pragma bank 255

INCBIN(dict_6_i, "src/dict/6_i_words.txt")
INCBIN(dict_6_j, "src/dict/6_j_words.txt")
INCBIN(dict_6_k, "src/dict/6_k_words.txt")
INCBIN(dict_6_l, "src/dict/6_l_words.txt")
INCBIN(dict_6_m, "src/dict/6_m_words.txt")
INCBIN(dict_6_n, "src/dict/6_n_words.txt")
INCBIN(dict_6_o, "src/dict/6_o_words.txt")

INCBIN_EXTERN(dict_6_i)
INCBIN_EXTERN(dict_6_j)
INCBIN_EXTERN(dict_6_k)
INCBIN_EXTERN(dict_6_l)
INCBIN_EXTERN(dict_6_m)
INCBIN_EXTERN(dict_6_n)
INCBIN_EXTERN(dict_6_o)

const static dict_entry_t dictionary[A_Z_COUNT] = {
    {.p_wordlist = (wordlist_t)&dict_6_i, .len = (uint16_t)INCBIN_SIZE(dict_6_i) },
    {.p_wordlist = (wordlist_t)&dict_6_j, .len = (uint16_t)INCBIN_SIZE(dict_6_j) },
    {.p_wordlist = (wordlist_t)&dict_6_k, .len = (uint16_t)INCBIN_SIZE(dict_6_k) },
    {.p_wordlist = (wordlist_t)&dict_6_l, .len = (uint16_t)INCBIN_SIZE(dict_6_l) },
    {.p_wordlist = (wordlist_t)&dict_6_m, .len = (uint16_t)INCBIN_SIZE(dict_6_m) },
    {.p_wordlist = (wordlist_t)&dict_6_n, .len = (uint16_t)INCBIN_SIZE(dict_6_n) },
    {.p_wordlist = (wordlist_t)&dict_6_o, .len = (uint16_t)INCBIN_SIZE(dict_6_o) },
};


#define WORD_LEN 6u
#define WORD_INC_SIZE (WORD_LEN - 1u)

#define FIRST_LETTER 'i'
#define LAST_LETTER  'o'


bool dict_check_word_6_io(const char * word) BANKED {

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
    const char sixth_letter  = word[5];

    while (dict_word_count--) {
        // Return true if a match was found, otherwise advance pointer to next word
        if ((second_letter == *p_words) &&
            (third_letter  == *(p_words + 1)) &&
            (fourth_letter == *(p_words + 2)) &&
            (fifth_letter  == *(p_words + 3)) &&
            (sixth_letter  == *(p_words + 4)) ) return true;
        else p_words += WORD_INC_SIZE;

    // TODO: below prevents scanning the WHOLE list if not needed, but adds 2x overhead for short searches - Test on worse case 6 letters [s]
        // Don't scan the rest of the list if we've moved beyond the second letter in the word list
        if (*p_words > second_letter) return false;
    }
    return false;
}