#include <vector>
#include <cstdlib>
#include <iostream>

using std::swap;
using std::vector;

class Solution {
public:
	Solution(vector<int> &nums) {
		srand(time(NULL));
		origin = nums;
	}

	vector<int> reset() {
		return origin;
	}

	vector<int> shuffle() {
		auto result = origin;
		for (int i = 0; i < result.size(); ++i) {
			int idx = rand() % result.size();
			swap(result[idx], result[i]);
		}
		return result;
	}

private:
	vector<int> origin;
	vector<vector<int>> pList;
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
