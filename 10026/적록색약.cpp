#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/*
int N;
char RGB[101][101];
const int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

bool nonWeakIsVisited[101][101];
bool WeakIsVisited[101][101];
queue<pair<int, int>> nonWeakQ;
queue<pair<int, int>> weakQ;


int nonWeakBFS(int i, int j) {
	char nowColor = RGB[i][j];
	int oldX, oldY;
	int newX, newY;
	nonWeakQ.push({ i,j });
	nonWeakIsVisited[i][j] = 1;

	while (!nonWeakQ.empty()) {
		oldX = nonWeakQ.front().first;
		oldY = nonWeakQ.front().second;
		nonWeakQ.pop();

		for (int i = 0; i < 4; i++) {
			newX = oldX + movement[i][0];
			newY = oldY + movement[i][1];
			if (newX < 1 || newY < 1 || newX>N || newY>N) continue;
			if (RGB[newX][newY] != nowColor) continue;
			if (nonWeakIsVisited[newX][newY]) continue;
			nonWeakIsVisited[newX][newY] = true;
			nonWeakQ.push({ newX,newY });
		}
	}
	return 1;
}
int WeakBFS(int i, int j) {
	bool isRedGreen = false;
	char nowColor = RGB[i][j];
	if (RGB[i][j] == 'R' || RGB[i][j] == 'G') isRedGreen = true;

	int oldX, oldY;
	int newX, newY;
	weakQ.push({ i,j });
	WeakIsVisited[i][j] = 1;

	while (!weakQ.empty()) {
		oldX = weakQ.front().first;
		oldY = weakQ.front().second;
		weakQ.pop();

		for (int i = 0; i < 4; i++) {
			newX = oldX + movement[i][0];
			newY = oldY + movement[i][1];
			if (newX < 1 || newY < 1 || newX>N || newY>N) continue;
			if (isRedGreen) {
				if (RGB[newX][newY] == 'B') continue;
			}
			else {
				if (RGB[newX][newY] != nowColor) continue;
			}

			if (WeakIsVisited[newX][newY]) continue;
			WeakIsVisited[newX][newY] = true;
			weakQ.push({ newX,newY });
		}
	}
	return 1;
}
int main() {
	cin >> N;
	int nonRGWeakness = 0;
	int RGWeakness = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> RGB[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!nonWeakIsVisited[i][j]) nonRGWeakness += nonWeakBFS(i, j);
			if (!WeakIsVisited[i][j]) RGWeakness += WeakBFS(i, j);
		}
	}

	cout << nonRGWeakness << " " << RGWeakness;
}
*/
int N;
char RGB[101][101];
const int movement[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

bool isVisited[101][101];
queue<pair<int, int>> q;

int BFS(int i, int j) {
	char nowColor = RGB[i][j];

	int oldX, oldY;
	int newX, newY;
	q.push({ i,j });
	isVisited[i][j] = 1;

	while (!q.empty()) {
		oldX = q.front().first;
		oldY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			newX = oldX + movement[i][0];
			newY = oldY + movement[i][1];
			if (newX < 1 || newY < 1 || newX>N || newY>N) continue;
			if (RGB[newX][newY] != nowColor) continue;
			if (isVisited[newX][newY]) continue;
			isVisited[newX][newY] = true;
			q.push({ newX,newY });
		}
	}
	return 1;
}
int main() {
	cin >> N;
	int nonRGWeakness = 0;
	int RGWeakness = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> RGB[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!isVisited[i][j]) nonRGWeakness += BFS(i, j);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (RGB[i][j] == 'G') RGB[i][j] = 'R'; //Point
			isVisited[i][j] = false;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!isVisited[i][j]) RGWeakness += BFS(i, j);
		}
	}

	cout << nonRGWeakness << " " << RGWeakness;
}