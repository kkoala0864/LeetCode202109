#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	bool isOneEditDistance(string s, string t);
	bool isOneEditDistance2(string s, string t);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
