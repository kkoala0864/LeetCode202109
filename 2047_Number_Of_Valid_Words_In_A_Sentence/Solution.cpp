#include <Solution.h>
#include <iostream>
#include <vector>

using std::vector;

bool isLowerLetter(char ch) {
	return ch >= 'a' && ch <= 'z';
}

void checkStr(const string &str, int &cnt) {
	int iter = 0;
	int punCnt = 0;
	int hyperCnt = 0;
	while (iter < str.size()) {
		if (str[iter] >= '0' && str[iter] <= '9')
			return;
		else if (str[iter] == '-') {
			if (iter == 0 || iter == str.size() - 1)
				return;
			if (isLowerLetter(str[iter - 1]) && isLowerLetter(str[iter + 1])) {
				++hyperCnt;
				if (hyperCnt > 1)
					return;
			} else
				return;
		} else if (str[iter] == '!' || str[iter] == '.' || str[iter] == ',') {
			if (iter != (str.size() - 1))
				return;
			++punCnt;
			if (punCnt > 1)
				return;
		}
		++iter;
	}
	++cnt;
}

int Solution::countValidWords(string sentence) {
	int cnt = 0;
	int iter = 0;
	while (iter < sentence.size() && sentence[iter] == ' ')
		++iter;
	int start = iter;
	while (iter < sentence.size()) {
		while (iter < sentence.size() && sentence[iter] != ' ')
			++iter;
		checkStr(sentence.substr(start, iter - start), cnt);
		while (iter < sentence.size() && sentence[iter] == ' ')
			++iter;
		start = iter;
	}
	if (start < sentence.size())
		checkStr(sentence.substr(start), cnt);
	return cnt;
}
