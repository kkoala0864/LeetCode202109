#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	int numDecodings(string s);
	int numDecodings2(string s);
	int numDecodings3(string s);
	int numDecodings4(string s);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
