#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

queue<int> infoQueue;
int friends[501][501];
int isVisit[501];

int answer;
int N, M;
void BFS() {
	infoQueue.push(1);
	isVisit[1] = 1;
	int mate;
	int count = 0;
	while (!infoQueue.empty()) {
		mate = infoQueue.front();
		infoQueue.pop();
		if (count > 2)continue;
		for (int i = 1; i <= N; i++) {
			if (friends[mate][i] == 1 && isVisit[i] == 0) {
				infoQueue.push(i);
				answer++;
				isVisit[i] = 1;
			}
		}
		count++;
	}
}
int main() {
	cin >> N >> M;

	int first, second;
	for (int i = 1; i <= M; i++) {
		cin >> first >> second;
		friends[first][second] = friends[second][first] = 1;
	}

	BFS();
	cout << answer;
}