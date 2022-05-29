#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int const WALL_NUM = 3;
int N, M;
int answer;
int grid[9][9];
bool isVisited[9][9];
int movement[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
vector<pair<int, int>> virus;
vector<pair<int, int>> emptyArray;
vector<pair<int, int>> usingEmptyArray(WALL_NUM);
void Reset() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			isVisited[i][j] = false;
		}
	}
}
int BFS(vector<pair<int, int>> usingWalls) {
	queue<pair<int, int>>q;
	int emptyCount = emptyArray.size();

	for (int i = 0; i < virus.size(); i++) {
		q.push({ virus[i].first,virus[i].second });
		isVisited[virus[i].first][virus[i].second] = true;
	}
	for (int i = 0; i < usingWalls.size(); i++) {
		grid[usingWalls[i].first][usingWalls[i].second] = 1;
		emptyCount--;
	}

	int frontRow, frontCol;
	int newRow, newCol;
	while (!q.empty()) {
		frontRow = q.front().first;
		frontCol = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			newRow = frontRow + movement[i][0];
			newCol = frontCol + movement[i][1];

			if (newRow < 1 || newCol < 1 || newRow > N || newCol > M) continue;
			if (grid[newRow][newCol] == 1) continue;
			if (isVisited[newRow][newCol]) continue;
			q.push({ newRow,newCol });
			isVisited[newRow][newCol] = true;
			emptyCount--;
		}
	}
	/*
	cout << "\n-----------------------------\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << isVisited[i][j] << " ";
		}
		cout << "\n";
	}
	cout << emptyCount << "\n";
	*/
	Reset();
	for (int i = 0; i < usingWalls.size(); i++) {
		grid[usingWalls[i].first][usingWalls[i].second] = 0;
	}
	return emptyCount;
}
void Combination(int index, int depth) {
	if (depth == WALL_NUM) {
		answer = max(answer, BFS(usingEmptyArray));
		/*
		for (int i = 0; i < usingEmptyArray.size(); i++) {
			cout << "row : " << usingEmptyArray[i].first << "col : " << usingEmptyArray[i].second<<"\n";
		}
		cout << "\n-----------------------------------------------\n";
		*/
		return;
	}
	for (int i = index; i < emptyArray.size(); i++) {
		usingEmptyArray[depth] = emptyArray[i];
		Combination(i + 1, depth + 1);
	}
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 2) virus.push_back({ i,j });
			if (grid[i][j] == 0) emptyArray.push_back({ i,j });
		}
	}
	Combination(0, 0);
	cout << answer;
}
/*
7 7
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
*/