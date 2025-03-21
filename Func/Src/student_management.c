/**
 * @file student_management.c
 * @brief 学生成绩管理系统实现文件
 * @version 0.1
 * @date 2023-10-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "student_management.h"
#include <locale.h> // 支持中文字符集

/**
 * @brief 添加学生信息
 * 
 * @param pstStudents 学生数组
 * @param pulCount 学生数量指针
 */
void m_AddStudent(ST_STUDENT *pstStudents, U32 *pulCount) 
{
    if(*pulCount >= MAX_STUDENTS) 
    {
        printf("学生数量已满！\n");
        return;
    }

    setlocale(LC_ALL, ""); // 设置本地化环境，支持中文

    // 清空输入缓冲区
    while(getchar() != '\n');

    printf("请输入学生姓名: ");
    if(fgets(pstStudents[*pulCount].pcName, MAX_NAME_LEN, stdin) == NULL) 
    {
        printf("输入错误！\n");
        return;
    }
    // 移除可能的换行符
    pstStudents[*pulCount].pcName[strcspn(pstStudents[*pulCount].pcName, "\n")] = '\0';

    // 新增：检查姓名是否为空
    if (strlen(pstStudents[*pulCount].pcName) == 0) 
    {
        printf("姓名不能为空，请重新输入！\n");
        while(getchar() != '\n'); // 清空缓冲区残留
        return;
    }

    printf("请输入学生学号: ");
    scanf("%u", &pstStudents[*pulCount].ulStudentID);
    while(getchar() != '\n'); // 清空输入缓冲区

    printf("请输入学生成绩: ");
    scanf("%f", &pstStudents[*pulCount].flScore);
    while(getchar() != '\n'); // 清空输入缓冲区

    (*pulCount)++;
    printf("学生信息添加成功！\n");
}

/**
 * @brief 删除学生信息
 * 
 * @param pstStudents 学生数组
 * @param pulCount 学生数量指针
 */
void m_DeleteStudent(ST_STUDENT *pstStudents, U32 *pulCount) 
{
    U32 ulID;
    U32 ulIndex = 0;
    U8 ucFound = FALSE;

    if(*pulCount == 0) 
    {
        printf("没有学生信息！\n");
        return;
    }

    printf("请输入要删除的学生学号: ");
    scanf("%u", &ulID);

    for(U32 i = 0; i < *pulCount; i++) 
    {
        if(pstStudents[i].ulStudentID == ulID) 
        {
            ulIndex = i;
            ucFound = TRUE;
            break;
        }
    }

    if(ucFound) 
    {
        for(U32 i = ulIndex; i < *pulCount - 1; i++) 
        {
            pstStudents[i] = pstStudents[i + 1];
        }
        (*pulCount)--;
        printf("学生信息删除成功！\n");
    } 
    else 
    {
        printf("未找到该学生信息！\n");
    }
}

/**
 * @brief 查询学生信息
 * 
 * @param pstStudents 学生数组
 * @param ulCount 学生数量
 */
void m_QueryStudent(const ST_STUDENT *pstStudents, U32 ulCount) 
{
    U32 ulID;
    U8 ucFound = FALSE;

    if(ulCount == 0) 
    {
        printf("没有学生信息！\n");
        return;
    }

    setlocale(LC_ALL, ""); // 设置本地化环境，支持中文

    // 清空输入缓冲区
    while(getchar() != '\n');

    printf("请输入要查询的学生学号: ");
    scanf("%u", &ulID);
    while(getchar() != '\n'); // 清空输入缓冲区

    for(U32 i = 0; i < ulCount; i++) 
    {
        if(pstStudents[i].ulStudentID == ulID) 
        {
            printf("姓名: %s\n", pstStudents[i].pcName);
            printf("学号: %u\n", pstStudents[i].ulStudentID);
            printf("成绩: %.2f\n", pstStudents[i].flScore);
            ucFound = TRUE;
            break;
        }
    }

    if(!ucFound) 
    {
        printf("未找到该学生信息！\n");
    }
}

/**
 * @brief 保存学生信息到文件
 * 
 * @param pstStudents 学生数组
 * @param ulCount 学生数量
 */
void m_SaveToFile(const ST_STUDENT *pstStudents, U32 ulCount) 
{
    FILE *pFile = fopen("students.dat", "wb");
    if(pFile == NULL) 
    {
        printf("无法打开文件！\n");
        return;
    }

    fwrite(pstStudents, sizeof(ST_STUDENT), ulCount, pFile);
    fclose(pFile);
    printf("学生信息保存成功！\n");
}

/**
 * @brief 从文件加载学生信息
 * 
 * @param pstStudents 学生数组
 * @param pulCount 学生数量指针
 */
void m_LoadFromFile(ST_STUDENT *pstStudents, U32 *pulCount) 
{
    FILE *pFile = fopen("students.dat", "rb");
    if(pFile == NULL) 
    {
        printf("无法打开文件！\n");
        return;
    }

    *pulCount = fread(pstStudents, sizeof(ST_STUDENT), MAX_STUDENTS, pFile);
    fclose(pFile);
    printf("学生信息加载成功！\n");
}

/**
 * @brief 排序学生信息
 * 
 * @param pstStudents 学生数组
 * @param ulCount 学生数量
 * @param ucSortBy 排序方式 (0: 按姓名, 1: 按成绩)
 */
void m_SortStudents(ST_STUDENT *pstStudents, U32 ulCount, U8 ucSortBy) 
{
    ST_STUDENT stTemp;

    for(U32 i = 0; i < ulCount - 1; i++) 
    {
        for(U32 j = 0; j < ulCount - i - 1; j++) 
        {
            if((ucSortBy == 0 && strcmp(pstStudents[j].pcName, pstStudents[j + 1].pcName) > 0) ||
               (ucSortBy == 1 && pstStudents[j].flScore > pstStudents[j + 1].flScore)) 
            {
                stTemp = pstStudents[j];
                pstStudents[j] = pstStudents[j + 1];
                pstStudents[j + 1] = stTemp;
            }
        }
    }
    printf("学生信息排序成功！\n");
}

/**
 * @brief 分析学生成绩
 * 
 * @param pstStudents 学生数组
 * @param ulCount 学生数量
 */
void m_AnalyzeScores(const ST_STUDENT *pstStudents, U32 ulCount) 
{
    F32 flTotal = 0.0f;
    F32 flMax = pstStudents[0].flScore;
    F32 flMin = pstStudents[0].flScore;

    if(ulCount == 0) 
    {
        printf("没有学生信息！\n");
        return;
    }

    for(U32 i = 0; i < ulCount; i++) 
    {
        flTotal += pstStudents[i].flScore;
        if(pstStudents[i].flScore > flMax) 
        {
            flMax = pstStudents[i].flScore;
        }
        if(pstStudents[i].flScore < flMin) 
        {
            flMin = pstStudents[i].flScore;
        }
    }

    printf("平均成绩: %.2f\n", flTotal / ulCount);
    printf("最高分: %.2f\n", flMax);
    printf("最低分: %.2f\n", flMin);
}