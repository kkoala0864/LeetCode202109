#include <data_type.h>
#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	bool canChange(string start, string target);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
