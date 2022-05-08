#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;
bool grid[101][101];
bool isVisited[101][101];
int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int BFS(int row, int col) {
	int count = 0;
	queue<pair<int, int>> q;
	isVisited[row][col] = true;
	q.push({ row,col });
	int frontRow, frontCol, newRow, newCol;

	while (!q.empty()) {
		count++;
		frontRow = q.front().first;
		frontCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			newRow = frontRow + movement[i][0];
			newCol = frontCol + movement[i][1];

			if (newRow < 1 || newCol < 1 || newRow > N || newCol > M)continue;
			if (!grid[newRow][newCol]) continue;
			if (isVisited[newRow][newCol]) continue;
			q.push({ newRow,newCol });
			isVisited[newRow][newCol] = true;
		}
	}
	return count;
}
int main() {
	cin >> N >> M >> K;

	int start, end;
	for (int i = 1; i <= K; i++) {
		cin >> start >> end;
		grid[start][end] = true;
	}
	int max = 0;
	int tempMax = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (isVisited[i][j])continue;
			if (!grid[i][j]) continue;
			tempMax = BFS(i, j);
			if (tempMax > max)max = tempMax;
		}
	}
	cout << max;
}