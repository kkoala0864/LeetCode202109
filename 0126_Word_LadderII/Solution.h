#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
	vector<vector<string>> second(string beginWord, string endWord, vector<string>& wordList);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

