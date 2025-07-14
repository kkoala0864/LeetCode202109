#include <data_type.h>

class GridMaster {
	public:
		bool canMove(char direction);
		int move(char direction);
		bool isTarget();
};

class Solution {
public:
	Solution() {
	}
	int findShortestPath(GridMaster &master);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
