int coins = 0;

// calculate number of coins
for (; cents > 0; coins++)
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
}

// print number of coins
printf("%i\n", coins);
return 0;