#include <Solution.h>

int main(void) {
	vector<int> boxes = {1,2,2,3,4};
	vector<int> warehouse = {3,4,1,2};
	Solution *test = new Solution();
	cout << test->maxBoxesInWarehouse(boxes, warehouse) << endl;
	return 0;
}
