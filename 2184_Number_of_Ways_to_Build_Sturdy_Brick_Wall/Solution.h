#include <data_type.h>

class Solution {
public:
	Solution() {
	}
	int buildWall(int height, int width, vector<int>& bricks);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
