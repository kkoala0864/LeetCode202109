#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> topKFrequent(vector<int> &nums, int k);
	vector<int> topKFrequent2(vector<int> &nums, int k);
	vector<int> topKFrequent3(vector<int> &nums, int k);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
