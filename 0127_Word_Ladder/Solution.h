#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	int ladderLength(string beginWord, string endWord, vector<string> &wordList);
	int ladderLength2(string beginWord, string endWord, vector<string> &wordList);
	int ladderLength3(string beginWord, string endWord, vector<string> &wordList);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
