#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	int shortestDistance(vector<string>& wordsDict, string word1, string word2);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

