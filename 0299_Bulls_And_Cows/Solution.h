#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	string getHint(string secret, string guess);
	string getHint2(string secret, string guess);
	string getHint3(string secret, string guess);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
