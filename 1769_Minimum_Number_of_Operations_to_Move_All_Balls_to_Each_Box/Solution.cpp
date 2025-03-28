#include <Solution.h>
#include <iostream>

vector<int> Solution::minOperations(string boxes) {
	int size = boxes.size();
	vector<int> post(size, 0);
	int sum = 0;
	int cnt = 0;
	for (int i = size - 1; i >= 0; --i) {
		cnt += boxes[i] == '0' ? 0 : 1;
		sum += cnt;
		post[i] = sum;
	}

	vector<int> result;
	int preSum = 0;
	cnt = 0;
	for (int i = 0; i < boxes.size(); ++i) {
		int v = preSum;
		if (i < boxes.size() - 1) {
			v += post[i + 1];
		}
		result.emplace_back(v);
		cnt += boxes[i] == '0' ? 0 : 1;
		preSum += cnt;
	}
	return result;
}
