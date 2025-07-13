#include <Solution.h>

int Solution::matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
	sort(players.begin(), players.end());
	sort(trainers.begin(), trainers.end());

	int pi = 0;
	int result = 0;

	for (int i = 0 ; i < trainers.size() ; ++i) {
		if (pi < players.size() && trainers[i] >= players[pi]) {
			++result;
			++pi;
		}
	}
	return result;
}
