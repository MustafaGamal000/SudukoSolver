#include <iostream>
#include <fstream>
#include<math.h>
#include "SolvePuzzel.h"
#include<Windows.h>
using namespace std;

void setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}


int** getBox(int** puzzel, int size) {
	int subGridSize = sqrt(size);

	int verticalBoxIndex = 0 / subGridSize;
	int horizontalBoxIndex = 3 / subGridSize;

	int topLeftOfSubBoxRow = subGridSize * verticalBoxIndex;
	int topLeftOfSubBoxCol = subGridSize * horizontalBoxIndex;

	int** subGrid = new int* [subGridSize];
	for (int i = 0; i < subGridSize; i++) {
		subGrid[i] = new int[subGridSize];
	}

	for (int i = 0; i < subGridSize; i++) {
		for (int j = 0; j < subGridSize; j++) {
			subGrid[i][j]= puzzel[topLeftOfSubBoxRow + i][topLeftOfSubBoxCol + j];
		}
	}
	return subGrid;
}

int main() {
	ifstream file{ "Puzzel.txt" };
	if (!file.is_open()) 
		cout<<"Error in finding file\n";
	
	int size;
	file >> size;
	int** puzzel = new int* [size];
	for (int i = 0; i < size; i++) {
		puzzel[i] = new int[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			file >> puzzel[i][j];
		}
	}
	file.close();
	SolvePuzzel s(puzzel, size);
	s.Solve();

	/*vector<vector<int>> puzzel;
	int size;
	file >> size;
	for (int i = 0; i < size; i++) {
		vector<int> my_vect;
		int num;
		for (int j = 0; j < size; j++) {
			file >> num;
			my_vect.push_back(num);
		}
		puzzel.push_back(my_vect);
	}*/
	
	/*int** box = getBox(puzzel, size);
	for (int i = 0; i < sqrt(size); i++) {
		for (int j = 0; j < sqrt(size); j++) {
			cout << box[i][j] << " ";
		}
		cout << endl;
	}*/
	
	/*int** subGrid = getBox(puzzel, size);
	for (int i = 0; i < sqrt(size); i++) {
		for (int j = 0; j < sqrt(size); j++) {
			cout << subGrid[i][j] << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}