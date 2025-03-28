#include <data_type.h>
#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	string answerString(string word, int numFriends);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
