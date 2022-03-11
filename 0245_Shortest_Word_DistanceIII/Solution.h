#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    public :
        Solution() {}
	int shortestWordDistance(vector<string>& wordsDict, string word1, string word2);
	int shortestWordDistance2(vector<string>& wordsDict, string word1, string word2);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

