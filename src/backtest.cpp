#include <iostream>
#include <filesystem>
#include "../include/data/asset.h"

int main() {

    // process nasdaq data into vector of assets
    std::filesystem::path current_path = std::filesystem::current_path();
    std::filesystem::path data_dir_path = current_path.append("data");
    std::filesystem::path nasdaq_dir_path = data_dir_path.append("nasdaq100");
    std::string data_file = "AAPL_5y.csv";
    std::filesystem::path data_path = data_dir_path.append(data_file);

    Asset asset("AAPL");
    asset.loadPricesFromCSV(data_path);
    std::vector<double> returns = asset.calculateRelativePrices();
    for (int i = 1; i < returns.size(); i++) {
        std::cout << "day " << i << " : " << returns[i] << std::endl;
    }

    // run meta-algorithm for ops


    return 0;
}
