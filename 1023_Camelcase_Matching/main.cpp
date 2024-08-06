#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
	string pattern = "FB";
	Solution* test = new Solution();
	auto result = test->camelMatch(input, pattern);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

