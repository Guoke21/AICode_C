// Calendar.h
#ifndef CALENDAR_H
#define CALENDAR_H

#include "m_MacroTypedef.h"

// void printCalendar(U16 year, U8 month);
BOOL isLeapYear(U16 year);
U8 getDaysInMonth(U16 year, U8 month);
U8 getFirstDayOfWeek(U16 year, U8 month);

#endif // CALENDAR_H
