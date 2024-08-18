#include <gbdk/platform.h>
#include <gbdk/incbin.h>
#include <stdint.h>
#include <stdbool.h>
#include "dict_common.h"

#pragma bank 255


INCBIN(dict_4_a, "src/data/dict/4_a_words.txt")
INCBIN(dict_4_b, "src/data/dict/4_b_words.txt")
INCBIN(dict_4_c, "src/data/dict/4_c_words.txt")
INCBIN(dict_4_d, "src/data/dict/4_d_words.txt")
INCBIN(dict_4_e, "src/data/dict/4_e_words.txt")
INCBIN(dict_4_f, "src/data/dict/4_f_words.txt")
INCBIN(dict_4_g, "src/data/dict/4_g_words.txt")
INCBIN(dict_4_h, "src/data/dict/4_h_words.txt")
INCBIN(dict_4_i, "src/data/dict/4_i_words.txt")
INCBIN(dict_4_j, "src/data/dict/4_j_words.txt")
INCBIN(dict_4_k, "src/data/dict/4_k_words.txt")
INCBIN(dict_4_l, "src/data/dict/4_l_words.txt")
INCBIN(dict_4_m, "src/data/dict/4_m_words.txt")
INCBIN(dict_4_n, "src/data/dict/4_n_words.txt")
INCBIN(dict_4_o, "src/data/dict/4_o_words.txt")
INCBIN(dict_4_p, "src/data/dict/4_p_words.txt")
INCBIN(dict_4_q, "src/data/dict/4_q_words.txt")
INCBIN(dict_4_r, "src/data/dict/4_r_words.txt")
INCBIN(dict_4_s, "src/data/dict/4_s_words.txt")
INCBIN(dict_4_t, "src/data/dict/4_t_words.txt")
INCBIN(dict_4_u, "src/data/dict/4_u_words.txt")
INCBIN(dict_4_v, "src/data/dict/4_v_words.txt")
INCBIN(dict_4_w, "src/data/dict/4_w_words.txt")
INCBIN(dict_4_x, "src/data/dict/4_x_words.txt")
INCBIN(dict_4_y, "src/data/dict/4_y_words.txt")
INCBIN(dict_4_z, "src/data/dict/4_z_words.txt")

INCBIN_EXTERN(dict_4_a)
INCBIN_EXTERN(dict_4_b)
INCBIN_EXTERN(dict_4_c)
INCBIN_EXTERN(dict_4_d)
INCBIN_EXTERN(dict_4_e)
INCBIN_EXTERN(dict_4_f)
INCBIN_EXTERN(dict_4_g)
INCBIN_EXTERN(dict_4_h)
INCBIN_EXTERN(dict_4_i)
INCBIN_EXTERN(dict_4_j)
INCBIN_EXTERN(dict_4_k)
INCBIN_EXTERN(dict_4_l)
INCBIN_EXTERN(dict_4_m)
INCBIN_EXTERN(dict_4_n)
INCBIN_EXTERN(dict_4_o)
INCBIN_EXTERN(dict_4_p)
INCBIN_EXTERN(dict_4_q)
INCBIN_EXTERN(dict_4_r)
INCBIN_EXTERN(dict_4_s)
INCBIN_EXTERN(dict_4_t)
INCBIN_EXTERN(dict_4_u)
INCBIN_EXTERN(dict_4_v)
INCBIN_EXTERN(dict_4_w)
INCBIN_EXTERN(dict_4_x)
INCBIN_EXTERN(dict_4_y)
INCBIN_EXTERN(dict_4_z)

