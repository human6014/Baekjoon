#include <iostream>
#include <queue>
using namespace std;

int R, C;
int allCheeses;
int endCount;
int beforeEndCount;
int movement[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool grid[101][101];
bool isVisit[101][101];
void Reset() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			isVisit[i][j] = 0;
		}
	}
}
void BFS() {
	queue<pair<int, int>> q;
	q.push({ 1,1 });
	isVisit[1][1] = true;

	int frontRow, frontCol;
	int newRow, newCol;
	if (allCheeses > 0) beforeEndCount = allCheeses;
	while (!q.empty()) {
		frontRow = q.front().first;
		frontCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			newRow = frontRow + movement[i][0];
			newCol = frontCol + movement[i][1];
			if (newRow < 1 || newCol < 1 || newRow > R || newCol > C) continue;
			if (isVisit[newRow][newCol]) continue;
			if (grid[newRow][newCol] == 1) {
				grid[newRow][newCol] = 0;
				allCheeses--;
			}
			else q.push({ newRow,newCol });
			isVisit[newRow][newCol] = true;
		}
	}

	endCount++;
	
	
	return;
}
int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) allCheeses++;
		}
	}

	while (true) {
		BFS();
		if (allCheeses <= 0) break;
		Reset();
	}

	cout << endCount << "\n" << beforeEndCount;
}
/*
5 5
0 0 0 0 0
0 1 1 0 0
0 1 0 1 0
0 1 1 1 0
0 0 0 0 0

 : 1 7
*/