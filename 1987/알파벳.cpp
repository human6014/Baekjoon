#include <iostream>

using namespace std;

int R, C;
char grid[21][21];
int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int maxLevel = 0;
bool isVisited[26];
void DFS(int row, int col,int level ) {
	//cout << row << "\t" << col << "\tchar : " << grid[row][col] <<"\tlevel : " << level << "\n";
	if (maxLevel < level) {
		maxLevel = level;
	}
	int newCol, newRow;
	for (int i = 0; i < 4; i++) {
		newRow = row + movement[i][0];
		newCol = col + movement[i][1];

		if (newCol < 1 || newRow < 1 || newCol > C || newRow > R) continue;
		if (isVisited[grid[newRow][newCol]-'A']) continue;

		isVisited[grid[newRow][newCol] - 'A'] = true;
		DFS(newRow, newCol, level + 1);
		isVisited[grid[newRow][newCol] - 'A'] = false;
	}
}
int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> grid[i][j];
		}
	}
	isVisited[grid[1][1] - 'A'] = true;
	DFS(1, 1, 1);
	cout << maxLevel;
}