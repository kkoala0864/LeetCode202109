#include <Solution.h>
#include <iostream>
#include <string>

using std::string;
using std::to_string;

int Solution::maximum69Number(int num) {
	string numStr = to_string(num);
	for (int i = 0 ; i < numStr.size() ; ++i) {
		if (numStr[i] == '6') {
			numStr[i] = '9';
			break;
		}
	}
	return stoi(numStr);
}
