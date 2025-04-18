#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> message = {"How is leetcode for everyone", "Leetcode is useful for practice"};
	vector<string> sender = {"Bob", "Charlie"};
	Solution *test = new Solution();
	cout << test->largestWordCount(message, sender) << endl;
	return 0;
}
