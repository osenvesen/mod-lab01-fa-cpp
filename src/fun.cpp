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

int main() {

    setlocale(LC_ALL, "rus");

    const char* input = "fghfijghd Vfpjm 5739 78678578 Aghfgmb fgkmognopgnnonrojn";

    std::cout << "Количество слов, не содержащих цифр: " << faStr1(input) << std::endl;
    std::cout << "Количество слов, начинающихся на заглавную латинскую букву, а среди других символов этих слов только латинские строчные буквы: " << faStr2(input) << std::endl;
    std::cout << "Средняя длина слова в строке: " << faStr3(input) << std::endl;

    return 0;
}
