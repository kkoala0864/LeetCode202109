#include <Solution.h>
#include <iostream>
#include <deque>
#include <algorithm>

using std::deque;
using std::max;
using std::cout;
using std::endl;

int Solution::getWinner(vector<int>& arr, int k) {
	int result = max(arr[0], arr[1]);

	deque<int> dq;

	int cnt = 1;
	for (int i = 2 ; i < arr.size() ; ++i) {
		dq.emplace_back(arr[i]);
	}
	dq.emplace_back(result == arr[0] ? arr[1] : arr[0]);

	for (int i = 0 ; i < arr.size() && cnt < k ; ++i) {
		if (result > dq.front()) {
			++cnt;
			dq.emplace_back(dq.front());
		} else {
			cnt = 1;
			dq.emplace_back(result);
			result = dq.front();
		}
		dq.pop_front();
	}
	return result;
}
