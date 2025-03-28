#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> findPermutation(string s);
	vector<int> findPermutation2(string s);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
