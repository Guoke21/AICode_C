# Reallin编码规范

## 数据类型定义

typedef 	signed char   	    S8;

typedef 	unsigned char  	U8;

typedef 	signed short   	  S16;

typedef 	unsigned short        U16;

typedef 	signed int   	       S32;

typedef 	int   			    U32;

typedef 	signed long long       S64;

typedef 	unsigned long long  U64;

typedef 	float     			F32;

typedef 	double      		   F64;



\#define TRUE   1

\#define FALSE  0



## 命名规范

###  变量定义

规范要求：

1. 变量的缩写应保持一致。例如channel 写成chanl；
1. 对于循环计数的变量，也可以不定义数据类型前缀，如i，j，k等；

举例：

| 数据类型     | 前缀举例                                                     | 备注        |
| ------------ | ------------------------------------------------------------ | ----------- |
| U8           | ucVlaue                                                      |             |
| S8           | scValue                                                      |             |
| U16          | usValue                                                      |             |
| S16          | ssValue                                                      |             |
| U32          | ulValue                                                      |             |
| S32          | slValue                                                      |             |
| U64          | udlValue                                                     |             |
| S64          | sdlValue                                                     |             |
| F32          | flValue                                                      |             |
| F64          | fdlValue                                                     |             |
| 结构体       | stValue                                                      |             |
| 联合体       | unValue                                                      |             |
| Volatile类型 | vulValue                                                     |             |
| 数组         | U8 pucBuf[5];//U8类型数组<br />ST_KEY_DEF pstKey[5];//结构体数组 | 需要加前缀p |
| 指针         | U8 *pucBuf;//U8类型指针                                      | 需要加前缀p |
| 全局变量     | g_ucValue                                                    |             |
| 静态变量     | s_ucValue                                                    |             |
|              |                                                              |             |



### 自定义结构体

规范要求：

1. 结构体命名加前缀ST_，结构体名必须大写;
2. 应使用typedef定义结构体；

​	

举例：

```c
typedef void (*pKeyFun)(void);//函数指针定义
typedef U8	 (*pKeyFunGet)(void);
/*结构体定义*/
typedef struct
{
	U8 ucCnt;//U8类型定义
	S32 slValue;//S32类型定义
	U8 pucCnt[5];//U8类型数组定义
	S32 pslValue[5];//S32类型数组定义
	pKeyFun pFunCtrlOpen;//定义函数指针
	pKeyFun pFunCtrlClose;//定义函数指针	
	pKeyFunGet pFunStGet;//定义函数指针		
}ST_KEY_DEF;
/*结构体变量定义*/
ST_KEY_DEF st_MeterVol;//voltage
ST_KEY_DEF st_MeterCur;//Current
```

### 自定义枚举变量

规范要求：

1. 枚举变量前加前缀ENUM；


举例：

```c
typedef enum
{
	E_RESULT_EQUAL;
	E_RESULT_BIGGER;
	E_RESULT_LESS;
	E_RESULT_ERR;    
}ENUM_CMP_RESULT;
```

### 函数定义规范

1. 每个函数都需要有函数头注释；

2. 形参定义时，数据类型需要左对齐，变量名需要右对齐；
3. 函数名前需要有一个字符空格；
4. 形参和逗号之间无空格；
5. 逗号后面一个空格；
6. 指针的‘*’，符号靠近变量名；
7. 使用typedef定义函数指针；
8. 模块内函数需要加前缀‘m_文件名’；



举例如下：

```C
/**
 * @brief 冒泡排序
 * 
 * @param[in][out] pslArray 
 * @param[in] slSize 
 */
void m_Test_BubbleSort(S32 *pslArray, S32 slSize) //Test.c文件函数命名
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
```





## 书写规范

### 排版

1. 右缩进都是4个空格；

2. 函数体每行不能太长，必要的地方需要分行；

3. 逻辑运算符两边的表达式需要外加括号，以表明逻辑关系；

   举例如下：

   ```c
   /**
    * @brief 测试函数
    * 
    * @return U8 测试结果
    */
   U8 m_Test_Paiban(void)
   {
       for(U8 i = 0; i < 5; i++)
       {
           /*适当分行，逻辑运算符两边的表达式需要外加括号/
           if(((pucBuf[i] >= 'a') && (pucBuf[i] <= 'z')) || \
              ((pucBuf[i] >= 'A') && (pucBuf[i] <= 'Z')) || \
              ((pucBuf[i] >= '0') && (pucBuf[i] >= '9')))
           {
               ucCnt++;
               return FALSE;
           }
           break;
       }
       
       return TRUE;
   }
   ```

   

### 注释

需要加注释的地方：

