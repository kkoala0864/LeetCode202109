#include <data_type.h>
#include <vector>

using std::vector;

class Solution {
public:
	Solution() {
	}
	vector<int> distanceK(TreeNode *root, TreeNode *target, int k);
	vector<int> distanceK2(TreeNode *root, TreeNode *target, int k);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
