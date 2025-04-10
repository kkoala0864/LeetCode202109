#include <Solution.h>
#include <iostream>

int Solution::maxConsecutiveAnswers(string answerKey, int k) {
	int result = 0;
	int l = 0;
	int tCnt = 0, fCnt = 0;

	for (int i = 0 ; i < answerKey.size() ; ++i) {
		if (answerKey[i] == 'T') ++tCnt;
		else ++fCnt;

		while (l < i && fCnt > k) {
			if (answerKey[l] == 'T') --tCnt;
			else --fCnt;
			++l;
		}

		result = max(result, i - l + 1);
	}

	tCnt = 0;
	fCnt = 0;
	l = 0;
	for (int i = 0 ; i < answerKey.size() ; ++i) {
		if (answerKey[i] == 'T') ++tCnt;
		else ++fCnt;
		while (l < i && tCnt > k) {
			if (answerKey[l] == 'T') --tCnt;
			else --fCnt;
			++l;
		}
		result = max(result, i - l + 1);
	}
	return result;
}
