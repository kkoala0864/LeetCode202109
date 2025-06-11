#include <Solution.h>

// even size :
//
// count 0 even idx odd idx, 1 even idx odd idx
// if 0 at even idx
//     cnt0even = 0's odd idx + 1's even idx
// if 0 at odd idx
//     cnt0odd = 0's even idx + 1's odd idx
// min(cnt0even, cnt0odd)
//
// odd size :
// 01234
// 10010 => 0 odd 1, even 2 | 1 odd : 1, even : 1
// 00101 => 0 odd 2, even 1 | 1 odd : 0, even : 2
// 01010 => 0 odd 0, even 3 | 1 odd : 2, even : 0
//
// every time rotation curren first char's even cnt keep 1 cnt would not switch to odd cnt
// because first char rotate to tail it still at even idx
int Solution::minFlips(string s) {
	int size = s.size();
	int cnt0 = 0;
	int cnt0Odd = 0;
	int cnt1 = 0;
	int cnt1Odd = 0;
	for (int i = 0 ; i < size ; ++i) {
		if (s[i] == '0') {
			++cnt0;
			if (i & 1) ++cnt0Odd;
		} else {
			++cnt1;
			if (i & 1) ++cnt1Odd;
		}
	}
	int cnt0Even = cnt0 - cnt0Odd;
	int cnt1Even = cnt1 - cnt1Odd;
	int result = min(cnt0Odd + cnt1Even, cnt0Even + cnt1Odd);
	if ((size & 1) == 0) return result;
	for (int i = 0 ; i < size - 1 ; ++i) {
		if (s[i] == '0') {
			cnt0Odd = cnt0Even - 1;
			cnt0Even = cnt0 - cnt0Odd;
			swap(cnt1Odd, cnt1Even);
		} else {
			cnt1Odd = cnt1Even - 1;
			cnt1Even = cnt1 - cnt1Odd;
			swap(cnt0Odd, cnt0Even);
		}
		result = min({result, cnt0Odd + cnt1Even, cnt0Even + cnt1Odd});
	}
	return result;
}
