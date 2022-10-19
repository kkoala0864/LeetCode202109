#include <vector>
#include <string>

using std::vector;
using std::string;

struct TrieNode {
	vector<TrieNode*> next;
	bool isEnd;
	TrieNode() : isEnd(false) {
		next = vector<TrieNode*>(26, nullptr);
	}
};

class Solution {
    public :
        Solution() {}
	vector<string> topKFrequent(vector<string>& words, int k);
	vector<string> topKFrequent2(vector<string>& words, int k);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

