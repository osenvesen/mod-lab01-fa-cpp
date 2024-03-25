// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cstring>
#include <cctype>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    const char *word = str;
    
    while (*str) {
        if (std::isalpha(*str)) {
            word = str;
            while (std::isalpha(*str)) {
                if (std::isdigit(*str)) {
                    break;
                }
                str++;
            }
            if (word != str) {
                count++;
            }
        } else {
            str++;
        }
    }
    
    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;
    bool startOfWord = true;
    
    while (*str) {
        if (std::isupper(*str)) {
            startOfWord = true;
        } else if (startOfWord && std::islower(*str)) {
            const char *word = str;
            while (std::isalpha(*str)) {
                if (!std::islower(*str)) {
                    break;
                }
                str++;
            }
            if (word != str) {
                count++;
            }
            startOfWord = false;
        } else {
            startOfWord = false;
            str++;
        }
    }
    
    return count;
}

unsigned int faStr3(const char *str) {
     unsigned int wordCount = 0;
    unsigned int letterCount = 0;
    
    while (*str) {
        if (std::isalpha(*str)) {
            const char *word = str;
            while (std::isalpha(*str)) {
                letterCount++;
                str++;
            }
            wordCount++;
        } else {
            str++;
        }
    }
    
    return letterCount / wordCount;
}
