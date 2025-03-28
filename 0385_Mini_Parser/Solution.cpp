#include <Solution.h>
#include <iostream>

using std::stoi;

NestedInteger parseNum(const string &s, int &i) {
	string local("");
	for (; i < s.size(); ++i) {
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-') {
			local.push_back(s[i]);
		} else {
			break;
		}
	}
	--i;
	return local == "" ? NestedInteger() : NestedInteger(stoi(local));
}

NestedInteger parseList(const string &s, int &i) {
	NestedInteger result;
	for (; i < s.size(); ++i) {
		if (s[i] == '[') {
			result.add(parseList(s, ++i));
		} else if (s[i] == ']') {
			break;
		} else if (s[i] == ',') {
			continue;
		} else {
			result.add(parseNum(s, i));
		}
	}
	return result;
}

NestedInteger Solution::deserialize(string s) {
	int i = 0;
	if (s[0] == '[') {
		return parseList(s, ++i);
	} else {
		return parseNum(s, i);
	}
}
