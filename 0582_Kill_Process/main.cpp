#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> pid = {1,3,10,5};
	vector<int> ppid = {3,0,5,3};
	Solution* test = new Solution();
	auto result = test->killProcess(pid, ppid, 5);
	for (const auto& v : result) cout << v << " ";
	cout << endl;
	return 0;
}

