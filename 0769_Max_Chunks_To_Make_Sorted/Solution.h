#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int maxChunksToSorted(vector<int> &arr);
	int maxChunksToSortedStack(vector<int> &arr);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
