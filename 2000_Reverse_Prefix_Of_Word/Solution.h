#include <data_type.h>
#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	string reversePrefix(string word, char ch);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
