#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	int maxProduct(vector<string> &words);
	int maxProduct2(vector<string> &words);
	int maxProduct3(vector<string> &words);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
