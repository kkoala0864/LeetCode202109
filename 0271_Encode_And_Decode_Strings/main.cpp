#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> input = {"63/Rc","h","BmI3FS~J9#vmk","7uBZ?7*/","24h+X","O "};
	Solution* test = new Solution();
	string enc = test->encode(input);
	cout << "enc: " << enc << endl;
	vector<string> result = test->decode(enc);
	for (const auto& iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}

