#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	int countValidWords(string sentence);
	int countValidWords2(string sentence);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
