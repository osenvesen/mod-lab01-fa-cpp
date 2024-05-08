#include "fun.h"
#include <iostream>
#include <cstring>
#include <cctype>

unsigned int faStr1(const char* str) {
    unsigned int count = 0;
    bool inWord = false;
    bool hasDigit = false;

    while (*str != '\0') {
        if (isalpha((unsigned char)*str)) {
            if (!inWord) {
                inWord = true;
                hasDigit = false;
            }
        } else if (isdigit((unsigned char)*str)) {
            hasDigit = true;
        }

        if ((!isalnum((unsigned char)*str) || *(str + 1) == '\0') && inWord && !hasDigit) {
            count++;
            inWord = false;
        }

        if (!isalnum((unsigned char)*str)) {
            inWord = false;
        }

        str++;
    }

    return count;
}

unsigned int faStr2(const char* str) {
    unsigned int count = 0;

    while (*str) {
        if (isupper((unsigned char)*str)) {
            bool validWord = true;
            str++;

            while (islower((unsigned char)*str)) {
                str++;
            }

            if (isalpha((unsigned char)*str)) {
                validWord = false;
            }

            if (validWord) {
                count++;
            }
        }

        if (*str) {
            str++;
        }
    }

    return count;
}

unsigned int faStr3(const char* str) {
    unsigned int totalLength = 0;
    unsigned int wordCount = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (isalnum(str[i])) {
            int wordLength = 0;
            while (isalnum(str[i])) {
                wordLength++;
                i++;
            }
            totalLength += wordLength;
            wordCount++;
        }
        else {
            i++;
        }
    }

    if (wordCount == 0) return 0;

    unsigned int avgLength = (totalLength + wordCount / 2) / wordCount;
    return avgLength;
}
