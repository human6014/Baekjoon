#include <iostream>
#include <queue>;
using namespace std;

int T, M, N, K;
queue<pair<int, int>>qu;
int vertex[51][51];
int isVisit[51][51];
int movement[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int answer[1000000];
int BFS(int i, int j) {
	isVisit[i][j] = 1;
	qu.push({ i,j });
	int xPos, zPos;
	while (!qu.empty()) {
		xPos = qu.front().first;
		zPos = qu.front().second;
		qu.pop();
		for (int i = 0; i < 4; i++) {
			int newX = xPos + movement[i][0];
			int newY = zPos + movement[i][1];
			if (newX < 0 || newX > M - 1 || newY < 0 || newY > N - 1)continue;
			if (isVisit[newX][newY] == 1)continue;
			if (vertex[newX][newY] == 0)continue;
			qu.push({ newX,newY });
			isVisit[newX][newY] = 1;
		}
	}
	return 1;
}
int main() {
	cin >> T;
	for (int k = 0; k < T; k++) {
		cin >> M >> N >> K;
		int first, second;
		for (int i = 0; i < K; i++) {
			cin >> first >> second;
			vertex[first][second] = 1;
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (vertex[i][j] == 0)continue;
				if (isVisit[i][j] == 1)continue;
				answer[k] += BFS(i, j);
			}
		}
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				isVisit[i][j] = 0;
				vertex[i][j] = 0;
			}
		}
	}
	for (int k = 0; k < T; k++) {
		cout << answer[k] << "\n";
	}
}