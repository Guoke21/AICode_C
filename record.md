测试C项目：
    1、C语言实现一个函数，计算两个数的和。
    2、C语言实现一个冒泡排序算法。
    3、C语言实现一个简单的计算器，可以进行加减乘除运算
    4、使用 C 语言完成一个简单的日历功能，输入相应的年/月即可看到当月的日历。
    5、使用 C 语言完成一个2048游戏；
    6、使用C语言实现一个猜数字的游戏，让用户猜随机生成的数字，直到猜中为止。
    7、使用C语言实现一个简单的扫雷游戏；
    8、使用C语言实现五子棋游戏。
 
综合项目：
    多个C项目放入不同的子文件中，然后再main文件中选择调用，调用方法可以是输入特定值执行特定的应用程序；
    将modbus协议实现放入工程中，然后通过协议选择调用方法；


    


-------------分隔符-------------

    // {
    //   "name": "变量命名规范",
    //   "prompt": "{{{ input }}}\n\n请根据以下规范命名变量:\n1. 变量命名举例:U8 ucValue;\nS8 scValue;\nU16 usValue;\nS16 ssValue;\nU32 ulValue;\nS32 slValue;\nU64 udlValue;\nS64 sdlValue;\nF32 flValue;\nF64 fdlValue;\n2. 结构体加前缀st;联合体加前缀un;数组和指针加前缀p,例如:U8 pucBuf[5];全局变量加前缀g_;静态变量加前缀s_;\n3. 适当缩写变量名，例如:U8 ucVal;",
    //   "description": "根据规范命名变量"
    // },
    // {
    //   "name": "函数命名规范",
    //   "prompt": "{{{ input }}}\n\n请根据以下规范命名函数:\n1. 函数名加前缀'm_文件名_',例如:m_Test_Init();",
    //   "description": "根据规范命名函数"
    // },
    // {
    //   "name": "生成代码注释",
    //   "prompt": "请为以下代码生成详细的注释：{{{ input }}}",
    //   "description": "为以下代码生成详细的注释"
    // },

    
    // {
    //   "name": "其他要求",
    //   "prompt": "{{{ input }}}\n\n根据实际需求申请内存,避免内存泄漏",
    //   "description": "嵌入式开发需要注意内存使用"
    // }

---------------

你是一名资深的C语言程序员，熟悉C语言语法，熟悉C语言内存管理机制，熟悉C语言数据类型，熟悉C语言函数调用机制，熟悉C语言指针机制，熟悉C语言数组机制，熟悉C语言结构体机制，熟悉C语言枚举机制，熟悉C语言预处理器机制，熟悉C语言宏机制，熟悉C语言内存泄漏机制，熟悉C语言内存分配机制，熟悉C语言内存释放机制，熟悉C语言内存泄漏检测机制，熟悉C语言内存泄漏修复机制，熟悉C语言内存泄漏原因分析机制，熟悉C语言内存泄漏


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./Func/Inc/Module_Ctrl_Cfg.h"
#include "Calendar.h"
#include "Calculator.h"
#include "Game_2048.h"
#include "student.h" // 新增学生管理模块头文件引用

