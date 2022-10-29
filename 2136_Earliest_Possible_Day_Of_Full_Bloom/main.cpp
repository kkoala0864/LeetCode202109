#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<int> plantTime = {1};
	vector<int> growTime = {1};
	Solution* test = new Solution();
	cout << test->earliestFullBloom(plantTime, growTime) << endl;
	return 0;
}

