#include <Solution.h>

int Solution::addMinimum(string word) {
	int result = 0;

	int c = 2;
	for (int i = 0 ; i < word.size() ; ++i) {
		int cur = word[i] - 'a';
		if (((cur - c + 3) % 3) != 1) {
			result += ((cur + 3 - (1 + c)) % 3);
		}
		c = cur;
	}
	int cur = 0;
	if (((cur - c + 3) % 3) != 1) {
		result += ((cur + 3 - (1 + c)) % 3);
	}
	return result;
}
