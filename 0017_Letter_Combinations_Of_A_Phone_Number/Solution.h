#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<string> letterCombinations(string digits);
	vector<string> letterCombinations2(string digits);
	vector<string> letterCombinations3(string digits);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
