class Solution {
public:
	Solution() {
	}
	int getSum(int a, int b);
	int getSum2(int a, int b);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
