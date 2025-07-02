#include <Solution.h>

int main(void) {
	// ["Solution","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick"]
	// [[[1,3,2,3,3]],[3],[3],[3],[3],[3],[3],[3],[3],[3],[3],[3],[3],[3],[3],[3],[3],[3],[3]]
	vector<int> v = {1, 3, 2, 3, 3};
	Solution* obj = new Solution(v);
	for (int i = 0; i < 18; ++i) {
		int param_1 = obj->pick(3);
		cout << param_1 << endl;
	}
	return 0;
}
