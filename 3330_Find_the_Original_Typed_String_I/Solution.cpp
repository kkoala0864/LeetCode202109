#include <Solution.h>

int Solution::possibleStringCount(string word) {
	int result = 1;
	for (int i = 1 ; i < word.size() ; ++i) {
		if (word[i] != word[i-1]) continue;
		else ++result;
	}
	return result;
}
