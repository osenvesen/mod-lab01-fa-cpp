#include "fun.h"
#include <iostream>
#include <cstring>
#include <cctype>

unsigned int faStr1(const char* str) {
    unsigned int count = 0;
    bool hasDigit = false;
    
    while (*str != '\0' && isspace((unsigned char)*str)) {
        str++;
    }

    while (*str != '\0') {
        if (isalnum(*str) && isdigit(*str)) {
            hasDigit = true;
        }
        if (isspace((unsigned char)*str) || *(str + 1) == '\0') {
            if (!hasDigit) {
                if (!isdigit(*(str - 1)) || isspace((unsigned char)*str)) {
                    count++;
                }
            }
            hasDigit = false;
        }
        str++;
    }

    return count;
}

unsigned int faStr2(const char* str) {
    unsigned int count = 0;

    while (*str != '\0') {
        if (isupper(*str)) {
            bool validWord = true;
            str++;
            while (islower(*str)) {
                str++;
            }
            if (isalpha(*str)) {
                validWord = false;
            }
            if (validWord) {
                count++;
            }
        }
        while (*str && !isupper(*str)) {
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
