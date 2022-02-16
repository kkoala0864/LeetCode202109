#include <vector>
#include <string>

using std::string;
using std::vector;

class Node {
	public:
		int wordEnd;
		vector<Node*> next;
		vector<int> RPList;
		Node() {
			wordEnd = -1;
			next = vector<Node*>(26, nullptr);
		}
};

class Solution {
    public :
        Solution() {}
	vector<vector<int>> palindromePairs(vector<string>& words);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

