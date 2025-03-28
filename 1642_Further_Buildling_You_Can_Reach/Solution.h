#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int furthestBuilding(vector<int> &heights, int bricks, int ladders);
	int furthestBuilding2(vector<int> &heights, int bricks, int ladders);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
