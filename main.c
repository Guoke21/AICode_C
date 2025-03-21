/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./Func/Inc/Module_Ctrl_Cfg.h"
#include "Calendar.h"
#include "Calculator.h"
#include "Game_2048.h"
#include "student_management.h"


int main() 
{
#if STUDENT_EN
    ST_STUDENT stStudents[MAX_STUDENTS];
    U32 ulCount = 0;
    U8 ucChoice;

    while(TRUE) 
    {
        printf("\n学生成绩管理系统\n");
        printf("1. 添加学生\n");
        printf("2. 删除学生\n");
        printf("3. 查询学生\n");
        printf("4. 保存数据\n");
        printf("5. 加载数据\n");
        printf("6. 排序学生\n");
        printf("7. 成绩分析\n");
        printf("0. 退出\n");
        printf("请选择操作: ");
        scanf("%hhu", &ucChoice);

        switch(ucChoice) 
        {
            case 1:
            {
                m_AddStudent(stStudents, &ulCount);
            }break;
            case 2:
            {
                m_DeleteStudent(stStudents, &ulCount);
            }break;
            case 3:
            {
                m_QueryStudent(stStudents, ulCount);
            }break;
            case 4:
            {
                m_SaveToFile(stStudents, ulCount);
            }break;
            case 5:
            {
                m_LoadFromFile(stStudents, &ulCount);
            }break;
            case 6:
            {
                U8 ucSortBy;
                printf("请选择排序方式 (0: 按姓名, 1: 按成绩): ");
                scanf("%hhu", &ucSortBy);
                m_SortStudents(stStudents, ulCount, ucSortBy);
            }break;
            case 7:
            {
                m_AnalyzeScores(stStudents, ulCount);
            }break;
            case 0:
            {
                return 0;
            }break;
            default:
            {
                printf("无效的选择！\n");
            }break;
        }
    }
#endif // STUDENT_EN

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