#include <data_type.h>
#include <vector>

using namespace std;

class Solution {
    public :
        Solution() {}
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root);
    private :
        virtual ~Solution() {}
        Solution& operator=(const Solution& source);
        Solution(const Solution&);
};

