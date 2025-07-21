#include <data_type.h>

class Trie {
	public:
		unordered_map<string, Trie*> ch;
		bool deleted = false;
};

class Solution {
public:
	Solution() {
	}
	vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
