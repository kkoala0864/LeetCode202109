#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> timeTaken(vector<int>& arrival, vector<int>& state);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

