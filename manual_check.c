#include <stdio.h>

int main(void)
{
    // Card number: 4003600000000014
    // Let's manually trace through Luhn's algorithm
    
    printf("Manual Luhn calculation for 4003600000000014:\n");
    printf("Position (from right): 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15\n");
    printf("Digits:               4  1  0  0  0  0  0  0  0  0  0  6  0  0  3  4\n");
    printf("Multiply by 2 (odd):   -  2  -  0  -  0  -  0  -  0  - 12  -  0  -  8\n");
    printf("After adding digits:   4  2  0  0  0  0  0  0  0  0  0  3  0  0  3  8\n");
    
    int sum = 4 + 2 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 0 + 3 + 0 + 0 + 3 + 8;
    printf("Sum: %d\n", sum);
    printf("Sum %% 10 = %d\n", sum % 10);
    
    if (sum % 10 == 0)
    {
        printf("Valid checksum!\n");
    }
    else
    {
        printf("Invalid checksum.\n");
    }
    
    return 0;
}