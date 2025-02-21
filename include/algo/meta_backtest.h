#ifndef META_BACKTEST_H
#define META_BACKTEST_H

#include <vector>

class AssetPrice;

double meta_alg(const std::vector<std::vector<AssetPrice>>& assets, int T);

#endif //META_BACKTEST_H
