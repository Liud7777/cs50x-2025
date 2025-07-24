#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);

    for (int i = 0; i < n; i++)
    {
        print_row(n - i - 1, i + 1);
        printf("\n");
    }
}

void print_row(int spaces, int bricks)
{
    for(int j = 0; j < spaces; j++ )
    {
        printf(" ");
    }

    for(int k = 0; k < bricks; k++)
    {
        printf("#");
    }
}