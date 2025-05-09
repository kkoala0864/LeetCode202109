#include <Solution.h>


// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 (1, 3, 5, 7, 9, 11, 13, 15) diff : 2
//   2   4   6   8   10    12    14    16 (4, 8, 12, 16)              diff : 4
//   2       6       10          14       (2, 10)                     diff : 8
//           6                   14       (14)                        diff : 16
//           6
int Solution::lastRemaining(int n) {
	int left = true;
	int diff = 1;
	int remain = n;
	int head = 1;

	while (remain > 1) {
		if (left || (remain & 1)) {
			head += diff;
		}
		diff <<= 1;
		remain >>= 1;
		left = !left;
	}
	return head;
}
