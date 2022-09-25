#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;
int main() {
	cin >> N;
	stack <pair<int, int>> s;
	vector<int>numbers(N);
	vector<int>answers(N);
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	int front;
	s.push({ numbers[0], 0 });
	for (int i = 1; i < numbers.size(); i++) {
		front = numbers[i];
		while (!s.empty() && s.top().first < front) {
			answers[s.top().second] = front;
			s.pop();
		}
		s.push({ front,i });
	}

	while (!s.empty()) {
		answers[s.top().second] = -1;
		s.pop();
	}

	for (int i = 0; i < answers.size(); i++) {
		cout << answers[i] << " ";
	}
}
/*
7
4 3 2 1 2 3 4
 = -1 4 3 2 3 4 -1
*/
