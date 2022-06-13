#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int const MAXIMUM = 100001;
int const MINIMUM = -1;
int N, K;
int isVisit[100001];
queue<pair<int, int>> numbers;
int BFS() {
	numbers.push({ N,0 });

	int front, dist;
	while (!numbers.empty()) {
		front = numbers.front().first;
		dist = numbers.front().second;
		numbers.pop();

		if (front == K) return dist;

		if (front + 1 < MAXIMUM && isVisit[front + 1] == MAXIMUM) {
			isVisit[front + 1] = front;
			numbers.push({ front + 1,dist + 1 });
		}
		if (front - 1 > MINIMUM && isVisit[front - 1] == MAXIMUM) {
			isVisit[front - 1] = front;
			numbers.push({ front - 1,dist + 1 });
		}
		if (front * 2 < MAXIMUM && isVisit[front * 2] == MAXIMUM) {
			isVisit[front * 2] = front;
			numbers.push({ front * 2, dist + 1 });
		}
	}
	return -1;
}
int main() {
	fill_n(isVisit, 100001, 100001);
	cin >> N >> K;
	cout << BFS() << "\n";

	vector<int> answers;
	answers.push_back(K);
	int back = K;
	while (back != N) {
		answers.push_back(back = isVisit[back]);
	}

	for (int i = answers.size() - 1; i >= 0; i--) {
		cout << answers[i] << " ";
	}
}
