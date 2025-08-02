#include <cs50.h>
#include <stdio.h>

const int N = 3;

float average(int length, int number[]);

int main(void)
{
    int scores[N];
    for(int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }
    float avg = average(N, scores);  // 修复：使用N代替length，使用scores代替number
    printf("%f\n", avg);
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