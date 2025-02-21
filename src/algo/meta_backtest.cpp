#include "../../include/algo/meta_backtest.h"
#include <iostream>
#include <vector>

double meta_alg(const std::vector<std::vector<AssetPrice>>& assets, int T){
	d = assets.size();
    std::cout << "d = " << d << std::endl;

    vector<double> w(d,1/d);
    std::cout << "w(0) = " << w[0] << std::endl;

    for (int t = 1; t <= T; t++){
		std::cout << "t = " << t << std::endl;
        
    }


	return 1;
}
