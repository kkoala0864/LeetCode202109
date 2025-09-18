#include <Solution.h>

int main(void) {
	//["TaskManager","rmv","add","execTop","edit","execTop"]
	//[[[[8,11,1],[9,23,14],[2,6,4]]],[23],[6,12,42],[],[6,5],[]]
	vector<vector<int>> input = {{8,11,1},{9,23,14},{2,6,4}};
	TaskManager* obj = new TaskManager(input);
	obj->rmv(23);
	obj->add(6,12,42);
	int param_4 = obj->execTop();
	cout << param_4 << endl;
	obj->edit(6,5);
	int param_6 = obj->execTop();
	cout << param_6 << endl;
	return 0;
}
