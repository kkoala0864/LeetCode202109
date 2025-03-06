#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 3;
	vector<string> input = {"0:start:0","0:end:0","1:start:1","1:end:1","2:start:2","2:end:2","2:start:3","2:end:3"};
	Solution* test = new Solution();
	auto result = test->exclusiveTime(n, input);
	for (const auto& v : result) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

