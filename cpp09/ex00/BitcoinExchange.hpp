#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <map>
#include <fstream>
#include <cstdlib>

typedef struct tm t_tm;
bool operator==(const t_tm& lhs, const t_tm& rhs);
struct tmCompare {
    bool operator()(const t_tm& lhs, const t_tm& rhs) const;
};

class BitcoinExchange{
    public:
        BitcoinExchange(const std::string& filename);
        ~BitcoinExchange();
        void processInput(const std::string& filename);
    private:
        BitcoinExchange();
        void readCSV(void);
        bool isLeapYear(int year);
        bool isValidDate(const t_tm& tm);
        bool isFutureDate(const t_tm& tm);
        bool isValidNumber(const std::string& str, double& value);
        bool parseDate(const std::string& dateStr, t_tm& tm);
        void calculateBitcoinValue(const t_tm& tm, double value);
        BitcoinExchange(const BitcoinExchange& old_obj);
        BitcoinExchange& operator=(const BitcoinExchange& old_obj);
        std::map<t_tm, double, tmCompare> _database;
};

#endif