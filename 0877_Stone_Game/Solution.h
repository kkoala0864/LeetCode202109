#include <data_type.h>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	bool stoneGame(vector<int>& piles);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
