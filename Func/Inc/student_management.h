/**
 * @file student_management.h
 * @brief 学生成绩管理系统头文件
 * @version 0.1
 * @date 2023-10-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef STUDENT_MANAGEMENT_H
#define STUDENT_MANAGEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "m_MacroTypedef.h"

#define MAX_NAME_LEN 50
#define MAX_STUDENTS 100

typedef struct {
    char pcName[MAX_NAME_LEN];
    U32 ulStudentID;
    F32 flScore;
} ST_STUDENT;

/* 函数声明 */
void m_AddStudent(ST_STUDENT *pstStudents, U32 *pulCount);
void m_DeleteStudent(ST_STUDENT *pstStudents, U32 *pulCount);
void m_QueryStudent(const ST_STUDENT *pstStudents, U32 ulCount);
void m_SaveToFile(const ST_STUDENT *pstStudents, U32 ulCount);
void m_LoadFromFile(ST_STUDENT *pstStudents, U32 *pulCount);
void m_SortStudents(ST_STUDENT *pstStudents, U32 ulCount, U8 ucSortBy);
void m_AnalyzeScores(const ST_STUDENT *pstStudents, U32 ulCount);

#endif /* STUDENT_MANAGEMENT_H */