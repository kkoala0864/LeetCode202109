#include <data_type.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Node
{
	vector<Node *> child;
	Node() {
		child = vector<Node *>(26, nullptr);
	}
};

class Solution {
public:
	Solution() {
	}
	string longestWord(vector<string> &words);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
