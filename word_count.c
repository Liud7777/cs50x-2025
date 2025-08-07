#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 错误的实现（您原来的代码）
int calculate_words_wrong(char* text)
{
    int spaces = 0;
    int words; // 需要声明这个变量
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isblank(text[i]))
        {
            spaces++;
            words = spaces + 1; // 这里的位置是错误的！
        }
    }
    return words; // 如果没有空格，words 可能未初始化
}

// 正确的实现方法1：在循环结束后计算
int calculate_words_correct1(char* text)
{
    int spaces = 0;
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isblank(text[i]))
        {
            spaces++;
        }
    }
    int words = spaces + 1; // 正确位置：在循环结束后
    return words;
}

// 正确的实现方法2：更好的算法（推荐）
int calculate_words_correct2(char* text)
{
    int words = 0;
    int in_word = 0; // 标记是否在单词中
    
    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(!isblank(text[i]))
        {
            if(!in_word) // 如果之前不在单词中，现在遇到非空格字符
            {
                words++; // 找到一个新单词
                in_word = 1;
            }
        }
        else
        {
            in_word = 0; // 遇到空格，标记不在单词中
        }
    }
    return words;
}

// 测试函数
int main()
{
    char test1[] = "hello world test";
    char test2[] = "  hello   world  ";
    char test3[] = "single";
    char test4[] = "";
    
    printf("测试字符串: \"%s\"\n", test1);
    printf("方法1结果: %d\n", calculate_words_correct1(test1));
    printf("方法2结果: %d\n", calculate_words_correct2(test1));
    
    printf("\n测试字符串: \"%s\"\n", test2);
    printf("方法1结果: %d\n", calculate_words_correct1(test2));
    printf("方法2结果: %d\n", calculate_words_correct2(test2));
    
    printf("\n测试字符串: \"%s\"\n", test3);
    printf("方法1结果: %d\n", calculate_words_correct1(test3));
    printf("方法2结果: %d\n", calculate_words_correct2(test3));
    
    return 0;
}