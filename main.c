#include <cs50.h>
#include <stdio.h>

// constant
const int N = 3;  // 改为正数，比如3个分数

// prototype
float average(int length, int number[]);

int main(void)
{
    int scores[N];
    for(int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }
    float avg = average(N, scores);  // 正确的函数调用语法，并避免变量名冲突
    printf("%.2f\n", avg);
}

float average(int length, int number[])
{
    int sum = 0;
    for(int i = 0; i < length; i++)
    {
        sum += number[i];
    }
    return sum / (float)length;
}