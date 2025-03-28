#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;
using std::unordered_map;

long long Solution::numberOfSubsequences(vector<int> &nums) {
	long long result = 0;
	int size = nums.size();

	unordered_map<double, int> sdr;
	for (int r = nums.size() - 3; r > 3; --r) {
		for (int s = r + 2; s < nums.size(); ++s) {
			double v = (double)nums[s] / (double)nums[r];
			++sdr[v];
		}
	}

	for (int q = 2; q < nums.size() - 3; ++q) {
		for (int p = q - 2; p >= 0; --p) {
			double v = (double)nums[p] / (double)nums[q];
			result += (long long)sdr[v];
		}
		for (int s = q + 4; s < nums.size(); ++s) {
			double v = (double)nums[s] / (double)nums[q + 2];
			--sdr[v];
		}
	}
	return result;
}
