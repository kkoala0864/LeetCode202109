#include <data_type.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	string evaluate(string s, vector<vector<string>>& knowledge);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
