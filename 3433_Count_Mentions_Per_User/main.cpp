#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	int n = 3;
	vector<vector<string>> input = {{"MESSAGE","5","HERE"},{"OFFLINE","10","0"},{"MESSAGE","15","HERE"},{"OFFLINE","18","2"},{"MESSAGE","20","HERE"}};
	Solution* test = new Solution();
	auto result = test->countMentions(n, input);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

