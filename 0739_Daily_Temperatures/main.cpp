#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {73,74,75,71,69,72,76,73};
	Solution* test = new Solution();
	vector<int> result = test->dailyTemperatures(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	cout << endl;
	result = test->dailyTemperatures2(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

