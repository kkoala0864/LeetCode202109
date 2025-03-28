#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int search(vector<int> &nums, int target);
	int search2(vector<int> &nums, int target);
	int search3(vector<int> &nums, int target);
	int search4(vector<int> &nums, int target);
	int search5(vector<int> &nums, int target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
