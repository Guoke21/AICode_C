#include <stdio.h>  // 包含标准输入输出头文件
#include "./Inc/code_rules.h"

// 定义快速排序函数
void QuickSort(S32 *pslArray, S32 slLow, S32 slHigh) 
{
    if (slLow < slHigh) 
    {
        S32 slPi = Partition(pslArray, slLow, slHigh);
        QuickSort(pslArray, slLow, slPi - 1);
        QuickSort(pslArray, slPi + 1, slHigh);
    }
}

// 定义分区函数
S32 Partition(S32 *pslArray, S32 slLow, S32 slHigh) 
{
    S32 slPivot = pslArray[slHigh];
    S32 slI = (slLow - 1);
    for (S32 slJ = slLow; slJ <= slHigh - 1; slJ++) 
    {
        if (pslArray[slJ] < slPivot) 
        {
            slI++;
            // 交换 pslArray[slI] 和 pslArray[slJ]
            S32 slTemp = pslArray[slI];
            pslArray[slI] = pslArray[slJ];
            pslArray[slJ] = slTemp;
        }
    }
    // 交换 pslArray[slI + 1] 和 pslArray[slHigh]
    S32 slTemp = pslArray[slI + 1];
    pslArray[slI + 1] = pslArray[slHigh];
    pslArray[slHigh] = slTemp;
    return (slI + 1);
}

//写一个冒泡排序函数
void BubbleSort(S32 *pslArray, S32 slLength) 
{
    for (S32 slI = 0; slI < slLength - 1; slI++) 
    {
        for (S32 slJ = 0; slJ < slLength - slI - 1; slJ++) 
        {
            if (pslArray[slJ] > pslArray[slJ + 1]) 
            {}
        }
    }
}
