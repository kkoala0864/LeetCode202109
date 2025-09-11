#include <Solution.h>

vector<int> Solution::sumZero(int n) {
	vector<int> result;
	if (n & 1) result.emplace_back(0);

	for (int i = 1 ; i <= (n / 2) ; ++i) {
		result.emplace_back(i);
		result.emplace_back(i * - 1);
	}
	return result;

}
