#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<string>> equation = {{"a","b"},{"b","c"}};
	vector<double> values = {2.0,3.0};
	vector<vector<string>> quries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
	Solution* test = new Solution();
	auto result = test->calcEquation(equation, values, quries);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

