#include "SolvePuzzel.h"
#include "Node.h"
#include<string>
#include<math.h>
#include<Windows.h>
SolvePuzzel::SolvePuzzel(int** puzzel, int size)
{
	this->puzzel = puzzel;
	this->size = size;
}

void SolvePuzzel::printPuzzel()
{
	cout << "\t\t\t******************Sudoku Solver*******************\n";
	int subGridSize = sqrt(size);
	int line = subGridSize - 1;
	cout << "\n\t\t\t|------------------------------------------------|\n";
	for (int i = 0; i < size; i++) {
		cout<<"\t\t\t\t ";
		for (int j = 0; j < size; j++) {
			if (j % subGridSize == 0)
				cout << "|  ";
			cout << puzzel[i][j] << "  ";
		}
		if (i % subGridSize == line)
			cout << "|\n\t\t\t|------------------------------------------------";
		cout <<"|"<< endl;	
	}
}

int** SolvePuzzel::getBox(Node node)
{
	int subGridSize = sqrt(size);

	int verticalBoxIndex = node.getx_Pos() / subGridSize;
	int horizontalBoxIndex = node.gety_Pos() / subGridSize;

	int topLeftOfSubBoxRow = subGridSize * verticalBoxIndex;
	int topLeftOfSubBoxCol = subGridSize * horizontalBoxIndex;

	int** subGrid = new int* [subGridSize];
	for (int i = 0; i < subGridSize; i++) {
		subGrid[i] = new int[subGridSize];
	}

	for (int i = 0; i < subGridSize; i++) {
		for (int j = 0; j < subGridSize; j++) {
			subGrid[i][j] = puzzel[topLeftOfSubBoxRow + i][topLeftOfSubBoxCol + j];
		}
	}
	return subGrid;
}

Node SolvePuzzel::getNextEmptyNode(Node node)
{
	int nextX=size-1;
	int nextY=size-1;
	if (node.gety_Pos() < size-1) {
		nextX = node.getx_Pos();
		nextY = node.gety_Pos() + 1;
	}
	else if (node.gety_Pos() == size-1 && node.getx_Pos() < size-1) {
		nextX = node.getx_Pos() + 1;
		nextY = 0;
	}
	else if (node.getx_Pos() == size-1 && node.gety_Pos() == size-1) {
		
		return Node();
	}
	Node nextNode (nextX, nextY);
	if (puzzel[nextX][nextY] != 0)
	{
		return getNextEmptyNode(nextNode);
	}
	return nextNode;
}

void SolvePuzzel::Solve()
{
	int x = 0;
	int y = 0;
	Node node(x, y);
	if (puzzel[x][y] != 0) {
		node = getNextEmptyNode(node);
	}
	if (Solve(node) == "solved")
		printPuzzel();
	else {
		cout << "There Is No Solution For This Puzzel\n\n";
	}
}

string SolvePuzzel::Solve(Node& node)
{
	if (PossibleValue(node))
	{
		Node next_node = getNextEmptyNode(node);
		if (next_node.getx_Pos() != -1)
		{
			node.creatChildNode(next_node);
			for (Node child_node : node.getChildNode())
			{
				puzzel[node.getx_Pos()][node.gety_Pos()] = child_node.getbBranchValue();
				string status = Solve(child_node);
				if (status == ("solved")) {
					return "solved";
				}
				else if (status == ("backTrack"))
				{
					puzzel[node.getx_Pos()][node.gety_Pos()] = 0;
					continue;
				}
			}
			return "backTrack";
		}
		else
		{

			if (node.getPossibleValues().size() == 1) {
				puzzel[node.getx_Pos()][node.gety_Pos()] = node.getPossibleValues().at(0);
				return "solved";
			}
			else {
				return "backTrack";
			}
		}
	}
	else
	{
		return "backTrack";
	}

}

bool SolvePuzzel::PossibleValue(Node& node) {
	bool* values = new bool[size+1] {};
	int x = node.getx_Pos();
	int y = node.gety_Pos();
	int** box = getBox(node);
	
	for (int i = 0; i < size; i++) { 
		if (puzzel[x][i] != 0) {
			values[puzzel[x][i]] = true;
		}
	}
	for (int j = 0; j < size; j++) {
		if (puzzel[j][y] != 0) {
			values[puzzel[j][y]] = true;
		}
	}
	for (int i = 0; i < sqrt(size); i++) {
		for (int j = 0; j < sqrt(size); j++) {
			if (box[i][j] != 0) {
				values[box[i][j]] = true;
			}
		}
	}
	for (int i = 1; i <= size; i++) {
		if (values[i] == false ) {
			node.addPossibleValue(i);
		}
	}
	/*for (int value : possibleValues) {
		node.addPossibleValue(value);
	}*/
	for (int i = 1; i <= size ; i++) {
		if (values[i] == false) {
			return true;
		}
	}
	return false;
}


void SolvePuzzel::setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

