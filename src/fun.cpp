#include "fun.h"
#include <iostream>
#include <cstring>
#include <cctype>

unsigned int faStr1(const char* str) {
    unsigned int count = 0;
    bool isWord = false;

    while (*str) {
        if (isalpha((unsigned char)*str)) {
            if (!isWord) {
                isWord = true;
            }
        } else if (isdigit((unsigned char)*str)) {
            if (isWord) {
                isWord = false;
            }
        } else {
            if (isWord) {
                count++;
            }
            isWord = false;
        }
        str++;
    }

    if (isWord) {
        count++;
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

        if (!isupper((unsigned char)*str)) {
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
