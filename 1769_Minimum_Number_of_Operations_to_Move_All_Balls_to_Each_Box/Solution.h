#include <data_type.h>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	vector<int> minOperations(string boxes);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

