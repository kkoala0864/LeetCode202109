#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"practice", "makes", "perfect", "coding", "makes"};
	Solution* test = new Solution();
	cout << test->shortestDistance(input, "makes", "coding") << endl;
    return 0;
}

