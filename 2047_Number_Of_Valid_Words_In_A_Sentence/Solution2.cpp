#include <Solution.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

bool check(const string &w) {
	int pruncCnt = 0;
	int hyperCnt = 0;
	for (int i = 0; i < w.size(); ++i) {
		if (w[i] >= '0' && w[i] <= '9')
			return false;
		else if (w[i] == '!' || w[i] == '.' || w[i] == ',') {
			++pruncCnt;
			if (pruncCnt > 1)
				return false;
			if (i != w.size() - 1)
				return false;
		} else if (w[i] == '-') {
			++hyperCnt;
			if (hyperCnt > 1)
				return false;
			if (i == w.size() - 1 || i == 0)
				return false;
			if (w[i - 1] < 'a' || w[i - 1] > 'z' || w[i + 1] < 'a' || w[i + 1] > 'z')
				return false;
		}
	}
	return true;
}

int Solution::countValidWords2(string sentence) {
	vector<string> words;
	for (int i = 0; i < sentence.size(); ++i) {
		while (i < sentence.size() && sentence[i] == ' ')
			++i;
		if (i == sentence.size())
			break;
		int start = i;
		while (i < sentence.size() && sentence[i] != ' ')
			++i;
		words.push_back(sentence.substr(start, i - start));
	}

	int result = 0;
	for (const auto &w : words) {
		if (check(w))
			++result;
	}
	return result;
}
