#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"ab", "cde", "f"};
	Solution* test = new Solution();
	cout << test->wordsTyping(input, 3, 5) << endl;
	return 0;
}

