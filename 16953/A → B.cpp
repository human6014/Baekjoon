#include <iostream>
#include <vector>
#include <queue>
using namespace std;

unsigned int N, M;
int BFS() {
	queue<pair<unsigned int, unsigned int>> q;
	int start = 1;
	q.push({ N, start });

	int frontFirst,frontSecond;
	while (!q.empty()) {
		frontFirst = q.front().first;
		frontSecond = q.front().second;
		q.pop();

		if (frontFirst == M)return frontSecond;

		else if (frontFirst <= M /2) {
			q.push({ frontFirst * 2, frontSecond + 1 });
			q.push({ frontFirst * 10 + 1, frontSecond + 1 });
		}
	}
	return -1;
}
int main() {
	cin >> N >> M;
	
	cout << BFS();
}
//10^9
//1,000,000,000