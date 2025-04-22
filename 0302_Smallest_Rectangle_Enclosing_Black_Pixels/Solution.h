#include <data_type.h>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	int minArea(vector<vector<char>>& image, int x, int y);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
