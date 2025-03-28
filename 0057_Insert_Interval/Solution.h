#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval);
	vector<vector<int>> insert2(vector<vector<int>> &intervals, vector<int> &newInterval);
	vector<vector<int>> insert3(vector<vector<int>> &intervals, vector<int> &newInterval);
	vector<vector<int>> insert4(vector<vector<int>> &intervals, vector<int> &newInterval);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
