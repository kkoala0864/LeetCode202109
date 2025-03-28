#include <vector>
#include <string>
#include <set>

using std::set;
using std::string;
using std::vector;

struct TrieNode
{
	set<string> ps;
	vector<TrieNode *> child;
	TrieNode() {
		child = vector<TrieNode *>(26, nullptr);
	}
};

class Solution {
public:
	Solution() {
	}
	vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
