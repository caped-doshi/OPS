#ifndef ASSET_PRICE_H
#define ASSET_PRICE_H

#include <string>
#include <vector>
#include <filesystem>

struct AssetPrice {
    std::string date;
    double open;
    double high;
    double low;
    double close;
    long volume;
};

// Read CSV file and return vector of AssetPrice objects
std::vector<AssetPrice> readCSV(const std::filesystem::path& filepath);

#endif