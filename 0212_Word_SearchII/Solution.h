#include <vector>
#include <string>

using std::vector;
using std::string;

struct Trie {
	string word;
	vector<Trie*> next;
	Trie() {
		next = vector<Trie*>(26, nullptr);
		word = "";
	}
};

class Solution {
    public :
        Solution() {}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
	vector<string> findWords2(vector<vector<char>>& board, vector<string>& words);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

