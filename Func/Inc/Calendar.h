/**
 * @file Calendar.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-03-20
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef CALENDAR_H
#define CALENDAR_H

#include "m_MacroTypedef.h"

// void printCalendar(U16 year, U8 month);
U8 m_Calendar_isLeapYear(U16 usYear);
U8 m_Calendar_getDaysInMonth(U16 usYear, U8 ucMonth);
U8 m_Calendar_getFirstDayOfWeek(U16 usYear, U8 ucMonth);

#endif // CALENDAR_H
