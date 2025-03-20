/**
 * @file calendar.c
 * @author John Doe (john.doe@example.com)
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
 * @brief 判断是否为闰年
 * 
 * @param usYear 年份
 * @return U8 返回TRUE表示是闰年，FALSE表示不是闰年
 */
U8 isLeapYear(U16 usYear) 
{
    return (usYear % 4 == 0 && usYear % 100 != 0) || (usYear % 400 == 0);
}

/**
 * @brief 获取指定年份和月份的天数
 * 
 * @param usYear 年份
 * @param ucMonth 月份
 * @return U8 返回该月的天数
 */
U8 getDaysInMonth(U16 usYear, U8 ucMonth) 
{
    U8 pucDaysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (ucMonth == 2 && isLeapYear(usYear)) 
    {
        return 29;
    }
    return pucDaysInMonth[ucMonth - 1];
}

/**
 * @brief 获取指定年份和月份的第一天是星期几
 * 
 * @param usYear 年份
 * @param ucMonth 月份
 * @return U8 返回星期几（0表示星期日，1表示星期一，依此类推）
 */
U8 getFirstDayOfWeek(U16 usYear, U8 ucMonth) 
{
    U8 ucDay = 1;
    S32 slWday = 1; // 1900-01-01 是星期一
    S32 slY, slM;
    for (slY = 1900; slY < usYear; slY++) 
    {
        slWday += isLeapYear(slY) ? 366 : 365;
    }
    for (slM = 1; slM < ucMonth; slM++) 
    {
        slWday += getDaysInMonth(usYear, slM);
    }
    return (U8)(slWday % 7);
}