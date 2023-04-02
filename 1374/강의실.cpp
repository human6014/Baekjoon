#include <iostream>
#include <queue>
using namespace std;

int N, answer = 1;
struct compare {
	bool operator ()(pair<int, int> f, pair<int, int> s) {
		if (f.second == s.second) f.first > f.first;
		return f.second > s.second;
	}
};

int main() {
	cin >> N;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> startPQ;
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> endPQ;
	int index, startTime, endTime;
	for (int i = 0; i < N; i++) {
		cin >> index >> startTime >> endTime;
		startPQ.push({ startTime,endTime });
		//endPQ.push({startTime,endTime});
	}

	endPQ.push(startPQ.top());
	startPQ.pop();
	int startPQTime, endPQTime;
	while (!startPQ.empty()) {
		if (endPQ.top().second <= startPQ.top().first) {
			startPQTime = endPQ.top().first;
			endPQTime = startPQ.top().second;
			endPQ.pop();

			endPQ.push({ startPQTime,endPQTime });
		}
		else {
			endPQ.push(startPQ.top());
			answer++;
		}
		startPQ.pop();
	}
	cout << answer;

	//

	//cout << "\n";
	//while (!startPQ.empty()) {
	//	cout << startPQ.top().first <<" , \t" << startPQ.top().second << "\n";
	//	startPQ.pop();
	//}
	//cout << "\n ---------------------------------------------\n";
	//while (!endPQ.empty()) {
	//	cout << endPQ.top().first << " , \t" << endPQ.top().second << "\n";
	//	endPQ.pop();
	//}

}
/*
8
6		15  21
7		20  25
1		3   8
3		2   14
8		6   27
2		7   13
4		12  18
5		6   20

 : 5


2 ,     14
3 ,     8
6 ,     20
6 ,     27
7 ,     13
12 ,    18
15 ,    21
20 ,    25
*/