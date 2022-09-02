
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) return a.second < b.second;
		return a.first > b.first;
	}
};
int main() {
	cin >> N;

	int maxTime = 0;
	int time = 1;
	int answer = 0;
	int first, second;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
	for (int i = 0; i < N; i++) {
		cin >> first >> second;
		maxTime = max(maxTime, first);
		pq.push({ first , second });
	}

	int frontFirst, frontSecond;
	while (!pq.empty() && time <= maxTime) {
		int frontFirst = pq.top().first;
		int frontSecond = pq.top().second;
		//std::cout << pq.top().first << " " << pq.top().second << "\n";
		
		if (time <= frontFirst) {
			answer += frontSecond;
			time++;
		}
		pq.pop();
	}
	cout << answer;
}
/*
7
1 9
1 100
2 300
2 99
3 100
5 100
5 999

 : 1599

3
3 5
3 4
1 1
 : 10

5
3 1
3 1
3 1
4 100
4 100
 : 202
*/
