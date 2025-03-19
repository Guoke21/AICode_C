/**
 * @file Calculator.c
 * @author your name (you@domain.com)
 * @brief 计算器功能实现
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Calculator.h"

F64 add(F64 a, F64 b) {
    return a + b;
}

F64 subtract(F64 a, F64 b) {
    return a - b;
}

F64 multiply(F64 a, F64 b) {
    return a * b;
}

F64 divide(F64 a, F64 b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0; // Or handle the error as needed
    }
}

