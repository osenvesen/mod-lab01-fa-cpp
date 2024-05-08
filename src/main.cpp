// Copyright 2022 UNN-IASR
#include <cctype>
#include <cstring>
#include <iostream>
#include "fun.h"

int main() {
    setlocale(LC_ALL, "rus");

    const char* input = "fghfijghd Vfpjm 5739";

    std::cout << "Количество слов, не содержащих цифр: "
              << faStr1(input) << std::endl;
    std::cout << "Количество слов, начинающихся на заглавную латинскую букву, "
              << "а среди других символов этих "
              << "слов только латинские строчные буквы:"
              << faStr2(input) << std::endl;
    std::cout << "Средняя длина слова в строке: "
              << faStr3(input) << std::endl;

    return 0;
}
