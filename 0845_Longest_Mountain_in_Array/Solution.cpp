#include <Solution.h>

int Solution::longestMountain(vector<int>& arr) {
	int up = 0, down = 0;
	int result = 0;
	for (int i = 1 ; i < arr.size() ; ++i) {
		if (arr[i] > arr[i-1]) {
			if (down > 0) {
				if (up > 0 && down > 0) {
					result = max(result, up + down + 1);
				}
				up = 1;
				down = 0;
			} else {
				++up;
			}
		} else if (arr[i] < arr[i-1]) {
			++down;
		} else {
			if (up > 0 && down > 0) {
				result = max(result, up + down + 1);
			}
			up = 0;
			down = 0;
		}
	}
	if (up > 0 && down > 0) {
		result = max(result, up + down + 1);
	}
	return result;
}
