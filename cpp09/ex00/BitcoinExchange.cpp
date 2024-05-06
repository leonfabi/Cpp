#include "BitcoinExchange.hpp"

bool operator==(const t_tm& lhs, const t_tm& rhs) {
    return (lhs.tm_year == rhs.tm_year &&
            lhs.tm_mon == rhs.tm_mon &&
            lhs.tm_mday == rhs.tm_mday);
}

BitcoinExchange::BitcoinExchange(const std::string& filename) {
    readCSV();
    processInput(filename);
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

bool BitcoinExchange::isValidNumber(const std::string& str, double& value) {
    std::istringstream iss(str);
    iss >> value;
    if (!iss || !iss.eof() || value < 0 || value > 1000)
        return false;
    return true;
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) 
        throw std::runtime_error("Could not open file");
    std::string line;
    if (!std::getline(file, line) || line != "date | value")
        throw std::runtime_error("The first line of the input does not match expected header 'date | value'.");
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string dateStr, valueStr;
        if (!std::getline(ss, dateStr, '|') || !std::getline(ss, valueStr)){
            std::cerr << "Error parsing line, skip line: " << line << "\n";
            continue;
        }
        t_tm tm;
        if (!parseDate(dateStr, tm)) {
            std::cerr << "Invalid date found, skip line: " << line << "\n";
            continue;
        }

        double value = 0;
        if (!isValidNumber(valueStr, value)) {
            std::cerr << "Value out of range skip line: " << line << "\n";
            continue;
        }
        calculateBitcoinValue(tm, value);
    }
}

void BitcoinExchange::calculateBitcoinValue(const t_tm& tm, double value) {
    std::map<t_tm, double, tmCompare>::iterator it = _database.lower_bound(tm);
    if (it == _database.end() || !(it->first == tm)) {
        if (it == _database.begin()) {
            std::cerr << "No previous exchange rate found for date: " << "\n";
            return;
        }
        --it;
    }
    double exchangeRate = it->second;
    double bitcoinValue = value * exchangeRate;
    char dateStr[11];
    strftime(dateStr, sizeof(dateStr), "%Y-%m-%d", &tm);
    std::cout << dateStr << " => " << value << " = " << bitcoinValue << "\n";
}