#include "Node.h"
Node::Node(int x_Pos, int y_Pos) {
	this->x_Pos = x_Pos;
	this->y_Pos = y_Pos;
}

int Node::getx_Pos() {
	return x_Pos;
}

int Node::gety_Pos() {
	return y_Pos;
}
int Node::getbBranchValue() {
	return branchValue;
}
void Node::addPossibleValue(int value) {
	possibleValues.push_back(value);
}
Node::Node()
{
	x_Pos = -1;
	y_Pos = -1;
}
vector<Node> Node::getChildNode() {
	return ChildNode;
}
void Node::creatChildNode(Node node) {
	for (int value : possibleValues) {
		Node child_node(node.getx_Pos(), node.gety_Pos());
		child_node.branchValue = value;
		ChildNode.push_back(child_node);
	}
}

vector<int> Node::getPossibleValues()
{
	return possibleValues;
}
