#include <vector>

using std::vector;

class Solution {
    public :
        Solution() {}
	void setZeroes(vector<vector<int>>& matrix);
	void setZeroes2(vector<vector<int>>& matrix);
	void setZeroes3(vector<vector<int>>& matrix);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

