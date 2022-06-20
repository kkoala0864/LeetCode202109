#include <string>
#include <vector>

using std::string;
using std::vector;

struct TrieNode {
	vector<TrieNode*> child;

	TrieNode() {
		child = vector<TrieNode*>(26, nullptr);
	}
};

class Solution {
    public :
        Solution() {}
	int minimumLengthEncoding(vector<string>& words);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

