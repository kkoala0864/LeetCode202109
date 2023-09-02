#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string s = "dwmodizxvvbosxxw";
	vector<string> dic = {"ox","lb","diz","gu","v","ksv","o","nuq","r","txhe","e","wmo","cehy","tskz","ds","kzbu"};
	Solution* test = new Solution();
	cout << test->minExtraChar(s, dic) << endl;
	return 0;
}

