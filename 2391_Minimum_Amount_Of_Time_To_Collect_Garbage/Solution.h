#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	int garbageCollection(vector<string>& garbage, vector<int>& travel);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

