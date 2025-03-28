#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
	Solution() {
	}
	bool areSentencesSimilar(vector<string> &sentence1, vector<string> &sentence2, vector<vector<string>> &similarPairs);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
