#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	int calculateTime(string keyboard, string word);
	int calculateTime2(string keyboard, string word);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
