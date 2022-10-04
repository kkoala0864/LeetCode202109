#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> input = {{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,3}};
	Solution* test = new Solution();
	auto result = test->Tarjan(6, input);

	for (const auto& vec : result) {
		for (const auto& val : vec) {
			cout << val << " ";
		}
		cout << endl;
	}
	result = test->criticalConnections2(6, input);

	for (const auto& vec : result) {
		for (const auto& val : vec) {
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}

