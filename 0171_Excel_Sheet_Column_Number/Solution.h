#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	int titleToNumber(string columnTitle);
	int titleToNumber2(string columnTitle);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
