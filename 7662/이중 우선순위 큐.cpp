#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int T;
int main() {
	cin >> T;

	int N;
	for (int i = 0; i < T; i++) {
		priority_queue<int, vector<int>, greater<int>> minQ;
		priority_queue<int, vector<int>, less<int>> maxQ;
		map<int, int> m;
		char command;
		int num;

		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> command >> num;
			if (command == 'I') {
				minQ.push(num);
				maxQ.push(num);
				m[num]++;
			}
			else if (command == 'D') {
				if (num == 1) {
					while (!maxQ.empty() && m[maxQ.top()] == 0) maxQ.pop();
					if (!maxQ.empty()) {
						m[maxQ.top()]--;
						maxQ.pop();
					}
				}
				else if (num == -1) {
					while (!minQ.empty() && m[minQ.top()] == 0) minQ.pop();
					if (!minQ.empty()) {
						m[minQ.top()]--;
						minQ.pop();
					}
				}
			}
		}
		while (!maxQ.empty() && m[maxQ.top()] == 0) maxQ.pop();
		while (!minQ.empty() && m[minQ.top()] == 0) minQ.pop();

		if (minQ.empty())cout << "EMPTY";
		else cout << maxQ.top() << " " << minQ.top();
		cout << "\n";
	}
}
/*
1
10
I 4
I 3
I 2
I 1
D 1
D 1
D -1
D -1
I 5
I 6

: 6 5

1
9
I -45
I 653
D 1
I -642
I 45
I 97
D 1
D -1
I 333
 : 333 -45

1
7
I 16
I -5643
D -1
D 1
D 1
I 123
D -1
 : EMPTY
 max : 333 45 -45 -642
 min : -45 45 97 333 653
*/

