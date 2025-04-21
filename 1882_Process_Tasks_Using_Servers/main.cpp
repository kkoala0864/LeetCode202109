#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> servers = {3,3,2};
	vector<int> tasks = {1,2,3,2,1,2};
	Solution *test = new Solution();
	auto result = test->assignTasks(servers, tasks);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}
