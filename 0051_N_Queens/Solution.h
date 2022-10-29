#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public :
        Solution() {}
	vector<vector<string>> solveNQueens(int n);
	vector<vector<string>> solveNQueens2(int n);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

