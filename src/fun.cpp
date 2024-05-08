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
        if ((!isalnum(str[i]) && hasDigit == false) || (str[i + 1] == '\0' && hasDigit == false)) {
            count++;
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
            bool isValid = true;
            i++;
            while (islower(str[i]) || str[i] == '\0') {
                if (isupper(str[i])) {
                    isValid = false;
                    break;
                }
                i++;
            }
            if (!isalpha(str[i]) && isValid) {
                count++;
            }
        } else {
            while (islower(str[i]) || isupper(str[i]) || str[i] == '\0') {
                i++;
            }
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
            while (isalnum(str[i]) || str[i] == '\0') {
                wordLength++;
                i++;
            }
            totalLength += wordLength;
            wordCount++;
        } else {
            i++;
        }
    }

    return wordCount > 0 ? totalLength / wordCount : 0;
}
