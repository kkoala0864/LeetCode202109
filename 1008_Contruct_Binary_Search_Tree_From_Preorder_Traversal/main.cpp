#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {8,5,1,7,10,12};
	Solution* test = new Solution();
	TreeNode* head = test->bstFromPreorder(input);
	head = test->bstFromPreorder2(input);
	return 0;
}

