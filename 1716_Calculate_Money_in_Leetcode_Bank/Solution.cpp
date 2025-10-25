#include <Solution.h>

int Solution::totalMoney(int n) {
	int fullweek = n / 7;
	int restWeek = n % 7;

	int base = ((1 + 7) * 7) / 2;

	int result = base * fullweek;

	if (fullweek > 1) {
		int v = fullweek * (fullweek - 1) / 2;
		result += (v * 7);
	}
	for (int i = 0 ; i < restWeek ; ++i) {
		result += (fullweek + 1 + i);
	}
	return result;
}
