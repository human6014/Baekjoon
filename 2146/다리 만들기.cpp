#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N;
bool grid[101][101];
bool isVisit[101][101];
int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int answer = 9999999;
struct info {
	int row;
	int col;
	int group;
};
vector<info>beachs;
void BFS(int row, int col, int groupNum) {
	queue<pair<int, int>> q;
	q.push({ row,col });
	isVisit[row][col] = true;

	int frontRow, frontCol;
	int newRow, newCol;
	bool isIn;
	while (!q.empty()) {
		frontRow = q.front().first;
		frontCol = q.front().second;
		q.pop();

		isIn = false;
		for (int i = 0; i < 4; i++) {
			newRow = frontRow + movement[i][0];
			newCol = frontCol + movement[i][1];

			if (newRow <1 || newCol < 1 || newRow > N || newCol > N) continue;
			if (isVisit[newRow][newCol]) continue;

			if (grid[newRow][newCol]) {
				q.push({ newRow,newCol });
				isVisit[newRow][newCol] = true;
			}
			else if (!isIn) {
				isIn = true;
				beachs.push_back({ frontRow,frontCol,groupNum });
			}
		}
	}
}
void FindDistance() {
	int row, col, group;
	int distance;
	for (int i = 0; i < beachs.size(); i++) {
		row = beachs[i].row;
		col = beachs[i].col;
		group = beachs[i].group;
		distance = 0;
		for (int j = i; j < beachs.size(); j++) {
			if (group == beachs[j].group) continue;
			distance = abs(beachs[j].row - row) + abs(beachs[j].col - col) - 1;
			answer = min(answer, distance);
			if (answer == 1)return;
		}
	}
}
int main() {
	cin >> N;
	int groupNum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!isVisit[i][j] && grid[i][j]) BFS(i, j, groupNum++);
		}
	}
	FindDistance();

	cout << answer;
	/*
	while (!beachs.empty()) {
		cout << beachs.front().row << "\t" << beachs.front().col<<"\t" << beachs.front().group <<"\n";
		beachs.pop();
	}
	*/

}
/*
1. 1인 즉 땅인 곳에 대하여 각 그룹에서 모두 bfs 실시
2. 만약 주변에 0(4방향)이 있다면 저장
3. 저장된 1의 위치에서 bfs모두 실시
4. 자기 땅 외의 다른 땅에서 1을 만날 경우 최소거리
5. 최소거리 갱신해가면서 더 클경우 break로 최솟값 찾아나감

*/

