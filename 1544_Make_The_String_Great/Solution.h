#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	string makeGood(string s);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
