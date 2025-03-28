#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string bw = "hit";
	string ew = "cog";
	vector<string> list = {"hot", "dot", "dog", "lot", "log", "cog"};
	Solution *test = new Solution();
	cout << test->ladderLength(bw, ew, list) << endl;
	cout << test->ladderLength2(bw, ew, list) << endl;
	cout << test->ladderLength3(bw, ew, list) << endl;
	return 0;
}
