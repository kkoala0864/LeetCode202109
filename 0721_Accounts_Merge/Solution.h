#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts);
	vector<vector<string>> accountsMerge2(vector<vector<string>>& accounts);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