// main入口函数测试
int main() 
{
    // 新增学生管理模块初始化
    #if STUDENT_EN
        ST_Student stStudents[MAX_STUDENTS];
        U16 usCount = 0;
        m_Student_Init(stStudents, &usCount);
    #endif // STUDENT_EN

    while(1) // 新增主菜单循环
    {
        printf("\n主菜单:\n");
        printf("1. 学生管理\n");
        printf("2. 日历功能\n");
        printf("3. 计算器功能\n");
        printf("4. 2048游戏\n");
        printf("0. 退出\n");
        printf("请选择功能: ");
        
        int choice;
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
            {
                // 学生管理子菜单
                #if STUDENT_EN
                    while(1) 
                    {
                        printf("\n学生管理子菜单:\n");
                        printf("1. 添加学生\n");
                        printf("2. 删除学生\n");
                        printf("3. 查询学生\n");
                        printf("4. 显示学生列表\n");
                        printf("5. 统计分析\n");
                        printf("6. 排序（按成绩/姓名/学号）\n");
                        printf("0. 返回主菜单\n");
                        printf("请选择操作: ");
                        int sub_choice;
                        scanf("%d", &sub_choice);
                        
                        switch(sub_choice) 
                        {
                            case 1: m_Student_Add(stStudents, &usCount); break;
                            case 2: m_Student_Delete(stStudents, &usCount); break;
                            case 3: m_Student_Search(stStudents, usCount); break;
                            case 4: m_Student_Display(stStudents, usCount); break;
                            case 5: m_Analysis_DisplayStats(stStudents, usCount); break;
                            case 6: 
                            {
                                printf("请选择排序方式（1-成绩 2-姓名 3-学号）: ");
                                int sort_type;
                                scanf("%d", &sort_type);
                                switch(sort_type)
                                {
                                    case 1: m_Sort_ByScore(stStudents, usCount); break;
                                    case 2: m_Sort_ByName(stStudents, usCount); break;
                                    case 3: m_Sort_ByID(stStudents, usCount); break;
                                    default: printf("无效选择\n"); break;
                                }
                            }break;
                            case 0: break;
                            default: printf("无效选项\n"); break;
                        }
                        if(sub_choice == 0) break;
                    }
                #endif // STUDENT_EN
            }break;
                
            case 2:
            {
                #if CALENDAR_EN // 日历功能
                    U16 usYear;
                    U8 ucMonth;
                    U8 ucDaysInMonth;
                    U8 ucFirstDayOfWeek;

                    printf("请输入年份: ");
                    scanf("%hd", &usYear);
                    printf("请输入月份: ");
                    scanf("%hhu", &ucMonth);

                    ucDaysInMonth = m_Calendar_getDaysInMonth(usYear, ucMonth);
                    ucFirstDayOfWeek = m_Calendar_getFirstDayOfWeek(usYear, ucMonth);
                    printf("\n%hd年%hhu月的日历\n", usYear, ucMonth);
                    printf("日 一 二 三 四 五 六\n");

                    // Print leading spaces for the first week
                    for (U8 ucI = 0; ucI < ucFirstDayOfWeek; ucI++) 
                    {
                        printf("   ");
                    }

                    // Print the days of the month
                    for (U8 ucDay = 1; ucDay <= ucDaysInMonth; ucDay++) 
                    {
                        printf("%02hhu ", ucDay);
                        if ((ucDay + ucFirstDayOfWeek) % 7 == 0) 
                        {
                            printf("\n");
                        }
                    }
                    printf("\n");
                #endif // CALENDAR_EN
            }break;

            case 3:
            {
                #if CALCULATOR_EN   // 计算器功能
                    F64 flNum1, flNum2;
                    char ucOperator;
                    F64 flResult;

                    printf("Enter two numbers: ");
                    scanf("%lf %lf", &flNum1, &flNum2);
                    printf("Enter an operator (+, -, *, /): ");
                    scanf(" %c", &ucOperator);

                    switch (ucOperator) {
                        case '+':
                        {
                            flResult = add(flNum1, flNum2);
                            printf("Result: %.2lf\n", flResult);
                        }break;
                        case '-':
                        {
                            flResult = subtract(flNum1, flNum2);
                            printf("Result: %.2lf\n", flResult);
                        }break;
                        case '*':
                        {
                            flResult = multiply(flNum1, flNum2);
                            printf("Result: %.2lf\n", flResult);
                        }break;
                        case '/':
                        {
                            flResult = divide(flNum1, flNum2);
                            printf("Result: %.2lf\n", flResult);
                        }break;
                        default:
                        {
                            printf("Error: Invalid operator\n");
                        }break;
                    }
                #endif // CALCULATOR_EN
            }break;

            case 4:
            {
                #if GAME_2048_EN    // 2048游戏功能
                    srand(time(NULL)); // 初始化随机数生成器
                    m_StartGame();
                #endif // GAME_2048_EN
            }break;

            case 0: return 0;
            default: printf("无效选项，请重新选择\n"); break;
        }
    }
}