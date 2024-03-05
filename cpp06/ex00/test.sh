#!/bin/bash
# Array of arguments to test
args=("c" "a" "0" "-42" "42" "0.0f" "-4.2f" "4.2f" "0.0" "-4.2" "4.2" "-inff" "+inff" "nanf" "-inf" "+inf" "nan") # Replace arg1, arg2, arg3 with your arguments

# Loop through the arguments and run the program with each one
make re; make clean
for arg in "${args[@]}"; do
  echo "Running with argument: $arg" >> output.txt
  ./convert "$arg" >> output.txt
  echo "" >> output.txt
done
