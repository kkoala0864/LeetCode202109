#include <vector>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<string> expand(string s);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
