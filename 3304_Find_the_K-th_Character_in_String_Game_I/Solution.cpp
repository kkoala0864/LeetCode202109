#include <Solution.h>

// abbcbccd
// 0 1 12 1223
// 12232334
char Solution::kthCharacter(int k) {
	--k;
	if (k == 0) return 'a';

	int v = 0;
	for (int i = 0 ; i < 32 ; ++i) {
		if (k & (1 << i)) ++v;
	}
	return (v % 26) + 'a';
}
