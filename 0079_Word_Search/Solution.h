#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	bool exist(vector<vector<char>> &board, string word);
	bool exist2(vector<vector<char>> &board, string word);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
