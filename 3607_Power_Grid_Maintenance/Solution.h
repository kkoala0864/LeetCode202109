#include <data_type.h>

class Solution {
public:
	Solution() {
	}
	vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
