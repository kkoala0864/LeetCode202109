#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	TreeNode *one = new TreeNode(2);
	TreeNode *two = new TreeNode(3);
	TreeNode *three = new TreeNode(5);
	TreeNode *four = new TreeNode(8);
	TreeNode *five = new TreeNode(13);
	TreeNode *six = new TreeNode(21);
	TreeNode *seven = new TreeNode(34);
	one->left = two;
	one->right = three;
	two->left = four;
	two->right = five;
	three->left = six;
	three->right = seven;
	Solution* test = new Solution();
	test->reverseOddLevels(one);
	return 0;
}

