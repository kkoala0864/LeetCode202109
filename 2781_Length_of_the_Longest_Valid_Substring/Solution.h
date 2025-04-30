#include <data_type.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Trie {
	public :
		Trie() : child(26, nullptr), isEnd(false) {}
		vector<Trie*> child;
		bool isEnd;
};

class Solution {
public:
	Solution() {
	}
	int longestValidSubstring(string word, vector<string>& forbidden);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
