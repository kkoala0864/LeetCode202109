#include <data_type.h>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
