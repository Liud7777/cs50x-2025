#include <cs50.h>
#include <stdio.h>

const int N = 3;

// 正确的声明方式1：使用方括号表示数组
float average1(int N, int scores[]);

// 正确的声明方式2：使用指针（等价于方式1）
float average2(int N, int *scores);

// 错误的声明方式（这会导致编译错误）
// float average_wrong(int N, int scores);  // 注释掉，因为这是错误的

int main(void)
{
    int scores[N];
    
    // 获取用户输入
    for(int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }
    
    // 正确的函数调用
    float avg1 = average1(N, scores);  // 可以工作
    float avg2 = average2(N, scores);  // 也可以工作
    
    printf("Average (method 1): %.2f\n", avg1);
    printf("Average (method 2): %.2f\n", avg2);
    
    return 0;
}

// 实现方式1：使用数组语法
float average1(int N, int scores[])
{
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += scores[i];  // 可以使用数组下标访问
    }
    return sum / (float)N;
}

// 实现方式2：使用指针语法
float average2(int N, int *scores)
{
    int sum = 0;
    for(int i = 0; i < N; i++)
    {
        sum += scores[i];  // 也可以使用数组下标访问
        // 或者使用指针算术：sum += *(scores + i);
    }
    return sum / (float)N;
}