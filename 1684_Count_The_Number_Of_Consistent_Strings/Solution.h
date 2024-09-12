#include <data_type.h>
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
    public :
        Solution() {}
	int countConsistentStrings(string allowed, vector<string>& words);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

