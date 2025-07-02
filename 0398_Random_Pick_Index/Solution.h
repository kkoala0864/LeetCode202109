#include <data_type.h>
#include <cstdlib>
#include <ctime>

class Solution {
public:
	Solution(vector<int>& nums) {
		for (int i = 0 ; i < nums.size() ; ++i) {
			idxs[nums[i]].emplace_back(i);
		}
		srand(time(NULL));
	}

	int pick(int target) {
		int size = idxs[target].size();
		int x = rand();
		return idxs[target][x % size];
	}

private:
	unordered_map<int, vector<int>> idxs;
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
