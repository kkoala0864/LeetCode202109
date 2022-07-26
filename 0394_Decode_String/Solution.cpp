#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

string recur(string s, int& i) {
	string local("");
	string num("");

	for (; i < s.size() ; ++i) {
		if (s[i] == ']') {
			return local;
		} else if (s[i] == '[') {
			string substr = recur(s, ++i);
			int n = num == "" ? 1 : stoi(num);
			num = "";
			while (n--) local += substr;
		} else if (s[i] >= 'a' && s[i] <= 'z') {
			local.push_back(s[i]);
		} else {
			num.push_back(s[i]);
		}
	}
	return local;
}

string Solution::decodeString(string s) {
	int i = 0;
	return recur(s, i);
}
