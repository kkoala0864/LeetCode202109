#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "eccbbbbdec";
	Solution* test = new Solution();
	vector<int> result = test->partitionLabels(input);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

