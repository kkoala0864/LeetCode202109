#include <Solution.h>

int main(void) {
	string s = "exhmepeeeeeekeeetelqyeeeeudtdsjeeyeweeeeekqeizesieqnddzeaefqeyeeezesxfreveeeeyeeeseregoneiftemerujfveysezkeeiofsbeeerheueeehedkluoedeeemeweeekeefeqaleb";
	int k = 65;
	Solution *test = new Solution();
	cout << test->longestSubsequenceRepeatedK(s, k) << endl;
	return 0;
}
