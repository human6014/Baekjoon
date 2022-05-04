#include <iostream>
#include <queue>
using namespace std;

bool isVisited[100001];
int BFS(int startNum, int endNum) {
	queue<pair<int, int>> q;
	q.push({startNum, 0});
	isVisited[startNum] = true;
	int firstFront,secondFront;
	while (!q.empty()) {
		firstFront = q.front().first;
		secondFront = q.front().second;

		
		if (firstFront == endNum)return secondFront;
		q.pop();

		if (firstFront * 2 < 100001 && !isVisited[firstFront * 2]) {
			q.push({ firstFront * 2, secondFront + 1 });
			isVisited[firstFront * 2] = true;
		}
		if (firstFront + 1 < 100001 && !isVisited[firstFront + 1]) {
			q.push({ firstFront + 1, secondFront + 1 });
			isVisited[firstFront + 1] = true;
		}
		if (firstFront > 0 && !isVisited[firstFront - 1]) {
			q.push({ firstFront - 1, secondFront + 1 });
			isVisited[firstFront - 1] = true;
		}
	}
	return -1;
}
int main() {
	int startNum,endNum;
	cin >> startNum >> endNum;
	cout << BFS(startNum, endNum);
}