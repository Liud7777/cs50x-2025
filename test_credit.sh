#!/bin/bash

# Compile the program
make credit

echo "Testing Credit Card Validation Program"
echo "======================================"

# Test cases with expected outputs
echo "Testing AMEX card (378282246310005):"
echo "378282246310005" | ./credit

echo -e "\nTesting VISA card (4003600000000014):"
echo "4003600000000014" | ./credit

echo -e "\nTesting MasterCard (5555555555554444):"
echo "5555555555554444" | ./credit

echo -e "\nTesting invalid card (1234567890):"
echo "1234567890" | ./credit

echo -e "\nTesting another VISA (4111111111111111):"
echo "4111111111111111" | ./credit

echo -e "\nAll tests completed!"