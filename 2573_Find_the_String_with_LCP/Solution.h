#include <data_type.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	Solution() {
	}

	string findTheString(vector<vector<int>>& lcp);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
