#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	int minEatingSpeed(vector<int> &piles, int h);
	int minEatingSpeed2(vector<int> &piles, int h);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
