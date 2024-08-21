#pragma bank 255

#include "vm_gameboy.h"
#include "data/game_globals.h"
#include "dict_lookup.h"
#include "string.h"

uint8_t selectedLetters[6];

void isThisAWord(SCRIPT_CTX *THIS) OLDCALL BANKED {

    INT16 *is_this_a_word = VM_REF_TO_PTR(FN_ARG0);

    // reset the check
    *is_this_a_word = 0;

    // populate a local array with the selected letter indexes
    uint8_t count;
    for (count = 0; count < *(script_memory + VAR_SELECTEDNUMBER); count++) {
        switch (count) {
            case 0:
                selectedLetters[count] = *(script_memory + VAR_SELECTION1);
                break;
            case 1:
                selectedLetters[count] = *(script_memory + VAR_SELECTION2);
                break;
            case 2:
                selectedLetters[count] = *(script_memory + VAR_SELECTION3);
                break;
            case 3:
                selectedLetters[count] = *(script_memory + VAR_SELECTION4);
                break;
            case 4:
                selectedLetters[count] = *(script_memory + VAR_SELECTION5);
                break;
            case 5:
                selectedLetters[count] = *(script_memory + VAR_SELECTION6);
                break;
        }
    }
    
    // String needs to be sized for: max number of letters + 1 for null string terminator character
    unsigned char wordToCheck[7] = "";
    // build a string which contains the word to check
    for (count = 0; count < *(script_memory + VAR_SELECTEDNUMBER); count++) {

        // add it
        switch (selectedLetters[count]) {
            case 1:
                strcat(wordToCheck, "a");
                break;
            case 2:
                strcat(wordToCheck, "b");
                break;
            case 3:
                strcat(wordToCheck, "c");
                break;
            case 4:
                strcat(wordToCheck, "d");
                break;
            case 5:
                strcat(wordToCheck, "e");
                break;
            case 6:
                strcat(wordToCheck, "f");
                break;
            case 7:
                strcat(wordToCheck, "g");
                break;
            case 8:
                strcat(wordToCheck, "h");
                break;
            case 9:
                strcat(wordToCheck, "i");
                break;
            case 10:
                strcat(wordToCheck, "j");
                break;
            case 11:
                strcat(wordToCheck, "k");
                break;
            case 12:
                strcat(wordToCheck, "l");
                break;
            case 13:
                strcat(wordToCheck, "m");
                break;
            case 14:
                strcat(wordToCheck, "n");
                break;
            case 15:
                strcat(wordToCheck, "o");
                break;
            case 16:
                strcat(wordToCheck, "p");
                break;
            case 17:
                strcat(wordToCheck, "q");
                break;
            case 18:
                strcat(wordToCheck, "r");
                break;
            case 19:
                strcat(wordToCheck, "s");
                break;
            case 20:
                strcat(wordToCheck, "t");
                break;
            case 21:
                strcat(wordToCheck, "u");
                break;
            case 22:
                strcat(wordToCheck, "v");
                break;
            case 23:
                strcat(wordToCheck, "w");
                break;
            case 24:
                strcat(wordToCheck, "x");
                break;
            case 25:
                strcat(wordToCheck, "y");
                break;
            case 26:
                strcat(wordToCheck, "z");
                break;
        }
    }

    // Note: The code above makes it easy to understand the conversion to a string.
    //       A more compact and efficient method would be something like as follows:
    //
    //    // Fill string with terminator chars
    //    // String needs to be sized for: max number of letters + 1 for null string terminator character
    //    unsigned char wordToCheck[7] = {'\0','\0','\0','\0','\0','\0','\0' };
    //
    //    // Build a string which contains the word to check
    //    for (count = 0; count < *(script_memory + VAR_SELECTEDNUMBER); count++)
    //    {
    //        uint8_t char_num = (selectedLetters[count] - 1u);
    //        if ((char_num >= 0u) && (char_num <= 25u))
    //        {
    //            wordToCheck[count] = 'a' + char_num;
    //        }
    //    }

    // do the check and assign the result (1 or 0)
    *is_this_a_word = dict_check_word(wordToCheck);
}
