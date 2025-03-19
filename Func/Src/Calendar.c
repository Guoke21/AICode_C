/**
 * @file calendar.c
 * @author your name (you@domain.com)
 * @brief 
 * 1. 获取指定年份和月份的第一天是星期几
 * 2. 获取指定年份和月份的天数
 * 3. 获取指定年份和月份的周数
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include "Calendar.h"

/**
 * @brief 
 * 
 * @param year 
 * @return BOOL 
 */
BOOL isLeapYear(U16 year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

U8 getDaysInMonth(U16 year, U8 month) {
    U8 daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

U8 getFirstDayOfWeek(U16 year, U8 month) {
    U8 day = 1;
    S32 wday = 1; // 1900-01-01 是星期一
    S32 y, m;
    for (y = 1900; y < year; y++) {
        wday += isLeapYear(y) ? 366 : 365;//
    }
    for (m = 1; m < month; m++) {
        wday += getDaysInMonth(year, m);
    }
    return (U8)(wday % 7);
}


