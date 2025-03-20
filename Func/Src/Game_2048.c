/**
 * @file Game_2048.c
 * @author your name (you@domain.com)
 * @brief 2048游戏
 * @version 0.1
 * @date 2025-03-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Game_2048.h"
#include "m_MacroTypedef.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4

static U32 s_pulGrid[GRID_SIZE][GRID_SIZE]; // 游戏网格
static S8 s_scGameOver;

/**
 * @brief 打印棋盘
 * 
 */
static void m_PrintGrid(void) 
{
    for (U8 ucRow = 0; ucRow < GRID_SIZE; ucRow++) 
    {
        for (U8 ucCol = 0; ucCol < GRID_SIZE; ucCol++) 
        {
            printf("%5u", s_pulGrid[ucRow][ucCol]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief 添加新的数字
 * 
 */
static void m_AddNewTile(void) 
{
    U32 pulEmptyCells[GRID_SIZE * GRID_SIZE]; // 记录空位置的索引
    U8 ucCnt = 0;

    for (U8 ucRow = 0; ucRow < GRID_SIZE; ucRow++) 
    {
        for (U8 ucCol = 0; ucCol < GRID_SIZE; ucCol++) 
        {
            if (s_pulGrid[ucRow][ucCol] == 0) 
            {
                pulEmptyCells[ucCnt++] = ucRow * GRID_SIZE + ucCol; // 记录空位置的索引
            }
        }
    }

    if (ucCnt > 0) 
    {
        S32 slRandomIndex = rand() % ucCnt;
        S32 slTile = (rand() % 10) < 9 ? 2 : 4; // 90% 的几率生成2，10% 的几率生成4
        U32 ulPos = pulEmptyCells[slRandomIndex];

        s_pulGrid[ulPos / GRID_SIZE][ulPos % GRID_SIZE] = slTile;
    }
}

/**
 * @brief 移动方块
 * 
 * @param ucDirection 移动方向
 * @return U8 是否移动成功
 */
static U8 m_MoveTiles(U8 ucDirection) 
{
    U8 ucMoved = FALSE;
    U32 pulNewGrid[GRID_SIZE][GRID_SIZE] = {0};
    U8 pucMerged[GRID_SIZE][GRID_SIZE] = {FALSE};

    // 复制当前s_pulGrid到pulNewGrid
    for (U8 ucRow = 0; ucRow < GRID_SIZE; ucRow++) 
    {
        for (U8 ucCol = 0; ucCol < GRID_SIZE; ucCol++) 
        {
            pulNewGrid[ucRow][ucCol] = s_pulGrid[ucRow][ucCol];
        }
    }

    switch (ucDirection) 
    {
        case 0: // 上
        {
            for (U8 ucCol = 0; ucCol < GRID_SIZE; ucCol++) 
            {
                for (U8 ucRow = 1; ucRow < GRID_SIZE; ucRow++) 
                {
                    if (pulNewGrid[ucRow][ucCol] != 0) 
                    {
                        for (U8 ucRow2 = 0; ucRow2 < ucRow; ucRow2++) 
                        {
                            if (pulNewGrid[ucRow2][ucCol] == 0) 
                            {
                                pulNewGrid[ucRow2][ucCol] = pulNewGrid[ucRow][ucCol];
                                pulNewGrid[ucRow][ucCol] = 0;
                                ucMoved = TRUE;
                            } 
                            else if ( (pulNewGrid[ucRow2][ucCol] == pulNewGrid[ucRow][ucCol]) && (!pucMerged[ucRow2][ucCol]) ) // 修改：为操作数添加括号
                            {
                                pulNewGrid[ucRow2][ucCol] *= 2;
                                pulNewGrid[ucRow][ucCol] = 0;
                                pucMerged[ucRow2][ucCol] = TRUE;
                                ucMoved = TRUE;
                                break;
                            }
                        }
                    }
                }
            }
        }break;
        case 1: // 下
        {
            for (U8 ucCol = 0; ucCol < GRID_SIZE; ucCol++) 
            {
                for (S8 ucRow = GRID_SIZE - 2; ucRow >= 0; ucRow--) 
                {
                    if (pulNewGrid[ucRow][ucCol] != 0) 
                    {
                        for (S8 ucRow2 = GRID_SIZE - 1; ucRow2 > ucRow; ucRow2--) 
                        {
                            if (pulNewGrid[ucRow2][ucCol] == 0) 
                            {
                                pulNewGrid[ucRow2][ucCol] = pulNewGrid[ucRow][ucCol];
                                pulNewGrid[ucRow][ucCol] = 0;
                                ucMoved = TRUE;
                            } 
                            else if ( (pulNewGrid[ucRow2][ucCol] == pulNewGrid[ucRow][ucCol]) && (!pucMerged[ucRow2][ucCol]) ) // 修改：为操作数添加括号
                            {
                                pulNewGrid[ucRow2][ucCol] *= 2;
                                pulNewGrid[ucRow][ucCol] = 0;
                                pucMerged[ucRow2][ucCol] = TRUE;
                                ucMoved = TRUE;
                                break;
                            }
                        }
                    }
                }
            }
        }break;
        case 2: // 左
        {
            for (U8 ucRow = 0; ucRow < GRID_SIZE; ucRow++) 
            {
                for (U8 ucCol = 1; ucCol < GRID_SIZE; ucCol++) 
                {
                    if (pulNewGrid[ucRow][ucCol] != 0) 
                    {
                        for (U8 ucCol2 = 0; ucCol2 < ucCol; ucCol2++) 
                        {
                            if (pulNewGrid[ucRow][ucCol2] == 0) 
                            {
                                pulNewGrid[ucRow][ucCol2] = pulNewGrid[ucRow][ucCol];
                                pulNewGrid[ucRow][ucCol] = 0;
                                ucMoved = TRUE;
                            } 
                            else if ( (pulNewGrid[ucRow][ucCol2] == pulNewGrid[ucRow][ucCol]) && (!pucMerged[ucRow][ucCol2]) ) // 修改：为操作数添加括号
                            {
                                pulNewGrid[ucRow][ucCol2] *= 2;
                                pulNewGrid[ucRow][ucCol] = 0;
                                pucMerged[ucRow][ucCol2] = TRUE;
                                ucMoved = TRUE;
                                break;
                            }
                        }
                    }
                }
            }
        }break;
        case 3: // 右
        {
            for (U8 ucRow = 0; ucRow < GRID_SIZE; ucRow++) 
            {
                for (S8 ucCol = GRID_SIZE - 2; ucCol >= 0; ucCol--) 
                {
                    if (pulNewGrid[ucRow][ucCol] != 0) 
                    {
                        for (S8 ucCol2 = GRID_SIZE - 1; ucCol2 > ucCol; ucCol2--) 
                        {
                            if (pulNewGrid[ucRow][ucCol2] == 0) 
                            {
                                pulNewGrid[ucRow][ucCol2] = pulNewGrid[ucRow][ucCol];
                                pulNewGrid[ucRow][ucCol] = 0;
                                ucMoved = TRUE;
                            } 
                            else if ( (pulNewGrid[ucRow][ucCol2] == pulNewGrid[ucRow][ucCol]) && (!pucMerged[ucRow][ucCol2]) ) // 修改：为操作数添加括号
                            {
                                pulNewGrid[ucRow][ucCol2] *= 2;
                                pulNewGrid[ucRow][ucCol] = 0;
                                pucMerged[ucRow][ucCol2] = TRUE;
                                ucMoved = TRUE;
                                break;
                            }
                        }
                    }
                }
            }
        }break;
        default:
        {
            // 无操作
        }break;
    }

    if (ucMoved) 
    {
        for (U8 ucRow = 0; ucRow < GRID_SIZE; ucRow++) 
        {
            for (U8 ucCol = 0; ucCol < GRID_SIZE; ucCol++) 
            {
                s_pulGrid[ucRow][ucCol] = pulNewGrid[ucRow][ucCol];
            }
        }
    }

    return ucMoved;
}

/**
 * @brief 处理用户输入
 * 
 */
static void m_HandleInput(void) 
{
    char cInput;
    printf("输入移动方向 (w/a/s/d) 或 q 退出: ");
    scanf(" %c", &cInput);
    switch (cInput) 
    {
        case 'w':
        {
            m_MoveTiles(0);
        }break;
        case 'a':
        {
            m_MoveTiles(2);
        }break;
        case 's':
        {
            m_MoveTiles(1);
        }break;
        case 'd':
        {
            m_MoveTiles(3);
        }break;
        case 'q':
        {
            s_scGameOver = TRUE;
        }break;
        default:
        {
            // 无操作
        }break;
    }
}

/**
 * @brief 判断是否还有移动可能
 * 
 * @return U8 是否还有移动可能
 */
static U8 m_IsMovePossible(void) 
{
    for (U8 ucRow = 0; ucRow < GRID_SIZE; ucRow++) 
    {
        for (U8 ucCol = 0; ucCol < GRID_SIZE; ucCol++) 
        {
            if (s_pulGrid[ucRow][ucCol] == 0) 
            {
                return TRUE;
            }
            if ((ucRow > 0) && (s_pulGrid[ucRow][ucCol] == s_pulGrid[ucRow - 1][ucCol])) 
            {
                return TRUE;
            }
            if ((ucRow < (GRID_SIZE - 1)) && (s_pulGrid[ucRow][ucCol] == s_pulGrid[ucRow + 1][ucCol])) 
            {
                return TRUE;
            }
            if ((ucCol > 0) && (s_pulGrid[ucRow][ucCol] == s_pulGrid[ucRow][ucCol - 1])) 
            {
                return TRUE;
            }
            if ((ucCol < (GRID_SIZE - 1)) && (s_pulGrid[ucRow][ucCol] == s_pulGrid[ucRow][ucCol + 1])) 
            {
                return TRUE;
            }
        }
    }
    
    return FALSE;
}

/**
 * @brief 初始化游戏
 * 
 */
void m_InitGame(void) 
{
    for (U8 ucRow = 0; ucRow < GRID_SIZE; ucRow++) 
    {
        for (U8 ucCol = 0; ucCol < GRID_SIZE; ucCol++) 
        {
            s_pulGrid[ucRow][ucCol] = 0;
        }
    }
    m_AddNewTile();
    m_AddNewTile();
    s_scGameOver = FALSE;
}

/**
 * @brief 开始游戏
 * 
 */
void m_StartGame(void) 
{
    m_InitGame();
    while (!s_scGameOver) 
    {
        m_PrintGrid();
        m_HandleInput();
        if ( (!m_MoveTiles(0)) && (!m_MoveTiles(1)) && (!m_MoveTiles(2)) && (!m_MoveTiles(3)) ) // 修改：为操作数添加括号
        {
            if (!m_IsMovePossible()) 
            {
                s_scGameOver = TRUE;
            }
        } 
        else 
        {
            m_AddNewTile();
        }
    }
    printf("游戏结束!\n");
    m_PrintGrid();
}