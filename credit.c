#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get credit card number from user
    long number = get_long("Number: ");
    
    // Variables for Luhn's algorithm
    int sum = 0;
    int digit_count = 0;
    long temp = number;
    
    // Calculate checksum using Luhn's algorithm
    while (temp > 0)
    {
        int digit = temp % 10;
        
        // Every other digit starting from the second-to-last
        if (digit_count % 2 == 1)
        {
            digit *= 2;
            // If the result is two digits, add them together
            if (digit > 9)
            {
                digit = (digit % 10) + (digit / 10);
            }
        }
        
        sum += digit;
        temp /= 10;
        digit_count++;
    }
    
    // Check if the card number is valid (checksum divisible by 10)
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // Get the first digit(s) to determine card type
    long first_digits = number;
    while (first_digits >= 100)
    {
        first_digits /= 10;
    }
    
    int first_digit = first_digits / 10;
    
    // Determine card type based on length and starting digits
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
        printf("INVALID\n");
    }
    
    return 0;
}