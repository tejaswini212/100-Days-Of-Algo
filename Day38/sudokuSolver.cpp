#include<bits/stdc++.h>
using namespace std;
const int kEmptyEntry = 0;

//Check using backtracking if value added is correct if it is a misleading solution assign 0 to it
bool validToAddVal(vector<vector<int>>& partialAssignment, int i, int j, int val) {

	//Check if value is already present in the column
	for (int k = 0; k < partialAssignment.size(); k++) {
		if (val == partialAssignment[k][j])
			return false;
	}

	//Check if value is already present in the row
	for (int k = 0; k < partialAssignment.size(); k++) {
		if (val == partialAssignment[i][k])
			return false;
	}

	//Check if value is already present in the grid of size sqrt(n)*sqrt(n)
	int regionSize = sqrt(partialAssignment.size());
	int I = i / regionSize, J = j / regionSize;
	for (int a = 0; a < regionSize; ++a) {
		for (int b = 0; b < regionSize; ++b) {
			if (val == partialAssignment[regionSize * I + a][regionSize * J + b])
				return false;
		}
	}
	return true;
}


bool solvePartialSudoku(int i, int j, vector<vector<int>>& partialAssignment) {
	
	if (i == partialAssignment.size()){
		i = 0;						//Start a new row
		if (++j == partialAssignment[i].size())
			return true;			//Entire matrix is filled without conflict
	}

	//Check if the cell is already filled
	if (partialAssignment[i][j] != kEmptyEntry)
		return solvePartialSudoku(i + 1, j, partialAssignment);

	//Fill the value in cell if it can recursively construct the correct solution
	for (int val = 1; val <= partialAssignment.size(); ++val) {
		if (validToAddVal(partialAssignment, i, j, val)) {
			partialAssignment[i][j] = val;
			if (solvePartialSudoku(i + 1, j, partialAssignment))
				return true;
		}
	}

	//Undo assignment
	partialAssignment[i][j] = kEmptyEntry;
	return false;
}

//Check if solution exists
bool solveSudoku(vector<vector<int>>& partialAssignment) {
	return solvePartialSudoku(0, 0, partialAssignment);
}

int main() {
	vector<vector<int>> partialAssignment = { {5,3,0,0,7,0,0,0,0},
										   {6,0,0,1,9,5,0,0,0},
										   {0,9,8,0,0,0,0,6,0},
										   {8,0,0,0,6,0,0,0,3},
										   {4,0,0,8,0,3,0,0,1},
										   {7,0,0,0,2,0,0,0,6},
										   {0,6,0,0,0,0,2,8,0},
										   {0,0,0,4,1,9,0,0,5},
										   {0,0,0,0,8,0,0,7,9} };
		if (solveSudoku(partialAssignment)) {
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 9; j++)
					cout << partialAssignment[i][j] << " ";
				cout << "\n";
			}
			
		}

	return 0;
}