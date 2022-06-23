#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int grid[301][301];
bool isVisited[301][301];
int movement[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void Reset() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			isVisited[i][j] = false;
		}
	}
}
void BFS(int row,int col) {
	queue<pair<int, int>> q;
	q.push({ row,col });
	isVisited[row][col] = true;
	int frontRow,newRow;
	int frontCol,newCol;
	while (!q.empty()) {
		frontRow = q.front().first;
		frontCol = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			newRow = frontRow + movement[i][0];
			newCol = frontCol + movement[i][1];
			if (newRow > N || newCol > M || newRow < 1 || newCol < 1) continue;
			if (grid[newRow][newCol] == 0 && grid[frontRow][frontCol] > 0 && !isVisited[newRow][newCol]) grid[frontRow][frontCol]--;
			else if(grid[newRow][newCol] != 0 && !isVisited[newRow][newCol]){
				q.push({ newRow,newCol });
				isVisited[newRow][newCol] = true;
			}
		}
	}
}
int main() {
	int flag =0;
	int zeroCount;
	int time = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> grid[i][j];
		}
	}

	while (true) {
		zeroCount = 0;
		flag = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (grid[i][j] == 0) {
					zeroCount++;
					if (zeroCount == N * M) {
						cout << 0;
						return 0;
					}
				}
				else if (!isVisited[i][j]) {
					if (flag == 1) {
						cout << time;
						return 0;
					}
					BFS(i, j);
					flag++;
				}
			}
		}
		time++;
		Reset();
	}
}
/*
5 7
0 0 0 0 0 0 0
0 2 4 5 3 0 0
0 3 0 2 5 2 0
0 7 6 2 4 0 0
0 0 0 0 0 0 0
=2

5 7
0 0 0 0 0 0 0
0 9 8 9 8 9 0
0 9 8 9 8 9 0
0 9 8 9 8 9 0
0 0 0 0 0 0 0
=0

5 7
0 0 0 0 0 0 0
0 9 8 3 8 9 0
0 9 8 0 8 9 0
0 9 8 9 8 9 0
0 0 0 0 0 0 0
=5
*/