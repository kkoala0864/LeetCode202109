#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"cat","bt","hat","tree"};
	Solution* test = new Solution();
	cout << test->countCharacters(input, "atach") << endl;
	return 0;
}

