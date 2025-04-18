#include <data_type.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	Solution() {
	}
	string largestWordCount(vector<string> &messages, vector<string> &senders);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
