#include <data_type.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	bool matchReplacement(string s, string sub, vector<vector<char>>& mappings);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
