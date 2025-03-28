#include <vector>
#include <string>

using std::string;
using std::vector;

struct node
{
	int cnt;
	vector<node *> child;
	node() {
		cnt = 0;
		child = vector<node *>(26);
	}
};

class Solution {
public:
	Solution() {
	}
	vector<string> wordsAbbreviation(vector<string> &words);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