1. 文件头部；
2. 函数头部，main函数除外；
3. 重要的逻辑设计思路；
4. 结构体里面各成员的说明；
5. 重要参数和变量的定义

举例：

```c
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

static U32 s_pulGrid[GRID_SIZE][GRID_SIZE];// 游戏网格
static S8 s_scGameOver;

/**
 * @brief 打印棋盘
 * 
 */
static void PrintGrid() 
{
    for(U8 i = 0; i < GRID_SIZE; i++) 
    {
        for(U8 j = 0; j < GRID_SIZE; j++) 
        {
            printf("%5u", s_pulGrid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
 * @brief 添加新的数字
 * 
 */
static void AddNewTile() 
{
    U32 pulEmptyCells[GRID_SIZE * GRID_SIZE];// 记录空位置的索引
    U8 ucCnt = 0;
    S32 slRandomIndex = rand() % ucCnt;
    S32 slTile = (rand() % 10) < 9 ? 2 : 4; // 90% 的几率生成2，10% 的几率生成4
    U32 ulPos = pulEmptyCells[slRandomIndex];

    for(U8 i = 0; i < GRID_SIZE; i++) 
    {
        for(U8 j = 0; j < GRID_SIZE; j++) 
        {
            if(s_pulGrid[i][j] == 0) 
            {
                pulEmptyCells[ucCnt++] = i * GRID_SIZE + j;// 记录空位置的索引
            }
        }
    }
    if(ucCnt > 0) 
    {
        s_pulGrid[ulPos / GRID_SIZE][ulPos % GRID_SIZE] = slTile;
    }
}
```





### 常见的逻辑书写规范



#### 常规要求

1. 运算符（逻辑运算符、算数运算符和条件运算符）前后，需要用一个字符空格；
2. (前后不加空格；
3. )前后不需要空格；
4. '{'不能写在行尾，需要独立占一行；
5. ‘}’需要独立占一行；
6. 最后一条定义的变量与语句之间空一行；

7. 右缩进都需要4个空格；

8. 一元运算符‘!’，’~’，‘++’，’--'等，这些符号与操作数之间不能有空格；

举例：

```c
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
```



####  if语句

1. 每个if，以及对应的else if或者else，必须用{}包含起来，即使只有一行代码；

举例：

```c
/**
 * @brief 获取指定年份和月份的第一天是星期几
 * 
 * @param[in] slYear 年份
 * @param[in] slMonth 月份
 * @return U8 返回星期几（0表示星期日，1表示星期一，依此类推）
 */
S32 m_GetStartDayOfWeek(S32 slYear, S32 slMonth) 
{
    S32 slNum1;
    S32 slNum2;
    S32 slNum3;
    
    if(slMonth < 3) 
    {
        slMonth += 12;
        slYear--;
    }
    slNum1 = slYear % 100;
    slNum2 = slYear / 100;
    slNum3 = (1 + 13 * (slMonth + 1) / 5 + slNum1 + slNum1 / 4 + slNum2 / 4 + 5 * slNum2) % 7;
    
    return slNum3;
}
```

#### for循环

1. 每个for循环，必须用{}包含起来，即使只有一行代码;

举例：

```c
for(S32 slDay = 1; slDay <= slDaysInMonth; slDay++) 
{
    printf("%2ld ", slDay);
    if((slDay + slStartDay) % 7 == 0) 
    {
	    printf("\n");
    }
}
```

####  while循环

1. 每个while循环，须用{}包含起来，即使只有一行代码；

举例：

```c
while(!gameOver) 
{
    printGrid();
    handleInput();
    if((!moveTiles(0)) && (!moveTiles(1)) && (!moveTiles(2)) && (!moveTiles(3))) 
    {
        if(!isMovePossible()) 
        {
	        gameOver = TRUE;
	    }
    } 
    else 
    {
	    addNewTile();
    }
}
```

####  switch语句

1. switch后面的括号内，为判断变量名，括号前后无空格；
2. switch正对的{，独立成行，且需要与switch左对齐；
3. switch正对的}，单独成行，并且后面需要写明注释，注释格式/* end of switch，判断变量名*/；
4. 判断的每个case 向右缩进4个空格；
5. 每个case，{须独立成行，且与case左对齐；
6. 每个case 对应的}，后面须跟上break；

举例：

```c
switch(input) 
{
    case 'w':
    {
        moveTiles(0);
    }break;
    case 'a':
    {
	    moveTiles(2);    
    }break;
    case 's':
    {
        moveTiles(1);
    }break;
    case 'd':
    {
        moveTiles(3);
    }break;
    case 'q':
    {
        gameOver = TRUE;
    }break;
    default:
    {
    
    }break;
}
```















