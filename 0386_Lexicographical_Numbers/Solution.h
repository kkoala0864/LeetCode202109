#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> lexicalOrder(int n);
	vector<int> lexicalOrder2(int n);
	vector<int> lexicalOrder3(int n);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
