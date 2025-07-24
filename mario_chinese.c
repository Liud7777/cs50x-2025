#include <stdio.h>

// 获取整数输入的函数
int get_int(const char* prompt)
{
    int value;
    printf("%s", prompt);
    scanf("%d", &value);
    return value;
}

int main(void)
{
    int n;
    // 循环获取用户输入，直到输入的高度大于等于1
    do
    {
        n = get_int("高度: ");
    }
    while (n < 1);
    
    // 外层循环：控制金字塔的行数（从0到n-1）
    for(int i = 0; i < n; i++)
    {
        // 第一个内层循环：打印左金字塔前的空格（用于右对齐）
        for(int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // 第二个内层循环：打印左金字塔的井号
        for(int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        // 打印两个金字塔之间的间隔（2个空格）
        printf("  ");
        // 第三个内层循环：打印右金字塔的井号
        for(int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        // 换行，准备打印下一行
        printf("\n");
    }
    
    return 0;
}