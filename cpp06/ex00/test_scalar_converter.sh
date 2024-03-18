#!/bin/bash

# Function to perform a test
perform_test() {
    input=$1
    expected=$2
    echo "Testing with input: '${input}'"
    output=$(./convert "${input}")
    if [[ "$output" == *"$expected"* ]]; then
        echo -e "PASS: Output matched expected\n"
    else
        echo -e "FAIL: Expected '${expected}', but got '${output}'\n"
    fi
}

# List of tests
echo "Starting tests..."
perform_test "42" "int: 42"
perform_test "42.0f" "float: 42.0f"
perform_test "42.0" "double: 42.0"
perform_test "a" "char: a"
perform_test "-42" "int: -42"
perform_test "+42.0f" "float: 42.0f"
perform_test "-inff" "float: -inff"
perform_test "nan" "double: nan"
perform_test ".42f" "UNKNOWN"  # No digit before the decimal
perform_test "42.f" "UNKNOWN"  # No digit after the decimal
perform_test "4.2.2f" "UNKNOWN"  # Two decimals
perform_test "abc" "UNKNOWN"  # Not a number
perform_test "--42" "UNKNOWN"  # Double sign
perform_test "42..0" "UNKNOWN"  # Double decimal
perform_test "42.ff" "UNKNOWN"  # Double 'f'
perform_test "4a2" "UNKNOWN"  # Alphabetic character in integer
perform_test "4.2a" "UNKNOWN"  # Alphabetic character in double
perform_test "+-42.0" "UNKNOWN"  # Conflicting signs
perform_test "++42" "UNKNOWN"  # Double plus
perform_test ".f" "UNKNOWN"  # Just a decimal and 'f'
perform_test "-.f" "UNKNOWN"  # Negative, only decimal and 'f'
perform_test "42.0g" "UNKNOWN"  # Invalid character after float
perform_test "NaN" "UNKNOWN"  # Case sensitivity test
perform_test "+nanf" "float: +nanf"  # Positive NaN float
perform_test "-42.0f42" "UNKNOWN"  # Numbers after 'f'

echo "All tests completed!"
