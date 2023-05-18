#include <iostream>
#include <queue>
using namespace std;


struct grid {
	int height;
	int row;
	int col;
	int dist;
};
int M, N, H, allCount;
int map[101][101][101];
int movement[6][3] = { {0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0} };
queue<grid> ripeTomato;

int BFS() {

	int currentHeight, newHeight;
	int currentRow, newRow;
	int currentCol, newCol;
	int currentDist = 0;
	while (!ripeTomato.empty()) {
		currentHeight = ripeTomato.front().height;
		currentRow = ripeTomato.front().row;
		currentCol = ripeTomato.front().col;
		currentDist = ripeTomato.front().dist;

		ripeTomato.pop();
		allCount--;

		for (int i = 0; i < 6; i++) {
			newHeight = currentHeight + movement[i][0];
			newRow = currentRow + movement[i][1];
			newCol = currentCol + movement[i][2];

			if (newHeight >= H || newHeight < 0 || newRow >= N || newRow < 0 || newCol >= M || newCol < 0) continue;
			if (map[newHeight][newRow][newCol] == -1 || map[newHeight][newRow][newCol] == 1) continue;

			ripeTomato.push({ newHeight,newRow,newCol,currentDist + 1 });
			map[newHeight][newRow][newCol] = 1;
		}
	}
	return currentDist;

}
int main() {
	cin >> M >> N >> H;

	allCount = M * N * H;
	int num = 0;
	for (int height = 0; height < H; height++) {
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < M; col++) {
				cin >> num;
				map[height][row][col] = num;
				if (num == 1) ripeTomato.push({ height,row,col,0 });
				else if (num == -1) allCount--;
			}
		}
	}
	int answer = BFS();

	if (allCount != 0) cout << -1;
	else cout << answer;
}