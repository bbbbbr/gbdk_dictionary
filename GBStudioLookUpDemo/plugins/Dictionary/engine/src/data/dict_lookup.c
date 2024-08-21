#include <gbdk/platform.h>
#include <stdint.h>
#include <stdbool.h>

#pragma bank 255

#include "dict_len_3.h"
#include "dict_len_4.h"
#include "dict_len_5.h"
#include "dict_len_6.h"



// our own strlen here to avoid pulling any lib code into Bank 0
inline uint8_t strlen_u8( const char * str ) {
  uint8_t i = 0u;

  while (*str++) i++ ;
  return i;
}


bool dict_check_word(const char * str) BANKED {
    bool result = false;
    uint8_t word_len = strlen_u8(str);

    switch (word_len) {
        case 3: result = dict_check_word_3(str); break;
        case 4: result = dict_check_word_4(str); break;
        case 5: if      (str[0] <= 'j') result = dict_check_word_5_aj(str);
                else if (str[0] <= 's') result = dict_check_word_5_ks(str);
                else                    result = dict_check_word_5_tz(str);
                break;
        case 6: if      (str[0] <= 'b') result = dict_check_word_6_ab(str);
                else if (str[0] <= 'e') result = dict_check_word_6_ce(str);
                else if (str[0] <= 'h') result = dict_check_word_6_fh(str);
                else if (str[0] <= 'o') result = dict_check_word_6_io(str);
                else if (str[0] <= 'r') result = dict_check_word_6_pr(str);
                else if (str[0] <= 'u') result = dict_check_word_6_su(str);
                else                    result = dict_check_word_6_vz(str);
                break;
    };
    return result;
}
