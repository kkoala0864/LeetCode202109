#include <Solution.h>

// abbcbccd
// 0 1 12 1223
// 12232334

int getCnt(int v) {
	int ret = 0;
	while (v > 0) {
		++ret;
		v &= (v-1);
	}
	return ret;
}
char Solution::kthCharacter(int k) {
	--k;
	if (k == 0) return 'a';

	int v = getCnt(k);
	return (v % 26) + 'a';
}
