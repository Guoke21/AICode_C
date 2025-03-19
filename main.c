#include <stdio.h>
#include <stdlib.h>

// #include "./Func/Inc/Module_Ctrl_Cfg.h"
#include "./Func/Inc/Module_Ctrl_Cfg.h"
#include "Calendar.h"
// #include "Calculator.h"
// #include "Game_2048.h"

//main入口函数测试
int main() 
{
#if CALENDAR_EN //日历功能
    U16 year;
    U8 month;

    printf("请输入年份: ");
    scanf("%hd", &year);
    printf("请输入月份: ");
    scanf("%hhu", &month);

    U8 daysInMonth;
    U8 firstDayOfWeek;

    daysInMonth = getDaysInMonth(year, month);
    firstDayOfWeek = getFirstDayOfWeek(year, month);
    printf("\n%hd年%hhu月的日历\n", year, month);
    printf("日 一 二 三 四 五 六\n");

    // Print leading spaces for the first week
    for (U8 i = 0; i < firstDayOfWeek; i++) {
        printf("   ");
    }

    // Print the days of the month
    for (U8 day = 1; day <= daysInMonth; day++) {
        printf("%02hhu ", day);
        if ((day + firstDayOfWeek) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
#endif//CALENDAR_EN

#if CALCULATOR_EN   //计算器功能
    F64 num1, num2;
    char operator;
    F64 result;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch (operator) {
        case '+':
            result = add(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case '-':
            result = subtract(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case '*':
            result = multiply(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case '/':
            result = divide(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        default:
            printf("Error: Invalid operator\n");
            break;
    }
#endif//CALCULATOR_EN

#if GAME_2048_EN    //2048游戏功能
    srand(time(NULL)); // 初始化随机数生成器
    startGame();
#endif//GAME_2048_EN


    return 0;
}


