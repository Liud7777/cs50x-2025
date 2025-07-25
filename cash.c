#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for change owed
    float change;
    do
    {
        change = get_float("change owed: ");
    }
    while (change < 0);

    // convert dollars to cents
    int cents = (int)(change * 100 + 0.5);

    // initialize coin count
    int coins = 0;

    // calculate number of coins
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
        }
        else if (cents >= 10)
        {
            cents -= 10;
        }
        else if (cents >= 5)
        {
            cents -= 5;
        }
        else
        {
            cents -= 1;
        }
        coins++;
    }
    // print number of coins
    printf("%i\n", coins);
    return 0;
}