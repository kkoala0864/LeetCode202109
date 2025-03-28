#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	int minMutation(string start, string end, vector<string> &bank);
	int minMutation2(string start, string end, vector<string> &bank);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
