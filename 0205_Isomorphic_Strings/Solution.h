#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	bool isIsomorphic(string s, string t);
	bool isIsomorphic2(string s, string t);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
