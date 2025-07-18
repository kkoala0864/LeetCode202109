#include <data_type.h>

class Trie {
	public:
	Trie() {
		children = vector<Trie*>(26, nullptr);
	}
	vector<Trie*> children;
	vector<string> preStr;
};

class Solution {
public:
	Solution() {
	}
	vector<vector<string>> wordSquares(vector<string>& words);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
