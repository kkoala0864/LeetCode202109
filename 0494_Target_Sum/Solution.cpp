#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int Solution::findTargetSumWays(vector<int>& nums, int target) {
	int sum = 0;
	for (const auto& v : nums) sum += v;
	vector<int> last(2 * sum + 1, 0), cur(2 * sum + 1, 0);

	int offset = sum;

	last[sum] = 1;

	for (const auto& v : nums) {
		for (int i = 0 ; i < last.size() ; ++i) {
			if (last[i] > 0) {
				cur[i + v] += last[i];
				cur[i - v] += last[i];
			}
		}
		last = cur;
		fill(cur.begin(), cur.end(), 0);
	}

	return (target + offset) >= last.size() ? 0 : last[target + offset];
}
