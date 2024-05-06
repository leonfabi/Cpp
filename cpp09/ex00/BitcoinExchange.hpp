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
struct tmCompare {
    bool operator()(const t_tm& lhs, const t_tm& rhs) const {
        if (lhs.tm_year != rhs.tm_year)
            return lhs.tm_year < rhs.tm_year;
        if (lhs.tm_mon != rhs.tm_mon)
            return lhs.tm_mon < rhs.tm_mon;
        return lhs.tm_mday < rhs.tm_mday;
    }
};

class BitcoinExchange{
    public:
        BitcoinExchange();
        void readCSV(void);
        ~BitcoinExchange();
    private:
        bool parseDate(const std::string& dateStr, t_tm& tm);
        BitcoinExchange(const BitcoinExchange& old_obj);
        BitcoinExchange& operator=(const BitcoinExchange& old_obj);
        std::map<t_tm, double, tmCompare> _database;
};

#endif