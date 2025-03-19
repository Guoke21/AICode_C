# Reallin编码规范

## 1、数据类型定义

typedef 	unsigned char  	BOOL;

typedef 	signed char   		S8;

typedef 	unsigned char  	U8;

typedef 	signed short   	  S16;

typedef 	unsigned short    U16;

typedef 	signed int   		   S32;

typedef 	int   						U32;

typedef 	signed long long   S64;

typedef 	unsigned long long U64;

typedef 	float     					 F32;

typedef 	double      				F64;



\#define TRUE   1

\#define FALSE  0



## 2、命名规范

### 2.1 变量定义

规范要求：

1. 变量的缩写应保持一致。例如channel 写成chanl ,只能使用一种缩写，而不能两种缩写混着用。

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



### 2.2 自定义结构体

规范要求：



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

### 2.3 自定义枚举变量

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



## 3、书写规范

### 3.1 常规要求

1. 运算符前后，需要用一个字符空格；
2. '('前后不需要空格，')'前后不需要空格，；
3. '{'不能写在行尾，需要独立占一行；‘}’需要独立占一行；
4. 最后一条定义的变量与语句之间空一行；

```c
int main() 
{
    S32 pslArray[] = {64, 34, 25, 12, 22, 11, 90};
    S32 slN = sizeof(pslArray) / sizeof(pslArray[0]);//最后一条变量定义
    
    printf("未排序数组: \n");
    printArray(pslArray, slN);
    bubbleSort(pslArray, slN);
    printf("排序后数组: \n");
    printArray(pslArray, slN);
    return 0;
}
```

5. 





### 3.2 if语句

1. 每个if，以及对应的else if或者else，必须用{}包含起来，即使只有一行代码；
2. If后面的()，与if之间不空格，()前后都不空格；
3. 右缩进都需要4个空格；
4. 逻辑运算符前后需要空格一个字符；

举例：

```c
S32 m_GetStartDayOfWeek(S32 slYear, S32 slMonth) 
{
    if(slMonth < 3) 
    {
        slMonth += 12;
        slYear--;
    }
    S32 slK = slYear % 100;
    S32 slJ = slYear / 100;
    S32 slH = (1 + 13 * (slMonth + 1) / 5 + slK + slK / 4 + slJ / 4 + 5 * slJ) % 7;
    return slH;
}
```

### 3.3 for循环

1. 每个for循环，须用{}包含起来，即使只有一行代码;
2. for后面的（）括号前后都不空格;
3. 右缩进都需要4个空格。;
4. 逻辑运算符前后需要空格一个字符;

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

### 3.4 while循环

1. 每个while循环，须用{}包含起来，即使只有一行代码；
2. while后面的()前后都不空格；
3. 右缩进都需要4个空格；
4. 逻辑运算符前后需要空格一个字符；

举例：

```c
while(!gameOver) 
{
    printGrid();
    handleInput();
    if(!moveTiles(0) && !moveTiles(1) && !moveTiles(2) && !moveTiles(3)) 
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

### 3.5 switch语句

1. switch后面的括号内，为判断的变量名，括号前后无空格；
2. switch正对的下面{，独立成行，且需要与switch左对齐；
3. }单独成行，并且后面需要写明注释，注释格式/* end of switch，判断变量名*/；
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















