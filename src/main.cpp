// Copyright 2022 UNN-IASR
#include "fun.h"
#include <iostream>
#include <cstring>
#include <cctype>

int main() {
     setlocale(LC_ALL, "rus");

  const char* input = "fghfijghd Vfpjm 5739 78678578 Aghfgmb fgkmognopgnnonrojn";

  std::cout << "Количество слов, не содержащих цифр: " << faStr1(input) << std::endl;
  std::cout << "Количество слов, начинающихся на заглавную латинскую букву, а среди других символов этих слов только латинские строчные буквы: " << faStr2(input) << std::endl;
  std::cout << "Средняя длина слова в строке: " << faStr3(input) << std::endl;
    
    return 0;
}