const static dict_entry_t dictionary[A_Z_COUNT] = {

    {.p_wordlist = (wordlist_t)&dict_4_a, .len = (uint16_t)INCBIN_SIZE(dict_4_a) },
    {.p_wordlist = (wordlist_t)&dict_4_b, .len = (uint16_t)INCBIN_SIZE(dict_4_b) },
    {.p_wordlist = (wordlist_t)&dict_4_c, .len = (uint16_t)INCBIN_SIZE(dict_4_c) },
    {.p_wordlist = (wordlist_t)&dict_4_d, .len = (uint16_t)INCBIN_SIZE(dict_4_d) },
    {.p_wordlist = (wordlist_t)&dict_4_e, .len = (uint16_t)INCBIN_SIZE(dict_4_e) },
    {.p_wordlist = (wordlist_t)&dict_4_f, .len = (uint16_t)INCBIN_SIZE(dict_4_f) },
    {.p_wordlist = (wordlist_t)&dict_4_g, .len = (uint16_t)INCBIN_SIZE(dict_4_g) },
    {.p_wordlist = (wordlist_t)&dict_4_h, .len = (uint16_t)INCBIN_SIZE(dict_4_h) },
    {.p_wordlist = (wordlist_t)&dict_4_i, .len = (uint16_t)INCBIN_SIZE(dict_4_i) },
    {.p_wordlist = (wordlist_t)&dict_4_j, .len = (uint16_t)INCBIN_SIZE(dict_4_j) },
    {.p_wordlist = (wordlist_t)&dict_4_k, .len = (uint16_t)INCBIN_SIZE(dict_4_k) },
    {.p_wordlist = (wordlist_t)&dict_4_l, .len = (uint16_t)INCBIN_SIZE(dict_4_l) },
    {.p_wordlist = (wordlist_t)&dict_4_m, .len = (uint16_t)INCBIN_SIZE(dict_4_m) },
    {.p_wordlist = (wordlist_t)&dict_4_n, .len = (uint16_t)INCBIN_SIZE(dict_4_n) },
    {.p_wordlist = (wordlist_t)&dict_4_o, .len = (uint16_t)INCBIN_SIZE(dict_4_o) },
    {.p_wordlist = (wordlist_t)&dict_4_p, .len = (uint16_t)INCBIN_SIZE(dict_4_p) },
    {.p_wordlist = (wordlist_t)&dict_4_q, .len = (uint16_t)INCBIN_SIZE(dict_4_q) },
    {.p_wordlist = (wordlist_t)&dict_4_r, .len = (uint16_t)INCBIN_SIZE(dict_4_r) },
    {.p_wordlist = (wordlist_t)&dict_4_s, .len = (uint16_t)INCBIN_SIZE(dict_4_s) },
    {.p_wordlist = (wordlist_t)&dict_4_t, .len = (uint16_t)INCBIN_SIZE(dict_4_t) },
    {.p_wordlist = (wordlist_t)&dict_4_u, .len = (uint16_t)INCBIN_SIZE(dict_4_u) },
    {.p_wordlist = (wordlist_t)&dict_4_v, .len = (uint16_t)INCBIN_SIZE(dict_4_v) },
    {.p_wordlist = (wordlist_t)&dict_4_w, .len = (uint16_t)INCBIN_SIZE(dict_4_w) },
    {.p_wordlist = (wordlist_t)&dict_4_x, .len = (uint16_t)INCBIN_SIZE(dict_4_x) },
    {.p_wordlist = (wordlist_t)&dict_4_y, .len = (uint16_t)INCBIN_SIZE(dict_4_y) },
    {.p_wordlist = (wordlist_t)&dict_4_z, .len = (uint16_t)INCBIN_SIZE(dict_4_z) }
};

#define WORD_LEN 4u
#define WORD_INC_SIZE (WORD_LEN - 1u)

bool dict_check_word_4(const char * word) BANKED {

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
    const char fourth_letter = word[3];

    while (dict_word_count--) {
        // Return true if a match was found, otherwise advance pointer to next word
        if ((second_letter == *p_words) &&
            (third_letter  == *(p_words + 1)) &&
            (fourth_letter == *(p_words + 2)) ) return true;
        else p_words += WORD_INC_SIZE;

        // Don't scan the rest of the list if we've moved beyond the second letter in the word list
        if (*p_words > second_letter) return false;
    }
    return false;
}