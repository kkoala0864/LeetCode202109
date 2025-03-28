#include <vector>

using std::vector;

struct Trie
{
	vector<Trie *> child;
	bool End;
	Trie()
	    : End(false) {
		child = vector<Trie *>(5, nullptr);
	}
};

class Solution {
public:
	Solution() {
	}
	int numDistinctIslands(vector<vector<int>> &grid);
	int numDistinctIslandsTrie(vector<vector<int>> &grid);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
