#include <data_type.h>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

