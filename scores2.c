#include <stdio.h>

int main(void)
{
    const int N = 3;
    int scores[N];
    for(int i = 0; i < N; i++)
    {
        printf("Score: ");
        scanf("%d", &scores[i]);
    }
    printf("average: %.2f\n", (scores[0] + scores[1] + scores[2]) / (float)N);
    
    return 0;
}