#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	vector<int> getRow(int rowIndex);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

