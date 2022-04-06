#include <Solution.h>
#include <iostream>
#include <unordered_map>

using std::unordered_map;

int getComb(int total, int cnt) {
	if (total == cnt) return 1;
	if (cnt == 1) return total;
	long long up = 1, down = 1;
	long long base = 1e9 + 7;
	for (int i = cnt ; i >= 1 ; --i) {
		up *= total--;
		down *= i;
	}
	return (up / down) % base;
}

int Solution::threeSumMulti(vector<int>& arr, int target) {
	vector<int> cnt(101, 0);
	for (const auto& iter : arr) ++cnt[iter];
	arr.clear();
	for (int i = 0 ; i < cnt.size() ; ++i) {
		if (cnt[i] == 0) continue;
		for (int j = 0 ; j < cnt[i] ; ++j) {
			arr.emplace_back(i);
		}
	}

	int result = 0;
	int base = 1e9 + 7;
	for (int i = 0 ; i < arr.size(); ++i) {
		int localT = target - arr[i];
		int left = i + 1, right = arr.size() - 1;
		while (left < right) {
			int sum = arr[left] + arr[right];
			if (sum == localT) {
				unordered_map<int, int> local;
				++local[arr[i]];
				++local[arr[left]];
				++local[arr[right]];
				int sum = 1;
				for (const auto& it : local) {
					sum *= getComb(cnt[it.first], it.second);
					sum %= base;
				}
				result += sum;
				result %= base;
				++left;
				while (left < right && arr[left] == arr[left-1]) ++left;
				--right;
				while (right > left && arr[right] == arr[right+1]) --right;
			} else if (sum < localT) {
				++left;
				while (left < right && arr[left] == arr[left-1]) ++left;
			} else {
				--right;
				while (right > left && arr[right] == arr[right+1]) --right;
			}
		}
		while (i < arr.size() - 1 && arr[i] == arr[i+1]) ++i;
	}
	return result;
}
