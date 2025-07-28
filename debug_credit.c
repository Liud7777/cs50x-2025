#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get the credit card number entered by the user
    long number = get_long("Number: ");
    
    // variables for luhn's algorithm
    int sum = 0;
    int digit_count = 0;
    long temp = number;

    printf("DEBUG: Processing number %ld\n", number);

    // calculate checksum using luhn's algorithm
    while (temp > 0)
    {
        int digit = temp % 10;
        int original_digit = digit;

        // every other digit starting from the second-to-last
        if (digit_count % 2 == 1)
        {
            digit *= 2;
            // if the result is two digits, add them together
            if (digit > 9)
            {
                digit = (digit % 10) + (digit / 10);
            } 
        }
        
        printf("DEBUG: Position %d, original digit %d, processed digit %d\n", 
               digit_count, original_digit, digit);
        
        sum += digit;
        temp /= 10;
        digit_count++;
    }
    
    printf("DEBUG: Total digits: %d, Sum: %d\n", digit_count, sum);
    
    // check if the card number is valid (checksum divisible by 10)
    if (sum % 10 != 0)
    {
        printf("INVALID (checksum failed)\n");
        return 0;
    }

    // get the first digit(s) to determine card type
    long first_digits = number;
    while (first_digits >= 100)
    {
        first_digits /= 10;
    }

    int first_digit = first_digits / 10;
    
    printf("DEBUG: First two digits: %ld, First digit: %d\n", first_digits, first_digit);

    // determine card type based on length and starting digits
    if (digit_count == 15 && (first_digits == 34 || first_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (digit_count == 16 && (first_digits >= 51 && first_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((digit_count == 13 || digit_count == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID (card type not recognized)\n");
    }
    
    return 0;
}