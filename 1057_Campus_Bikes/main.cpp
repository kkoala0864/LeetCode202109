#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	vector<vector<int>> worker = {{906, 92}, {397, 522}, {543, 253}, {839, 747}, {527, 955}, {14, 515}, {440, 825}, {506, 429}, {108, 133}, {702, 689}, {134, 841}, {889, 148}, {297, 267}, {886, 197}, {280, 389}, {61, 850}, {791, 653}, {256, 601}, {377, 750}, {615, 647}, {527, 294}, {908, 573}, {352, 558}, {824, 789}, {707, 349}, {900, 697}, {558, 142}, {145, 461}, {27, 141}, {8, 656}, {190, 125}, {531, 599}, {456, 181}, {866, 218}, {487, 270}, {863, 261}, {339, 167}, {443, 280}, {139, 906}, {510, 984}, {102, 676}, {971, 68}, {379, 208}, {921, 928}, {905, 101}, {259, 69}, {839, 371}, {881, 103}, {517, 659}, {557, 150}, {89, 260}, {839, 494}, {860, 526}, {82, 783}, {226, 619}, {4, 861}, {870, 425}, {34, 985}, {827, 353}, {505, 846}, {484, 611}, {414, 77}, {749, 648}, {792, 233}};
	vector<vector<int>> bikes = {{319, 686}, {280, 180}, {720, 320}, {80, 888}, {561, 892}, {137, 575}, {838, 955}, {827, 292}, {234, 332}, {673, 896}, {880, 457}, {794, 918}, {627, 432}, {618, 990}, {847, 427}, {366, 990}, {525, 257}, {444, 148}, {675, 51}, {657, 493}, {706, 671}, {312, 890}, {590, 57}, {250, 502}, {434, 125}, {40, 265}, {361, 926}, {667, 464}, {54, 363}, {725, 170}, {501, 244}, {357, 572}, {247, 113}, {783, 502}, {938, 59}, {306, 165}, {519, 297}, {40, 639}, {587, 997}, {361, 785}, {654, 196}, {736, 540}, {847, 362}, {292, 636}, {653, 300}, {65, 48}, {639, 419}, {133, 933}, {550, 656}, {987, 75}, {550, 58}, {811, 310}, {641, 953}, {504, 486}, {835, 407}, {889, 247}, {775, 954}, {248, 34}, {208, 796}, {342, 11}, {185, 155}, {685, 921}, {110, 617}, {884, 824}, {745, 180}, {207, 850}, {686, 991}, {941, 162}, {846, 544}, {472, 256}, {888, 112}, {432, 840}, {508, 278}, {776, 378}, {534, 404}, {288, 699}, {897, 889}, {33, 395}, {849, 741}, {524, 846}, {432, 936}};
	Solution *test = new Solution();
	vector<int> result = test->assignBikes(worker, bikes);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	result = test->assignBikes2(worker, bikes);
	for (const auto &iter : result) {
		cout << iter << " ";
	}
	cout << endl;
	return 0;
}
