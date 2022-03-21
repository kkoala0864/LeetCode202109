#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "ababcbacadefegdehijhklij";
	Solution* test = new Solution();
	vector<int> result = test->partitionLabels(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->partitionLabels3(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

