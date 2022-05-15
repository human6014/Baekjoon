#include <iostream>
#include <queue>
using namespace std;

int N, K;
int isVisited[100001] = {100001};
int answerTime = 0;
int answer = 0;

void BFS(int start) {
	queue < pair<int, int>> q;

	q.push({ start, 0 });
	bool isEnd = false;
	int front;
	int frontCount;
	while (!q.empty()) {
		front = q.front().first;
		frontCount = q.front().second;
		q.pop();

		if (front == K && !isEnd) {
			answerTime = frontCount;
			isEnd = true;
		}

		if (answerTime == frontCount && front == K) {
			answer++;
			continue;
		}
		if (isEnd)continue;

		if (front * 2 < 100001 && isVisited[front * 2] >= frontCount + 1) {
			isVisited[front * 2] = frontCount + 1;
			q.push({ front * 2, frontCount + 1 });
		}
		if (front + 1 < 100001 && isVisited[front + 1] >= frontCount + 1) {
			isVisited[front + 1] = frontCount + 1;
			q.push({ front + 1, frontCount + 1 });
		}
		if (front - 1 > -1 && isVisited[front - 1] >= frontCount + 1) {
			isVisited[front - 1] = frontCount + 1;
			q.push({ front - 1, frontCount + 1 });
		}
	}
}
int main() {
	fill_n(isVisited, 100001, 100001);
	cin >> N >> K;
	BFS(N);
	cout << answerTime << "\n" << answer;
}
/*
5 17
4
2

1 3
2
2

1 4
2
2

72 394
27
2

5 100000
19
4

5 1000
11
2

1000 0
1000
1

5 237
10
5

5 100000
19
4

5 1000
11 
2
*/