/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, cheeseCount, meltTime;
int nodes[101][101]; // 0 : 없음	1 : 치즈
int nodesCount[101][101];
bool isVisited[101][101];
int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
queue<pair<int, int>> q;
void BFS(int row,int col) {
	isVisited[row][col] = true;
	q.push({ row,col });
	int frontRow, frontCol;
	int newRow, newCol;
	int areaCount;
	while (!q.empty()) {
		frontRow = q.front().first;
		frontCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			newRow = frontRow + movement[i][1];
			newCol = frontCol + movement[i][0];
			if (newRow < 1 || newCol < 1 || newRow > N || newCol > M) continue;
			if (isVisited[newRow][newCol]) continue;
			if (nodes[newRow][newCol] == 1) {
				nodesCount[newRow][newCol]++;
				if (nodesCount[newRow][newCol] == 2)cheeseCount--;
				continue;
			}
			
			q.push({ newRow,newCol });
			isVisited[newRow][newCol] = true;
		}
	}
}
void Reset() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (nodesCount[i][j] >= 2) nodes[i][j] = 0;
			nodesCount[i][j] = 0;
			isVisited[i][j] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> nodes[i][j];
			if(nodes[i][j] == 1)cheeseCount++;
		}
	}

	while (cheeseCount > 0) {
		meltTime++;
		BFS(1, 1);
		Reset();
	}

	cout << meltTime << "\n";

	
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << nodesCount[i][j] << " ";
		}
		cout << "\n";
	}
	cout << cheeseCount;
	
}
*/
/*
8 9
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 1 1 0
0 1 0 1 1 1 0 1 0
0 1 0 0 1 0 0 1 0
0 1 0 1 1 1 0 1 0
0 1 1 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0

9 9
0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 1 0
0 1 0 0 0 0 0 1 0
0 1 0 0 1 0 0 1 0
0 1 0 1 0 1 0 1 0
0 1 0 0 1 0 0 1 0
0 1 0 0 0 0 0 1 0
0 1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0 0
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, cheeseCount, meltTime;
int nodes[101][101]; // 0 : 공기	1 : 치즈	2 ~ * : 치즈가 맞닿은 공기 수 + 1
bool isVisited[101][101];
int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
queue<pair<int, int>> q;
void BFS(int row,int col) {
	isVisited[row][col] = true;
	q.push({ row,col });
	int frontRow, frontCol;
	int newRow, newCol;
	int areaCount;
	while (!q.empty()) {
		frontRow = q.front().first;
		frontCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			newRow = frontRow + movement[i][1];
			newCol = frontCol + movement[i][0];
			if (newRow < 1 || newCol < 1 || newRow > N || newCol > M) continue;
			if (isVisited[newRow][newCol]) continue;
			if (nodes[newRow][newCol] >= 1) {
				nodes[newRow][newCol]++;
				if (nodes[newRow][newCol] == 3)cheeseCount--;
				continue;
			}

			q.push({ newRow,newCol });
			isVisited[newRow][newCol] = true;
		}
	}
}
void Reset() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (nodes[i][j] >= 3) nodes[i][j] = 0;
			else if (nodes[i][j] > 0) nodes[i][j] = 1;
			isVisited[i][j] = false;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> nodes[i][j];
			if(nodes[i][j] == 1)cheeseCount++;
		}
	}

	while (cheeseCount > 0) {
		meltTime++;
		BFS(1, 1);
		Reset();
	}

	cout << meltTime << "\n";
}
