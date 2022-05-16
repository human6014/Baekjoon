#include <iostream>
using namespace std;

int N, M;
int answer;
int grid[51][51];
int movement[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

void Cleaning(int row, int col, int direction) {
	int stopCount = 0;
	int newRow;
	int newCol;
	bool isContinue = false;
	while (true) {
		
		grid[row][col] = 2;
		stopCount = 0;

		for (int i = 0; i < 4;i++) {
			if (direction - 1 == -1) direction = 4;
			newRow = row + movement[direction - 1][0];
			newCol = col + movement[direction - 1][1];
			direction -= 1;
			if (grid[newRow][newCol] == 0) {
				row = newRow;
				col = newCol;
				answer++;
				isContinue = true;
				break;
			}
			else stopCount++;
		}

		if (isContinue) {
			//cout << newRow << " " << newCol << "\t" << answer << "\n";
			isContinue = false;
			continue;
		}

		if (direction == -1) direction = 3;
		newRow = row - movement[direction][0];
		newCol = col - movement[direction][1];
		if (stopCount == 4 && grid[newRow][newCol] == 1) return;
		else if (grid[newRow][newCol] == 0 || grid[newRow][newCol] == 2) {
			row = newRow;
			col = newCol;
			stopCount = 0;
		}
	}
}
int main() {
	int r, c, direction;
	cin >> N >> M;
	cin >> r >> c >> direction;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}

	Cleaning(r, c, direction);
	 
	/*
	std::cout << "\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << grid[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	*/
	cout << answer + 1;
}
/*
3 3
1 1 0
1 1 1
1 0 1
1 1 1
=1

11 10
7 4 0
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1
=57

4 4
1 1 0
1 1 1 1
1 0 1 1
1 0 0 1
1 1 1 1
*/