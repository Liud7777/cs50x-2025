#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);
    
    for(int i = 0; i < n; i++)
    {
        // Print spaces for right alignment of left pyramid
        for(int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }
        // Print left pyramid blocks
        for(int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        // Print gap between pyramids
        printf("  ");
        // Print right pyramid blocks
        for(int l = 0; l < i + 1; l++)
        {
            printf("#");
        }
        // Print newline after each row
        printf("\n");
    }
}