#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> sequentialDigits(int low, int high);
	vector<int> sequentialDigits2(int low, int high);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
