#include <iostream>
#include <cmath>
using namespace std;

int N;
int grid[21][21];
bool isUsing[21];
int minValue = 99999999;
int Calc() {
	int value = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (isUsing[i] && isUsing[j]) value += grid[i][j] + grid[j][i];
			else if (!isUsing[i] && !isUsing[j]) value -= grid[i][j] + grid[j][i];
		}
	}
	return abs(value);
}
void Combination(int index, int depth) {
	if (depth == N / 2) {
		minValue = min(minValue, Calc());
		return;
	}
	for (int i = index; i < N; i++) {
		if (depth == 0 && i != 0) break;
		isUsing[i] = true;
		Combination(i + 1, depth + 1);
		isUsing[i] = false;
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	Combination(0, 0);
	cout << minValue;
}