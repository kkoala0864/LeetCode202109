#include <data_type.h>
#include <vector>

using namespace std;

class TrieNode {
	public:
		TrieNode() : children(2, nullptr), val(-1) {};
		vector<TrieNode*> children;
		int val;
};


class Solution {
public:
	Solution() {
	}
	vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
