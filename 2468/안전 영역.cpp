#include <iostream>
#include <queue>
using namespace std;

int N;
int matrix[101][101];
int isVisit[101][101];
int maxNum;
int maxAnswer;
int nowAnswer;
queue<pair<int,int>>q;
int movement[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
void BFS(int i, int j,int k) {
	int firstFront, secondFront;
	int newX, newY;

	isVisit[i][j] = 1;
	q.push({i,j});
	while (!q.empty()) {
		firstFront = q.front().first;
		secondFront = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			newX = firstFront + movement[i][0];
			newY = secondFront + movement[i][1];
			if (newX < 1 || newX > N || newY < 1 || newY > N)continue;
			if (isVisit[newX][newY] == 1)continue;
			if (matrix[newX][newY] <= k) {
				isVisit[newX][newY] = 1;
				continue;
			}
			isVisit[newX][newY] = 1;
			q.push({ newX,newY });
		}
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] > maxNum) maxNum = matrix[i][j];
		}
	}
	//int k = 6;
	for (int k = 0; k < maxNum; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (matrix[i][j] <= k) isVisit[i][j] = 1;
				if (isVisit[i][j] == 1) continue;
				BFS(i, j, k);
				nowAnswer++;
			}
		}
		if (nowAnswer > maxAnswer) maxAnswer = nowAnswer;
		nowAnswer = 0;
		if (k == maxNum - 1)break;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				isVisit[i][j] = 0;
			}
		}
	}
	
	cout << maxAnswer;
}