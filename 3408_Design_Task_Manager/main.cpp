#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	//["TaskManager","add","edit","execTop","rmv","add","execTop"]
	//[[[[1,101,8],[2,102,20],[3,103,5]]],[4,104,5],[102,9],[],[101],[50,101,8],[]]

	vector<vector<int>> input = {{1, 101, 8}, {2, 102, 20}, {3, 103, 5}};
	TaskManager *obj = new TaskManager(input);
	obj->add(4, 104, 5);
	obj->edit(102, 9);
	cout << obj->execTop() << endl;
	obj->rmv(101);
	obj->add(50, 101, 8);
	cout << obj->execTop() << endl;
	return 0;
}
