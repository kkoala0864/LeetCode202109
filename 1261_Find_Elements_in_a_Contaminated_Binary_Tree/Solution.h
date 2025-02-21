#include <data_type.h>
#include <vector>

using std::vector;

class FindElements {
    public :
	FindElements(TreeNode* root) {
		_root = root;
	}

	bool find(int target) {
		TreeNode* iter = _root;
		vector<int> path;
		while (target > 0) {
			path.emplace_back(target);
			target -= target & 1 ? 1 : 2;
			target = target >> 1;
		}
		while (!path.empty()) {
			if (path.back() & 1) {
				if (iter->left) iter = iter->left;
				else return false;
			} else {
				if (iter->right) iter = iter->right;
				else return false;
			}
			path.pop_back();
		}
		return true;
	}
    private :
	TreeNode* _root;
        virtual ~FindElements() {}
        FindElements& operator=(const FindElements& source);
        FindElements(const FindElements&);
};

