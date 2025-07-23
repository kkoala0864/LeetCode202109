#include <data_type.h>

class Trie {
	public :
		Trie() {
			ch = vector<Trie*>(26, nullptr);
			cnt = 0;
		}
		vector<Trie*> ch;
		int cnt;
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
