#pragma once
#include<iostream>
#include<vector>
using namespace std;
class Node
{
private:
	int x_Pos, y_Pos;
	int branchValue;
	vector<int> possibleValues;
	vector<Node> ChildNode;
public:
	Node();
	Node(int x_Pos, int y_Pos);
	int getx_Pos();
	int gety_Pos();
	int getbBranchValue();
	void addPossibleValue(int value);
	vector<Node> getChildNode();
	void creatChildNode(Node node);
	vector<int>getPossibleValues();

};


