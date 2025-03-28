#include <vector>
#include <string>

using std::string;
using std::vector;

struct Node
{
	vector<Node *> next;
	int cnt;
	Node()
	    : cnt(-1) {
		next = vector<Node *>(26, nullptr);
	}
};

class Solution {
public:
	Solution() {
	}
	vector<string> findAllConcatenatedWordsInADict(vector<string> &words);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
