#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	string input = "100110111111000000010011101000111011000001000111010001010111100001111110110010100011100100111000011011000000100001011000000100110110001101011010011";
	Solution* test = new Solution();
	cout << test->longestSubsequence(input, 522399436) << endl;
	return 0;
}

