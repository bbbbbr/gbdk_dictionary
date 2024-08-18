#pragma bank 255

#include "vm_gameboy.h"
#include "game_globals.h"
#include "dict_lookup.h"
#include "string.h"

uint8_t selectedLetters[6];

void isThisAWord(void) OLDCALL BANKED {

    // reset the check
    *(script_memory + VAR_ISTHISAWORD) = 0;

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
    
    // build a string which contains the word to check
    unsigned char wordToCheck[6] = "";
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

    // do the check and assign the result (1 or 0)
    *(script_memory + VAR_ISTHISAWORD) = dict_check_word(wordToCheck);
}