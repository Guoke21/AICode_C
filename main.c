#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./Func/Inc/Module_Ctrl_Cfg.h"
#include "Calendar.h"
#include "Calculator.h"
#include "Game_2048.h"

// main入口函数测试
int main() 
{


#if CALENDAR_EN // 日历功能
    U16 usYear;
    U8 ucMonth;
    U8 ucDaysInMonth;
    U8 ucFirstDayOfWeek;

    printf("请输入年份: ");
    scanf("%hd", &usYear);
    printf("请输入月份: ");
    scanf("%hhu", &ucMonth);

    ucDaysInMonth = m_Calendar_getDaysInMonth(usYear, ucMonth);
    ucFirstDayOfWeek = m_Calendar_getFirstDayOfWeek(usYear, ucMonth);
    printf("\n%hd年%hhu月的日历\n", usYear, ucMonth);
    printf("日 一 二 三 四 五 六\n");

    // Print leading spaces for the first week
    for (U8 ucI = 0; ucI < ucFirstDayOfWeek; ucI++) 
    {
        printf("   ");
    }

    // Print the days of the month
    for (U8 ucDay = 1; ucDay <= ucDaysInMonth; ucDay++) 
    {
        printf("%02hhu ", ucDay);
        if ((ucDay + ucFirstDayOfWeek) % 7 == 0) 
        {
            printf("\n");
        }
    }
    printf("\n");
#endif // CALENDAR_EN

#if CALCULATOR_EN   // 计算器功能
    F64 flNum1, flNum2;
    char ucOperator;
    F64 flResult;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &flNum1, &flNum2);
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &ucOperator);

    switch (ucOperator) {
        case '+':
        {
            flResult = add(flNum1, flNum2);
            printf("Result: %.2lf\n", flResult);
        }break;
        case '-':
        {
            flResult = subtract(flNum1, flNum2);
            printf("Result: %.2lf\n", flResult);
        }break;
        case '*':
        {
            flResult = multiply(flNum1, flNum2);
            printf("Result: %.2lf\n", flResult);
        }break;
        case '/':
        {
            flResult = divide(flNum1, flNum2);
            printf("Result: %.2lf\n", flResult);
        }break;
        default:
        {
            printf("Error: Invalid operator\n");
        }break;
    }
#endif // CALCULATOR_EN

#if GAME_2048_EN    // 2048游戏功能
    srand(time(NULL)); // 初始化随机数生成器
    m_StartGame();
#endif // GAME_2048_EN

    return 0;
}

