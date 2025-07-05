#include <Solution.h>

vector<int> Solution::getStrongest(vector<int>& arr, int k) {
	sort(arr.begin(), arr.end());

	int l = 0, r = arr.size() - 1;

	int midIdx = (arr.size() - 1) / 2;
	int mid = arr[midIdx];

	vector<int> result;

	while (k-- > 0) {
		int lv = abs(arr[l] - mid);
		int rv = abs(arr[r] - mid);

		int v = -1;
		if (lv == rv) {
			v = arr[l] > arr[r] ? arr[l] : arr[r];
		} else {
			v = lv > rv ? arr[l] : arr[r];
		}
		result.emplace_back(v);
		if (v == arr[l]) ++l;
		else --r;
	}
	return result;
}
