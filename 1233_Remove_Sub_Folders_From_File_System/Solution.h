#include <data_type.h>
#include <string>
#include <vector>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;

struct Trie {
	unordered_map<string, Trie*> child;
	bool isEnd;
};

class Solution {
    public :
        Solution() {}
	vector<string> removeSubfolders(vector<string>& folder);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

