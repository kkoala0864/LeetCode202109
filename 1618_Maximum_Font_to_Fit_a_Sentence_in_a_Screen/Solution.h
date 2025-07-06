#include <data_type.h>

class FontInfo {
	public:
		int getWidth(int fontSize, char ch);
		int getHeight(int fontSize);
};

class Solution {
public:
	Solution() {
	}
	int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
