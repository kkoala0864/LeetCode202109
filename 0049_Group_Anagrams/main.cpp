#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"eat","tea","tan","ate","nat","bat"};
	Solution* test = new Solution();
	vector<vector<string>> result = test->groupAnagrams2(input);
	for (const auto& group : result) {
		for (const auto& str : group) {
			cout << str << " ";
		}
		cout << endl;
	}
	cout << endl;
	result = test->groupAnagrams3(input);
	for (const auto& group : result) {
		for (const auto& str : group) {
			cout << str << " ";
		}
		cout << endl;
	}
	return 0;
}

