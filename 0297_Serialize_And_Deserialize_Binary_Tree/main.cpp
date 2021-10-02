#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "1,2,3,null,null,4,5";
	Solution* test = new Solution();
	TreeNode* head = test->deserialize(input);
	cout << test->serialize(head) << endl;
	return 0;
}

