#include <stdio.h>

int main(void)
{
    // Test with the problematic number: 4003600000000014
    long number = 4003600000000014L;
    
    printf("Testing number: %ld\n", number);
    
    // variables for luhn's algorithm
    int sum = 0;
    int digit_count = 0;
    long temp = number;

    // calculate checksum using luhn's algorithm
    while (temp > 0)
    {
        int digit = temp % 10;
        int original = digit;

        // every other digit starting from the second-to-last (position 1, 3, 5...)
        if (digit_count % 2 == 1)
        {
            digit *= 2;
            // if the result is two digits, add them together
            if (digit > 9)
            {
                digit = (digit % 10) + (digit / 10);
            } 
        }
        
        printf("Position %d: %d -> %d\n", digit_count, original, digit);
        sum += digit;
        temp /= 10;
        digit_count++;
    }
    
    printf("Total sum: %d\n", sum);
    printf("Sum %% 10 = %d\n", sum % 10);
    
    // check if the card number is valid (checksum divisible by 10)
    if (sum % 10 != 0)
    {
        printf("Result: INVALID\n");
        return 0;
    }

    // get the first digit(s) to determine card type
    long first_digits = number;
    while (first_digits >= 100)
    {
        first_digits /= 10;
    }

    int first_digit = first_digits / 10;
    
    printf("Digits: %d, First two digits: %ld, First digit: %d\n", 
           digit_count, first_digits, first_digit);

    // determine card type based on length and starting digits
    if (digit_count == 15 && (first_digits == 34 || first_digits == 37))
    {
        printf("Result: AMEX\n");
    }
    else if (digit_count == 16 && (first_digits >= 51 && first_digits <= 55))
    {
        printf("Result: MASTERCARD\n");
    }
    else if ((digit_count == 13 || digit_count == 16) && first_digit == 4)
    {
        printf("Result: VISA\n");
    }
    else
    {
        printf("Result: INVALID\n");
    }
    
    return 0;
}