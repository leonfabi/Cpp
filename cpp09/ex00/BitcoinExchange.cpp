#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::~BitcoinExchange() {
}

void BitcoinExchange::readCSV(void) {
    std::ifstream file("data.csv");
    if (!file.is_open()) 
        throw std::runtime_error("Could not open file");
    std::string line;
    if (!std::getline(file, line) || line != "date,exchange_rate")
        throw std::runtime_error("The first line of the CSV does not match expected header 'date,exchange_rate'.");
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
            std::cerr << "Value not valid, skip: " << line << "\n";
        }
    }
}

bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool BitcoinExchange::isFutureDate(const t_tm& tm) {
    t_tm now;
    std::time_t t = std::time(NULL);
    std::tm* now_tm = std::localtime(&t);
    now.tm_year = now_tm->tm_year;
    now.tm_mon = now_tm->tm_mon;
    now.tm_mday = now_tm->tm_mday;
    return tmCompare()(now, tm);
}

bool BitcoinExchange::isValidDate(const t_tm& tm) {
    if (isFutureDate(tm))
        return false;
    if (tm.tm_mon < 0 || tm.tm_mon > 11)
        return false;
    if (tm.tm_mday < 1)
        return false;
    if (tm.tm_mon == 1) {
        if (isLeapYear(tm.tm_year + 1900))
            return tm.tm_mday <= 29;
        return tm.tm_mday <= 28;
    }
    if (tm.tm_mon == 3 || tm.tm_mon == 5 || tm.tm_mon == 8 || tm.tm_mon == 10)
        return tm.tm_mday <= 30;
    return tm.tm_mday <= 31;
}

bool BitcoinExchange::parseDate(const std::string& dateStr, t_tm& tm){
    std::istringstream ss(dateStr);
    char dash;
    if (ss >> tm.tm_year >> dash >> tm.tm_mon >> dash >> tm.tm_mday && dash == '-') {
        tm.tm_year -= 1900;
        tm.tm_mon--;
        if (isValidDate(tm))
            return true;
    }
    return false;
}