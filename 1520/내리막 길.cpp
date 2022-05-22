#include <iostream>
using namespace std;

int N, M;
int grid[501][501];
bool isVisited[501][501];
int memory[501][501];
int movement[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int answer = 0;
int DFS(int row,int col) {
	if (row == N && col == M) {
		return 1;
	}
	if (memory[row][col] == -1) {
		memory[row][col] = 0;
		int newRow, newCol;
		for (int i = 0; i < 4; i++) {
			newRow = row + movement[i][0];
			newCol = col + movement[i][1];

			if (newRow < 1 || newCol < 1 || newRow > N || newCol > M)continue;
			//if (isVisited[newRow][newCol]) continue;
			if (grid[row][col] > grid[newRow][newCol]) memory[row][col] += DFS(newRow, newCol);
		}
	}
	return memory[row][col];
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> grid[i][j];
			memory[i][j] = -1;
		}
	}
	
	cout << DFS(1, 1);
}