#include <Solution.h>

long long Solution::maximumProfit(vector<int>& prices, int k) {
	int size = prices.size();
	vector<long long> longHold(k, LLONG_MIN / 2), shortHold(k, LLONG_MIN / 2), flat(k + 1, LLONG_MIN / 2);
	flat[0] = 0;
	for (int i = 0 ; i < prices.size() ; ++i) {
		auto nlong = longHold;
		auto nShort = shortHold;
		auto nFlat = flat;
		for (int j = 0 ; j < k ; ++j) {
			nlong[j] = max(longHold[j], flat[j] - prices[i]);
			nShort[j] = max(shortHold[j], flat[j] + prices[i]);
			nFlat[j + 1] = max({flat[j + 1], longHold[j] + prices[i], shortHold[j] - prices[i]});
		}
		swap(longHold, nlong);
		swap(shortHold, nShort);
		swap(flat, nFlat);
	}
	long long result = 0;
	for (const auto& v : flat) {
		result = max(result, v);
	}
	return result;

}
