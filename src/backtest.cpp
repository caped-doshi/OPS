#include <iostream>
#include <filesystem>
#include "../include/data/asset_price.h"

int main() {

    std::filesystem::path current_path = std::filesystem::current_path();
    std::filesystem::path data_dir_path = current_path.append("data");
    std::string data_file = "btc-usd-2014-2024.csv";
    std::filesystem::path data_path = data_dir_path.append(data_file);

    std::vector<AssetPrice> asset_prices = readCSV(data_path);
    for (int i = 0; i < 5; i++){
        std::cout << "Date: " << asset_prices[i].date
                  << ", Close: " << asset_prices[i].close << std::endl;
    }

    return 0;
}
