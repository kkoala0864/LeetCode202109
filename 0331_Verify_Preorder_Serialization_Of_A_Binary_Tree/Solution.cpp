#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

bool traverse(const string& s, int& index) {
	if (index >= s.size()) return false;
	int iter = index;
	while (index < s.size() && s[index] != ',') ++index;
	string val = s.substr(iter, index - iter);
	++index;
	if (val == "#") return true;
	return traverse(s, index) && traverse(s, index);
}

bool Solution::isValidSerialization(string preorder) {
	int index = 0;
	return traverse(preorder, index) && index == preorder.size() + 1;
}
