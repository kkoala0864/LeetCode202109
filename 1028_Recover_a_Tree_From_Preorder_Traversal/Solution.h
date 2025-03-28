#include <data_type.h>
#include <string>

using std::string;

class Solution {
public:
	Solution() {
	}
	TreeNode *recoverFromPreorder(string traversal);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
