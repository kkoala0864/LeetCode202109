#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> input = {0,0,1,1,1,1,2,3,3};
	Solution* test = new Solution();
	int result = test->removeDuplicates2(input);
	cout << result << endl;
	for (int i = 0 ; i < result ; ++i) {
		cout << input[i] << " " ;
	}
	cout << endl;
	return 0;
}

