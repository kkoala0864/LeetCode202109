#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder = {9,3,15,20,7};
	Solution* test = new Solution();
	test->buildTree(preorder, inorder);
	return 0;
}

