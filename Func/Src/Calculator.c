/**
 * @file Calculator.c
 * @author John Doe (john.doe@example.com)
 * @brief 实现基本计算器功能
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Calculator.h"
#include <stdio.h>

/**
 * @brief 两个浮点数相加
 * 
 * @param fdlA 第一个操作数
 * @param fdlB 第二个操作数
 * @return F64 相加结果
 */
F64 add(F64 fdlA, F64 fdlB) 
{
    return fdlA + fdlB;
}

/**
 * @brief 两个浮点数相减
 * 
 * @param fdlA 第一个操作数
 * @param fdlB 第二个操作数
 * @return F64 相减结果
 */
F64 subtract(F64 fdlA, F64 fdlB) 
{
    return fdlA - fdlB;
}

/**
 * @brief 两个浮点数相乘
 * 
 * @param fdlA 第一个操作数
 * @param fdlB 第二个操作数
 * @return F64 相乘结果
 */
F64 multiply(F64 fdlA, F64 fdlB) 
{
    return fdlA * fdlB;
}

/**
 * @brief 两个浮点数相除
 * 
 * @param fdlA 被除数
 * @param fdlB 除数
 * @return F64 相除结果，若除数为零则返回0并打印错误信息
 */
F64 divide(F64 fdlA, F64 fdlB) 
{
    if (fdlB != 0) 
    {
        return fdlA / fdlB;
    } 
    else 
    {
        printf("Error: Division by zero\n");
        return 0; // 或者根据需要处理错误
    }
}