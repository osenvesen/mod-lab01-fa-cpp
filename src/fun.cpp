// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cstring>
#include <cctype>

unsigned int faStr1(const char* str) {
    unsigned int count = 0;
    bool hasDigit = false;
    int i = 0;

    while (str[i] != '\0') {
        if (isalnum(str[i]) && isdigit(str[i])) {
            hasDigit = true;
        }
        if (!isalnum(str[i]) || str[i + 1] == '\0') {
            if (!hasDigit) {
                count++;
            }
            hasDigit = false;
        }
        i++;
    }

    return count;
}

unsigned int faStr2(const char* str) {
    unsigned int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (isupper(str[i])) {
            i++;
            while (islower(str[i])) {
                i++;
            }
            if (!isalpha(str[i])) {
                count++;
            }
        }
        else {
            while (islower(str[i])) {
                i++;
            }
        }
        i++;
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

    return totalLength / wordCount;
}
