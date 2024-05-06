#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./ex00 filename.csv\n";
        return 1;
    }

    try {
        BitcoinExchange btc;
        // btc.readCSV();
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }
}