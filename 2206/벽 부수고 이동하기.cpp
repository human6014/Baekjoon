/*
#include <iostream>
using namespace std;
#define MAXNUM 10000000

int N, M;
bool grid[1001][1001];
bool isVisited[1001][1001];
int movement[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int minValue = MAXNUM;
void DFS(int row,int col,int depth, bool isCrash) {
	//cout <<"row  : " << row << "\tcol : " << col <<"\tdepth : " << depth<< "\t isCrash : "<<isCrash << "\n";
	if (depth > minValue) return;
	if (row == N && col == M) {
		minValue =  min(minValue,depth);
		return;
	}
	int newRow,newCol;
	for (int i = 0; i < 4; i++) {
		newRow = row + movement[i][0];
		newCol = col + movement[i][1];

		if (newRow < 1 || newCol < 1 || newRow > N || newCol > M) continue;
		if (isVisited[newRow][newCol]) continue;

		isVisited[newRow][newCol] = true;
		if (!grid[newRow][newCol]) DFS(newRow, newCol, depth + 1, isCrash);
		else if (grid[newRow][newCol] && !isCrash) {
			isCrash = true;
			DFS(newRow, newCol, depth + 1, isCrash);
			isCrash = false;
		}
		isVisited[newRow][newCol] = false;
	}
}
int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &grid[i][j]);
		}
	}
	//cout << "\n";
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 1; j <= M; j++) {
	//		cout << grid[i][j] <<" ";
	//	}
	//	cout << "\n";
	//}

	isVisited[1][1] = true;
	DFS(1, 1, 1, 0);
	if (minValue == MAXNUM)cout << -1;
	else cout << minValue;
}
*/
#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool grid[1001][1001];
bool isVisited[1001][1001][2];
int movement[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
struct info {
	int row;
	int col;
	int depth;
	bool isCrash;
};
int BFS(int row, int col) {
	queue<info> q;
	q.push({ row,col,1,false });
	isVisited[row][col][0] = true;
	int nowRow, nowCol, depth;
	int newRow, newCol;
	bool isCrash;
	while (!q.empty()) {
		nowRow = q.front().row;
		nowCol = q.front().col;
		depth = q.front().depth;
		isCrash = q.front().isCrash;
		q.pop();

		if (nowRow == N && nowCol == M)return depth;

		for (int i = 0; i < 4; i++) {
			newRow = nowRow + movement[i][0];
			newCol = nowCol + movement[i][1];

			if (newRow < 1 || newCol < 1 || newRow > N || newCol > M) continue;
			if (isCrash) {
				if (isVisited[newRow][newCol][1]) continue;
				if (!grid[newRow][newCol]) {
					isVisited[newRow][newCol][1] = true;
					q.push({ newRow, newCol, depth + 1, isCrash });
				}
			}
			else {
				if (isVisited[newRow][newCol][0]) continue;
				if (!grid[newRow][newCol]) {
					isVisited[newRow][newCol][0] = true;
					q.push({ newRow, newCol, depth + 1, isCrash });
				}
				else {
					//isCrash = true;
					isVisited[newRow][newCol][0] = true;
					q.push({ newRow, newCol, depth + 1, true }); //true -> isCrash 시간 8ms 감소함
					//isCrash = false;
				}
			}
		}
	}
	return -1;
}
int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &grid[i][j]);
		}
	}

	cout << BFS(1, 1);
}
/*
8 8
01000100
01010100
01010100
01010100
01010100
01010100
01010100
00010100

=29
*/