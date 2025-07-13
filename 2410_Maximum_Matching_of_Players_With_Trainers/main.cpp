#include <Solution.h>

int main(void) {
	vector<int> players = {4,7,9};
	vector<int> trainers = {8,2,5,8};
	Solution *test = new Solution();
	cout << test->matchPlayersAndTrainers(players, trainers) << endl;
	return 0;
}
