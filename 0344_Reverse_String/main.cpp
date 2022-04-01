#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<char> input = {'h','e','l','l','o'};
	Solution* test = new Solution();
	test->reverseString(input);
	for (const auto& it : input) cout << it << " ";
	cout << endl;
	return 0;
}

