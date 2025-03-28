#include <Solution.h>
#include <iostream>
#include <queue>

using std::queue;

vector<int> Solution::deckRevealedIncreasing(vector<int> &deck) {
	queue<int> idx;
	vector<int> result(deck.size(), 0);
	sort(deck.begin(), deck.end());

	for (int i = 0; i < deck.size(); ++i) {
		idx.emplace(i);
	}

	for (int i = 0; i < deck.size(); ++i) {
		result[idx.front()] = deck[i];
		idx.pop();

		if (!idx.empty()) {
			idx.emplace(idx.front());
			idx.pop();
		}
	}
	return result;
	;
}
