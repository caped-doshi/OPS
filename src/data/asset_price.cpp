#include "../../include/data/asset_price.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>

bool isNumber(const std::string& str) {
    if (str.empty()) return false;
    char* end = nullptr;
    std::strtod(str.c_str(), &end);
    return end != str.c_str() && *end == '\0';
}

std::vector<AssetPrice> readCSV(const std::filesystem::path& filepath){
    std::vector<AssetPrice> asset_prices;
    std::ifstream file(filepath);

    if(!file.is_open()) {
        std::cerr << "Error: Could not open file " << filepath << std::endl;
    }
    else {
        std::cout << "Opened file " << filepath << std::endl;
    }

    std::string line;
    std::getline(file, line);

    std::cout << line << std::endl;

    while (std::getline(file,line)){

        std::stringstream ss(line);
        std::string token;
        AssetPrice asset_price;

        // Read date
        std::getline(ss,token,',');
        asset_price.date = token;

        // Read open price
        std::getline(ss, token, ',');
        if (!isNumber(token)){
            std::cerr << "Error: Could not parse line." << std::endl;
            return asset_prices;
        }
        asset_price.open = std::stod(token);

        // Read high price
        std::getline(ss, token, ',');
        asset_price.high = std::stod(token);

        // Read low price
        std::getline(ss, token, ',');
        asset_price.low = std::stod(token);

        // Read close price
        std::getline(ss, token, ',');
        asset_price.close = std::stod(token);

        // Read volume
        std::getline(ss, token, ',');
        asset_price.volume = std::stol(token);

        asset_prices.push_back(asset_price);
    }
    file.close();
    return asset_prices;
}