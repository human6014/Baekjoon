#include <iostream>
#include <vector>
using namespace std;

int N;
bool grid[17][17];
//int dp[17][17];
int movement[3][2] = { {0,1},{1,1},{1,0} };
int answer = 0;
// rotaiton
// 0 : ->
// 1 : ´ë°¢¼± ¹Ø
// 2 : ¡é
int DFS(int row, int col, int rotation) {
	if (row == N && col == N) {
		answer++;
		//return 1;
	}
	int newRow, newCol;

	for (int i = 0; i < 3; i++) {
		if (rotation == 0 && i == 2) continue;
		if (rotation == 2 && i == 0) continue;

		newRow = row + movement[i][0];
		newCol = col + movement[i][1];

		if (newRow > N || newCol > N) continue;
		if (grid[newRow][newCol]) continue;
		if (i == 1)
			if (grid[newRow - 1][newCol] || grid[newRow][newCol - 1]) continue;

		//dp[row][col] +=
		DFS(newRow, newCol, i);
	}

	/*
	if (rotation == 2) {
		if (dp[row + 1][col] == -1) dp[row + 1][col] = 0;
		return dp[row][col] - dp[row + 1][col];
	}
	if (rotation == 0) {
		if (dp[row][col + 1] == -1) dp[row][col + 1] = 0;
		return dp[row][col] - dp[row][col + 1];
	}
	*/
	//return dp[row][col];
	return answer;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> grid[i][j];
			//dp[i][j] = -1;
		}
	}

	cout << DFS(1, 2, 0);
	/*
	cout << "\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << dp[i][j] << "\t";
		}
		cout << "\n";
	}
	*/
}
/*
16
0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1
0 1 0 1 0 1 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 1 1 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 = 664

4
0 0 0 0
0 0 0 0
0 0 0 1
0 0 1 0
 = 0

16
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 = 988402
*/
