#include <gbdk/platform.h>
#include <gbdk/incbin.h>
#include <stdint.h>
#include <stdbool.h>
#include "dict_common.h"

#pragma bank 255


INCBIN(dict_3_a, "src/data/dict/3_a_words.txt")
INCBIN(dict_3_b, "src/data/dict/3_b_words.txt")
INCBIN(dict_3_c, "src/data/dict/3_c_words.txt")
INCBIN(dict_3_d, "src/data/dict/3_d_words.txt")
INCBIN(dict_3_e, "src/data/dict/3_e_words.txt")
INCBIN(dict_3_f, "src/data/dict/3_f_words.txt")
INCBIN(dict_3_g, "src/data/dict/3_g_words.txt")
INCBIN(dict_3_h, "src/data/dict/3_h_words.txt")
INCBIN(dict_3_i, "src/data/dict/3_i_words.txt")
INCBIN(dict_3_j, "src/data/dict/3_j_words.txt")
INCBIN(dict_3_k, "src/data/dict/3_k_words.txt")
INCBIN(dict_3_l, "src/data/dict/3_l_words.txt")
INCBIN(dict_3_m, "src/data/dict/3_m_words.txt")
INCBIN(dict_3_n, "src/data/dict/3_n_words.txt")
INCBIN(dict_3_o, "src/data/dict/3_o_words.txt")
INCBIN(dict_3_p, "src/data/dict/3_p_words.txt")
INCBIN(dict_3_q, "src/data/dict/3_q_words.txt")
INCBIN(dict_3_r, "src/data/dict/3_r_words.txt")
INCBIN(dict_3_s, "src/data/dict/3_s_words.txt")
INCBIN(dict_3_t, "src/data/dict/3_t_words.txt")
INCBIN(dict_3_u, "src/data/dict/3_u_words.txt")
INCBIN(dict_3_v, "src/data/dict/3_v_words.txt")
INCBIN(dict_3_w, "src/data/dict/3_w_words.txt")
INCBIN(dict_3_x, "src/data/dict/3_x_words.txt")
INCBIN(dict_3_y, "src/data/dict/3_y_words.txt")
INCBIN(dict_3_z, "src/data/dict/3_z_words.txt")

INCBIN_EXTERN(dict_3_a)
INCBIN_EXTERN(dict_3_b)
INCBIN_EXTERN(dict_3_c)
INCBIN_EXTERN(dict_3_d)
INCBIN_EXTERN(dict_3_e)
INCBIN_EXTERN(dict_3_f)
INCBIN_EXTERN(dict_3_g)
INCBIN_EXTERN(dict_3_h)
INCBIN_EXTERN(dict_3_i)
INCBIN_EXTERN(dict_3_j)
INCBIN_EXTERN(dict_3_k)
INCBIN_EXTERN(dict_3_l)
INCBIN_EXTERN(dict_3_m)
INCBIN_EXTERN(dict_3_n)
INCBIN_EXTERN(dict_3_o)
INCBIN_EXTERN(dict_3_p)
INCBIN_EXTERN(dict_3_q)
INCBIN_EXTERN(dict_3_r)
INCBIN_EXTERN(dict_3_s)
INCBIN_EXTERN(dict_3_t)
INCBIN_EXTERN(dict_3_u)
INCBIN_EXTERN(dict_3_v)
INCBIN_EXTERN(dict_3_w)
INCBIN_EXTERN(dict_3_x)
INCBIN_EXTERN(dict_3_y)
INCBIN_EXTERN(dict_3_z)

