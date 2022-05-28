#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
    Solution* test = new Solution();
    auto result = test->readBinaryWatch(9);
    for (const auto& val : result) {
	cout << val << " ";
    }
    cout << endl;
    return 0;
}

