#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"cat","rye","aye","cud","cat","old","fop","bra"};
	Solution* test = new Solution();
	vector<vector<string>> result = test->groupAnagrams(input);
	for (const auto& group : result) {
		for (const auto& str : group) {
			cout << str << " ";
		}
		cout << endl;
	}
	return 0;
}

