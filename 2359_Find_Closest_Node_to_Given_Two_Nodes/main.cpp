#include <Solution.h>

int main(void) {
	vector<int> input = {4,4,8,-1,9,8,4,4,1,1};
	int node1 = 5;
	int node2 = 6;
	Solution *test = new Solution();
	cout << test->closestMeetingNode(input, node1, node2) << endl;
	return 0;
}
