#include <vector>

using std::vector;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode()
	    : val(0), left(nullptr), right(nullptr) {
	}
	TreeNode(int x)
	    : val(x), left(nullptr), right(nullptr) {
	}
	TreeNode(int x, TreeNode *left, TreeNode *right)
	    : val(x), left(left), right(right) {
	}
};

class Solution {
public:
	Solution() {
	}
	vector<int> findFrequentTreeSum(TreeNode *root);
	vector<int> findFrequentTreeSum2(TreeNode *root);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
