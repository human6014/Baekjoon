#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool isVisited[1001];
bool vertex[1001][1001];
int answer;
queue<int> q;

void BFS(int start) {
	q.push(start);
	isVisited[start] = true;
	int front;
	while (!q.empty()) {
		front = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (isVisited[i]) continue;
			if (vertex[front][i]) {
				
				isVisited[i] = true;
				q.push(i);
			}
		}
	}
}
int main() {
	cin >> N >> M;

	int first, second;
	for (int i = 1; i <= M; i++) {
		cin >> first >> second;
		vertex[first][second] = vertex[second][first]= 1;
	}
	for (int i = 1; i <= N; i++) {
		if (isVisited[i])continue;
		BFS(i);
		answer++;
	}
	cout << answer;
}