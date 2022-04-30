#include <iostream>
using namespace std;

int N;
int color[1001][4];
int answer[1001][4];
int main() {
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> color[i][1] >> color[i][2] >> color[i][3];
	}

	answer[1][1] = color[1][1];
	answer[1][2] = color[1][2];
	answer[1][3] = color[1][3];

	/*
	for (int i = 2; i <= N; i++) {
		answer[i][1] = answer[i - 1][1] + min(color[i][2], color[i][3]);//
		answer[i][2] = answer[i - 1][2] + min(color[i][1], color[i][3]);//
		answer[i][3] = answer[i - 1][3] + min(color[i][1], color[i][2]);//
	}
	*/

	for (int i = 2; i <= N; i++) {
	answer[i][1] = color[i][1] + min(answer[i - 1][2], answer[i - 1][3]);
	answer[i][2] = color[i][2] + min(answer[i - 1][1], answer[i - 1][3]);
	answer[i][3] = color[i][3] + min(answer[i - 1][1], answer[i - 1][2]);
	}
	
	cout << min(answer[N][1], min(answer[N][2], answer[N][3]));
}