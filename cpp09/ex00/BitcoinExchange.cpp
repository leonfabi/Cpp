#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

bool BitcoinExchange::parseDate(const std::string& dateStr, t_tm& tm){
    std::istringstream ss(dateStr);
    char dash;
    if (ss >> tm.tm_year >> dash >> tm.tm_mon >> dash >> tm.tm_mday && dash == '-') {
        tm.tm_year -= 1900;
        tm.tm_mon--;
        return true;
    }
    return false;
}

void BitcoinExchange::readCSV(void) {
    std::ifstream file("wrong_data.csv");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string dateStr, valueStr;
        std::getline(ss, dateStr, ',');
        std::getline(ss, valueStr);
        t_tm tm;
        if (parseDate(dateStr, tm)) {
            double value = std::atof(valueStr.c_str());
            _database[tm] = value;
        } else {
            std::cerr << "Error on line: " << line << "\n";
        }
    }
}