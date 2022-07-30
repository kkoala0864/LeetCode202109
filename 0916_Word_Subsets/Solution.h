#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
    public :
        Solution() {}
	vector<string> wordSubsets(vector<string>& words1, vector<string>& words2);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

