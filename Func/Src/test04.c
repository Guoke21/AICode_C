//输入：参照编码规范@code_relus_jh.md，使用C语言写一个冒泡排序，中文输出
//结论：简单函数的效果还不错，代码风格符合规范，但是需要进一步优化和测试。

#include <stdio.h>
#include "code_rules.h"


typedef signed int S32;
/**
 * @brief 
 * 
 * @param pslArray 
 * @param slSize 
 */
void bubbleSort(S32 pslArray[], S32 slSize) 
{
    S32 slOuter, slInner, slTmp;
    
    for(slOuter = 0; slOuter < slSize - 1; slOuter++) 
    {
        for(slInner = 0; slInner < slSize - slOuter - 1; slInner++) 
        {
            if(pslArray[slInner] > pslArray[slInner + 1]) 
            {
                slTmp = pslArray[slInner];
                pslArray[slInner] = pslArray[slInner + 1];
                pslArray[slInner + 1] = slTmp;
            }
        }
    }
}

void printArray(S32 pslArray[], S32 slSize) 
{
    S32 slI;
    for(slI = 0; slI < slSize; slI++) 
    {
        printf("%d ", pslArray[slI]);
    }
    printf("\n");
}

int main() 
{
    S32 pslArray[] = {64, 34, 25, 12, 22, 11, 90};
    S32 slN = sizeof(pslArray) / sizeof(pslArray[0]);
    printf("未排序数组: \n");
    printArray(pslArray, slN);
    bubbleSort(pslArray, slN);
    printf("排序后数组: \n");
    printArray(pslArray, slN);
    return 0;
}

