#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;

	priority_queue<int,vector<int>,greater<int>> pq;
	int number, answer = 0;
	for (int i = 0; i < N; i++) {
		cin >> number;
		pq.push(number);
	}

	int front, second;
	while (pq.size() > 1) {
		front = pq.top();
		pq.pop();
		second = pq.top();
		pq.pop();

		answer += front + second;
		pq.push(front + second);
	}
	cout << answer;
}