// Copyright 2024 osenvesen
#include <iostream>
#include "fun.h"
int main() {
    const char* input = "fg Vfpj 7gf 78  fgkm";

    std::cout << "faStr1: " << faStr1(input) << std::endl;
    std::cout << "faStr2: " << faStr2(input) << std::endl;
    std::cout << "faStr3: " << faStr3(input) << std::endl;

    return 0;
}