const static dict_entry_t dictionary[A_Z_COUNT] = {

    {.p_wordlist = (wordlist_t)&dict_3_a, .len = (uint16_t)INCBIN_SIZE(dict_3_a) },
    {.p_wordlist = (wordlist_t)&dict_3_b, .len = (uint16_t)INCBIN_SIZE(dict_3_b) },
    {.p_wordlist = (wordlist_t)&dict_3_c, .len = (uint16_t)INCBIN_SIZE(dict_3_c) },
    {.p_wordlist = (wordlist_t)&dict_3_d, .len = (uint16_t)INCBIN_SIZE(dict_3_d) },
    {.p_wordlist = (wordlist_t)&dict_3_e, .len = (uint16_t)INCBIN_SIZE(dict_3_e) },
    {.p_wordlist = (wordlist_t)&dict_3_f, .len = (uint16_t)INCBIN_SIZE(dict_3_f) },
    {.p_wordlist = (wordlist_t)&dict_3_g, .len = (uint16_t)INCBIN_SIZE(dict_3_g) },
    {.p_wordlist = (wordlist_t)&dict_3_h, .len = (uint16_t)INCBIN_SIZE(dict_3_h) },
    {.p_wordlist = (wordlist_t)&dict_3_i, .len = (uint16_t)INCBIN_SIZE(dict_3_i) },
    {.p_wordlist = (wordlist_t)&dict_3_j, .len = (uint16_t)INCBIN_SIZE(dict_3_j) },
    {.p_wordlist = (wordlist_t)&dict_3_k, .len = (uint16_t)INCBIN_SIZE(dict_3_k) },
    {.p_wordlist = (wordlist_t)&dict_3_l, .len = (uint16_t)INCBIN_SIZE(dict_3_l) },
    {.p_wordlist = (wordlist_t)&dict_3_m, .len = (uint16_t)INCBIN_SIZE(dict_3_m) },
    {.p_wordlist = (wordlist_t)&dict_3_n, .len = (uint16_t)INCBIN_SIZE(dict_3_n) },
    {.p_wordlist = (wordlist_t)&dict_3_o, .len = (uint16_t)INCBIN_SIZE(dict_3_o) },
    {.p_wordlist = (wordlist_t)&dict_3_p, .len = (uint16_t)INCBIN_SIZE(dict_3_p) },
    {.p_wordlist = (wordlist_t)&dict_3_q, .len = (uint16_t)INCBIN_SIZE(dict_3_q) },
    {.p_wordlist = (wordlist_t)&dict_3_r, .len = (uint16_t)INCBIN_SIZE(dict_3_r) },
    {.p_wordlist = (wordlist_t)&dict_3_s, .len = (uint16_t)INCBIN_SIZE(dict_3_s) },
    {.p_wordlist = (wordlist_t)&dict_3_t, .len = (uint16_t)INCBIN_SIZE(dict_3_t) },
    {.p_wordlist = (wordlist_t)&dict_3_u, .len = (uint16_t)INCBIN_SIZE(dict_3_u) },
    {.p_wordlist = (wordlist_t)&dict_3_v, .len = (uint16_t)INCBIN_SIZE(dict_3_v) },
    {.p_wordlist = (wordlist_t)&dict_3_w, .len = (uint16_t)INCBIN_SIZE(dict_3_w) },
    {.p_wordlist = (wordlist_t)&dict_3_x, .len = (uint16_t)INCBIN_SIZE(dict_3_x) },
    {.p_wordlist = (wordlist_t)&dict_3_y, .len = (uint16_t)INCBIN_SIZE(dict_3_y) },
    {.p_wordlist = (wordlist_t)&dict_3_z, .len = (uint16_t)INCBIN_SIZE(dict_3_z) }
};

#define WORD_LEN 3u
#define WORD_INC_SIZE (WORD_LEN - 1u)

bool dict_check_word_3(const char * word) BANKED {

    static wordlist_t p_words;
    static uint16_t dict_word_count;

    // Bounds check input based on first letter (make "a" == 0 for indexing letter arrays below)
    const char first_letter  = word[0] - 'a';
    if ((first_letter < ('a' - 'a')) || (first_letter > ('z' - 'a'))) return false;

    // Load a letter dictionary based on the first letter of the word (so no need to test first letter)
    const dict_entry_t * p_dict = &dictionary[ first_letter ];
    p_words = p_dict->p_wordlist;
    dict_word_count = p_dict->len / 2;

    // Search the wordlist for matches
    const char second_letter = word[1];
    const char third_letter  = word[2];

    while (dict_word_count--) {
        // Return true if a match was found, otherwise advance pointer to next word
        if ((second_letter == *p_words) &&
            (third_letter == *(p_words + 1)) ) return true;
        else p_words += WORD_INC_SIZE;

        // Not really needed for shorter lists:
        // Don't scan the rest of the list if we've moved beyond the second letter in the word list
        // if (*p_words > second_letter) return false;
    }
    return false;
}