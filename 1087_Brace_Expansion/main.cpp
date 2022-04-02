#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "{a,b}c{d,e}f";
	Solution* test = new Solution();
	vector<string> result = test->expand(input);
	for (const auto& it : result) {
		cout << it << " ";
	}
	cout << endl;
	return 0;
}

