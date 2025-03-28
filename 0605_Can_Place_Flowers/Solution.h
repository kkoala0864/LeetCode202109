#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	bool canPlaceFlowers(vector<int> &flowerbed, int n);
	bool canPlaceFlowers2(vector<int> &flowerbed, int n);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
