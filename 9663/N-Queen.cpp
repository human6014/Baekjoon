#include <iostream>
using namespace std;
int N;
int answer;
int position[15];

bool isPromising(int row, int col) {
	for (int i = 1; i < row; i++) {
		if (position[i] == col) return true;
		else if (position[i] > col) {
			if (row + col == i + position[i]) return true;
		}
		else {
			if (row - col == i - position[i]) return true;
		}
	}
	return false;
}
void DFS(int row, int col) {
	if (row == N + 1) {
		answer++;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (isPromising(row, i))continue;
		position[row] = i;
		DFS(row + 1, i);
		position[row] = 0;
	}
}
int main() {
	cin >> N;
	DFS(1, 1);

	cout << answer;
}
/*
1 : 1
2 : 0
3 : 0
4 : 2
5 : 10
6 : 4
7 : 40
8 : 92
9 : 352
10 : 724
.
.
.
14 : 365,596
*/