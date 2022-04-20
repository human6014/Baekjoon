#include <iostream>
#include <queue>
using namespace std;

int N, M;
int storage[1001][1001];
int isVisit[1001][1001];
int dist[1001][1001];
int movement[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int visitCount;
int endDist;
queue<pair<int,int>>q;

void BFS() {
	int firstFront,secondFront;
	int newX, newY;
	while (!q.empty()) {
		firstFront = q.front().first;
		secondFront = q.front().second;
		endDist = dist[q.back().first][q.back().second];
		q.pop();
		for (int i = 0; i < 4; i++) {
			newX = firstFront + movement[i][0];
			newY = secondFront + movement[i][1];
			if (newX < 1 || newY < 1 || newX > M || newY > N)continue;
			if (isVisit[newX][newY] == 1)continue;
			if (storage[newX][newY] == -1)continue;

			dist[newX][newY] = dist[firstFront][secondFront] + 1;
			isVisit[newX][newY] = 1;
			q.push({ newX,newY });
		}
		

		visitCount++;
		/*
		cout << "\n";
		for (int i = 1; i <= M; i++) {
			for (int j = 1; j <= N; j++) {
				cout << dist[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
		
	}
}
int main() {
	cin >> N >> M;
	int empty = 0;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> storage[i][j];
			if (storage[i][j] == -1) empty++;
			else if (storage[i][j] == 1) {
				isVisit[i][j] = 1;
				q.push({ i,j });
			}
		}
	}

	BFS();
	//cout << visitCount << "\t" << N * M << "\t" << empty << "\n";
	if (visitCount == N * M - empty)cout << endDist;
	else cout << -1;
}
/*
3 3

0 0 1

0 0 1

0 0 1

: 2


*/