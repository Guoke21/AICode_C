#include <stdio.h>
#include "m_MacroTypedef.h"

int main()
{
    U32 ulNum1, ulNum2;
    U8 ucOperation;

    ulNum2 = 0;
    printf("请输入一个数:\n");
    scanf("%d", &ulNum1);
    /*{}都需要独立占一行*/
    switch(ulNum1)
    {
        case 1:
        {
            if(ulNum2 < 10)//()前后都不需要空格
            {
                printf("相加：%d\n", ulNum1 + ulNum2);//运算符前后有空格
            }
        }break;
        case 2:
        {
            if(ulNum2 != ulNum1)
            {
                printf("不等于：%d\n", ulNum1);
            }
        }break;
        case 3:
        {
            ulNum2 = ~ulNum1;//一元运算符与操作数之间没有空格；
            printf("取反：%d\n", ulNum2);
        }break;
        case 4:
        {
            if (ulNum2 != 0)
            {
                ulNum2 = ulNum1++;
                printf("自加：%d\n", ulNum2);
            }
        }break;
        default:
        {
            printf("无效的运算符！\n");
        }break;
    }

    return 0;
}
