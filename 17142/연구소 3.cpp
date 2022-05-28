#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXVALUE 99999999

int N, M;
int grid[51][51];
int movement[4][2] = { {0,1} ,{0,-1},{1,0},{-1,0} };
bool isVisited[51][51];
int answer = MAXVALUE;
int emptyCount;
vector<pair<int, int>> virus;
vector<pair<int, int>> activeVirus;
struct virusInfo {
	int row;
	int col;
	int dis;
};
void Reset() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			isVisited[i][j] = false;
		}
	}
}
int BFS(vector<pair<int, int>> aVirus) {
	queue<virusInfo> q;
	int count = emptyCount;
	for (int i = 0; i < aVirus.size(); i++) {
		q.push({ aVirus[i].first,aVirus[i].second ,0 });
		isVisited[aVirus[i].first][aVirus[i].second] = true;
	}

	int frontRow, frontCol, frontDis;
	int newRow, newCol;
	int minValue = 0;
	while (!q.empty()) {
		frontRow = q.front().row;
		frontCol = q.front().col;
		frontDis = q.front().dis;
		q.pop();

		for (int i = 0; i < 4; i++) {
			newRow = frontRow + movement[i][0];
			newCol = frontCol + movement[i][1];

			if (newRow < 1 || newCol < 1 || newRow > N || newCol > N) continue;
			if (grid[newRow][newCol] == 1) continue;
			if (isVisited[newRow][newCol]) continue;

			q.push({ newRow,newCol,frontDis + 1 });
			isVisited[newRow][newCol] = true;
			if (grid[newRow][newCol] != 2) {
				minValue = max(minValue, frontDis + 1);
				count--;
			}
		}
		if (minValue > answer) break;
	}
	/*
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (isVisited[i][j]) cout << "1 ";
			else cout << "0 ";
		}
		cout << "\n";
	}
	cout << minValue << "\n";
	cout << count << "\n";
	*/
	if (count != 0) return MAXVALUE;
	return minValue;
}
void Combination(int index, int depth) {
	if (depth == M) {
		answer = min(answer, BFS(activeVirus));
		Reset();
		/*
		for (int i = 0; i < M; i++) {
			cout << "row : " << activeVirus[i].first << "\tcol : " << activeVirus[i].second << "\n";
		}
		cout << "\n-------------------------------------------------\n";
		*/
		return;
	}
	for (int i = index; i < virus.size(); i++) {
		activeVirus[depth] = virus[i];
		Combination(i + 1, depth + 1);
	}
}
int main() {
	cin >> N >> M;
	activeVirus.resize(M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 0) emptyCount++;
			if (grid[i][j] == 2) virus.push_back({ i, j });
		}
	}
	Combination(0, 0);
	if (answer == MAXVALUE) cout << -1;
	else cout << answer;
}
/*
5 1
2 2 2 1 1
2 1 1 1 1
2 1 1 1 1
2 1 1 1 1
2 2 2 1 1
=0

4 2
0 1 1 0
2 1 1 2
2 1 1 2
0 1 1 0
=2

9 1
0 2 2 2 2 2 2 2 0
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1

5 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
2 0 0 2 0
1 1 1 1 1
=3
*/