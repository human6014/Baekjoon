#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

struct info {
	int row;
	int col;
	int dis;
};
int N, M;
char grid[51][51];
int movement[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int maxDis;
void BFS(int row, int col) {
	bool isVisit[51][51];
	memset(isVisit, 0, sizeof(isVisit));
	queue<info> q;
	q.push({row,col,0});
	isVisit[row][col] = true;

	int frontRow, frontCol;
	int newRow, newCol;
	int frontDis;
	while (!q.empty()) {
		frontRow = q.front().row;
		frontCol = q.front().col;
		frontDis = q.front().dis;
		q.pop();

		if (maxDis < frontDis) maxDis = frontDis;
		for (int i = 0; i < 4; i++) {
			newRow = frontRow + movement[i][0];
			newCol = frontCol + movement[i][1];

			if (newRow > N || newCol > M || newRow < 1 || newCol < 1) continue;
			if (grid[newRow][newCol] == 'W') continue;
			if (isVisit[newRow][newCol]) continue;
			isVisit[newRow][newCol] = true;
			q.push({newRow,newCol,frontDis + 1});
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (grid[i][j] == 'L')BFS(i, j);
		}
	}
	cout << maxDis;
}
/*
5 7
WLLWWWL
LLLWLLL
LWLWLWW
LWLWLLL
WLLWLWW
= 8
*/