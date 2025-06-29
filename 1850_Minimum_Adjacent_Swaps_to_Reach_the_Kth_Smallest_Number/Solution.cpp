#include <Solution.h>

void getNextValue(string& num) {
	int size = num.size();
	int i = size - 2;

	while (i >= 0 && num[i] >= num[i+1]) --i;
	if (i < 0) return;

	int j = size - 1;
	while (j > i && num[j] <= num[i]) --j;
	swap(num[j], num[i]);
	reverse(num.begin() + i + 1, num.end());
}

int Solution::getMinSwaps(string num, int k) {
	string ori = num;
	for (int i = 0 ; i < k ; ++i) {
		getNextValue(num);
	}
	int result = 0;
	int size = ori.size();
	for (int i = 0 ; i < size ; ++i) {
		if (num[i] == ori[i]) continue;
		for (int j = i + 1 ; j < size ; ++j) {
			if (num[j] != ori[i]) continue;
			for (int k = j - 1 ; k >= i ; --k) {
				swap(num[k], num[k+1]);
				++result;
			}
			break;
		}
	}
	return result;
}
