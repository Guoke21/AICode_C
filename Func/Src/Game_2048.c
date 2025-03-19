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

#include "Game_2048.h" // 修改头文件包含名称
#include "m_MacroTypedef.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4

static U32 grid[GRID_SIZE][GRID_SIZE];
static S8 gameOver;

static void printGrid() {
    for (U8 i = 0; i < GRID_SIZE; i++) {
        for (U8 j = 0; j < GRID_SIZE; j++) {
            printf("%5u", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

static void addNewTile() {
    U32 emptyCells[GRID_SIZE * GRID_SIZE];
    U8 count = 0;

    for (U8 i = 0; i < GRID_SIZE; i++) {
        for (U8 j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                emptyCells[count++] = i * GRID_SIZE + j;
            }
        }
    }

    if (count > 0) {
        S32 randomIndex = rand() % count;
        S32 tile = (rand() % 10) < 9 ? 2 : 4; // 90% 的几率生成2，10% 的几率生成4
        U32 position = emptyCells[randomIndex];
        grid[position / GRID_SIZE][position % GRID_SIZE] = tile;
    }
}

static BOOL moveTiles(U8 direction) {
    BOOL moved = FALSE;
    U32 newGrid[GRID_SIZE][GRID_SIZE] = {0};
    BOOL merged[GRID_SIZE][GRID_SIZE] = {FALSE};

    // Copy current grid to newGrid
    for (U8 i = 0; i < GRID_SIZE; i++) {
        for (U8 j = 0; j < GRID_SIZE; j++) {
            newGrid[i][j] = grid[i][j];
        }
    }

    switch (direction) {
        case 0: // Up
            for (U8 x = 0; x < GRID_SIZE; x++) {
                for (U8 y = 1; y < GRID_SIZE; y++) {
                    if (newGrid[y][x] != 0) {
                        for (U8 y2 = 0; y2 < y; y2++) {
                            if (newGrid[y2][x] == 0) {
                                newGrid[y2][x] = newGrid[y][x];
                                newGrid[y][x] = 0;
                                moved = TRUE;
                            } else if (newGrid[y2][x] == newGrid[y][x] && !merged[y2][x]) {
                                newGrid[y2][x] *= 2;
                                newGrid[y][x] = 0;
                                merged[y2][x] = TRUE;
                                moved = TRUE;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 1: // Down
            for (U8 x = 0; x < GRID_SIZE; x++) {
                for (S8 y = GRID_SIZE - 2; y >= 0; y--) {
                    if (newGrid[y][x] != 0) {
                        for (S8 y2 = GRID_SIZE - 1; y2 > y; y2--) {
                            if (newGrid[y2][x] == 0) {
                                newGrid[y2][x] = newGrid[y][x];
                                newGrid[y][x] = 0;
                                moved = TRUE;
                            } else if (newGrid[y2][x] == newGrid[y][x] && !merged[y2][x]) {
                                newGrid[y2][x] *= 2;
                                newGrid[y][x] = 0;
                                merged[y2][x] = TRUE;
                                moved = TRUE;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 2: // Left
            for (U8 y = 0; y < GRID_SIZE; y++) {
                for (U8 x = 1; x < GRID_SIZE; x++) {
                    if (newGrid[y][x] != 0) {
                        for (U8 x2 = 0; x2 < x; x2++) {
                            if (newGrid[y][x2] == 0) {
                                newGrid[y][x2] = newGrid[y][x];
                                newGrid[y][x] = 0;
                                moved = TRUE;
                            } else if (newGrid[y][x2] == newGrid[y][x] && !merged[y][x2]) {
                                newGrid[y][x2] *= 2;
                                newGrid[y][x] = 0;
                                merged[y][x2] = TRUE;
                                moved = TRUE;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        case 3: // Right
            for (U8 y = 0; y < GRID_SIZE; y++) {
                for (S8 x = GRID_SIZE - 2; x >= 0; x--) {
                    if (newGrid[y][x] != 0) {
                        for (S8 x2 = GRID_SIZE - 1; x2 > x; x2--) {
                            if (newGrid[y][x2] == 0) {
                                newGrid[y][x2] = newGrid[y][x];
                                newGrid[y][x] = 0;
                                moved = TRUE;
                            } else if (newGrid[y][x2] == newGrid[y][x] && !merged[y][x2]) {
                                newGrid[y][x2] *= 2;
                                newGrid[y][x] = 0;
                                merged[y][x2] = TRUE;
                                moved = TRUE;
                                break;
                            }
                        }
                    }
                }
            }
            break;
        default:
            break;
    }

    if (moved) {
        for (U8 i = 0; i < GRID_SIZE; i++) {
            for (U8 j = 0; j < GRID_SIZE; j++) {
                grid[i][j] = newGrid[i][j];
            }
        }
    }

    return moved;
}

static void handleInput() {
    char input;
    printf("输入移动方向 (w/a/s/d) 或 q 退出: ");
    scanf(" %c", &input);
    switch (input) {
        case 'w':
            moveTiles(0);
            break;
        case 'a':
            moveTiles(2);
            break;
        case 's':
            moveTiles(1);
            break;
        case 'd':
            moveTiles(3);
            break;
        case 'q':
            gameOver = TRUE;
            break;
        default:
            break;
    }
}

static BOOL isMovePossible() {
    for (U8 i = 0; i < GRID_SIZE; i++) {
        for (U8 j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                return TRUE;
            }
            if (i > 0 && grid[i][j] == grid[i-1][j]) return TRUE;
            if (i < GRID_SIZE-1 && grid[i][j] == grid[i+1][j]) return TRUE;
            if (j > 0 && grid[i][j] == grid[i][j-1]) return TRUE;
            if (j < GRID_SIZE-1 && grid[i][j] == grid[i][j+1]) return TRUE;
        }
    }
    return FALSE;
}

void initGame() {
    for (U8 i = 0; i < GRID_SIZE; i++) {
        for (U8 j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = 0;
        }
    }
    addNewTile();
    addNewTile();
    gameOver = FALSE;
}

void startGame() {
    initGame();
    while (!gameOver) {
        printGrid();
        handleInput();
        if (!moveTiles(0) && !moveTiles(1) && !moveTiles(2) && !moveTiles(3)) {
            if (!isMovePossible()) {
                gameOver = TRUE;
            }
        } else {
            addNewTile();
        }
    }
    printf("游戏结束!\n");
    printGrid();
}