#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> preorder = {1,2};
	vector<int> inorder = {2,1};
	Solution* test = new Solution();
	test->buildTree(preorder, inorder);
	test->buildTree2(preorder, inorder);
	test->buildTree3(preorder, inorder);
	return 0;
}

