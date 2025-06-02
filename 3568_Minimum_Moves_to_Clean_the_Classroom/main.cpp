#include <Solution.h>

int main(void) {
	vector<string> input = {".XR.X.RR.XR.XX.XXXRR", "R..RRL.RXXXRXRXXXRX.", "RRRR.RRXX.X.RX.R..XX", "R...R.RX.L..RRL..R.L", ".X..RX.XRRRX..X.R.R.", "R.XRXRXX..R.R..R.X.R", "R.X.RX.RR..X.X.RL.R.", "LXRX.RRXXRRLRXRX.RXR", "X.XR.RRR..RXX.X.XRXR", "XXXR..XRXRR.RR..RX.R", "RR..XXRR..XXX.X..R.R", "RR.RRR.X.RRRX...XRRR", "R...S.XXLX.XRRX.XRRX", "X..X.X.RXRX.X.XXXR.R", "R.LXRR.RX.XR.RRXX.RX", "XX.XR.R.R.XR.X.R..RR", "..XXR.R..RXX.R..RRXX", ".XR.R....XR.R.XX..RX", "XXRRRRXXXRRX.RXLRXXR", "X.XXXXRRXR.RXRXRXX.R"};
	int energy = 11;
	Solution *test = new Solution();
	cout << test->minMoves(input, energy) << endl;
	return 0;
}
