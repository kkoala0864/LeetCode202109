#include <vector>

using std::vector;

struct TrieNode
{
	vector<TrieNode *> next;
	TrieNode() {
		next = vector<TrieNode *>(2, nullptr);
	}
};

class Solution {
public:
	Solution() {
	}
	int findMaximumXOR(vector<int> &nums);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
