//Cline的deepseek生成效果：
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* 自定义数据类型 */
typedef unsigned char  U8;
typedef signed int     S32;
typedef unsigned int   U32;

/* 枚举类型定义 */
typedef enum
{
    E_GUESS_EQUAL,
    E_GUESS_BIGGER,
    E_GUESS_SMALLER
}ENUM_GUESS_RESULT;

/* 函数声明 */
void vInitGame(void);
ENUM_GUESS_RESULT eCompareNumber(S32 slInput);
void vPrintResult(ENUM_GUESS_RESULT eResult);

/* 全局变量 */
static U32 s_ulGuessCount = 0;
static S32 s_slTargetNumber = 0;

int main(void)
{
    vInitGame();
    U8 ucGameRunning = 1;
    
    printf("数字猜谜游戏开始！\n");
    
    while(ucGameRunning)
    {
        S32 slInput = 0;
        printf("请输入你猜的数字（0-100）：");
        scanf("%ld", &slInput);
        
        ENUM_GUESS_RESULT eResult = eCompareNumber(slInput);
        vPrintResult(eResult);
        s_ulGuessCount++;
        
        if(eResult == E_GUESS_EQUAL)
        {
            printf("恭喜！你用了%lu次猜中数字。\n", s_ulGuessCount);
            ucGameRunning = 0;
        }
    }
    return 0;
}

void vInitGame(void)
{
    srand((U32)time(NULL));
    s_slTargetNumber = rand() % 100 + 1;
    s_ulGuessCount = 0;
}

ENUM_GUESS_RESULT eCompareNumber(S32 slInput)
{
    if(slInput == s_slTargetNumber)
    {
        return E_GUESS_EQUAL;
    }
    else if(slInput > s_slTargetNumber)
    {
        return E_GUESS_BIGGER;
    }
    else
    {
        return E_GUESS_SMALLER;
    }
}

void vPrintResult(ENUM_GUESS_RESULT eResult)
{
    switch(eResult)
    {
        case E_GUESS_EQUAL:
        {
            // 结果在main函数处理
        }break;
        case E_GUESS_BIGGER:
        {
            printf("太大了！\n");
        }break;
        case E_GUESS_SMALLER:
        {
            printf("太小了！\n");
        }break;
        default:
        {
            printf("无效输入！\n");
        }break;
    }/* end of switch eResult */
}
