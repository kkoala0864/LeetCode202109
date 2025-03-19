#include <Solution.h>
#include <iostream>

using std::cout;
using std::endl;

int main(void) {
	//[1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
	Node* root = new Node(1);
	Node* node1 = new Node(2);
	Node* node2 = new Node(3);
	Node* node3 = new Node(4);
	Node* node4 = new Node(5);
	Node* node5 = new Node(6);
	Node* node6 = new Node(7);
	Node* node7 = new Node(8);
	Node* node8 = new Node(9);
	Node* node9 = new Node(10);
	Node* node10 = new Node(11);
	Node* node11 = new Node(12);
	Node* node12 = new Node(13);
	Node* node13 = new Node(14);
	root->children.push_back(node1);
	root->children.push_back(node2);
	root->children.push_back(node3);
	root->children.push_back(node4);
	node2->children.push_back(node5);
	node2->children.push_back(node6);
	node3->children.push_back(node7);
	node4->children.push_back(node8);
	node4->children.push_back(node9);
	node6->children.push_back(node10);
	node7->children.push_back(node11);
	node8->children.push_back(node12);
	node10->children.push_back(node13);
	Solution* test = new Solution();
	string str = test->serialize(root);
	cout << str << endl;
	Node* result = test->deserialize(str);
	return 0;
}

