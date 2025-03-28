#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<vector<string>> groupAnagrams(vector<string> &strs);
	vector<vector<string>> groupAnagrams2(vector<string> &strs);
	vector<vector<string>> groupAnagrams3(vector<string> &strs);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
