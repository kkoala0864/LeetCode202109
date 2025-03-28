#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"practice", "makes", "perfect", "coding", "makes"};
	Solution *test = new Solution();
	cout << test->shortestWordDistance(input, "makes", "makes") << endl;
	cout << test->shortestWordDistance2(input, "makes", "makes") << endl;
	return 0;
}
