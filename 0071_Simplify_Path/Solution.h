#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	string simplifyPath(string path);
	string simplifyPath2(string path);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
