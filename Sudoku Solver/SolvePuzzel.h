#pragma once
#include "Node.h"
class SolvePuzzel
{
private:
	int** puzzel;
	int size;
public:
	SolvePuzzel(int** puzzel, int size);
	void printPuzzel();
	int** getBox(Node node);
	bool PossibleValue(Node& node);
	Node getNextEmptyNode(Node node);
	void Solve();
	string Solve(Node& node);
	void setcolor(unsigned short color);


};

