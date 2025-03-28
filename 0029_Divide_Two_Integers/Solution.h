class Solution {
public:
	Solution() {
	}
	int addingPowerOfTwo(int dividend, int divisor);
	int divide(int dividend, int divisor);

private:
	virtual ~Solution() {
	}
	Solution &operator=(const Solution &source);
	Solution(const Solution &);
};
