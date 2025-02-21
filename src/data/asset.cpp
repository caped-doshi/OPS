#include "../../include/data/asset.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>

// Date class implementation
Date::Date(int year, int month, int day)
    : year(year), month(month), day(day) {}

int Date::getYear() const {
    return year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << year << "-"
        << std::setw(2) << std::setfill('0') << month << "-"
        << std::setw(2) << std::setfill('0') << day;
    return oss.str();
}

// AssetPrice class implementation
AssetPrice::AssetPrice(const Date& date, double price)
    : date(date), price(price) {}

Date AssetPrice::getDate() const {
    return date;
}

double AssetPrice::getPrice() const {
    return price;
}

// Asset class implementation
Asset::Asset(const std::string& symbol)
    : symbol(symbol) {}

void Asset::addPrice(const Date& date, double price) {
    prices.emplace_back(date, price);
}

void Asset::printPrices() const {
    std::cout << "Prices for " << symbol << ":\n";
    for (const auto& assetPrice : prices) {
        std::cout << "Date: " << assetPrice.getDate().toString()
                  << ", Price: " << assetPrice.getPrice() << "\n";
    }
}

std::vector<double> Asset::calculateRelativePrices() const {
    std::vector<double> returns;
    for (size_t i = 1; i < prices.size(); ++i) {
        double prevPrice = prices[i - 1].getPrice();
        double currPrice = prices[i].getPrice();
        double ret = currPrice / prevPrice;
        returns.push_back(ret);
    }
    return returns;
}

void Asset::loadPricesFromCSV(const std::filesystem::path& filepath) {
    std::ifstream file(filepath);
    std::string line;

    if(!file.is_open()) {
        std::cerr << "Error: Could not open file " << filepath << std::endl;
    }
    else {
        std::cout << "Opened file " << filepath << std::endl;
    }

    std::getline(file, line); // skip the first line

    while (std::getline(file, line)) {
        // Parse line string (format: "Date,Open,High,Low,Close,Volume,Dividends,Stock Splits)
        std::stringstream ss(line);
        std::string dateStr,open_str, high, low, close, volume, dividend, split;
        double open;
        std::getline(ss, dateStr, ',');
        std::getline(ss, open_str,',');
        std::getline(ss, high, ',');
        std::getline(ss, low, ',');
        std::getline(ss, close, ',');
        std::getline(ss, volume, ',');
        std::getline(ss, dividend, ',');
        ss >> split;

        open = std::stod(open_str);

        // Parse date string (format: "YYYY-MM-DD hh:mm:ss-hh:mm")
        std::stringstream dateStr_ss(dateStr);
        std::string date;
        std::string time;
        std::string timezone;
        std::getline(dateStr_ss, date, ' ');
        std::getline(dateStr_ss, time, '-');
        dateStr_ss >> timezone;

        std::string  year_str, month_str, day_str;
        int year, month, day;

        std::stringstream dateSS(date);
        std::getline(dateSS,year_str,'-');
        std::getline(dateSS,month_str,'-');
        dateSS >> day_str;

        year = std::stoi(year_str);
        month = std::stoi(month_str);
        day = std::stoi(day_str);

        addPrice(Date(year, month, day), open);
    }
}

