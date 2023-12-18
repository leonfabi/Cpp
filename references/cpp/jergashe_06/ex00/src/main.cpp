#include "../include/ScalarConverter.hpp"

int main(int argc, char **argv) {

  if (argc != 2) {
    std::cout << RED_TXT << "Wrong Number Of Arguments Passed" << DEFAULT_TXT
              << std::endl;
    return 0;
  }

  try {
    std::string input(argv[1]);
    ScalarConverter::convert(input);
  } catch (const std::exception &e) {
    std::cout << RED_TXT << "Error " << e.what() << DEFAULT_TXT << std::endl;
  }

  return 0;
}