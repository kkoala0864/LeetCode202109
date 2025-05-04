#include <Solution.h>

int Solution::maxProduct(int n) {
	vector<int> value;

	while (n > 0) {
		value.emplace_back(n % 10);
		n /= 10;
	}

	sort(value.rbegin(), value.rend());
	return value[0] * value[1];

}
