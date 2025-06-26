#include <Solution.h>

int main(void) {
	vector<string> input = {"dog","cat","dad","good"};
	vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
	vector<int> scores = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
	Solution *test = new Solution();
	cout << test->maxScoreWords(input, letters, scores) << endl;
	return 0;
}
