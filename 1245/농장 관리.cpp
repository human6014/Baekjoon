#include <iostream>
#include <queue>
using namespace std;

int N, M;
int grid[101][71];
int movement[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
bool isVisisted[101][71];
int BFS(int row, int col) {
	queue<pair<int, int>> q;
	isVisisted[row][col] = true;
	q.push({ row,col });
	bool isValid = true;
	int frontRow, frontCol;
	int newRow, newCol;
	while (!q.empty()) {
		frontRow = q.front().first;
		frontCol = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			newRow = frontRow + movement[i][0];
			newCol = frontCol + movement[i][1];

			if (newRow < 1 || newCol < 1 || newRow > N || newCol > M) continue;
			if (grid[frontRow][frontCol] == 0 || grid[newRow][newCol] > grid[frontRow][frontCol]) isValid = false;
			if (isVisisted[newRow][newCol]) continue;

			else if (grid[newRow][newCol] == grid[frontRow][frontCol]) {
				q.push({ newRow,newCol });
				isVisisted[newRow][newCol] = true;
			}
			else continue;
		}
	}
	if (isValid) return 1;
	else return 0;
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> grid[i][j];
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (!isVisisted[i][j]) answer += BFS(i, j);
		}
	}
	cout << answer;
}
/*
8 7
4 3 2 2 1 0 1
3 3 3 2 1 0 1
2 2 2 2 1 0 0
2 1 1 1 1 0 0
1 1 0 0 0 1 0
0 0 0 1 1 1 0
0 1 2 2 1 1 0
0 1 1 1 2 1 0
= 3
*/