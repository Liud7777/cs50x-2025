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
        // print sapces before hashes
        for(int j = 0; j < n - i - 1; j++)
        {
        printf(" ");
        }
        // print hashes
        for(int k = 0; k < i + 1; k++)
        {
        printf("#");
        }
        // print gap between pyramids
        printf("  ");
        // print second pyramid
        for(int l = 0; l < i + 1; l++)
        {
        printf("#");
        }
        printf("\n");
    }
}