#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int width, height;
int startW, startH;
char building[1001][1001];
int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
queue<pair<int, int>> fire;
struct info {
	int row;
	int col;
	bool isFire;
	int distance;
};

int BFS(int h, int w) {
	queue<info> q;
	while (!fire.empty()) {
		q.push({ fire.front().first, fire.front().second, true, 0 });
		fire.pop();
	}
	building[h][w] = '@';
	q.push({ h, w, false, 0 });

	bool isFire;
	int distance;
	int curRow, curCol;
	int newRow, newCol;
	while (!q.empty()) {
		curRow = q.front().row;
		curCol = q.front().col;
		isFire = q.front().isFire;
		distance = q.front().distance;
		q.pop();

		for (int i = 0; i < 4; i++) {
			newRow = curRow + movement[i][0];
			newCol = curCol + movement[i][1];
			if (newRow > height || newCol > width || newRow < 1 || newCol < 1) {
				if (!isFire) return distance + 1;
				continue;
			}
			if (building[newRow][newCol] == '#') continue;
			if (building[newRow][newCol] == '*') continue;
			if (isFire) {
				building[newRow][newCol] = '*';
				q.push({ newRow, newCol, true, 0 });
			}
			else {
				if (building[newRow][newCol] == '@') continue;
				q.push({ newRow, newCol, false, distance + 1 });
				building[newRow][newCol] = '@';
			}
		}
	}
	return -1;
}

void reset() {
	for (int h = 1; h <= height; h++) {
		for (int w = 1; w <= width; w++) {
			building[h][w] = '#';
		}
	}
	while (!fire.empty()) fire.pop();
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> width >> height;
		for (int h = 1; h <= height; h++) {
			for (int w = 1; w <= width; w++) {
				cin >> building[h][w];
				if (building[h][w] == '@') {
					startH = h;
					startW = w;
				}
				else if (building[h][w] == '*')
					fire.push({ h, w });
			}
		}

		int calDist = BFS(startH, startW);
		if (calDist == -1) cout << "IMPOSSIBLE\n";
		else cout << calDist << "\n";
		reset();
	}
}
// ºÒ -> »ó±Ù