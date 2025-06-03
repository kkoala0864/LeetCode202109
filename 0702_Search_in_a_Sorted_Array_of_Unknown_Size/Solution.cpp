#include <Solution.h>

int Solution::search(const ArrayReader& reader, int target) {
	int l = 0, r = INT_MAX;

	int mid = 0;

	while (l < r) {
		mid = l + ((r - l) >> 1);
		if (reader.get(mid) >= target) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return reader.get(l) == target ? l : -1;
}
