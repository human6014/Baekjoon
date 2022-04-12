#include<iostream>
#include<queue>
using namespace std;

struct Position
{
	int x, y, dist;
};

int N, M;
int vertex[101][101];
int isVisit[101][101];

int movePosition[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int destination[2];

int BFS() {
	int count = 0;
	queue<Position> bfs;
	bfs.push({1, 1, 1});
	isVisit[1][1] = 1;
	int newX, newY;
	while (!bfs.empty()) {
		Position position = bfs.front();
		bfs.pop();

		if (position.x == destination[0] && position.y == destination[1]) {
			count = position.dist;
			break;
		}
		for (int i = 0; i < 4; i++) {
			newX = position.x + movePosition[i][0];
			newY = position.y + movePosition[i][1];
			if (newX <= 0 || newY <= 0 || newX > N || newY > M) continue;
			if (vertex[newX][newY] == 1 && isVisit[newX][newY] == 0) {
				isVisit[newX][newY] = 1;
				bfs.push({ newX,newY,position.dist + 1 });
			}
		}
	}
	return count;
}
int main() {
	cin >> N >> M;
	destination[0] = N;
	destination[1] = M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &vertex[i][j]);
		}
	}
	cout << BFS();
}