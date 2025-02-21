#ifndef ASSET_H
#define ASSET_H

#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

// Date class definition
class Date {
public:
    // Constructor
    Date(int year, int month, int day);

    // Getters
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    // Convert date to string (e.g., "2023-10-01")
    std::string toString() const;

private:
    int year;
    int month;
    int day;
};

// AssetPrice class definition
class AssetPrice {
public:
    // Constructor
    AssetPrice(const Date& date, double price);

    // Getters
    Date getDate() const;
    double getPrice() const;

private:
    Date date;  // Date of the price
    double price; // Price of the asset on the given date
};

// Asset class definition
class Asset {
public:
    // Constructor
    Asset(const std::string& symbol);

    // Add a price to the asset
    void addPrice(const Date& date, double price);

    // Print all prices
    void printPrices() const;

    // Calculate daily returns
    std::vector<double> calculateRelativePrices() const;

    // Load prices from a CSV file
    void loadPricesFromCSV(const std::filesystem::path& filepath);

    // Save prices to a CSV file
    void savePricesToCSV(const std::filesystem::path& filepath) const;

private:
    std::string symbol;               // Symbol of the asset (e.g., "TSLA")
    std::vector<AssetPrice> prices;   // Vector of AssetPrice objects
};

#endif //ASSET_H
