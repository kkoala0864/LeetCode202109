#include <data_type.h>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
    public :
        Solution() {}
	int minOperations(vector<string>& logs);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

