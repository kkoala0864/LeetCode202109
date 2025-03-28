#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<string> s1 = {"great", "acting", "skills"};
	vector<string> s2 = {"fine", "drama", "talent"};
	vector<vector<string>> similiar = {{"great", "fine"}, {"drama", "acting"}, {"skills", "talent"}};
	Solution *test = new Solution();
	cout << test->areSentencesSimilar(s1, s2, similiar) << endl;
	return 0;
}
