#include <data_type.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	Solution() {
	}
	long long calculateScore(vector<string>& instructions, vector<int>& values);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
