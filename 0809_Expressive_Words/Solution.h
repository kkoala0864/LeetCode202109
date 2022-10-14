#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    public :
        Solution() {}
	int expressiveWords(string s, vector<string>& words);
	int expressiveWords2(string s, vector<string>& words);
	int expressiveWords3(string s, vector<string>& words);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

