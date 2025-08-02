#include <cs50.h>
#include <stdio.h>

const int N = 3;

// 函数声明：参数名与main中的变量名相同
float average(int N, int scores[]);

int main(void)
{
    // main函数中的变量
    int N = 5;           // 这个N与全局常量N不同
    int scores[3];       // 这个scores数组
    
    printf("main函数中的N值: %d\n", N);
    
    // 获取用户输入
    for(int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }
    
    // 调用函数：传递main中的变量
    float avg = average(3, scores);  // 注意：这里传递的是3，不是main中的N
    
    printf("Average: %.2f\n", avg);
    printf("main函数结束时N的值: %d\n", N);  // N仍然是5
    
    return 0;
}

// 函数定义：参数名与main中的变量名相同，但它们是不同的变量！
float average(int N, int scores[])
{
    printf("average函数中的N值: %d\n", N);  // 这是函数参数N
    
    int sum = 0;
    for(int i = 0; i < N; i++)  // 这里的N是函数参数
    {
        sum += scores[i];       // 这里的scores是函数参数
        printf("scores[%d] = %d\n", i, scores[i]);
    }
    
    return sum / (float)N;      // 这里的N也是函数参数
}