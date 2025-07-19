#include <data_type.h>

class Trie {
	public :
		Trie() {
			children = vector<Trie*>(27, nullptr);
			isEnd = false;
		}
		vector<Trie*> children;
		bool isEnd;
};

class Solution {
public:
	Solution() {
	}
	vector<string> removeSubfolders(vector<string> &folder);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
